//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "servo_motor.h"

//=====[Declaration of private defines]========================================

#define MOTOR_UPDATE_TIME 9


//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

PwmOut servo(PF_9);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

motorDirection_t motorDirection;
motorDirection_t motorState;

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void servoInit() {
    servo.period(PERIOD); // 20ms period
    delay(1000);
}

void servoWrite(){
    servo.write(DUTY_CYCLE_MS+0.005);
    delay(1000);
}

motorDirection_t motorDirectionRead()
{
    return motorDirection;
}

void motorDirectionWrite( motorDirection_t direction )
{
    motorDirection = direction;
}

void motorControlUpdate()
{
    static int motorUpdateCounter = 0;
    
    motorUpdateCounter++;
    
    if ( motorUpdateCounter > MOTOR_UPDATE_TIME ) {
        
        motorUpdateCounter = 0;
        
        switch ( motorState ) {
            case DIRECTION_1:
                if ( motorDirection == DIRECTION_2 || 
                     motorDirection == STOPPED ) {

                    motorState = STOPPED;
                }
            break;
    
            case DIRECTION_2:
                if ( motorDirection == DIRECTION_1 || 
                     motorDirection == STOPPED ) {

                    motorState = STOPPED;
                }
            break;
    
            case STOPPED:
            default:
                if ( motorDirection == DIRECTION_1 ) {
  
                    motorState = DIRECTION_1;
                }
                
                if ( motorDirection == DIRECTION_2 ) {

                    motorState = DIRECTION_2;
                }
            break;
        }
    }        
}

//=====[Implementations of private functions]==================================
