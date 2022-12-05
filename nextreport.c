#include "types.h"
#include <string.h> // For memcpy

// How many times does the report still need to repeat for the console
// to register it? Used by sys_echoes_remaining
#define SYS_ECHOES 12 // 12 = 30 FPS
// How many frames do we need to release for entirely before doing anything else?
// Used by need_blank
#define BLANK_ECHOES 16 // 12 = 30 FPS

#define STEP_BLOCK_SIZE 2 // ints per step in the data structure

#define PRE 1 // include controller sync steps?
#define WRAPAROUND 0

static int sys_echoes_remaining;
// How many more times do we want to simulate the last report? (Read from input)
static int echoes_remaining;
static uint8_t need_blank;

// Where are we in the step array?
static int stepIndex;
// How big is it?
static int arrayMax;

void initReport(int array_max) {
	sys_echoes_remaining = 0;
	echoes_remaining = 0;
	need_blank = 0;
	stepIndex = -1;

	arrayMax = array_max;
	return;
}

static USB_JoystickReport_t last_report;

USB_JoystickReport_t BLANK_REPORT = {
	0,  // 16 buttons; see JoystickButtons_t for bit mapping
	HAT_CENTER,  // HAT switch; one nibble w/ unused nibble
	STICK_CENTER,  // Left  Stick X
	STICK_CENTER,  // Left  Stick Y
	STICK_CENTER,  // Right Stick X
	STICK_CENTER,  // Right Stick Y
	4,  // Vendor Specification
};

//I know, it's icky.
#include "steps.c"

uint8_t prestep[] = {
    0, 4,  //Wait
    SWITCH_L | SWITCH_R, 1, //Triggers
    0, 2,
 	SWITCH_A, 1,
 0 };


static uint8_t* reportArray = NULL;

uint8_t pseudoBH;
uint16_t bData;
uint8_t hData;
uint8_t repData;

//#include <stdio.h> // Just for debugging.

// Prepare the next report for the host.
void GetNextReport(USB_JoystickReport_t* const ReportData) {
	if (reportArray == NULL) {
		#if PRE==1
			reportArray = prestep;
			initReport(4);
			// static int arrayMax = 4;
		#else
			reportArray = step;
			initReport(numsteps - 1);
		#endif
	}

	if (sys_echoes_remaining > 0) {
		// Echo last for polling purposes
		sys_echoes_remaining -= 1;
		memcpy(ReportData, &last_report, sizeof(USB_JoystickReport_t));
		return;
	}

	if (need_blank) {
		// Send blank step
		need_blank -= 1;
		memcpy(ReportData, &BLANK_REPORT, sizeof(USB_JoystickReport_t));
		return;
	}

	if (echoes_remaining > 0) {
		// Echo last planned button press as a repeated input
		memcpy(ReportData, &last_report, sizeof(USB_JoystickReport_t));
		echoes_remaining -= 1;
		sys_echoes_remaining = SYS_ECHOES;
		need_blank = BLANK_ECHOES;  // Blank for 1 button after this
		return;
	}

	// Do next step
	// ReportData->VendorSpec = 4;
	memcpy(ReportData, &BLANK_REPORT, sizeof(USB_JoystickReport_t));
	stepIndex += 1;
	// Wraparound
	if (stepIndex > arrayMax)
	{
		if (reportArray == prestep) {
			// If we're still in the prestep, just switch to the main report array.
			reportArray = step;
			initReport(numsteps - 1);
			return;
		} else if (WRAPAROUND) {
			// Otherwise, if wraparound is set, go back to step #1 of the main report array.
			stepIndex = 0;
		} else {
			// Otherwise just capture and hold.
			// Return blank report
			ReportData->Button = SWITCH_CAPTURE;
			ReportData->VendorSpec = 88;
			// Avoid overflow
			stepIndex = arrayMax + 1;
			return;
		}
	}

	// Send next report
	if (reportArray == prestep) {
		bData = prestep[(STEP_BLOCK_SIZE*stepIndex)+0]; // Full range of button options for prestep
		repData = prestep[(STEP_BLOCK_SIZE*stepIndex)+1];
		hData = 0x08;

	} else {
		pseudoBH = reportArray[(STEP_BLOCK_SIZE*stepIndex)+0];
		bData = (pseudoBH & 0xf0) >> 4;
		hData = (pseudoBH & 0x0f);

		repData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+1];

		if (bData == 0x08) { // Translate X to Lclick
			bData = SWITCH_LCLICK;
		} else if (bData == 0x06) { // Translate A+B to L
			bData = SWITCH_L;
		} else if (bData == 0x07) { // Translate A+B+Y to R
			bData = SWITCH_R;
		}
	}

	ReportData->HAT = hData;
	ReportData->Button = bData;

	echoes_remaining = repData-1;
	sys_echoes_remaining = SYS_ECHOES;

	// Copy the ReportData to last_report
	memcpy(&last_report, ReportData, sizeof(USB_JoystickReport_t));

	need_blank = BLANK_ECHOES;  // Blank for many frames after this to simulate cleanly releasing the button.
	return;
}