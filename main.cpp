//=====[Libraries]=============================================================
#include "mbed.h"
#include "arm_book_lib.h"

#include "microwave_system.h"
#include "servo_motor.h"
#include "light.h"
#include "date_and_time.h"
#include "display.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    displayInit();
    while (true) {
         if (setDateAndTime() == true){
             while (true){
                 displayUpdate();
             }
         }
    }
}
