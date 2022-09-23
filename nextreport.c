#include "types.h"
#include <string.h> // For memcpy

#define ECHOES 12 // 12 = 30 FPS
#define BLANK_ECHOES 12 // 12 = 30 FPS
#define STEP_BLOCK_SIZE 2 // ints per step

#define PRE 1
#define WRAPAROUND 0

static int sys_echoes_remaining = 0;
static int echoes_remaining = 0;
static uint8_t need_blank = 0;
static int stepIndex = -1;

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

typedef enum {
	SYNC_CONTROLLER,
	SYNC_POSITION,
	BREATHE,
	PROCESS,
	CLEANUP,
	DONE
} State_t;
State_t state = SYNC_CONTROLLER;

//I know, it's icky.
#include "steps.c"

uint8_t prestep[] = {
    0, 4,  //Wait
    SWITCH_L, 1, //Triggers
    SWITCH_L | SWITCH_R, 3, //Triggers
    0, 2,
 	SWITCH_A, 1,
 0 };

static uint8_t* reportArray = prestep;
#if PRE==1
	static int arrayMax = 5;
#else
	static int arrayMax = 0;
#endif

uint8_t pseudoBH;
uint16_t bData;
uint8_t hData;
uint8_t repData;

//#include <stdio.h> // Just for debugging.

// Prepare the next report for the host.
void GetNextReport(USB_JoystickReport_t* const ReportData) {

	if (sys_echoes_remaining > 0) {
		// Echo last for polling purposes
		sys_echoes_remaining -= 1;
		memcpy(ReportData, &last_report, sizeof(USB_JoystickReport_t));
		// ReportData->VendorSpec = 0;
		return;
	} else {
		if (need_blank) {
			// Send blank step
			need_blank -= 1;
			memcpy(ReportData, &BLANK_REPORT, sizeof(USB_JoystickReport_t));
			ReportData->VendorSpec = 3;
			return;
		} else
		if (echoes_remaining > 0) {
			// Echo last planned button press as a repeated input
			// ReportData->VendorSpec = 2;
			memcpy(ReportData, &last_report, sizeof(USB_JoystickReport_t));
			echoes_remaining -= 1;
			sys_echoes_remaining = ECHOES;
			need_blank = BLANK_ECHOES;  // Blank for 1 button after this
			return;
		} else {
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
					arrayMax = (numsteps - 1);
					stepIndex = 0;
					// ReportData->VendorSpec = 10;
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
			// ReportData->VendorSpec = 5;


			if (reportArray == prestep) {
				bData = prestep[(STEP_BLOCK_SIZE*stepIndex)+0];
				repData = prestep[(STEP_BLOCK_SIZE*stepIndex)+1];
				hData = 0x08;
				// ReportData->VendorSpec = 30 + stepIndex;

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

			// Copy the ReportData to last_report
			memcpy(&last_report, ReportData, sizeof(USB_JoystickReport_t));

			echoes_remaining = repData-1;
			sys_echoes_remaining = ECHOES;

			// ReportData->VendorSpec = 5;

			need_blank = BLANK_ECHOES;  // Blank for 1 button after this
		}
	}
}