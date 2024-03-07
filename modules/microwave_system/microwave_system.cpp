//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "microwave_system.h"

#include "light.h"
#include "keypad.h"
#include "servo_motor.h"
#include "buzzer.h"
#include "code.h"
#include "date_and_time.h"
#include "display.h"
#include "ldr_sensor.h"
#include "light_level.h"
#include "timer.h"


//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void microwaveSystemInit(){
    lightSystemInit();
    motorInit();
    sirenInit();
    codeInit();
    displayInit();
    matrixKeypadInit( SYSTEM_TIME_INCREMENT_MS );
}

void microwaveSystemUpdate()
{
    displayUpdate();
    lightSystemUpdate(codeUpdate());
    motorControlUpdate();
    runTimer();
    sirenUpdate();

}

//=====[Implementations of private functions]==================================
