#include "types.h"
#include <string.h> // For memcpy

#define ECHOES 12 // 30 FPS
#define BLANK_ECHOES 12 // 30 FPS
#define STEP_BLOCK_SIZE 3 // ints per step
#define DO_BLANK 1

//#define PRE SPLAT
#define PRE 1
#define WRAPAROUND 0
//0: NONE
//1: SPLAT

static int sys_echoes_remaining = 0;
static int echoes_remaining = 0;
static uint8_t need_blank = 0;
static int stepIndex = -1;


// static int echoes = 0;
// static int stepIndex = 0;

static USB_JoystickReport_t last_report;

// static uint8_t* pseudoL;
// static uint8_t* pseudoR;
// static uint8_t* pseudoH;
// static uint8_t* pseudoB;

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

#if PRE==1
	static uint8_t* reportArray = prestep;
	static int arrayMax = 5;
#else
	static uint8_t* reportArray = prestep;
	static int arrayMax = 0;
#endif

//#include <stdio.h> // Just for debugging.

// Prepare the next report for the host.
void GetNextReport(USB_JoystickReport_t* const ReportData) {

	// printf("[%u] 0x%x {%u, %u, %u, %u} | ",
	// 	stepIndex, reportArray, bData, lData, rData, hData 
	// );

	if (sys_echoes_remaining > 0) {
		// Echo last
		sys_echoes_remaining -= 1;
		memcpy(ReportData, &last_report, sizeof(USB_JoystickReport_t));
		// ReportData->VendorSpec = 0;
		return;
	} else {
		if (need_blank) {
			// Send blank step
			need_blank -= 1;
			memcpy(ReportData, &BLANK_REPORT, sizeof(USB_JoystickReport_t));
			// ReportData->VendorSpec = 3;
			return;
		} else 
		if (echoes_remaining > 0) {
			// Echo last
			echoes_remaining -= 1;
			memcpy(ReportData, &last_report, sizeof(USB_JoystickReport_t));
			// ReportData->VendorSpec = 1;
			sys_echoes_remaining = ECHOES;
			#if DO_BLANK
			need_blank = BLANK_ECHOES;  // Blank for 1 button after this
			#endif
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
					reportArray = step;
					arrayMax = (numsteps - 1);
					stepIndex = 0;
				} else if (WRAPAROUND) {
					stepIndex = 0;
				} else {
					// Overflow without wraparound
					// Return blank report
					ReportData->Button = SWITCH_CAPTURE;
					ReportData->VendorSpec = 88;
					// Avoid overflow
					stepIndex = arrayMax + 1;
					return;
				}
			}

			// Send next report
			uint8_t offset = (STEP_BLOCK_SIZE*stepIndex);
			uint8_t bData = reportArray[offset+0];
			uint8_t hData = reportArray[offset+1];
			uint8_t repData = reportArray[offset+2];

			ReportData->Button = bData;
			ReportData->HAT = hData;
			if (bData == 0xFF) {
				ReportData->Button = 0x400;
			}
			// ReportData->VendorSpec = 2;

			// Copy the ReportData to last_report
			memcpy(&last_report, ReportData, sizeof(USB_JoystickReport_t));

			echoes_remaining = repData-1;
			sys_echoes_remaining = ECHOES;

			// ReportData->VendorSpec = 5;

			#if DO_BLANK
			need_blank = BLANK_ECHOES;  // Blank for 1 button after this
			#endif
		} 
		
		
	}


}

