#ifndef I_CLOCK_DATA_H
#define I_CLOCK_DATA_H

#include "stdint.h"
#include "E_DAY.h"

/* Client_Server_Interface */
/* i_Clock_Data defines operations allowing to access the data of a clock. */
class i_Clock_Data {
public :
    virtual void Get_Date( E_DAY* day, uint8_t* hour, uint8_t* minute, uint8_t* second ) = 0;
    virtual void Get_Day( E_DAY* day ) = 0;
    virtual void Get_Hour( uint8_t* hour) = 0;
    virtual void Get_Minute( uint8_t* minute ) = 0;
    virtual void Get_Second( uint8_t* second ) = 0;
};

#endif