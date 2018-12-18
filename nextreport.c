#include "types.h"
#include <string.h> // For memcpy

#define ECHOES 4 // 30 FPS
#define STEP_BLOCK_SIZE 5

//#define PRE SPLAT
#define PRE 1
//0: NONE
//1: SPLAT

static int echoes = 0;
static int stepIndex = 0;

static USB_JoystickReport_t last_report;

static uint8_t* pseudoL;
static uint8_t* pseudoR;
static uint8_t* pseudoH;
static uint16_t* pseudoB;

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

uint16_t prestep[] = {
    0, 32896, 32896, 8, 255,  //Wait
    64, 32896, 32896, 8, 7, 
    192, 32896, 32896, 8, 24, //Triggers
    0, 32896, 32896, 8, 63, 
    4, 32896, 32896, 8, 15,  //Continue
    0, 32896, 32896, 8, 63, 
 0 };

#if PRE==1
	static uint16_t* reportArray = prestep;
	static int arrayMax = 6;
#else
	static uint16_t* reportArray = prestep;
	static int arrayMax = 0;
#endif

//#include <stdio.h> // Just for debugging.

// Prepare the next report for the host.
void GetNextReport(USB_JoystickReport_t* const ReportData) {

	uint16_t bData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+0];
	uint16_t lData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+1];
	uint16_t rData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+2];
	uint16_t hData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+3];
	uint16_t repData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+4];

	// printf("[%u] 0x%x {%u, %u, %u, %u} | ",
	// 	stepIndex, reportArray, bData, lData, rData, hData 
	// );

	// Prepare an empty report
	memcpy(ReportData, &BLANK_REPORT, sizeof(USB_JoystickReport_t));

	// Repeat ECHOES times the last report
	if (echoes > 0)
	{
		memcpy(ReportData, &last_report, sizeof(USB_JoystickReport_t));
		echoes--;
		return;
	} else {
		stepIndex += 1;
	}

	// Wraparound
	if (stepIndex >= arrayMax)
	{
		if (reportArray == prestep) {
			reportArray = step;
			arrayMax = numsteps;
		}
		stepIndex = 0;
		//state = SYNC_POSITION;
	}

	// States and moves management
	switch (state)
	{
		case SYNC_CONTROLLER:
			state = BREATHE;
			break;

		case SYNC_POSITION:
			stepIndex = 0;

			ReportData->Button = 0;
			ReportData->LX = STICK_CENTER;
			ReportData->LY = STICK_CENTER;
			ReportData->RX = STICK_CENTER;
			ReportData->RY = STICK_CENTER;
			ReportData->HAT = HAT_CENTER;

			state = BREATHE;
			break;

		case BREATHE:
			state = PROCESS;
			break;

		case PROCESS:
			//ReportData->Button = bData;

			pseudoB = (uint16_t*)(&bData);
			pseudoL = (uint8_t*)(&lData);
			pseudoR = (uint8_t*)(&rData);
			pseudoH = (uint8_t*)(&hData);

			ReportData->Button = *pseudoB;
			ReportData->LX = pseudoL[0];
			ReportData->LY = 255-pseudoL[1];
			ReportData->RX = pseudoR[0];
			ReportData->RY = 255-pseudoR[1];

			ReportData->HAT = pseudoH[0];
			ReportData->VendorSpec = pseudoH[1];

			// Echo this report
			echoes = ECHOES*repData;

			break;

		case CLEANUP:
			//*ReportData = BLANK_REPORT;
			state = DONE;
			break;

		case DONE:
			return;
	}
	// Copy the ReportData to last_report
	memcpy(&last_report, ReportData, sizeof(USB_JoystickReport_t));

}