//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "servo_motor.h"


#include "timer.h"

//=====[Declaration of private defines]========================================

//defines the period, the duty cycle (which stops the motor from running), and the running speed of the motor
//when the microwave is running
#define PERIOD 0.02
#define DUTY_CYCLE_MS 0.074
#define RUNNING_SPEED 0.079

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//declare the servo motor
PwmOut servo(PF_9);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//declare the state and change variable of the state machine
motion_t motorState;
motion_t motorMotion;

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

void motorWrite(float speed);

//=====[Implementations of public functions]===================================

//initialize the motor and the state machines initial value
void motorInit() {
    servo.period(PERIOD); // 20ms period
    delay(1000);
    motorState = STOPPED;
    motorWrite(DUTY_CYCLE_MS);
}

//function that updates the state machine and the motors function according to the motorMotion variable
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

//using the state variable as a parameter, change motorMotion to be that parameter so the update function can 
//update the state machine and change the behavior of the motor
void motorMotionControl(motion_t changeMotion){
    motorMotion = changeMotion;
}

//=====[Implementations of private functions]==================================

//when gien a speed, write that speed to the servo motor
void motorWrite(float speed){
    servo.write(speed);
}