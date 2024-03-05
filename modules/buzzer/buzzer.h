//=====[#include guards - begin]===============================================

#ifndef _BUZZER_H_
#define _BUZZER_H_

//=====[Declaration of public defines]=========================================
#define SYSTEM_TIME_INCREMENT_MS 10
//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void sirenInit();
bool sirenStateRead();
void sirenStateWrite( bool state );
void sirenUpdate( int strobeTime );

//=====[#include guards - end]=================================================

#endif // _BUZZER_H_
