import argparse
# import colorsys
import enum
# import math
import pprint

from PIL import Image

import itertools
import functools

import collections
import subprocess

from itertools import product
from itertools import zip_longest

import traceback

try:
    # raise ImportError("Disabling threads")
    from parallel_threads import do_work_helper
except ImportError:
    traceback.print_exc()

    def do_work_helper(workfn, inputs, max_threads=8):
        for i in inputs:
            # print(i)
            workfn(*i)

# TODO: Pattern that first draws the solid blocks, then erases any extras needed

TEENSY_MCU = "AT90USB1286"
JOYSTICK_HEX = "Joystick.hex"

# CALC_COMPRESSED_SIZE = True  # Choose smallest compressed size (True) instead of smallest runtime (False)
MAX_COMPRESSED_SIZE = 4000 # Reject plans with more than this many steps after compression

# Other potential methods:
# Edge detection?
# Boxes
# Fold more steps

NUM_ECHOES = 5
TIME_PER_STEP = (1/120) * (1 + NUM_ECHOES) * 2 # 120hz, 2 echoes, one blank after each step

NO_FOLDING = False

# uint4s, max size is 0b1111 == 15 == 0x0f
class Step(enum.Enum):
    NONE = (0x0, 0x08)
    Y = (0x01, 0x08)
    B = (0x02, 0x08)
    A = (0x04, 0x08)
    # X = (0x08, 0x08)
    L = (0x06, 0x08)
    R = (0x07, 0x08)
    # L = (0x10, 0x08)
    # R = (0x20, 0x08)
    LR = (0x30, 0x08)
    ZL = (0x40, 0x08)
    ZR = (0x80, 0x08)
    # MINUS = (0x100, 0x08)
    # PLUS = (0x200, 0x08)
    # LCLICK = (0x400, 0x08)
    LCLICK = (0x08, 0x08)  # C code needs to map 0x08 -> 0x400
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


def foldSteps(step1, step2, label=None):
    if NO_FOLDING:
        return [step1, step2]
    if step1.value[0] != Step.NONE.value[0] and step2.value[0] != Step.NONE.value[0]:
        print(f"Can't fold buttons {step1}, {step2}")
        return [step1, step2]
    if step1.value[0] == Step.LR.value[0] or step2.value[0] == Step.LR.value[0]:
        print(f"Can't fold LR {step1}, {step2}")
        return [step1, step2]
    if step1.value[1] != Step.NONE.value[1] and step2.value[1] != Step.NONE.value[1]:
        print(f"Can't fold d-pad {step1}, {step2}")
        # different d-pad movements
        return [step1, step2]
    if step1.value[0] == Step.LCLICK.value[0] and step2.value[0] == Step.LCLICK.value[0]:
        print(f"Can't fold LCLICK {step1}, {step2}")
        return [step1, step2]
    else:
        return [PseudoStep(step1).plus(step2)]


def foldStepSeqs(steps1, steps2, label=None):
    if not steps1:
        return steps2
    if not steps2:
        return steps1

    new_steps_compressed = []
    for xstep, ystep in zip_longest(steps1, steps2, fillvalue=Step.NONE):
        new_steps_compressed += foldSteps(xstep, ystep, label=label)
    return new_steps_compressed


def compressSteps(steps, rep_max=0xff):
    steps = steps.copy()

    last_step = None
    last_step_times = 0

    for next_step in steps:
        if last_step and next_step.value == last_step.value:
            # Duplicate valued step
            last_step_times += 1
            if last_step_times >= rep_max:
                # Step has filled rep capacity, yield and reset
                bData, hData = last_step.value
                yield (bData, hData, last_step_times, last_step.name)
                last_step = None
                last_step_times = 0
        else:
            if last_step:
                # Yield the previous step and mark the new step as the new previous
                bData, hData = last_step.value
                yield (bData, hData, last_step_times, last_step.name)
            last_step_times = 1
            last_step = next_step
    if last_step:
        # Yield any leftover steps
        bData, hData = last_step.value
        yield (bData, hData, last_step_times, last_step.name)


def saveSteps(steps):
    numsteps = 0

    with open("steps.c", "w") as fp:
        fp.write('#include "types.h"\n')
        fp.write('uint8_t step[] = {\n')

        for bData, hData, repetitions, label in compressSteps(steps):
            numsteps += 1
            bhData = (bData << 4) + hData
            fp.write(f"    0b{bhData:08b}, {repetitions}, // b={bData} {bData:04b} h={hData} {hData:04b} {label} x {repetitions}\n")

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
                pixels[x, y] = (0, 0, 0) if self.canvas[x][y] else (255, 255, 255)
        return image_canvas

    # def getAllNeighborPairs(self):
    #     # For each, check colors down and to the right
    #     for x in range(self.w - 1):
    #         for y in range(self.h - 1):
    #             yield ((x, y), (x + 1, y))
    #             yield ((x, y), (x, y + 1))

    def rel_stamp_footprint(self, stamp, tx, ty):
        return rel_stamp_footprint(self.w, self.h, stamp, tx, ty)


@functools.lru_cache()
def rel_stamp_footprint(w, h, stamp, tx, ty):
    return [
        (x + tx, y + ty)
        for (x, y) in stamp.value[1]
        if (x + tx) in range(w) and (y + ty) in range(h)
    ]

class NoValueEnum(enum.Enum):
    def __repr__(self):
        return '<%s.%s>' % (self.__class__.__name__, self.name)

class Size(NoValueEnum):
    # Pixels, releative to the center, that this affects.
    SMALL = (0, [(0, 0)])
    MED = (1, list(set([  # a square
        (x, y)
        for x in range(-2, 3)
        for y in range(-2, 3)
    ]) - set([  # with no corners
        (x, y)
        for x in [-2, 2]
        for y in [-2, 2]
    ])))
    LARGE = (2, list(set([  # a square
        (x, y)
        for x in range(-3, 4)
        for y in range(-3, 4)
    ]) | set([  # with extra bits
        (x, y)
        for x in range(-1, 2)
        for y in [-4, 4]
    ]) | set([  # with extra bits
        (x, y)
        for x in [-4, 4]
        for y in range(-1, 2)
    ])))


class Printer(object):

    def __init__(self, source, settings={}):
        super(Printer, self).__init__()

        self.steps = []

        self.source = source

        self.x = int(source.w / 2)
        self.y = int(source.h / 2)
        self.center = (self.x, self.y)

        self.size = Size.MED

        self.settings = self.defaultSettings()
        self.settings.update(settings)
        self.last_movement = Step.NONE

        self.sim = Splat3Canvas(self.source.w, self.source.h)  # .fromSentinal()

    def copy(self):
        ret = self.__class__(source=self.source, settings=self.settings)
        return ret

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

    def genGif(self, *args):
        raise NotImplementedError(self.__class__.genGif)

    def moveCursorTo(self, target_x, target_y):
        new_steps_x = []
        new_steps_y = []

        new_steps_x += self.moveTo(self.x, target_x, Step.HAT_RIGHT, Step.HAT_LEFT)
        new_steps_y += self.moveTo(self.y, target_y, Step.HAT_DOWN, Step.HAT_UP)

        new_steps_compressed = []
        for xstep, ystep in zip_longest(new_steps_x, new_steps_y, fillvalue=Step.NONE):
            if NO_FOLDING:
                new_steps_compressed.append(xstep)
                new_steps_compressed.append(ystep)
                continue

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

        if len(new_steps_compressed) > 0:
            self.last_movement = new_steps_compressed[-1]
            new_steps_compressed[-1] = PseudoStep(new_steps_compressed[-1], label=f"Moveto {target_x, target_y}")

        self.x = target_x
        self.y = target_y

        return new_steps_compressed

    def smartTraverse(self, source, min_increment=(1, 1)):
        if self.settings.get("horizontal") and self.settings.get("vertical"):
            # Diagonal traverse
            raise NotImplementedError

        elif self.settings.get("horizontal") and not self.settings.get("vertical"):
            x = 0
            y = 0
            # Left to right
            while x < source.w:
                # Top to bottom
                while y < source.h:
                    assert x < source.w
                    yield (x, y)
                    y += min_increment[1]
                x += min_increment[0]
                if x >= source.w:
                    break
                y -= min_increment[1]
                while y > 0:
                    yield (x, y)
                    y -= min_increment[1]
                assert x < source.w
                assert y < source.h
                yield (x, y)
                x += min_increment[0]
        elif self.settings.get("vertical") and not self.settings.get("horizontal"):
            x = 0
            y = 0
            # Top to bottom
            while y < source.h:
                # Left to right
                while x < source.w:
                    assert x < source.w
                    yield (x, y)
                    x += min_increment[0]
                y += min_increment[1]
                if y >= source.h:
                    break
                x -= min_increment[0]
                while x > 0:
                    yield (x, y)
                    x -= min_increment[0]
                assert x < source.w
                assert y < source.h
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

    def shouldStamp(self, target_x, target_y, source, stamp):
        chunk = self.sim.rel_stamp_footprint(stamp, target_x, target_y)
        marks = [
            source.canvas[x][y] for (x, y) in chunk
        ]
        (target_color, count) = collections.Counter(marks).most_common(1)[0]

        changes = [(x, y) for (x, y) in chunk if (self.sim.canvas[x][y] != target_color)]
        changed_correctly = [(x, y) for (x, y) in changes if (source.canvas[x][y] == target_color)]

        # change_count = len(changes)
        correct_change_count = len(changed_correctly)

        return (any(changed_correctly), correct_change_count, target_color)

    def markStamp(self, target_x, target_y, source, stamp=Size.SMALL):
        new_steps = []

        any_changes, correct_change_count, target_color = self.shouldStamp(target_x, target_y, source, stamp)

        if not any_changes:
            return new_steps

        move_to_steps = foldStepSeqs(
            self.moveCursorTo(target_x, target_y),
            self.setSize(stamp),
            label=f"Move to {target_x, target_y} w/ size {stamp}"
        )
        new_steps += move_to_steps

        # Make mark
        for (x, y) in self.sim.rel_stamp_footprint(stamp, self.x, self.y):
            self.sim.canvas[x][y] = target_color

        if len(new_steps) > 0:
            last_step = new_steps.pop()
            new_steps += foldSteps(last_step, Step.A if target_color else Step.B)  # Safe

        return new_steps

    def toSteps(self):
        new_steps = []
        new_steps += self.drawImage(self.source)
        return new_steps

    def drawImage(self, source):
        new_steps = []

        new_steps += [Step.LCLICK]
        self.sim.clear()
        new_steps += self.drawImageCustom(source)
        if self.sim.canvas != source.canvas:
            self.sim.toImage().save(f"{self.__class__.__name__} mismatch_sim.png")
            source.toImage().save(f"{self.__class__.__name__} mismatch_source.png")
            raise AssertionError("Generated wrong image!")

        # if self.settings.get('gif_out'):
        #     self.sim.toImage().save("final_sim.png")
        #     source.toImage().save("final_source.png")

        new_steps += foldStepSeqs(
            self.moveCursorTo(*self.center),
            self.setSize(Size.MED),
            label="Reset pos & size"
        )
        return new_steps

    def markedImage(self):
        im = self.sim.toImage()
        return im

        pixels = im.load()
        try:
            pixels[self.x, self.y] = (255, 0, 0)
            return im
        except IndexError:
            print("Out of bounds?")
            print(f"{im.size=} {self.x=} {self.y=}")
            raise

    def drawImageCustom(self, source):
        raise NotImplementedError


class NaivePrinter(Printer):

    def genGif(self, outfile):
        self.settings['gif_out'] = outfile
        self.gif_frames = []
        self.drawImage(self.source)
        if self.gif_frames:
            self.gif_frames[0].save(
                self.settings.get('gif_out'), format='GIF', append_images=self.gif_frames[1:],
                save_all=True, duration=30, loop=0)
        self.settings['gif_out'] = None

    def drawImageCustom(self, source, small=True):
        new_steps = []

        for x, y in self.smartTraverse(source):
            next_steps = self.markStamp(x, y, source)
            new_steps += next_steps
            if next_steps:
                if self.settings.get('gif_out'):
                    if len(new_steps) % 6 == 0:
                        self.gif_frames.append(self.markedImage())
        return new_steps


def genPixelsNearPoint(cx, cy, max_radius=440):
    radius = 1
    (x, y) = (1, 0)
    yield (cx, cy)
    yield (cx + x, cy + y)

    # def isValid(val):
    #     x, y = val
    #     if x <= 0 or y <= 0:
    #         return False
    #     return True

    while radius < max_radius:
        for i in range(radius):
            (x, y) = (x - 1, y - 1)
            val = (cx + x, cy + y)
            yield val
        for i in range(radius):
            (x, y) = (x - 1, y + 1)
            val = (cx + x, cy + y)
            yield val
        for i in range(radius):
            (x, y) = (x + 1, y + 1)
            val = (cx + x, cy + y)
            yield val
        for i in range(radius):
            (x, y) = (x + 1, y - 1)
            val = (cx + x, cy + y)
            yield val
        radius += 1
        x += 1
    # print("Exhaused radius", radius)


def genPixelsNearPointSquare(cx, cy, max_radius=440):
    radius = 1
    # (x, y) = (0, 0)
    yield(cx, cy)
    while radius < max_radius:
        # TODO: sometimes yields duplicates
        # print(radius)
        for length in range(-radius, radius + 1):
            for side in [-radius, radius]:
                yield (cx + side, cy + length)  # left and right edges
                yield (cx + length, cy + side)  # top and bottom edges
        radius += 1
        # x += 1
    # print("Exhaused radius", radius)


# g = genPixelsNearPoint(0, 0)
# print([next(g) for i in range(20)])
# g = genPixelsNearPointSquare(0, 0)
# print([next(g) for i in range(20)])

# image_canvas = Image.new("RGB", (100, 100))
# pixels = image_canvas.load()
# g = genPixelsNearPoint(50, 50)
# for i in range(255):
#     x, y = next(g)
#     pixels[x, y] = (i, i, 255)
# image_canvas.save("gentest.png")
# # return
# os.exit()
# image_canvas = Image.new("RGB", (100, 100))
# pixels = image_canvas.load()
# g = genPixelsNearPointSquare(50, 50)
# for i in range(255):
#     x, y = next(g)
#     pixels[x, y] = (i, i, 255)
# image_canvas.save("gentest.png")

def visualizeFootprint(x, y, source, stamp, target_color=True):
    print("VISUALIZING", stamp, "at", (x, y))
    chunk = source.rel_stamp_footprint(stamp, x, y)
    margin = 6
    xrange = range(
        max([min(x for (x, y) in chunk) - margin, 0]),
        min([max(x for (x, y) in chunk)+1+margin, source.w])
    )
    yrange = range(
        max([min(y for (x, y) in chunk) - margin, 0]),
        min([max(y for (x, y) in chunk)+1+margin, source.h])
    )

    def reprSquare(x, y):
        if source.canvas[x][y]:
            # Old was set
            if (x, y) in chunk:
                if target_color is True:
                    return 'x'  # Brush will leave set
                else:
                    return 'O'  # Brush will erase
            else:
                return '.'  # Unchanged set

        else:
            # Old was empty
            if (x, y) in chunk:
                if target_color is True:
                    return 'X'  # Brush will set
                else:
                    return 'o'  # Brush will leave empty
            else:
                return ' '  # Unchanged empty

    for x in xrange:
        for y in yrange:
            print(reprSquare(x, y), end='')
        print("|")
    # os.abort()


class ConnectedPrinter(NaivePrinter):

    @classmethod
    def defaultSettings(cls):
        return {
            **super().defaultSettings(),
            **{
                "threshhold": 0.9,
                "keepGoingExtent": 1,
                "nearalgo": genPixelsNearPointSquare,
                "nearbyRadius": 50,
                "untilExhaustedMax": 6,
                "stamps": [Size.SMALL]
            }
        }

    def tryKeepGoing(self):
        # Generate a few points in the same direction we were already going, for compression
        keepGoingRange = range(self.settings['keepGoingExtent'])
        yield from {
            Step.HAT_UP:         [(self.x, self.y+i) for i in keepGoingRange],
            Step.HAT_RIGHT:      [(self.x+i, self.y) for i in keepGoingRange],
            Step.HAT_DOWN:       [(self.x-i, self.y) for i in keepGoingRange],
            Step.HAT_LEFT:       [(self.x, self.y-i) for i in keepGoingRange],
            Step.HAT_UP_RIGHT:   [(self.x+i, self.y+i) for i in keepGoingRange],
            Step.HAT_DOWN_RIGHT: [(self.x+i, self.y-i) for i in keepGoingRange],
            Step.HAT_DOWN_LEFT:  [(self.x-i, self.y-i) for i in keepGoingRange],
            Step.HAT_UP_LEFT:    [(self.x-i, self.y+i) for i in keepGoingRange]
        }.get(self.last_movement, [])

    def closestTodoPixel(self, source, stamp=Size.SMALL, anywhere=False):
        if source.canvas == self.sim.canvas:
            return (None, None)
        for (x, y) in itertools.chain(
            self.tryKeepGoing(),
            self.settings['nearalgo'](self.x, self.y,
                max_radius=440 if anywhere else self.settings['nearbyRadius'])
        ):
            # if (x, y) in self.tryKeepGoing():
                # print("Kept going!", self.last_movement, self.x, self.y, x, y)
            if not (x in range(source.w) and y in range(source.h)):
                continue
            try:
                chunk = self.sim.rel_stamp_footprint(stamp, x, y)
                any_changes, correct_change_count, target_color = self.shouldStamp(x, y, source, stamp)
                if any_changes and (correct_change_count > self.settings['threshhold'] * len(chunk)):
                    # print(f"{(x, y, any_changes, correct_change_count, self.settings['threshhold'] * len(chunk), target_color)=}")
                    # visualizeFootprint(x, y, self.sim, stamp, target_color=target_color)
                    return (x, y)
            except IndexError:
                print("Out of bounds?", x, y)
                print(f"{len(self.sim.canvas)=} {len(source.canvas)=}")
                print(f"{len(self.sim.canvas[x])=} {len(source.canvas[x])=}")
                raise
        return (None, None)

    def drawImageCustom(self, source, small=False):
        new_steps = []

        stamps = [Size.SMALL] if small else self.settings["stamps"]

        # Find a todo pixel
        # Mark todo pixel
        # Find nearest todo pixel
        # print(self.sim.canvas, source)
        for stamp in stamps:
            # last_coords = []
            # print("Drawing connected spots with", stamp)
            untilExhausted = self.settings['untilExhaustedMax']
            while untilExhausted > 0:  # use TypeError to break
                (x, y) = self.closestTodoPixel(source, stamp=stamp)
                # last_coords = last_coords[:20] + [(x, y)]
                if (x, y) == (None, None):
                    # print("Stamp exhausted", stamp)
                    # print(last_coords)
                    untilExhausted -= 1
                    # Try to find another shape somewhere
                    (x, y) = self.closestTodoPixel(source, stamp=stamp, anywhere=True)
                    # last_coords = last_coords[:20] + [(x, y)]
                    if (x, y) == (None, None):
                        untilExhausted = 0
                        break
                    # else:
                    #     print(f"Exhausted radius from {(self.x, self.y)} but found new todo at {(x, y)}")
                # print("Stamping", x, y, stamp)
                new_steps += self.markStamp(x, y, source, stamp=stamp)
                if self.settings.get('gif_out'):
                    if stamp != Size.SMALL or len(new_steps) % 6 == 0:
                        self.gif_frames.append(self.markedImage())

        new_steps += super().drawImageCustom(source, small=True)
        return new_steps


class ConnectedPrinter2(ConnectedPrinter):

    def drawImageCustom(self, source):
        new_steps = []

        # print("Brush", stamp)
        untilExhausted = self.settings['untilExhaustedMax']
        while untilExhausted > 0:  # use TypeError to break
            for stamp in self.settings["stamps"]:
                (x, y) = self.closestTodoPixel(source, stamp=stamp)
                if (x, y) == (None, None):
                    untilExhausted -= 1
                    (x, y) = self.closestTodoPixel(source, stamp=stamp, anywhere=True)
                    if (x, y) == (None, None):
                        # untilExhausted = 0
                        # break
                        continue

                new_steps += self.markStamp(x, y, source, stamp=stamp)
                if self.settings.get('gif_out'):
                    if stamp != Size.SMALL or len(new_steps) % 6 == 0:
                        self.gif_frames.append(self.markedImage())

        new_steps += super().drawImageCustom(source, small=True)
        return new_steps

# TODO printer that does a naive smartTraverse but adjusts its stamp size each pixel and checks threshhold


class MultiBrushPrinter(NaivePrinter):

    @classmethod
    def defaultSettings(cls):
        return {
            **super().defaultSettings(),
            **{
                "threshhold": 0.9,
                "min_increment": (4, 3),
                "stamps": [Size.LARGE, Size.MED, Size.SMALL]
            }
        }

    def drawImageCustom(self, source, small=True):
        assert small
        new_steps = []

        for x, y in self.smartTraverse(source, min_increment=self.settings['min_increment']):  # filter(isOffset, ):
            # print(x, y)
            for stamp in self.settings['stamps']:
                chunk = self.sim.rel_stamp_footprint(stamp, x, y)
                any_changes, correct_change_count, target_color = self.shouldStamp(x, y, source, stamp)

                if any_changes and correct_change_count > self.settings['threshhold'] * len(chunk):
                    new_steps += self.markStamp(x, y, source, stamp=stamp)
                    if self.settings.get('gif_out'):
                        self.gif_frames.append(self.markedImage())

        new_steps += super().drawImageCustom(source, small=True)

        return new_steps


class InkErasePrinter(ConnectedPrinter):

    def drawImageCustom(self, source, small=False):
        new_steps = []

        stamps = [Size.SMALL] if small else self.settings["stamps"]

        # Find a todo pixel
        # Mark todo pixel
        # Find nearest todo pixel
        # print(self.sim.canvas, source)
        for should_ink_fn in [lambda c: c is True, lambda c: True]:
            for stamp in stamps:
                # last_coords = []
                # print("Drawing connected spots with", stamp)
                untilExhausted = self.settings['untilExhaustedMax']
                while untilExhausted > 0:  # use TypeError to break
                    (x, y) = self.closestTodoPixel(source, stamp=stamp)
                    # last_coords = last_coords[:20] + [(x, y)]
                    if (x, y) == (None, None):
                        # print("Stamp exhausted", stamp)
                        # print(last_coords)
                        untilExhausted -= 1
                        # Try to find another shape somewhere
                        (x, y) = self.closestTodoPixel(source, stamp=stamp, anywhere=True)
                        # last_coords = last_coords[:20] + [(x, y)]
                        if (x, y) == (None, None):
                            untilExhausted = 0
                            break
                        # else:
                        #     print(f"Exhausted radius from {(self.x, self.y)} but found new todo at {(x, y)}")
                    # print("Stamping", x, y, stamp)

                    any_changes, correct_change_count, target_color = self.shouldStamp(x, y, source, stamp)
                    if should_ink_fn(target_color):
                        new_steps += self.markStamp(x, y, source, stamp=stamp)
                        if self.settings.get('gif_out'):
                            if stamp != Size.SMALL or len(new_steps) % 6 == 0:
                                self.gif_frames.append(self.markedImage())

        new_steps += super().drawImageCustom(source, small=True)
        return new_steps

class SizeLayerPrinter(NaivePrinter):

    @classmethod
    def defaultSettings(cls):
        return {
            **super().defaultSettings(),
            **{
                "threshhold": 0.4,
                "min_increment_override": None,
                "stamps": [Size.SMALL],
            }
        }

    def drawImageCustom(self, source, small=True):
        assert small
        new_steps = []

        for i, (stamp, min_increment) in enumerate([
            (Size.LARGE, (7, 7)),
            (Size.MED, (4, 3)),
            # (Size.SMALL, (1,1))
        ]):
            if stamp not in self.settings["stamps"]:
                continue
            if self.settings["min_increment_override"]:
                min_increment = self.settings["min_increment_override"]
            for x, y in self.smartTraverse(source, min_increment=min_increment):  # filter(isOffset, ):
                # print(x, y)
                chunk = self.sim.rel_stamp_footprint(stamp, x, y)
                marks = [
                    (x2, y2) for (x2, y2) in chunk
                    if source.canvas[x2][y2] != self.sim.canvas[x2][y2]
                ]
                if len(marks) > self.settings['threshhold'] * len(chunk):
                    # print("Stamping", len(marks), threshhold, len(chunk))
                    new_steps += self.markStamp(x, y, source, stamp=stamp)
                    if self.settings.get('gif_out'):
                        self.gif_frames.append(self.markedImage())

        new_steps += super().drawImageCustom(source, small=True)

        return new_steps

# class MultiBrushPrinterL(MultiBrushPrinter, SizeLayerPrinter):
#     pass

class MultiBrushPrinterC(MultiBrushPrinter, ConnectedPrinter):
    pass

class SizeLayerPrinterC(SizeLayerPrinter, ConnectedPrinter):
    pass


def add_bool_arg(parser, name, default=True, help=None):
    group = parser.add_mutually_exclusive_group(required=False)
    group.add_argument('--' + name, dest=name.replace("-", "_"), action='store_true', help=help + f" (Default: {default})")
    group.add_argument('--no-' + name, dest=name.replace("-", "_"), action='store_false', help=help + f" (Default: {default})")
    parser.set_defaults(**{name: default})


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
add_bool_arg(parser, "gen", default=True, help="Perform any calculation logic (false w/ --make to just make)")
add_bool_arg(parser, "bogo", default=True, help="Find fastest solution")
add_bool_arg(parser, "gif", default=True, help="Render gif of process")
add_bool_arg(parser, "savesteps", default=True, help="Save output c file")
add_bool_arg(parser, "make", default=False, help="Automatically run make after completion")
args = parser.parse_args()

infile_image = Image.open(args.infile).convert('L')

w, h = infile_image.size
pattern = Splat3Canvas(w, h).fromPattern(infile_image)


all_printer_permutations = [
    ([NaivePrinter], [
        (binstr,
            {
                "horizontal": (binstr[0] == "1"), "vertical": (binstr[0] != "1"), # Horizontal?
            },
         )
        for binstr in ["".join(seq) for seq in product("01", repeat=1)]
    ]),
    ([ConnectedPrinter], [ #, ConnectedPrinter2], [
        (binstr,
            {
                "threshhold": (0.8 if binstr[0] == "1" else 0.51), # HighThreshhold?
                # "nearalgo": (genPixelsNearPoint if binstr[1] == "1" else genPixelsNearPointSquare), # Diamond?
                "keepGoingExtent": (1 if binstr[1] == "1" else 0), # KeepGoing?
                "nearbyRadius": (30 if binstr[2] == "1" else 440), # Smaller radius?
                # "untilExhaustedMax": (20 if binstr[3] == "1" else 5), # Smaller radius?
                # MedOnly?
                "stamps": ([Size.MED, Size.SMALL] if binstr[3] == "1" else [Size.LARGE, Size.MED, Size.SMALL])
            },
         )
        for binstr in ["".join(seq) for seq in product("01", repeat=4)]
    ]),
    ([InkErasePrinter], [
        (binstr,
            {
                # "horizontal": (binstr[0] == "1"), "vertical": (binstr[0] != "1"), # Horizontal?
                # "threshhold": (0.8 if binstr[1] == "1" else 0.51), # HighThreshhold?
                # # "nearalgo": (genPixelsNearPoint if binstr[2] == "1" else genPixelsNearPointSquare), # DiamondAlgo?
                # # "min_increment": ((2, 2) if binstr[3] == "1" else (7, 7)), # SmallMinIncrement?
                # # MedOnly?
                # "stamps": ([Size.MED, Size.SMALL] if binstr[2] == "1" else [Size.LARGE, Size.MED, Size.SMALL])
            },
         )
        for binstr in ["0"]  # ["".join(seq) for seq in product("01", repeat=3)]
    ]),
    ([SizeLayerPrinterC], [
        (binstr,
            {
                "horizontal": (binstr[0] == "1"), "vertical": (binstr[0] != "1"), # Horizontal?
                "threshhold": (0.8 if binstr[1] == "1" else 0.51), # HighThreshhold?
                # "nearbyRadius": (30 if binstr[2] == "1" else 440), # Smaller radius?
                # "min_increment_override": ((2, 2) if binstr[2] == "1" else None), # SmallMinIncrement?
                # MedOnly?
                "stamps": ([Size.MED, Size.SMALL] if binstr[2] == "1" else [Size.LARGE, Size.MED, Size.SMALL])
            },
         )
        for binstr in ["".join(seq) for seq in product("01", repeat=3)]
    ]),
    ([MultiBrushPrinterC], [
        (binstr,
            {
                "horizontal": (binstr[0] == "1"), "vertical": (binstr[0] != "1"), # Horizontal?
                "threshhold": (0.8 if binstr[1] == "1" else 0.51), # HighThreshhold?
                # "nearalgo": (genPixelsNearPoint if binstr[2] == "1" else genPixelsNearPointSquare), # DiamondAlgo?
                # "min_increment": ((2, 2) if binstr[3] == "1" else (7, 7)), # SmallMinIncrement?
                # MedOnly?
                "stamps": ([Size.MED, Size.SMALL] if binstr[2] == "1" else [Size.LARGE, Size.MED, Size.SMALL])
            },
         )
        for binstr in ["".join(seq) for seq in product("01", repeat=3)]
    ]),
]

if args.gen:
    if args.bogo:
        results = {}

        def generateResult(Printer_, settings_binstr, settings):
            # for settings_binstr, settings in settings_permutations:
            printer = Printer_(pattern, settings=settings)
            try:
                steps = printer.toSteps()
                compressed = [*compressSteps(steps)]
                print(
                    f"{Printer_} ({settings_binstr}) printed pattern in {len(steps)}/{len(compressed)} steps "
                    f"({(100*len(compressed)/MAX_COMPRESSED_SIZE if MAX_COMPRESSED_SIZE else 0):.2f}%) "
                    f"(~{fmtTime(len(steps) * TIME_PER_STEP)} runtime)")

                results[Printer_][settings_binstr] = {
                    "printer": printer,
                    "steps": steps,
                    "compressed": compressed
                }

            except Exception:
                print(f"{Printer_} ({settings_binstr} {settings}) failed!")

                traceback.print_exc()

        try:
            for (Printers_, settings_permutations) in all_printer_permutations:
                for Printer_ in Printers_:
                    results[Printer_] = {}
                do_work_helper(generateResult, [
                    (Printer_, settings_binstr, settings)
                    for Printer_, (settings_binstr, settings)
                    in itertools.product(Printers_, settings_permutations)
                ])
                # for Printer_, (settings_binstr, settings) in itertools.product(Printers_, settings_permutations):
                #     generateResult(Printer_, settings_binstr, settings)
        except KeyboardInterrupt:
            pass # continue with results collected

        pprint.pprint({
            name: {
                binstr: (
                    len(results[name][binstr]['steps']),
                    len(results[name][binstr]['compressed'])
                )
                for binstr in results[name]
            }
            for name in results
        })

        # Get best
        best_printer = None
        best_metric = None
        best_steps = None
        best_settings_binstr = None
        best_compressed = None
        for cls in results:
            for settings_binstr in results[cls]:
                len_compressed = len(results[cls][settings_binstr]['compressed'])
                if MAX_COMPRESSED_SIZE and len_compressed > MAX_COMPRESSED_SIZE:
                    continue

                metric = len(results[cls][settings_binstr]['steps'])
                if (not best_metric) or metric < best_metric:
                    best_metric = metric
                    best_settings_binstr = settings_binstr
                    best_printer = results[cls][settings_binstr]['printer']
                    best_steps = results[cls][settings_binstr]['steps']
                    best_compressed = len_compressed

        # Save output
        print(best_printer)
        print(best_printer.settings)
        print(
            f"{best_printer} ({best_settings_binstr}) printed pattern in {len(best_steps)} steps")

        if args.savesteps:
            saveSteps(best_steps)
        if args.gif:
            gifname = f"{best_printer.__class__.__name__} {best_settings_binstr}.gif"
            print("Writing", gifname)
            best_printer.copy().genGif(gifname)
            print("Done.")

    else:
        best_printer = ConnectedPrinter(
            pattern,
            {
                "threshhold": 0.8, # HighThreshhold?
                # "nearalgo": (genPixelsNearPoint if binstr[1] == "1" else genPixelsNearPointSquare), # Diamond?
                "keepGoingExtent": 0, # KeepGoing?
                "nearbyRadius": 440, # Smaller radius?
                # "untilExhaustedMax": (20 if binstr[3] == "1" else 5), # Smaller radius?
                # MedOnly?
                "stamps": [Size.LARGE, Size.MED, Size.SMALL]
            }
        )
        # best_printer = InkErasePrinter(pattern)
        print(f"Using default {best_printer}")
        best_steps = best_printer.toSteps()

        print(f"{best_printer} (default) printed pattern in {len(best_steps)} steps ")

        if args.savesteps:
            saveSteps(best_steps)
        if args.gif:
            gifname = f"{best_printer.__class__.__name__} Default.gif"
            print("Writing", gifname)
            best_printer.copy().genGif(gifname)
            print("Done.")

if args.make:
    if subprocess.run(["make"]):
        proc = ["../teensy_loader_cli", "--mcu", TEENSY_MCU, "-w", JOYSTICK_HEX]
        print(proc)
        print(f"Waiting for {TEENSY_MCU}...")
        subprocess.run(proc)
