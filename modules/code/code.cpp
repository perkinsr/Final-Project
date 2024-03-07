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

char timerSequence[TIMER_MAX_KEYS];
int wattageState = 0;

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

int returnArrayInt(){
    return convertArrayToInt(timerSequence);
}

//=====[Implementations of private functions]==================================

static int timerMatrixKeypadUpdate(){
    char keyReleased = matrixKeypadUpdate();
    int wattageWait = 0;

    if( keyReleased != '\0' ) {
        if(!checkButtonPressedNumber()){
            timerSequence[numberOfCodeChars] = keyReleased;
                numberOfCodeChars++;
        
        } else if (checkButtonPressedNumber()){
            while ( keyReleased == '#' && wattageWait == 0) {
                wattageWait = wattageUpdate();
            }
            return wattageWait;
            
        }
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


bool checkButtonPressedNumber(){
    int count = 0;
    for (int i=0; i<4; i++){
        if (timerSequence[i] != '\0'){
            count++;
        }
    }
    if (count == TIMER_MAX_KEYS){
        return true;
    }
    else{
        return false;
    }
}

int convertArrayToInt(char charArray []){
    int timerAmountMinInSec = 0;
    int timerAmountSec = 0;
    int timerAmount = 0;
    for (int i = 0; i < ARRAY_HALF_INDEX; i++){
        char charDigit1 = charArray[i];
        int intDigit1 = charDigit1 - '0';
        timerAmountMinInSec = timerAmountMinInSec * 10;
        timerAmountMinInSec = timerAmountMinInSec + intDigit1;
        timerAmountMinInSec = timerAmountMinInSec * 60;
    }
    for (int i = ARRAY_HALF_INDEX; i < TIMER_MAX_KEYS; i++){
        char charDigit2 = charArray[i];
        int intDigit2 = charDigit2 - '0';
        timerAmountSec = timerAmountSec * 10;
        timerAmountSec = timerAmountSec + intDigit2;
    }
    timerAmount = timerAmountMinInSec + timerAmountSec;
    return timerAmount;
}
