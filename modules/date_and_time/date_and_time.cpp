//=====[Libraries]=============================================================

#include "mbed.h"

#include "date_and_time.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============
UnbufferedSerial uartUsb(USBTX, USBRX, 115200);
//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================
bool setDateAndTime(){
    char receivedChar = '\0';
    char str[100];
    int stringLength;
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    if( uartUsb.readable() ) {
        uartUsb.read( &receivedChar, 1 );
        switch (receivedChar) {
            case 's':
            case 'S':
                struct tm rtcTime;
                int strIndex;

                uartUsb.write( "\r\nType four digits for the current year (YYYY): ", 48 );
                for( strIndex=0; strIndex<4; strIndex++ ) {
                    uartUsb.read( &str[strIndex] , 1 );
                    uartUsb.write( &str[strIndex] ,1 );
                }
                str[4] = '\0';
                year = atoi(str) - 1900;
                uartUsb.write( "\r\n", 2 );

                uartUsb.write( "Type two digits for the current month (01-12): ", 47 );
                for( strIndex=0; strIndex<2; strIndex++ ) {
                    uartUsb.read( &str[strIndex] , 1 );
                    uartUsb.write( &str[strIndex] ,1 );
                }
                str[2] = '\0';
                month  = atoi(str) - 1;
                uartUsb.write( "\r\n", 2 );

                uartUsb.write( "Type two digits for the current day (01-31): ", 45 );
                for( strIndex=0; strIndex<2; strIndex++ ) {
                    uartUsb.read( &str[strIndex] , 1 );
                    uartUsb.write( &str[strIndex] ,1 );
                }
                str[2] = '\0';
                day = atoi(str);
                uartUsb.write( "\r\n", 2 );

                uartUsb.write( "Type two digits for the current hour (00-23): ", 46 );
                for( strIndex=0; strIndex<2; strIndex++ ) {
                    uartUsb.read( &str[strIndex] , 1 );
                    uartUsb.write( &str[strIndex] ,1 );
                }
                str[2] = '\0';
                hour = atoi(str);
                uartUsb.write( "\r\n", 2 );

                uartUsb.write( "Type two digits for the current minutes (00-59): ", 49 );
                for( strIndex=0; strIndex<2; strIndex++ ) {
                    uartUsb.read( &str[strIndex] , 1 );
                    uartUsb.write( &str[strIndex] ,1 );
                }
                str[2] = '\0';
                min  = atoi(str);
                uartUsb.write( "\r\n", 2 );

                uartUsb.write( "Type two digits for the current seconds (00-59): ", 49 );
                for( strIndex=0; strIndex<2; strIndex++ ) {
                    uartUsb.read( &str[strIndex] , 1 );
                    uartUsb.write( &str[strIndex] ,1 );
                }
                str[2] = '\0';
                sec  = atoi(str);
                uartUsb.write( "\r\n", 2 );

                dateAndTimeWrite (year, month, day, hour, min, sec);
                
                uartUsb.write( "Date and time has been set\r\n", 28 );

                return true;
                break;

             default:
                uartUsb.write( "Type S to set the time\r\n", 24 );

                break;
        }
    }
    return false;
}

void dateAndTimeWrite( int year, int month, int day, 
                       int hour, int minute, int second ){
    struct tm rtcTime;

    rtcTime.tm_year = year;
    rtcTime.tm_mon  = month;
    rtcTime.tm_mday = day;
    rtcTime.tm_hour = hour;
    rtcTime.tm_min  = minute;
    rtcTime.tm_sec  = second;

    rtcTime.tm_isdst = -1;

    set_time( mktime( &rtcTime ) );
}


char* dateAndTimeRead()
{
    time_t epochSeconds;
    char str[100];
    epochSeconds = time(NULL);
    sprintf ( str,"Date and Time = %s", ctime(&epochSeconds));
    uartUsb.write( str , strlen(str) );
    uartUsb.write( "\r\n", 2 );
    return ctime(&epochSeconds);    
}



//=====[Implementations of private functions]==================================

