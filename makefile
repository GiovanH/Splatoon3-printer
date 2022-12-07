#
#             LUFA Library
#     Copyright (C) Dean Camera, 2014.
#
#  dean [at] fourwalledcubicle [dot] com
#           www.lufa-lib.org
#
# --------------------------------------
#         LUFA Project Makefile.
# --------------------------------------

# Run "make help" for target help.

# Set the MCU accordingly to your device (e.g. at90usb1286 for a Teensy 2.0++, or atmega16u2 for an Arduino UNO R3)
MCU          = at90usb1286
ARCH         = AVR8
F_CPU        = 16000000
F_USB        = $(F_CPU)
OPTIMIZATION = s
TARGET       = Joystick
MYSRC 		 = nextreport.c $(TARGET).c Descriptors.c
SRC          = $(MYSRC) $(LUFA_SRC_USB)
TESTSRC		 = nextreport.c test.c
LUFA_PATH    = ../LUFA/LUFA
CC_FLAGS     = -Wall -DUSE_LUFA_CONFIG_HEADER -IConfig/
LD_FLAGS     =

# Default target
all: $(TARGET).hex test

nextreport.o: steps.o

test: $(subst .c,.o,$(TESTSRC))
	$(CXX) $(LDFLAGS) -o test.exe $(subst .c,.o,$(TESTSRC)) $(LDLIBS) 

test2: test2.o
	$(CXX) $(LDFLAGS) -o test2.exe test2.o

%.o: %.c 
	$(CXX) $(CFLAGS) $(CPPFLAGS) -c $<

# Include LUFA build script makefiles
include $(LUFA_PATH)/Build/lufa_core.mk
include $(LUFA_PATH)/Build/lufa_sources.mk
include $(LUFA_PATH)/Build/lufa_build.mk
include $(LUFA_PATH)/Build/lufa_cppcheck.mk
include $(LUFA_PATH)/Build/lufa_doxygen.mk
include $(LUFA_PATH)/Build/lufa_dfu.mk
include $(LUFA_PATH)/Build/lufa_hid.mk
include $(LUFA_PATH)/Build/lufa_avrdude.mk
include $(LUFA_PATH)/Build/lufa_atprogram.mk

# Target for LED/buzzer to alert when print is done
with-alert: all
with-alert: CC_FLAGS += -DALERT_WHEN_DONE

Joystick.hex: $(SRC)

install: $(TARGET).hex
	../teensy_loader_cli --mcu $(MCU) -w $(TARGET).hex

clean:  
	rm -v test.exe test2.exe test.exe.stackdump test2.exe.stackdump steps.o $(subst .c,.o,$(TESTSRC)) $(subst .c,.o,$(MYSRC)) $(TARGET).bin $(TARGET).lss $(TARGET).sym $(TARGET).eep $(TARGET).hex $(TARGET).map $(TARGET).elf