//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "code.h"
#include "keypad.h"
#include "microwave_system.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

char codeSequenceFromKeypad[TIMER_MAX_KEYS];

//=====[Declaration and initialization of private global variables]============

static char startButton = '#';
static char lowWattage = 'C';
static char mediumWattage = 'B';
static char highWattage = 'A';

static char timerSequence[TIMER_MAX_KEYS];

//=====[Declarations (prototypes) of private functions]========================


//=====[Implementations of public functions]===================================

void timerWrite( char* timerInput ){
    int i;
    for (i = 0; i < TIMER_MAX_KEYS; i++) {
        timerSequence[i] = timerInput[i];
    }
}



//=====[Implementations of private functions]==================================



//=====[Declaration and initialization of private global variables]============

static bool codeComplete = false;
static int numberOfCodeChars = 0;

//=====[Declarations (prototypes) of private functions]========================

static void userInterfaceMatrixKeypadUpdate();
static void incorrectCodeIndicatorUpdate();
static void systemBlockedIndicatorUpdate();

//=====[Implementations of public functions]===================================

void userInterfaceInit()
{
    matrixKeypadInit( SYSTEM_TIME_INCREMENT_MS );
}

void userInterfaceUpdate()
{
    userInterfaceMatrixKeypadUpdate();
    incorrectCodeIndicatorUpdate();
}

bool incorrectCodeStateRead()
{
    return incorrectCodeState;
}

void incorrectCodeStateWrite( bool state )
{
    incorrectCodeState = state;
}



bool userInterfaceCodeCompleteRead()
{
    return codeComplete;
}

void userInterfaceCodeCompleteWrite( bool state )
{
    codeComplete = state;
}

//=====[Implementations of private functions]==================================

static void userInterfaceMatrixKeypadUpdate()
{
    static int numberOfHashKeyReleased = 0;
    char keyReleased = matrixKeypadUpdate();

    if( keyReleased != '\0' ) {

        if( alarmStateRead() && !systemBlockedStateRead() ) {
            if( !incorrectCodeStateRead() ) {
                codeSequenceFromUserInterface[numberOfCodeChars] = keyReleased;
                numberOfCodeChars++;
                if ( numberOfCodeChars >= CODE_NUMBER_OF_KEYS ) {
                    codeComplete = true;
                    numberOfCodeChars = 0;
                }
            } else {
                if( keyReleased == '#' ) {
                    numberOfHashKeyReleased++;
                    if( numberOfHashKeyReleased >= 2 ) {
                        numberOfHashKeyReleased = 0;
                        numberOfCodeChars = 0;
                        codeComplete = false;
                        incorrectCodeState = OFF;
                    }
                }
            }
        } else if ( !systemBlockedStateRead() ) {
            if( keyReleased == 'A' ) {
                motionSensorActivate();
            }
            if( keyReleased == 'B' ) {
                motionSensorDeactivate();
            }
            if( keyReleased == '1' ) {
                lightSystemBrightnessChangeRGBFactor( RGB_LED_RED, true );
            }
            if( keyReleased == '2' ) {
                lightSystemBrightnessChangeRGBFactor( RGB_LED_GREEN, true );
            }
            if( keyReleased == '3' ) {
                lightSystemBrightnessChangeRGBFactor( RGB_LED_BLUE, true );
            }
            if( keyReleased == '4' ) {
                lightSystemBrightnessChangeRGBFactor( RGB_LED_RED, false );
            }
            if( keyReleased == '5' ) {
                lightSystemBrightnessChangeRGBFactor( RGB_LED_GREEN, false );
            }
            if( keyReleased == '6' ) {
                lightSystemBrightnessChangeRGBFactor( RGB_LED_BLUE, false );
            }
        }
    }
}

static void incorrectCodeIndicatorUpdate()
{
    incorrectCodeLed = incorrectCodeStateRead();
}
