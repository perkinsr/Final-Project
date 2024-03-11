//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "timer.h"

#include "light.h"
#include "code.h"
#include "buzzer.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============


//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

//if the wattage of the RGB LED is above zero, meaning that the microwave is running, then delay
//the entire code by the user inputted amount of time, and then sound the buzzer indicating that the
//microwave is done
void runTimer(){
    if (getWattage() > 0){
        delay(keyReleasedDelay());
        sirenUpdate();
    }

    
}

//=====[Implementations of private functions]==================================

