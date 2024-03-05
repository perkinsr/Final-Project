//=====[Libraries]=============================================================

#include "microwave_system.h"
#include "servo_motor.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    servoInit();
    while (true) {
        servoWrite();
    }
}
