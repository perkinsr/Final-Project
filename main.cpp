//=====[Libraries]=============================================================
#include "mbed.h"
#include "arm_book_lib.h"

#include "microwave_system.h"


//=====[Main function, the program entry point after power on or reset]========

int main(){
    microwaveSystemInit();
    while (true) {
        microwaveSystemUpdate();
    }
}
