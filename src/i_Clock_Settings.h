#ifndef I_CLOCK_SETTINGS_H
#define I_CLOCK_SETTINGS_H

#include "stdint.h"
#include "E_DAY.h"

/* Client_Server_Interface */
/* i_Clock_Settings defines operations allowing to set a clock. */
class i_Clock_Settings {
public :
    virtual void Increment_Day( void ) = 0;
    virtual void Increment_Hour( void) = 0;
    virtual void Increment_Minute( void ) = 0;
    virtual void Increment_Second( void ) = 0;

    virtual void Decrement_Second( void ) = 0;
    virtual void Decrement_Minute( void ) = 0;
    virtual void Decrement_Hour( void ) = 0;
    virtual void Decrement_Day( void ) = 0;
};

#endif