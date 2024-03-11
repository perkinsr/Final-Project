//=====[#include guards - begin]===============================================

#ifndef _MICROWAVE_SYSTEM_H_
#define _MICROWAVE_SYSTEM_H_

//=====[Declaration of public defines]=========================================

//system delay used to set up the display
#define SYSTEM_TIME_INCREMENT_MS   10

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void microwaveSystemInit();
void microwaveSystemUpdate();

//=====[#include guards - end]=================================================

#endif // _MICROWAVE_SYSTEM_H_