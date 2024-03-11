//=====[#include guards - begin]===============================================

#ifndef _CODE_H_
#define _CODE_H_

//=====[Declaration of public defines]=========================================
 
//the set amout delay times in milliseconds
#define TEN_SEC_RUN_MS 10000
#define TWENTY_SEC_RUN_MS 20000
#define THIRTY_SEC_RUN_MS 30000
#define ONE_MIN_RUN_MS 60000
//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void codeInit();
int codeUpdate();
int keyReleasedDelay();

//=====[#include guards - end]=================================================

#endif // _CODE_H_
