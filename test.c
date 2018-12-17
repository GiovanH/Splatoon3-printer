#include <stdio.h>
#include <string.h>

#include "types.h"
#include "nextreport.h"

int v = 0;

int main(void) {
	for (uint i = 0; v != 88; i++) {
		USB_JoystickReport_t JoystickInputData;
		GetNextReport(&JoystickInputData);
		//if (JoystickInputData.LX != 128) {
			printf("%u Buttons: %u, Hat: %u, Sticks: (%u, %u), (%u, %u), Vendor: %u\n",
				0, 
				JoystickInputData.Button,
				JoystickInputData.HAT,
				JoystickInputData.LX,
				JoystickInputData.LY,
				JoystickInputData.RX,
				JoystickInputData.RY,
				JoystickInputData.VendorSpec
			);
			v = JoystickInputData.VendorSpec;
		//}
	}
}
