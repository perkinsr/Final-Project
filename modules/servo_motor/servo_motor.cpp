//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "servo_motor.h"
#include "timer.h"

//=====[Declaration of private defines]========================================



//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

PwmOut servo(PF_9);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

motion_t motorState;
motion_t motorMotion;

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void motorInit() {
    servo.period(PERIOD); // 20ms period
    delay(1000);
    motorState = STOPPED;
}

void motorWrite(float speed){
    servo.write(speed);
}

motion_t motorStateRead(){
    return motorState;
}

void motorControlUpdate(){
    switch ( motorState ) {
        case MOVING:
            if ( motorMotion == STOPPED) {
                motorWrite(DUTY_CYCLE_MS);
                motorState = STOPPED;
            }
        break;

        case STOPPED:
            if ( motorMotion == MOVING ) {
                motorWrite(RUNNING_SPEED);
                motorState = MOVING;
            }
        break;
    }
           
}

void motorMotionControl(motion_t changeMotion){
    motorMotion = changeMotion;
}

//=====[Implementations of private functions]==================================
