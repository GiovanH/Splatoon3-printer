# SysRepeater

A LUFA program for repeating arbitrary controller sequences. Inspired by the splatoon 2 printing apps and others. 



This is designed to be used with `sys-joymon`.



## Documentation

Once compiled and uploaded to a chip, controller events will begin firing as soon as the chip is connected to a system via USB.



The series of instructions goes like this:

```
prestep 1
prestep 2
...
prestep N
step 0
step 1
...
step M
step 0
step 1
...
step M
step 0
```

or

```
presteps()
forever(){
    steps()
}
```



Presteps are *not* part of steps.c, rather they are included in nextreport.c as selectable preprocessor instructions.



### steps.c format

Programs must have data compiled in; there is no simple way to read data from file. Thus, the series of steps must be compiled into the executable. The data format used is specifically designed to compress efficiently enough to fit onto the Teensy 2.0.

Each step can be thought of as a `joystickreport` struct, as such:

```
typedef struct {
	uint16_t Button; // 16 buttons; see JoystickButtons_t for bit mapping
	uint8_t  HAT;    // HAT switch; one nibble w/ unused nibble
	uint8_t  LX;     // Left  Stick X
	uint8_t  LY;     // Left  Stick Y
	uint8_t  RX;     // Right Stick X
	uint8_t  RY;     // Right Stick Y
	uint8_t  VendorSpec;
} USB_JoystickReport_t;
```

*However,* in order to optimize cross-compatibility, this is saved in the form of a 5-tuple of `uint16`s. The following is a valid steps.c file:

```uint16_t step[] = {
uint16_t step[] = {
    1024, 32896, 32896, 8, 26,  //Step 1
    0, 37885, 32896, 8, 0,      //Step 2
    0, 34777, 32896, 8, 0,      //Step 3
    0, 32896, 32896, 8, 11, 
    4, 32896, 32896, 8, 3,
    0, 32896, 32896, 8, 28,
0 } // Extra data ignored
static int numsteps = 6 // One-indexed.
```

The data stored, respectively, is

1. `Button`: A 16-bit uint that acts as a binary flag, selecting a combination of 16 buttons.
2. `lData`: Data for the left joystick. The 16-bit unsigned integer is actually storage for two 8-bit unsigned integers, prepended together, representing the X and Y axis. 
3. `rData`: See 2. 
4. `hData`: Two 8-bit uints, as with 2 and 3. The lower portion represents the HAT, while the upper portion represents the VendorSpec data.
5. `Repeats`: Each step, even if repeats is 0, is sent at least once. If repeats is greater than 0, the step is repeated before moving on. A step with 31 repeats, for instance, will be sent 32 times. (This does not include the echoes, used to timescale the data.)

See nextreport.c for full implementation. 