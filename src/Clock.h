#ifndef CLOCK_H
#define CLOCK_H


/* Attributes */
#include "stdint.h"
#include "E_DAY.h"


/* Realized interfaces */
#include "i_Clock_Data.h"
#include "i_Clock_Settings.h"


/* Needed interfaces */
#include "i_Microcontroller_Timestamp.h"


/* Events */

/* Component_Type */
/* The Clock Component_Type allows to measure the time.
It is based on the micro-controller timestamp.
It provides services to set its current data (day, hour, minute, second).
It shall be cyclically triggered (at least twice as second to provide accurate data). */
class Clock {
public :
    /*--------------------------------------------------------------------------------------------*/
    /* Constructor */
	Clock( void ) {}
    Clock( i_Microcontroller_Timestamp* microcontroller_timestamp );

    /*--------------------------------------------------------------------------------------------*/
    /* Component_Type_Operations */
    void Tick(void);

    /*--------------------------------------------------------------------------------------------*/
    /* Event reception points accessors */
    /* none */

    /*--------------------------------------------------------------------------------------------*/
    /* Prodided port accessors */
    i_Clock_Data* Get_Port__Clock_Data( void );
    i_Clock_Settings* Get_Port__Settings( void );


private :
    /*--------------------------------------------------------------------------------------------*/
    /* Private attributes */
    unsigned long clock_timestamp;
    E_DAY day;
    uint8_t hour; 
    uint8_t minute;
    uint8_t second;

    /*--------------------------------------------------------------------------------------------*/
    /* Private methods */
    void Increment_Clock_Second( void );
    void Increment_Clock_Minute( void );
    void Increment_Clock_Hour( void );
    void Increment_Clock_Day( void );

    /*--------------------------------------------------------------------------------------------*/
    /* Requirer_Ports */
    i_Microcontroller_Timestamp* Microcontroller_Timestamp;

    /*--------------------------------------------------------------------------------------------*/
    /* Provider ports */
    /*--------------------------------------------------------------------------------------------*/
    /* Clock_Settings:i_Clock_Settings */
    class Clock_Settings_Class : i_Clock_Settings {
    public :
        /* Constructors */
        Clock_Settings_Class(void) {}
        Clock_Settings_Class( Clock* x ) : parent(x) {}
        /* Provided operations */
        void Increment_Day( void ) override;
        void Increment_Hour( void ) override;
        void Increment_Minute( void ) override;
        void Increment_Second( void ) override;
        void Decrement_Second( void ) override;
        void Decrement_Minute( void ) override;
        void Decrement_Hour( void ) override;
        void Decrement_Day( void ) override;
    private :
        Clock* parent; /* reference to owner Component_Type */
    };
    Clock_Settings_Class Clock_Settings;
    /*--------------------------------------------------------------------------------------------*/
    /* Clock_Data:i_Clock_Data */
    class Clock_Data_Class : i_Clock_Data {
    public :
        /* Constructors */
        Clock_Data_Class(void) {}
        Clock_Data_Class( Clock* x ) : parent(x) {}
        /* Provided operations */
        void Get_Date( E_DAY* day, uint8_t* hour, uint8_t* minute, uint8_t* second ) override;
        void Get_Day( E_DAY* day ) override;
        void Get_Hour( uint8_t* hour) override;
        void Get_Minute( uint8_t* minute ) override;
        void Get_Second( uint8_t* second ) override;
    private :
        Clock* parent; /* reference to owner Component_Type */
    };
    Clock_Data_Class Clock_Data;

    /*--------------------------------------------------------------------------------------------*/
    /* Sent events */

    /*--------------------------------------------------------------------------------------------*/
    /* Received events */
};

#endif