#include "types.h"
#include <string.h> // For memcpy

#define ECHOES 1
#define STEP_BLOCK_SIZE 5

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

uint16_t prestep[] = {
    // 0, 32896, 32896, 8, 255, 
    // 64, 32896, 32896, 8, 4, 
    // 192, 32896, 32896, 8, 49, 
    // 0, 32896, 32896, 8, 250, 
    // 4, 32896, 32896, 8, 24, 
    // 0, 32896, 32896, 8, 400, 
    0, 32896, 32896, 8, 0, 
    64, 32896, 32896, 8, 0, 
    192, 32896, 32896, 8, 0, 
    0, 32896, 32896, 8, 0, 
    4, 32896, 32896, 8, 0, 
    0, 32896, 32896, 8, 0, 
 0 };
static const int numpresteps = 5;


//I know, it's icky.
#include "steps.c"

static uint16_t* reportArray = prestep;
//static int arrayMax = numpresteps;
static int arrayMax = 5;


#include <stdio.h> // Just for debugging.

// Prepare the next report for the host.
void GetNextReport(USB_JoystickReport_t* const ReportData) {

	uint16_t repeats = 0;

	uint16_t bData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+0];
	uint16_t lData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+1];
	uint16_t rData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+2];
	uint16_t hData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+3];
	uint16_t repData = reportArray[(STEP_BLOCK_SIZE*stepIndex)+4];

	// printf("[%u] 0x%x {%u, %u, %u, %u} | ",
	// 	stepIndex, bData, lData, rData, hData, reportArray
	// );

	// Prepare an empty report
	// memset(ReportData, 0, sizeof(USB_JoystickReport_t));
	// //Defaults

	// ReportData->LX = STICK_CENTER;
	// ReportData->LY = STICK_CENTER;
	// ReportData->RX = STICK_CENTER;
	// ReportData->RY = STICK_CENTER;
	// ReportData->HAT = HAT_CENTER;
	memcpy(ReportData, &BLANK_REPORT, sizeof(USB_JoystickReport_t));

	// Repeat ECHOES times the last report
	if (echoes > 0)
	{
		memcpy(ReportData, &last_report, sizeof(USB_JoystickReport_t));
		echoes--;
		return;
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
			ReportData->LY = pseudoL[1];
			ReportData->RX = pseudoR[0];
			ReportData->RY = pseudoR[1];

			ReportData->HAT = pseudoH[0];
			ReportData->VendorSpec = pseudoH[1];

			repeats = repData;
			stepIndex += 1;

			break;

		case CLEANUP:
			//*ReportData = BLANK_REPORT;
			state = DONE;
			break;

		case DONE:
			return;
	}


	if (stepIndex > arrayMax)
	{
		if (reportArray == prestep) {
			reportArray = step;
			arrayMax = numsteps;
		}
		stepIndex = 0;
		//state = SYNC_POSITION;
	}
	// Prepare to echo this report, copy the ReportData to last_report
	memcpy(&last_report, ReportData, sizeof(USB_JoystickReport_t));
	echoes = ECHOES*repeats;

}