//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "light_level.h"

#include "light.h"
#include "servo_motor.h"
#include "date_and_time.h"
#include "timer.h"

//=====[Declaration of private defines]========================================

#define LOW_DUTY 0.3f
#define MED_DUTY 0.6f
#define HIGH_DUTY 0.9f
#define OFF_DUTY 0.0f
//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============


//=====[Declaration of external public global variables]=======================
static float constantDutyCycle = 0.5f;
//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============


//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================
void lightSystemUpdate(int wattage){

    if (wattage == LOW_WATT){
        serialPrint();
        setDutyCycle( RGB_LED_RED, LOW_DUTY);
        setDutyCycle( RGB_LED_GREEN, LOW_DUTY);
        setDutyCycle( RGB_LED_BLUE, LOW_DUTY);
        motorMotionControl(MOVING);

    } else if (wattage == MED_WATT){
        setDutyCycle( RGB_LED_RED, MED_DUTY);
        setDutyCycle( RGB_LED_GREEN, MED_DUTY);
        setDutyCycle( RGB_LED_BLUE, MED_DUTY);
        motorMotionControl(MOVING);

    } else if (wattage == HIGH_WATT){
        setDutyCycle( RGB_LED_RED, HIGH_DUTY);
        setDutyCycle( RGB_LED_GREEN, HIGH_DUTY);
        setDutyCycle( RGB_LED_BLUE, HIGH_DUTY);
        motorMotionControl(MOVING);

    } else if (wattage == 0) {
        setDutyCycle( RGB_LED_RED, OFF_DUTY);
        setDutyCycle( RGB_LED_GREEN, OFF_DUTY);
        setDutyCycle( RGB_LED_BLUE, OFF_DUTY);
        motorMotionControl(STOPPED);

    }

    
}


//=====[Implementations of private functions]==================================

