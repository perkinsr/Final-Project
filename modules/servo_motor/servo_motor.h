//=====[#include guards - begin]===============================================

#ifndef _SERVO_MOTOR_H_
#define _SERVO_MOTOR_H_

//=====[Declaration of public defines]=========================================

#define PERIOD 0.02
#define DUTY_CYCLE_MS 0.075
#define RUNNING_SPEED 0.079


//=====[Declaration of public data types]======================================

typedef enum {
    MOVING,
    STOPPED
} motion_t;

//=====[Declarations (prototypes) of public functions]=========================

motion_t motorStateRead();

void motorControlUpdate();

void motorInit();

void motorWrite();

//=====[#include guards - end]=================================================

#endif // _MOTOR_H_
