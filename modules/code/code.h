//=====[#include guards - begin]===============================================

#ifndef _CODE_H_
#define _CODE_H_

//=====[Declaration of public defines]=========================================

#define TIMER_MAX_KEYS  4
#define ARRAY_HALF_INDEX  2
 

//=====[Declaration of public data types]======================================

bool countdownRunningState = false;

//=====[Declarations (prototypes) of public functions]=========================

void codeInit();
int codeUpdate();
int returnArrayInt();
//=====[#include guards - end]=================================================

#endif // _CODE_H_
