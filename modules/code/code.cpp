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

//keeps track of what key is most recently released
char keyReleased;

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

static int timerMatrixKeypadUpdate();
bool checkButtonPressedNumber();
int convertArrayToInt(char charArray []);
int wattageUpdate();

//=====[Implementations of public functions]===================================

//initializes the matrix keypad
void codeInit()
{
    matrixKeypadInit( SYSTEM_TIME_INCREMENT_MS );
}

//update function that is run to check the keypad for time and wattage values
int codeUpdate()
{
    return timerMatrixKeypadUpdate();
}


//=====[Implementations of private functions]==================================

//using the debounced matrixKeypadUpdate function, when a key is released, run wattageUpdate
//until a wattage as been chosen on the keypad. Then return the value of wattage wait.
static int timerMatrixKeypadUpdate(){
    keyReleased = matrixKeypadUpdate();
    int wattageWait = 0;
    while ( keyReleased != '\0' && wattageWait == 0) {
        wattageWait = wattageUpdate();
    }

    return wattageWait;

}

//check to see if the letters bellow have been pressed, meaning that a resulting wattage has been chosen
//and return that value.
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

//use the global variable keyReleased to determine what number was pressed. Based on that number value,
//a specific delay will be run
int keyReleasedDelay(){
    int delayValue = 0;
    if (keyReleased == '1'){
        delayValue = TEN_SEC_RUN_MS;
    }
    if (keyReleased == '2'){
        delayValue = TWENTY_SEC_RUN_MS;
    }
    if (keyReleased == '3'){
        delayValue = THIRTY_SEC_RUN_MS;
    }
    if (keyReleased == '4'){
        delayValue = ONE_MIN_RUN_MS;
    }
    return delayValue;
}
