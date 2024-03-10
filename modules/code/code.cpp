//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "code.h"
#include "keypad.h"
#include "microwave_system.h"
#include "light_level.h"
#include "date_and_time.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

int wattageState = 0;
char keyReleased;

//=====[Declaration and initialization of private global variables]============

static int numberOfCodeChars = 0;

//=====[Declarations (prototypes) of private functions]========================

static int timerMatrixKeypadUpdate();
bool checkButtonPressedNumber();
int convertArrayToInt(char charArray []);
int wattageUpdate();

//=====[Implementations of public functions]===================================

void codeInit()
{
    matrixKeypadInit( SYSTEM_TIME_INCREMENT_MS );
}

int codeUpdate()
{
    return timerMatrixKeypadUpdate();
}


//=====[Implementations of private functions]==================================

static int timerMatrixKeypadUpdate(){
    keyReleased = matrixKeypadUpdate();
    int wattageWait = 0;
    while ( keyReleased != '\0' && wattageWait == 0) {
        wattageWait = wattageUpdate();
    }

    return wattageWait;

}

int wattageUpdate(){
    char letterReleased = matrixKeypadUpdate();
    if ( letterReleased == 'A' ) {
        return LOW_WATT;
    }
    if( letterReleased == 'B'){
        return MED_WATT;
    }
    if (letterReleased == 'C'){
        return HIGH_WATT;
    } 

    return 0;
}

int keyReleasedDelay(){
    int delayValue = 0;
    if (keyReleased == '1'){
        delayValue = 10000;
    }
    if (keyReleased == '2'){
        delayValue = 20000;
    }
    if (keyReleased == '3'){
        delayValue = 30000;
    }
    if (keyReleased == '4'){
        delayValue = 60000;
    }
    return delayValue;
}
