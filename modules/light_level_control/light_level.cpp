//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "light_level.h"

#include "light.h"
#include "servo_motor.h"
#include "date_and_time.h"
#include "timer.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============


//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

//with the user inputted wattage value from the return of the codeUpdate() function, the specific
//duty cycles of the LED's are set. If any wattage value other than zero is passed through, then the 
//motorMotionControl() function will be run, changing the motor to be in a moving state when the motor update
//function is run. If the wattage value is zero, indicating that the user hasn't inputted a value to run the
//microwave yet, the motor will stay in the stopped position.
void lightSystemUpdate(int wattage){

    if (wattage == LOW_WATT){
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

