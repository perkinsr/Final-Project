//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "light.h"

#include "light_level.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//declade the RGB LED
PwmOut RGBLed[] = {(PB_4), (PA_0), (PD_12)};

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static void setPeriod( lightSystem_t light, float period );
void brightControlInit();

//=====[Declarations (prototypes) of public functions]========================

//initialize the light system by setting up the brightness of the RGB LED
void lightSystemInit()
{
    brightControlInit();
}

//given the specific light and the duty cycle as parameters, set the duty cycle of that specific light
void setDutyCycle( lightSystem_t light, float dutyCycle )
{
    RGBLed[light].write(dutyCycle);
}

//given the specific light and the period as parameters, set the period of that specific light
static void setPeriod( lightSystem_t light, float period )
{
    RGBLed[light].period(period);
}


//initialize the brightness and the duty cycles of the RGB LED
void brightControlInit()
{
    setPeriod( RGB_LED_RED, 0.01f );
    setPeriod( RGB_LED_GREEN, 0.01f );
    setPeriod( RGB_LED_BLUE, 0.01f );

    setDutyCycle( RGB_LED_RED, LOW_DUTY);
    setDutyCycle( RGB_LED_GREEN, LOW_DUTY);
    setDutyCycle( RGB_LED_BLUE, LOW_DUTY);
}

//in this system, the wattage of all three bulbs is the same. So by getting one, it can be determined if the 
//RGB LED is on or not. This function grabs the wattage value of the red LED and returns that value
float getWattage(){
    return RGBLed[RGB_LED_RED].read();
}