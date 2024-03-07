//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "microwave_system.h"

#include "light.h"
#include "display.h"
#include "keypad.h"
#include "servo_motor.h"

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
    displayInit();
    matrixKeypadInit(5);
    motorInit();
}

void microwaveSystemUpdate()
{

}

//=====[Implementations of private functions]==================================
