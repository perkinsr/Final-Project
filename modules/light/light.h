//=====[#include guards - begin]===============================================

#ifndef _LIGHT_H_
#define _LIGHT_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

typedef enum {
    RGB_LED_RED,
    RGB_LED_GREEN,
    RGB_LED_BLUE,
} lightSystem_t;

//=====[Declarations (prototypes) of public functions]=========================

void lightSystemInit();
void lightSystemUpdate();

void setDutyCycle( lightSystem_t light, float dutyCycle );

float getWattage();

//=====[#include guards - end]=================================================

#endif // _LIGHT_H_