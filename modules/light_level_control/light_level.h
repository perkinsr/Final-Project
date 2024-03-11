//=====[#include guards - begin]===============================================

#ifndef _LIGHT_LEVEL_H_
#define _LIGHT_LEVEL_H_

//=====[Declaration of public defines]=========================================

//defines to used to figure out user inputted wattage
#define LOW_WATT 1
#define MED_WATT 2
#define HIGH_WATT 3

//defines used to set the duty cycle based on the user inputted wattage
#define LOW_DUTY 0.1f
#define MED_DUTY 0.4f
#define HIGH_DUTY 0.9f
#define OFF_DUTY 0.0f
//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void lightSystemUpdate(int wattage);

//=====[#include guards - end]=================================================

#endif // _LIGHT_LEVEL_H_