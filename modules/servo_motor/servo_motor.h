//=====[#include guards - begin]===============================================

#ifndef _SERVO_MOTOR_H_
#define _SERVO_MOTOR_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//define the state machine of the motor so motorMotion can be changed in different modules
typedef enum {
    MOVING,
    STOPPED
} motion_t;

//=====[Declarations (prototypes) of public functions]=========================

void motorControlUpdate();

void motorInit();

void motorMotionControl(motion_t changeMotion);

//=====[#include guards - end]=================================================

#endif // _MOTOR_H_
