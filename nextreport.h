
#include "types.h"

extern USB_JoystickReport_t cur_report;
extern USB_JoystickReport_t last_report;

void GetNextReport(USB_JoystickReport_t* const ReportData);