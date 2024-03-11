//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "buzzer.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalInOut sirenPin(PC_9);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

//initializes the buzzer
void sirenInit()
{
    sirenPin.mode(OpenDrain);
    sirenPin.input();
}

//makes the buzzer buzz for 0.5 seconds
void sirenUpdate()
{
    sirenPin.output();                                     
    sirenPin = LOW; 
    delay(500);
    sirenPin.input();
}

//=====[Implementations of private functions]==================================

