//=====[#include guards - begin]===============================================

#ifndef _SERVO_MOTOR_H_
#define _SERVO_MOTOR_H_

//=====[Declaration of public defines]=========================================
#define DUTY_MIN 0.02
#define PERIOD 0.02
#define DUTY_CYCLE_MS 0.075
//=====[Declaration of public data types]======================================

typedef enum {
    DIRECTION_1,
    DIRECTION_2,
    STOPPED
} motorDirection_t;

//=====[Declarations (prototypes) of public functions]=========================

void motorControlInit();
void motorDirectionWrite( motorDirection_t direction );

motorDirection_t motorDirectionRead();

void motorControlUpdate();

void servoInit();

void servoWrite();

//=====[#include guards - end]=================================================

#endif // _MOTOR_H_
