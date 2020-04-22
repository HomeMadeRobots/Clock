#ifndef CLOCK_H
#define CLOCK_H


/* Attributes */
#include <stdint.h>
#include "E_Day.h"


/* Realized interfaces */
#include "Clock_Data.h"
#include "Clock_Setting.h"


/*============================================================================*/
/* Component_Type */
/*============================================================================*/
typedef struct {
    uint32_t Clock_Timestamp;
    uint32_t Time_Carrier;
    E_Day Day;
    uint8_t Hour; 
    uint8_t Minute;
    uint8_t Second;
} Clock_Var;

typedef struct {

    /* Variable attributes */
    Clock_Var* var_attr;

} Clock;


/*============================================================================*/
/* Component_Operations */
/*============================================================================*/
void Clock__Tick( const Clock* Me );


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void Clock__Data__Get_Date(
    const Clock* Me, 
    E_Day* day,
    uint8_t* hour,
    uint8_t* minute,
    uint8_t* second );
void Clock__Data__Get_Day( const Clock* Me, E_Day* day );
void Clock__Data__Get_Hour( const Clock* Me, uint8_t* hour );
void Clock__Data__Get_Minute( const Clock* Me, uint8_t* minute );
void Clock__Data__Get_Second( const Clock* Me, uint8_t* second );

void Clock__Setting__Increment_Day( const Clock* Me );
void Clock__Setting__Increment_Hour( const Clock* Me );
void Clock__Setting__Increment_Minute( const Clock* Me );
void Clock__Setting__Increment_Second( const Clock* Me );
void Clock__Setting__Decrement_Day( const Clock* Me );
void Clock__Setting__Decrement_Hour( const Clock* Me );
void Clock__Setting__Decrement_Minute( const Clock* Me );
void Clock__Setting__Decrement_Second( const Clock* Me );

#endif