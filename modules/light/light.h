//=====[#include guards - begin]===============================================

#ifndef _LIGHT_H_
#define _LIGHT_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void temperatureSensorInit();
void temperatureSensorUpdate();
float temperatureSensorReadCelsius();
float temperatureSensorReadFahrenheit();
float celsiusToFahrenheit( float tempInCelsiusDegrees );

//=====[#include guards - end]=================================================

#endif // _LIGHT_H_