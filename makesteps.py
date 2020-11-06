import argparse
from PIL import Image
import colorsys
import math
import enum

from itertools import zip_longest, product
import subprocess

TEENSY_MCU = "AT90USB1286"
JOYSTICK_HEX = "Joystick.hex"

# Other potential methods:
# Edge detection?
# Boxes
# Fold more steps

"""
Hue: 30 hues, each at zero, so H = i*12
Vividness: 15 saturations, so S = i*6
Vividness: 15 brightnesses, so B = i*6
"""

TIME_PER_STEP = 0.2  # This really is just about exactly right, according to time trials


class Step(enum.Enum):
    NONE = (0x0, 0x08)
    Y = (0x01, 0x08)
    B = (0x02, 0x08)
    A = (0x04, 0x08)
    X = (0x08, 0x08)
    L = (0x10, 0x08)
    R = (0x20, 0x08)
    LR = (0x30, 0x08)
    ZL = (0x40, 0x08)
    ZR = (0x80, 0x08)
    # MINUS = (0x100, 0x08)
    # PLUS = (0x200, 0x08)
    # LCLICK = (0x400, 0x08)
    # RCLICK = (0x800, 0x08)
    # HOME = (0x1000, 0x08)
    # CAPTURE = (0x2000, 0x08)
    HAT_UP = (0, 0x00)
    HAT_RIGHT = (0, 0x02)
    HAT_DOWN = (0, 0x04)
    HAT_LEFT = (0, 0x06)
    HAT_CENTER = (0, 0x08)
    HAT_UP_RIGHT = (0, 0x01)
    HAT_DOWN_RIGHT = (0, 0x03)
    HAT_DOWN_LEFT = (0, 0x05)
    HAT_UP_LEFT = (0, 0x07)


class PseudoStep(object):
    def __init__(self, step, label=None):
        super(PseudoStep, self).__init__()
        self.steps = [step]
        self.label = label

    @property
    def name(self):
        steps_part = (self.steps[0].name if len(self.steps) == 1 else "+".join(s.name for s in self.steps))
        label_part = (f" ({self.label})" if self.label else "")
        return f"{steps_part}{label_part}"
    
    @property
    def value(self):
        v1, v2 = 0, 8
        for step1, step2 in (s.value for s in self.steps):
            v1 |= step1
            assert not (v2 != 8 and step2 != 8)
            v2 = min(v2, step2)
        return (v1, v2)

    def plus(self, other):
        if other is not Step.NONE:
            self.steps.append(other)
        return self

    def __repr__(self):
        return "<%s.%s: %r>" % (self.__class__.__name__, self.name, self.value)
    

def foldSteps(step1, step2):
    if step1.value[0] != 0x0 and step2.value[0] != 0x0: 
        # print(f"Can't fold {step1}, {step2}")
        return [step1, step2]
    if step1.value[0] == Step.LR.value[0] or step2.value[0] == Step.LR.value[0]:
        # print(f"Can't fold {step1}, {step2}")
        return [step1, step2]
    if step1.value[1] != 0x8 and step2.value[1] != 0x8: 
        # print(f"Can't fold {step1}, {step2}")
        return [step1, step2]
    else:
        return [PseudoStep(step1).plus(step2)]


def foldStepSeqs(steps1, steps2):
    if not steps1:
        return steps2
    if not steps2:
        return steps1

    new_steps_compressed = []   
    for xstep, ystep in zip_longest(steps1, steps2, fillvalue=Step.NONE):
        new_steps_compressed += foldSteps(xstep, ystep)
    # print("Folded")
    # print(steps1)
    # print(steps2)
    # print(new_steps_compressed)
    return new_steps_compressed


def compressSteps(steps):
    steps = steps.copy()

    last_step = None
    last_step_times = 0

    for next_step in steps:
        if last_step and next_step.value == last_step.value:
            last_step_times += 1
        else:
            if last_step:
                bData, hData = last_step.value
                yield (bData, hData, last_step_times, last_step.name)
            last_step_times = 1
            last_step = next_step
    if last_step:
        bData, hData = last_step.value
        yield (bData, hData, last_step_times, last_step.name)
        

def saveSteps(steps):
    numsteps = 0

    with open("steps.c", "w") as fp:
        fp.write('#include "types.h"\n')
        fp.write('uint8_t step[] = {\n')
        
        for bData, hData, repetitions, label in compressSteps(steps):
            numsteps += 1
            fp.write(f"    {bData}, {hData}, {repetitions}, // {label} x {repetitions}\n")
        
        fp.write(" 0 };\n")
        fp.write(f"static int numsteps = {numsteps};\n")


# Zero index
HUES = 30 - 1
SATS = 15 - 1
VALS = 15 - 1



DEFAULT_PALETTE = [
    (0, 12, 14),  # Red
    (2, 12, 14),  # Orange
    (5, 13, 14),  # Yellow
    (8, 12, 14),  # Lime
    (10, 12, 8),  # Green
    (16, 11, 13),  # Teal  # Double check this
    (17, 12, 13),  # Cerulean
    (20, 11, 14),  # Blue
    (22, 10, 14),  # Purple
    (26, 9, 14),  # Pink  # Double check
    (1, 5, 14),  # Beige
    (1, 8, 8),  # Brown
    (0, 0, 14),  # White
    (0, 0, 6),  # Grey
    (0, 0, 0)  # Black
]


def percToInt(max):
    def c(val):
        return round(val * max)
    return c


def rgbaToACColor(pixel):
    if pixel[3] == 0:
        # Transparent, bad
        # raise NotImplementedError
        return (-1, -1, -1)
    r, g, b, *_ = pixel
    h, s, v = colorsys.rgb_to_hsv(r, g, b)
    v /= 255
    tup = (percToInt(HUES)(h), percToInt(SATS)(s), percToInt(VALS)(v))
    return tup


def acColorToRgba(color):
    if color == (-1, -1, -1):
        # raise NotImplementedError
        return (255, 0, 255, 0)
    # print(color)
    h_, s_, v_ = color
    rgbf = colorsys.hsv_to_rgb(
        (h_ / HUES),
        (s_ / SATS),
        (v_ / VALS)
    )
    rgb = list(map(percToInt(255), rgbf))
    # print(rgb)
    return (*rgb, 255)


class ACCanvas():
    def __init__(self, width, height):
        super(ACCanvas, self).__init__()
        self.w = width
        self.h = height
        self.canvas = [[None for x in range(width)] for y in range(height)]
        self.palette = None
        self.steps = []

    def fromPattern(self, infile_image):
        in_pixels = infile_image.load()
        for x in range(w):
            for y in range(h):
                self.canvas[x][y] = rgbaToACColor(in_pixels[x, y])
        return self

    def fromSentinal(self):
        self.canvas = [[(-2, -2, -2) for x in range(self.w)] for y in range(self.h)]
        return self

    def toPalImg(self):
        assert self.palette
        image_canvas = Image.new("RGBA", (len(self.palette), 1), color=(0, 0, 0, 0,))
        pixels = image_canvas.load()
        for i, pix in enumerate(self.palette):
            pixels[i, 0] = acColorToRgba(pix)
        return image_canvas

    def toImage(self):
        image_canvas = Image.new("RGBA", (self.w, self.h), color=(0, 0, 0, 0,))
        pixels = image_canvas.load()
        for x in range(self.w):
            for y in range(self.h):
                pixels[x, y] = acColorToRgba(self.canvas[x][y])
        return image_canvas

    def getAllNeighborPairs(self):
        # For each, check colors down and to the right
        for x in range(self.w - 1):
            for y in range(self.h - 1):
                yield ((x, y), (x + 1, y))
                yield ((x, y), (x, y + 1))

    def sortColorsByAdjacency(self, colorset):
        if len(colorset) < 2:
            return colorset

        # raise NotImplementedError

        colorset = list(colorset)
        color_pair_count = {}
        for (x1, y1), (x2, y2) in self.getAllNeighborPairs():
            if self.canvas[x1][y1] != self.canvas[x2][y2]:
                color_pair = tuple(sorted([self.canvas[x1][y1], self.canvas[x2][y2]]))
                color_pair_count[color_pair] = color_pair_count.get(color_pair, 0) + 1
        # Todo: Implement this properly
        color_pair_list = sorted(((color_pair_count.get(p), p) for p in color_pair_count.keys()))[::-1]
        
        freq, (color1, color2) = color_pair_list[0]
        # print(freq, colorset.index(color1), colorset.index(color2))
        new_colorset = [color1, color2]
        
        for freq, (color1, color2) in color_pair_list[1:]:
            # print(freq, colorset.index(color1), colorset.index(color2))
            for (c1, c2) in [(color1, color2), (color2, color1)]:
                if new_colorset[0] == c1:
                    if c2 not in new_colorset:
                        new_colorset = [c2] + new_colorset
                if new_colorset[-1] == c1:
                    if c2 not in new_colorset:
                        new_colorset.append(c2)
            for c in (color1, color2):
                if c not in new_colorset:
                    new_colorset.append(c)
            # print([colorset.index(c) for c in new_colorset])
            if len(colorset) == len(new_colorset):
                break
        for c in colorset:
            if c not in new_colorset:
                new_colorset.append(c)

        return new_colorset

    def genPalette(self, sortColorset=sorted):
        # if self.palette:
        #     return
        colorset = set()
        for row in self.canvas:
            for pixel in row:
                if pixel != (-1, -1, -1):
                    colorset.add(pixel)
        assert len(colorset) <= 15
        self.palette = sortColorset(colorset)
        for j, color in enumerate(self.palette):
            default = DEFAULT_PALETTE[j]

            # if color[1] == 0:
            #     self.palette[j] = (default[0], color[1], default[2])
            # If vividness is 0, hue doesn't matter
            if color[1] == 0:
                repl = (default[0], color[1], color[2])
                if repl != color:
                    # print(f"Replacing {color} with {repl}")
                    self.palette[j] = repl
                    for x in range(self.w):
                        for y in range(self.h):
                            if self.canvas[x][y] == color:
                                self.canvas[x][y] = repl
            # If brightness is 0, hue and vividness do not matter
            if color[2] == 0:
                repl = (default[0], default[1], color[2])
                if repl != color:
                    # print(f"Replacing {color} with {repl}")
                    self.palette[j] = repl
                    for x in range(self.w):
                        for y in range(self.h):
                            if self.canvas[x][y] == color:
                                self.canvas[x][y] = repl
        # print(f"Generated {len(colorset)} color image")
        # print(self.palette)

    # while y < source.h:
    #     while x < source.w:
    #         yield (x, y)
    #         x += 1
    #     y += 1
    #     x -= 1
    #     while x > 0:
    #         yield (x, y)
    #         x -= 1
    #     y += 1


class Tool(enum.Enum):
    PAL = (0, 0)
    PEN = (0, 1)
    BOX = (0, 2)
    FILL = (0, 3)
    STAMP_STAR = (0, 4)
    FILL_ALL = (0, 5)
    SWAP_PREVIEW = (0, 6)
    EDIT_COLOR = (1, 0)
    LINE = (1, 1)
    CIRCLE = (1, 2)
    STAMP_CIRCLE = (1, 3)
    STAMP_HEART = (1, 4)
    SHIFT = (1, 5)
    MIRROR = (1, 6)


class Printer(object):

    def __init__(self, source, settings={}):
        super(Printer, self).__init__()

        self.steps = []

        self.source = source
        self.pal_index = 0
        self.drawing = True

        self.x = 16
        self.y = 16

        self.tool_x = 0
        self.tool_y = 1
        self.pen_size = 1

        self.round_stamp_size = 2
        self.star_stamp_size = 2
        self.heart_stamp_size = 2

        self.mirror = False
        self.settings = {
            "startfill": True,
            "usemirror": True,
            "vertical": True,
            "horizontal": False,
            "adjpalette": False,
            # "neighborcolor": True,
        }
        self.settings.update(settings)

        self.sim = ACCanvas(self.source.w, self.source.h).fromSentinal()

    def setMirrored(self, target):
        new_steps = []
        if target is True and self.mirror is False:
            # Select tool
            new_steps.append(PseudoStep(Step.ZR, "SetMirrorT"))
            self.mirror = True
        if target is False and self.mirror is True:
            # Open menu
            new_steps.append(PseudoStep(Step.ZR, "SetMirrorF"))
            self.mirror = False

        return new_steps

    def setDrawing(self, target):
        new_steps = []
        if target is True and self.drawing is False:
            # Select tool
            new_steps.append(PseudoStep(Step.A, "SetDrawingT"))
            self.drawing = True
        if target is False and self.drawing is True:
            # Open menu
            new_steps.append(PseudoStep(Step.X, "SetDrawingF"))
            self.drawing = False

        return new_steps

    def moveTo(self, actual, desired, plus, minus):
        new_steps = []
        if desired > actual:
            new_steps += ([plus] * (desired - actual))
        elif actual > desired:
            new_steps += ([minus] * (actual - desired))

        return new_steps

    def setColorIndex(self, index, commit=True):
        new_steps = []

        if self.pal_index == index:
            return new_steps

        # if self.settings.get("neighborcolor") and abs(self.pal_index - index) > 4:
        #     # new_steps_start = len(new_steps)
        #     original_x, original_y = self.x, self.y
        #     # print(self.x, self.y, list(self.getNeighbors(self.x, self.y)))
        #     for nx, ny in self.getNeighbors(self.x, self.y):
        #         if self.sim.canvas[nx][ny] == self.source.palette[index]:
        #             new_steps += self.moveCursorTo(nx, ny)
        #             new_steps.append(PseudoStep(Step.LR, f"ColorPick{index} from {nx},{ny} for {original_x},{original_y}"))

        #             self.pal_index = index

        #             break
        #     new_steps += self.moveCursorTo(original_x, original_y)
        #     # print("nc", len(new_steps) - new_steps_start)

        # new_steps_start = len(new_steps)

        new_steps += self.moveTo(
            self.pal_index, index, 
            PseudoStep(Step.R, f"ColorR{index}"), PseudoStep(Step.L, f"ColorL{index}"))

        # print("c", len(new_steps) - new_steps_start)

        self.pal_index = index

        return new_steps

    def getNeighbors(self, tx, ty):
        for ox in [0, -1, 1]:
            x = self.x + ox
            if x > 0 and x < self.sim.w:
                for oy in [0, -1, 1]:
                    y = self.y + oy
                    if y > 0 and y < self.sim.h:
                        if (self.x, self.y) != (x, y):
                            yield (x, y)

    def setColor(self, color):
        new_steps = []

        try:
            new_steps += self.setColorIndex(self.source.palette.index(color))
        except ValueError:
            if color == (-1, -1, -1):
                new_steps += self.setColorIndex(-1)
            else:
                print(f"Color '{color}' not in list:")
                print(self.source.palette)
                raise

        return new_steps

    def setTool(self, tool):
        new_steps = []
        target_x, target_y = tool.value

        if (target_x, target_y) != (self.tool_x, self.tool_y):
            new_steps += self.setDrawing(False)

            new_steps += self.moveTo(self.tool_x, target_x, Step.HAT_RIGHT, Step.HAT_LEFT)
            self.tool_x = target_x
            new_steps += self.moveTo(self.tool_y, target_y, Step.HAT_DOWN, Step.HAT_UP)
            self.tool_y = target_y

            new_steps.append(PseudoStep(Step.A, "SetTool"))
            self.drawing = True
            # new_steps += self.setDrawing(True)

        return new_steps

    def moveCursorTo(self, target_x, target_y):
        new_steps_x = []
        new_steps_y = []

        new_steps_x += self.moveTo(self.x, target_x, Step.HAT_RIGHT, Step.HAT_LEFT)
        self.x = target_x
        new_steps_y += self.moveTo(self.y, target_y, Step.HAT_DOWN, Step.HAT_UP)
        self.y = target_y

        new_steps_compressed = []   
        for xstep, ystep in zip_longest(new_steps_x, new_steps_y, fillvalue=Step.NONE):
            if ystep == Step.NONE:
                new_steps_compressed.append(xstep)

            elif xstep == Step.NONE:
                new_steps_compressed.append(ystep)
            elif xstep == Step.HAT_LEFT:
                if ystep == Step.HAT_UP:
                    new_steps_compressed.append(Step.HAT_UP_LEFT)
                elif ystep == Step.HAT_DOWN:
                    new_steps_compressed.append(Step.HAT_DOWN_LEFT)
                else:
                    raise AssertionError(ystep)

            elif xstep == Step.HAT_RIGHT:
                if ystep == Step.HAT_UP:
                    new_steps_compressed.append(Step.HAT_UP_RIGHT)
                elif ystep == Step.HAT_DOWN:
                    new_steps_compressed.append(Step.HAT_DOWN_RIGHT)
                else:
                    raise AssertionError(ystep)
            else:
                raise AssertionError(xstep)

        # print(new_steps_x)
        # print(new_steps_y)
        # print(new_steps_compressed)

        return new_steps_compressed

    def smartTraverse(self, source):
        if self.settings.get("horizontal") and self.settings.get("vertical"):
            # Diagonal traverse
            # x = 0
            # y = 0
            # for sx in range(source.w):
            #     x = sx
            #     y = 0
            #     while x > 0 and y < source.h:
            #         x -= 1
            #         y += 1
            #         yield (x, y)
            raise NotImplementedError

        elif self.settings.get("horizontal") or self.settings.get("vertical"):
            x = 0
            y = 0
            while y < source.h:
                while x < source.w:
                    yield (x, y) if self.settings.get("horizontal") else (y, x)
                    x += 1
                y += 1
                x -= 1
                while x > 0:
                    yield (x, y) if self.settings.get("horizontal") else (y, x)
                    x -= 1
                yield (x, y) if self.settings.get("horizontal") else (y, x)    
                y += 1
        else:
            raise NotImplementedError

    def markPixel(self, target_x, target_y, target_color):

        new_steps = []

        if self.sim.canvas[target_x][target_y] == target_color:
            return new_steps

        if self.settings.get("usemirror") and self.source.canvas[self.source.w - target_x - 1][target_y] == target_color:
            should_mirror = True
        else:
            should_mirror = False

        new_steps += self.setTool(Tool.PEN)
        new_steps += self.setDrawing(True)

        move_to_steps = self.moveCursorTo(target_x, target_y)

        new_steps += foldStepSeqs(
            move_to_steps,
            self.setColor(target_color) + self.setMirrored(should_mirror)
        )

        # new_steps += self.setColor(target_color)

        # Make mark
        if should_mirror:
            new_steps += self.setMirrored(True)
            self.sim.canvas[self.x][self.y] = target_color
            self.sim.canvas[self.sim.w - self.x - 1][self.y] = target_color
        else:
            new_steps += self.setMirrored(False)
            self.sim.canvas[self.x][self.y] = target_color

        last_step = new_steps.pop()
        new_steps += foldSteps(last_step, Step.A)  # Safe

        # print(f"Mark {target_x} {target_y} {target_color}")
        # printSteps(new_steps)

        return new_steps

    # def markArea(self, area, target_color):

    #     new_steps = []

    #     if all(self.sim.canvas[x][y] == target_color for x, y in area):
    #         return new_steps

    #     new_steps += self.setTool(Tool.PEN)
    #     new_steps += self.setDrawing(True)

    #     new_steps += self.setColor(target_color)

    #     for x, y in self.smartTraverse(self.source):
    #         if (x, y) in area:
    #             new_steps += foldStepSeqs(
    #                 self.moveCursorTo(x, y),
    #                 self.setColor(target_color) + self.setMirrored(should_mirror)
    #             )

        

    #     # new_steps += self.setColor(target_color)

    #     # Make mark
    #     if should_mirror:
    #         new_steps += self.setMirrored(True)
    #         new_steps.append(Step.A)
    #         self.sim.canvas[self.x][self.y] = target_color
    #         self.sim.canvas[self.sim.w - self.x - 1][self.y] = target_color
    #     else:
    #         new_steps += self.setMirrored(False)
    #         new_steps.append(Step.A)
    #         self.sim.canvas[self.x][self.y] = target_color

    #     # print(f"Mark {target_x} {target_y} {target_color}")
    #     # printSteps(new_steps)

    #     return new_steps


    def setPalette(self, source_palette):
        new_steps = []
        assert source_palette

        # Reset palette
        new_steps += self.setTool(Tool.PAL)
        new_steps += [Step.NONE, Step.HAT_DOWN, Step.NONE, PseudoStep(Step.A, "ResetPalette"), Step.NONE]
        self.drawing = False  # Odd case

        new_steps += self.setTool(Tool.EDIT_COLOR)
        new_steps += self.setDrawing(True)

        # Set each color
        # Default colors are not all zero. Compensate.
        for j, color in enumerate(source_palette):
            new_steps += self.setColorIndex(j)
            new_steps.append(Step.NONE)
            for desired, actual in zip(color, DEFAULT_PALETTE[j]):
                new_steps += self.moveTo(actual, desired, Step.HAT_RIGHT, Step.HAT_LEFT)
                new_steps.append(Step.HAT_DOWN)

        # Exit menu
        new_steps.append(Step.A)

        # Done
        new_steps += self.setTool(Tool.PEN)
        new_steps += self.setDrawing(True)
        new_steps.append(Step.NONE)
        return new_steps

    def fillAll(self, color):
        new_steps = []

        new_steps += self.setColor(color)
        new_steps += self.setTool(Tool.FILL_ALL)
        new_steps.append(PseudoStep(Step.A, "FillAll"))
        for x in range(self.sim.w):
            for y in range(self.sim.h):
                self.sim.canvas[x][y] = color

        return new_steps

    def toSteps(self):
        new_steps = []
        if self.settings.get("adjpalette"):
            self.source.genPalette(sortColorset=self.source.sortColorsByAdjacency)
        else:
            self.source.genPalette()

        new_steps += self.setPalette(self.source.palette)
        new_steps.append(Step.NONE)
        new_steps += self.drawImage(self.source)
        # for step in self.genStepsPalette():
        #     self.steps.append(step)
        # for step in self.genStepsDraw():
        #     self.steps.append(step)
        return new_steps

    def drawImage(self, source):
        new_steps = []

        if self.settings.get("startfill"):
            all_pixels = [item for sublist in source.canvas for item in sublist]
            most_common_color = max(set(all_pixels), key=all_pixels.count)

            new_steps += self.fillAll(most_common_color)

        new_steps += self.drawImageCustom(source)

        new_steps += foldStepSeqs(self.moveCursorTo(16, 16), self.setColorIndex(0))
        new_steps += self.setMirrored(False)

        self.sim.toImage().save("progress.png")

        # assert self.sim.canvas == self.source.canvas

        return new_steps

    def drawImageCustom(self, source):
        raise NotImplementedError


class NaivePrinter(Printer):

    def drawImageCustom(self, source):
        new_steps = []

        for x, y in self.smartTraverse(source):
            new_steps += self.markPixel(x, y, source.canvas[x][y])
        return new_steps


class ScreenPrinter(Printer):

    def drawImageCustom(self, source):
        new_steps = []

        for color in source.palette:
            for x, y in self.smartTraverse(source):
                if source.canvas[x][y] == color:
                    new_steps += self.markPixel(x, y, color)
        return new_steps


class SpiralPrinter(Printer):
        
    def drawImageCustom(self, source):
        new_steps = []
        direction = "L"

        x = 16
        y = 16

        while self.sim.canvas != source:
            new_steps += self.markPixel(x, y, source.canvas[x][y])
            try:
                if direction == "L":
                    x -= 1
                    # new_steps.append(Step.HAT_LEFT)
                    if self.sim.canvas[x][y - 1] != source.canvas[x][y - 1]:
                        direction = "U"
                elif direction == "R":
                    x += 1
                    # new_steps.append(Step.HAT_RIGHT)
                    if self.sim.canvas[x][y + 1] != source.canvas[x][y + 1]:
                        direction = "D"
                elif direction == "U":
                    y -= 1
                    # new_steps.append(Step.HAT_UP)
                    if self.sim.canvas[x + 1][y] != source.canvas[x + 1][y]:
                        direction = "R"
                elif direction == "D":
                    y += 1
                    # new_steps.append(Step.HAT_DOWN)
                    if self.sim.canvas[x - 1][y] != source.canvas[x - 1][y]:
                        direction = "L"
            except IndexError:
                print(x, y)
                break
        return new_steps
        

def add_bool_arg(parser, name, default=True, help=None):
    group = parser.add_mutually_exclusive_group(required=False)
    group.add_argument('--' + name, dest=name.replace("-", "_"), action='store_true', help=help + f" (Default: {default})")
    group.add_argument('--no-' + name, dest=name.replace("-", "_"), action='store_false', help=help + f" (Default: {default})")
    parser.set_defaults(**{name: default})


def identifyInfile(infile_image):
    print(infile_image.size)
    if infile_image.size[0] < 64:
        if infile_image.size[1] < 64:
            return "PATTERN"
    return "UNKNOWN"


def printSteps(steps):
    # print("\n".join(repr(s) for s in steps))
    for bData, hData, repetitions, label in compressSteps(steps):
        print(f"{label} x {repetitions}")


def fmtTime(seconds):
    if seconds <= 60:
        return f"{seconds}s"
    else:
        return f"{int(seconds // 60)}m {int(seconds % 60)}s"

# Main
parser = argparse.ArgumentParser()
parser.add_argument("infile", help="Input pattern file")
add_bool_arg(parser, "dump", default=True, help="Save pattern")
add_bool_arg(parser, "gen", default=True, help="Generate steps file")
add_bool_arg(parser, "preview", default=True, help="Generate scaled preview file")
add_bool_arg(parser, "bogo", default=True, help="Find fastest solution")
add_bool_arg(parser, "make", default=False, help="Automatically run make after completion")
args = parser.parse_args()

infile_image = Image.open(args.infile).convert('RGBA')
infile_type = identifyInfile(infile_image)

pattern = None
if infile_type == "PATTERN":
    w, h = infile_image.size
    pattern = ACCanvas(w, h).fromPattern(infile_image)
else:
    raise NotImplementedError


if args.dump:
    if infile_type == "PATTERN":
        pattern.toImage().save("dump.png")
        pattern.genPalette()
        pattern.toPalImg().save("pal.png")
    else:
        raise NotImplementedError

if args.preview:
    if infile_type == "PATTERN":
        image = args.infile
    elif args.dump:
        image = "dump.png"
    else:
        raise NotImplementedError
    subprocess.run(["ScalerTest_Windows.exe", "-6xBRZ", image, "scalepreview.png"])
    print("Generated preview at scalepreview.png")

settings_permutations = [
    (
        binstr, 
        {
            "usemirror": (binstr[0] == "1"),
            "horizontal": (binstr[1] == "1"),
            "vertical": (binstr[2] == "1"),
            "startfill": (binstr[3] == "1"),
            "adjpalette": (binstr[4] == "1")
        },
    )
    for binstr in 
    ["".join(seq) for seq in product("01", repeat=5)]
]

if args.gen:
    if args.bogo:
        best_steps = None
        best_printer = None
        # , SpiralPrinter
        for Printer_ in [NaivePrinter, ScreenPrinter]:
            for settings_str, settings in settings_permutations:
                printer = Printer_(pattern, settings=settings)
                try:
                    steps = printer.toSteps()
                    print(f"{Printer_} ({settings_str}) printed pattern in {len(steps)} steps ({(len(steps)*3)/8} bytes) (~{fmtTime(len(steps) * TIME_PER_STEP)} runtime)")

                    if best_steps is None or len(steps) < len(best_steps):
                        best_steps = steps
                        best_printer = printer
                        print("BEST!")
                except NotImplementedError:
                    # print(f"{Printer_} ({settings_str}) has invalid settings.")
                    pass
                except Exception:
                    print(f"{Printer_} ({settings_str}) failed!")

                    import traceback
                    traceback.print_exc()
        print(best_printer)
        print(best_printer.settings)
        saveSteps(best_steps)
    else:
        saveSteps(NaivePrinter(pattern).toSteps())

if args.make:
    if subprocess.run(["make"]):
        print(f"Waiting for {TEENSY_MCU}...")
        subprocess.run(["../teensy_loader_cli", "--mcu", TEENSY_MCU, "-w", JOYSTICK_HEX])
