//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "ldr_sensor.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============
AnalogIn ldr(A2);
//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

//get and return the current value of the LDR sensor
float ldrCheck(){
    return ldr.read();
}
//=====[Implementations of pricate functions]===================================
