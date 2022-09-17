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
    LCLICK = (0x400, 0x08)
    LCLICK_OVERRIDE = (0xFF, 0x08)
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


class Splat3Canvas():
    def __init__(self, width, height):
        super().__init__()
        self.w = width
        self.h = height
        self.canvas = [[None for y in range(height)] for x in range(width)]
        self.palette = None
        self.steps = []

    def clear(self):
        self.canvas = [[False for y in range(self.h)] for x in range(self.w)]

    @classmethod
    def fromPattern(cls, infile_image):
        (width, height) = infile_image.size
        ret = cls(width, height)
        in_pixels = infile_image.load()
        for x in range(width):
            for y in range(height):
                ret.canvas[x][y] = (True if in_pixels[x, y] == 0 else False)
        return ret

    # def fromSentinal(self):
    #     self.canvas = [[None for x in range(self.w)] for y in range(self.h)]
    #     return self

    def toImage(self):
        image_canvas = Image.new("RGB", (self.w, self.h))
        pixels = image_canvas.load()
        for x in range(self.w):
            for y in range(self.h):
                pixels[x, y] = (0,0,0) if self.canvas[x][y] else (255,255,255)
        return image_canvas

    def getAllNeighborPairs(self):
        # For each, check colors down and to the right
        for x in range(self.w - 1):
            for y in range(self.h - 1):
                yield ((x, y), (x + 1, y))
                yield ((x, y), (x, y + 1))

    def rel_stamp_footprint(self, stamp, tx, ty):
        return [
            (x + tx, y + ty)
            for (x, y) in stamp.value[1].value
            if (x + tx) in range(self.w) and (y + ty) in range(self.h)
        ]

import itertools

class Footprints(enum.Enum):
    # Pixels, releative to the center, that this affects.
    SMALL = [(0, 0)]
    MED = list(set([ # a square
        (x, y)
        for x in range(-2, 3)
        for y in range(-2, 3)
    ]) - set([ # with no corners
        (x, y)
        for x in [-2, 2]
        for y in [-2, 2]
    ]))
    LARGE = list(set([ # a square
        (x, y)
        for x in range(-3, 4)
        for y in range(-3, 4)
    ]) | set([ # with extra bits
        (x, y)
        for x in range(-1, 2)
        for y in [-4, 4]
    ]) | set([ # with extra bits
        (x, y)
        for x in [-4, 4]
        for y in range(-1, 2)
    ]))

class Size(enum.Enum):
    # Index, Radius
    SMALL = (0, Footprints.SMALL)
    MED = (1, Footprints.MED)
    LARGE = (2, Footprints.LARGE)

class Printer(object):

    def __init__(self, source, settings={}):
        super(Printer, self).__init__()

        self.steps = []

        self.source = source

        self.x = int(source.w/2)
        self.y = int(source.h/2)
        self.center = (self.x, self.y)

        self.size = Size.MED

        self.settings = self.defaultSettings()
        self.settings.update(settings)

        self.sim = Splat3Canvas(self.source.w, self.source.h) # .fromSentinal()

    @classmethod
    def defaultSettings(cls):
        return {
            "horizontal": True,
            "vertical": False
        }

    def moveTo(self, actual, desired, plus, minus):
        new_steps = []
        if desired > actual:
            new_steps += ([plus] * (desired - actual))
        elif actual > desired:
            new_steps += ([minus] * (actual - desired))

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

    # def setTool(self, tool):
    #     new_steps = []
    #     target_x, target_y = tool.value

    #     if (target_x, target_y) != (self.tool_x, self.tool_y):
    #         new_steps += self.setDrawing(False)

    #         new_steps += self.moveTo(self.tool_x, target_x, Step.HAT_RIGHT, Step.HAT_LEFT)
    #         self.tool_x = target_x
    #         new_steps += self.moveTo(self.tool_y, target_y, Step.HAT_DOWN, Step.HAT_UP)
    #         self.tool_y = target_y

    #         new_steps.append(PseudoStep(Step.A, "SetTool"))
    #         self.drawing = True
    #         # new_steps += self.setDrawing(True)

    #     return new_steps

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

    def smartTraverse(self, source, min_increment=(1,1)):
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

        elif self.settings.get("horizontal") and not self.settings.get("vertical"):
            x = 0
            y = 0
            # Left to right
            while x < source.w:
                # Top to bottom
                while y < source.h:
                    yield (x, y)
                    y += min_increment[1]
                x += min_increment[0]
                y -= min_increment[1]
                while y > 0:
                    yield (x, y)
                    y -= min_increment[1]
                yield (x, y)
                x += min_increment[0]
        elif self.settings.get("vertical") and not self.settings.get("horizontal"):
            x = 0
            y = 0
            # Top to bottom
            while y < source.h:
                # Left to right
                while x < source.w:
                    yield (x, y)
                    x += min_increment[0]
                y += min_increment[1]
                x -= min_increment[0]
                while x > 0:
                    yield (x, y)
                    x -= min_increment[0]
                yield (x, y)
                y += min_increment[1]
        else:
            raise NotImplementedError(f"{self.settings.get('horizontal')=}, {self.settings.get('vertical')=}")

    def setSize(self, new_size):
        new_steps = []
        target_sizex, tool_size = new_size.value
        current_sizex = self.size.value[0]

        if target_sizex != current_sizex:
            new_steps += self.moveTo(current_sizex, target_sizex, Step.R, Step.L)

        self.size = new_size
        return new_steps

    def markStamp(self, target_x, target_y, target_color, stamp=Size.SMALL):

        new_steps = []
        # print(stamp_footprint)

        # print(rel_stamp_footprint)

        if all(
            self.sim.canvas[x][y] == target_color
            for (x, y) in self.sim.rel_stamp_footprint(stamp, target_x, target_y)
        ):
            # print(f"OK {target_x} {target_y} {target_color}")
            return new_steps

        move_to_steps = foldStepSeqs(
            self.moveCursorTo(target_x, target_y),
            self.setSize(stamp)
        )
        new_steps += move_to_steps

        # Make mark
        for (x, y) in self.sim.rel_stamp_footprint(stamp, self.x, self.y):
            self.sim.canvas[x][y] = target_color

        last_step = new_steps.pop()
        new_steps += foldSteps(last_step, Step.A if target_color else Step.B)  # Safe

        # print(f"Mark {target_x} {target_y} {target_color}:")
        # printSteps(new_steps)

        return new_steps

    def toSteps(self):
        new_steps = []
        new_steps += [Step.LCLICK_OVERRIDE]
        self.sim.clear()
        new_steps += self.drawImage(self.source)
        return new_steps

    def drawImage(self, source):
        new_steps = []

        new_steps += self.drawImageCustom(source)
        new_steps += self.moveCursorTo(*self.center)

        self.sim.toImage().save("progress.png")

        return new_steps

    def drawImageCustom(self, source):
        raise NotImplementedError


class NaivePrinter(Printer):

    def drawImageCustom(self, source):
        new_steps = []

        for x, y in self.smartTraverse(source):
            try:
                target = source.canvas[x][y]
                new_steps += self.markStamp(x, y, target)
            except IndexError:
                print(f"{x=}/{len(source.canvas)=}, {y=}/{len(source.canvas[x])=}")
                raise
        return new_steps


class SizeLayerPrinter(Printer):

    @classmethod
    def defaultSettings(cls):
        return {
            **super().defaultSettings(),
            **{
                "threshhold": 0.4,
            }
        }

    def drawImageCustom(self, source):
        new_steps = []

        def isOffset(tup, spacing_x=8, spacing_y=6):
            (x, y) = tup
            return any(
                ((x2 % (spacing_x - 1) == 0) and (y2 % (spacing_y - 1) == 0))
                for (x2, y2) in [tup, (x + (spacing_x / 2), y + (spacing_y / 2))]
            )

        def markedImage():
            im = self.sim.toImage()
            pixels = im.load()
            pixels[self.x, self.y] = (255,0,0)
            return im

        gif_frames = []
        for i, (stamp, min_increment) in enumerate([
            (Size.LARGE, (7, 7)),
            (Size.MED, (4, 3)),
            # (Size.SMALL, (1,1))
        ]):

            for x, y in self.smartTraverse(source, min_increment=min_increment):  # filter(isOffset, ):
                # print(x, y)
                chunk = self.sim.rel_stamp_footprint(stamp, x, y)
                threshhold = self.settings['threshhold']
                marks = [
                    (x2, y2) for (x2, y2) in chunk
                    if source.canvas[x2][y2] != self.sim.canvas[x2][y2]
                ]
                if len(marks) > threshhold * len(chunk):
                    # print("Stamping", len(marks), threshhold, len(chunk))
                    new_steps += self.markStamp(x, y, source.canvas[x][y], stamp=stamp)
                    gif_frames.append(markedImage())

        for i, (x, y) in enumerate(self.smartTraverse(source)):
            new_steps += self.markStamp(x, y, source.canvas[x][y])
            if i % 16 == 0:
                gif_frames.append(markedImage())

        if gif_frames:
            gif_frames[0].save(
                f'sl_{threshhold}_progress.gif', format='GIF', append_images=gif_frames[1:],
                save_all=True, duration=30, loop=0)

        # gif_frames = []
        # for x, y in reversed([*self.smartTraverse(source)]):
        #     pix_step = self.markStamp(x, y, source.canvas[x][y])
        #     new_steps += pix_step
        #     # if len(pix_step) > 0:
        #     #     gif_frames.append(self.sim.toImage())

        # if gif_frames:
        #     gif_frames[0].save(
        #         f'sl_{threshhold}_progress2.gif', format='GIF', append_images=gif_frames[1:],
        #         save_all=True, duration=30, loop=0)
        return new_steps


class SpiralPrinter(Printer):
        
    def drawImageCustom(self, source):
        new_steps = []
        direction = "L"

        x = 16
        y = 16

        while self.sim.canvas != source:
            new_steps += self.markStamp(x, y, source.canvas[x][y])
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


# def identifyInfile(infile_image):
#     print(infile_image.size)
#     if infile_image.size[0] < 64:
#         if infile_image.size[1] < 64:
#             return "PATTERN"
#     return "UNKNOWN"


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
# add_bool_arg(parser, "preview", default=True, help="Generate scaled preview file")
add_bool_arg(parser, "bogo", default=True, help="Find fastest solution")
add_bool_arg(parser, "make", default=False, help="Automatically run make after completion")
args = parser.parse_args()

infile_image = Image.open(args.infile).convert('L')
infile_type = "PATTERN" # identifyInfile(infile_image)

pattern = None
if infile_type == "PATTERN":
    w, h = infile_image.size
    pattern = Splat3Canvas(w, h).fromPattern(infile_image)
else:
    raise NotImplementedError


if args.dump:
    if infile_type == "PATTERN":
        pattern.toImage().save("dump.png")
        # pattern.genPalette()
        # pattern.toPalImg().save("pal.png")
    else:
        raise NotImplementedError

# if args.preview:
#     if infile_type == "PATTERN":
#         image = args.infile
#     elif args.dump:
#         image = "dump.png"
#     else:
#         raise NotImplementedError
#     subprocess.run(["ScalerTest_Windows.exe", "-6xBRZ", image, "scalepreview.png"])
#     print("Generated preview at scalepreview.png")

settings_permutations = [
    (
        binstr, 
        {
            # "usemirror": (binstr[0] == "1"),
            "horizontal": (binstr[0] == "1"),
            "threshhold": (0.7 if binstr[1] == "1" else 0.3),
            # "startfill": (binstr[3] == "1"),
            # "adjpalette": (binstr[4] == "1")
        },
    )
    for binstr in 
    ["".join(seq) for seq in product("01", repeat=2)]
]

if args.gen:
    if args.bogo:
        best_steps = None
        best_printer = None
        # , SpiralPrinter
        for Printer_ in [NaivePrinter, SizeLayerPrinter]:
            for settings_str, settings in settings_permutations:
                printer = Printer_(pattern, settings=settings)
                try:
                    steps = printer.toSteps()
                    print(f"{Printer_} ({settings_str}) printed pattern in {len(steps)} steps ({(len(steps)*3)/8} bytes / 8192 ({((len(steps)*3)/8)/81.92}%)) (~{fmtTime(len(steps) * TIME_PER_STEP)} runtime)")

                    if best_steps is None or len(steps) < len(best_steps):
                        best_steps = steps
                        best_printer = printer
                        print("BEST!")
                except NotImplementedError:
                    # print(f"{Printer_} ({settings_str}) has invalid settings.")
                    pass
                except Exception:
                    print(f"{Printer_} ({settings_str} {settings}) failed!")

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
