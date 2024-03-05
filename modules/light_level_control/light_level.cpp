//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "light_level.h"

#include "light.h"
#include "servo_motor.h"

//=====[Declaration of private defines]========================================

#define LOW_DUTY 0.3f
#define MED_DUTY 0.6f
#define HIGH_DUTY 0.9f
#define OFF_DUTY 0.0f
//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============


//=====[Declaration of external public global variables]=======================
static float dutyCycle = 0.5f;
float brightnessFactor = 0.5f;
//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============


//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================
void lightSystemUpdate(int wattage){
    motion_t motorState = motorStateRead();
    if (motorState == MOVING){
        if (wattage == LOW_WATT){
            brightnessFactor = LOW_DUTY;
        } else if (wattage == MED_WATT){
            brightnessFactor = MED_DUTY;
        } else if (wattage == HIGH_WATT){
            brightnessFactor = HIGH_DUTY;
        }
    } else if (motorState == STOPPED){
        brightnessFactor = OFF_DUTY;
    }
    
    setDutyCycle( RGB_LED_RED, brightnessFactor*dutyCycle );
    setDutyCycle( RGB_LED_GREEN, brightnessFactor*dutyCycle );
    setDutyCycle( RGB_LED_BLUE, brightnessFactor*dutyCycle );
}
//=====[Implementations of private functions]==================================

