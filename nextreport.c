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
	8,  // HAT switch; one nibble w/ unused nibble
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
    0, 8, 4,  //Wait
    20, 8, 1, //Triggers
    30, 8, 4, //Triggers
    0, 8, 4, 
    // 4, 8, 4,  //Continue
    // 0, 8, 4, 
 4, 8, 1,
 0 };

static uint8_t* reportArray = prestep;
#if PRE==1
	static int arrayMax = 5;
#else
	static int arrayMax = 0;
#endif

uint8_t pseudoBH;
uint8_t bData;
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
			// Echo last as a repeated input
			echoes_remaining -= 1;
			memcpy(ReportData, &last_report, sizeof(USB_JoystickReport_t));
			// ReportData->VendorSpec = 1;
			sys_echoes_remaining = ECHOES;
			need_blank = BLANK_ECHOES;  // Blank for 1 button after this
			return;
		} else {
			memcpy(ReportData, &BLANK_REPORT, sizeof(USB_JoystickReport_t));
			// ReportData->VendorSpec = 2;
			// Do next step
			stepIndex += 1;
			// Wraparound
			if (stepIndex > arrayMax)
			{
				if (reportArray == prestep) {
					// If we're still in the prestep, just switch to the main report array.
					reportArray = step;
					arrayMax = (numsteps - 1);
					stepIndex = 0;
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

			// uint8_t bData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+0];
			// uint8_t hData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+1];

			pseudoBH = reportArray[(STEP_BLOCK_SIZE*stepIndex)+0];
			bData = pseudoBH && 0x0f;
			hData = pseudoBH && 0xf0;

			// uint8_t repData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+2];
			repData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+1];

			ReportData->HAT = hData;
			if (bData == 0x08) { // Translate X to Lclick
				ReportData->Button = 0x400;
			} else if (bData == 0x06) { // Translate A+B to L
				ReportData->Button = 0x10;
			} else if (bData == 0x07) { // Translate A+B+Y to R
				ReportData->Button = 0x20;
			} else {
				ReportData->Button = bData;
			}
			// ReportData->VendorSpec = 2;

			// Copy the ReportData to last_report
			memcpy(&last_report, ReportData, sizeof(USB_JoystickReport_t));

			echoes_remaining = repData-1;
			sys_echoes_remaining = ECHOES;

			// ReportData->VendorSpec = 5;

			need_blank = BLANK_ECHOES;  // Blank for 1 button after this
		}
	}
}