//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "code.h"
#include "keypad.h"
#include "microwave_system.h"
#include "light_level.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

char timerSequence[TIMER_MAX_KEYS];
int wattageState = 0;

//=====[Declaration and initialization of private global variables]============

static int numberOfCodeChars = 0;

//=====[Declarations (prototypes) of private functions]========================

static void timerMatrixKeypadUpdate();
bool checkButtonPressedNumber();
int convertArrayToInt(char charArray []);

//=====[Implementations of public functions]===================================

void codeInit()
{
    matrixKeypadInit( SYSTEM_TIME_INCREMENT_MS );
}

int codeUpdate()
{
    timerMatrixKeypadUpdate();
}

int returnArrayInt(){
    convertArrayToInt(timerSequence);
}

//=====[Implementations of private functions]==================================

static int timerMatrixKeypadUpdate()
{
    char keyReleased = matrixKeypadUpdate();

    if( keyReleased != '\0' ) {
        if(!checkButtonPressedNumber()){
            timerSequence[numberOfCodeChars] = keyReleased;
                numberOfCodeChars++;
                if ( numberOfCodeChars >= TIMER_MAX_KEYS ) {
                    numberOfCodeChars = 0;
        }
        }
        if( keyReleased == '#' ) {
            countdownRunningState = true;
        } 
        if ( keyReleased == 'A' ) {
            return LOW_WATT;
        }
        if( keyReleased == 'B'){
            return MED_WATT;
        }
        if (keyReleased == 'C'){
            return HIGH_WATT;
        }
    }
}


bool checkButtonPressedNumber(){
    int count = 0;
    for (int i=0; i<4; i++){
        if (timerSequence[i] != '\0'){
            count++;
        }
    }
    if (count == 4){
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
        char charDigit = charArray[i];
        int intDigit = charDigit - '0';
        timerAmountMinInSec = timerAmountMinInSec * 10;
        timerAmountMinInSec = timerAmountMinInSec + intDigit;
        timerAmountMinInSec = timerAmountMinInSec * 60;
    }
    for (int i = ARRAY_HALF_INDEX; i < TIMER_MAX_KEYS; i++){
        char charDigit = charArray[i];
        int intDigit = charDigit - '0';
        timerAmountSec = timerAmountSec * 10;
        timerAmountSec = timerAmountSec + intDigit;
    }
    timerAmount = timerAmountMinInSec + timerAmountSec;
    return timerAmount;
}
