//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "light_level.h"

#include "light.h"


//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

PwmOut RGBLed[] = {(PB_4), (PA_0), (PD_12)};

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============



static void setPeriod( lightSystem_t light, float period );
void brightControlInit();
//=====[Declarations (prototypes) of public functions]========================

void lightSystemInit()
{
    brightControlInit();
}


void setDutyCycle( lightSystem_t light, float dutyCycle )
{
    RGBLed[light].write(dutyCycle);
}

static void setPeriod( lightSystem_t light, float period )
{
    RGBLed[light].period(period);
}

void brightControlInit()
{
    setPeriod( RGB_LED_RED, 0.01f );
    setPeriod( RGB_LED_GREEN, 0.01f );
    setPeriod( RGB_LED_BLUE, 0.01f );

    setDutyCycle( RGB_LED_RED, LOW_DUTY);
    setDutyCycle( RGB_LED_GREEN, LOW_DUTY);
    setDutyCycle( RGB_LED_BLUE, LOW_DUTY);
}

float getWattage(){
    return RGBLed[1].read();
}