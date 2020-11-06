import argparse
import subprocess

TEENSY_MCU = "AT90USB1286"
JOYSTICK_HEX = "Joystick.hex"


def add_bool_arg(parser, name, default=True, help=None):
    group = parser.add_mutually_exclusive_group(required=False)
    group.add_argument('--' + name, dest=name.replace("-", "_"), action='store_true', help=help + f" (Default: {default})")
    group.add_argument('--no-' + name, dest=name.replace("-", "_"), action='store_false', help=help + f" (Default: {default})")
    parser.set_defaults(**{name: default})


# Main
parser = argparse.ArgumentParser()
add_bool_arg(parser, "gen", default=True, help="Generate steps file")
add_bool_arg(parser, "make", default=False, help="Automatically run make after completion")
args = parser.parse_args()


if args.gen:
    with open("steps.c", "w") as fp:
        fp.write("""#define WRAPAROUND 1
#define PRE 0
#include "types.h"
uint8_t step[] = {
    6, 8, 1, // A&B x 1
    0, 8, 1, // NONE x 1
 0 };
static int numsteps = 2;
""")

if args.make:
    if subprocess.run(["make"]):
        print(f"Waiting for {TEENSY_MCU}...")
        subprocess.run(["../teensy_loader_cli", "--mcu", TEENSY_MCU, "-w", JOYSTICK_HEX])
