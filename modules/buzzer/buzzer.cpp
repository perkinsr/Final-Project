//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "buzzer.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut sirenPin(PE_10);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void sirenInit()
{
    sirenPin = ON;
}

void sirenUpdate()
{
    sirenPin = !sirenPin;
    delay(500);
    sirenPin = !sirenPin;
}

//=====[Implementations of private functions]==================================

