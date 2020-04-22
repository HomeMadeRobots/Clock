#include "Clock.h"

#include "Timestamp.h"

/*============================================================================*/
/* Variable attributes access */
/*============================================================================*/
#define My_Clock_Timestamp (Me->var_attr->Clock_Timestamp)
#define My_Time_Carrier (Me->var_attr->Time_Carrier)
#define My_Day (Me->var_attr->Day)
#define My_Hour (Me->var_attr->Hour)
#define My_Minute (Me->var_attr->Minute)
#define My_Second (Me->var_attr->Second)


/*============================================================================*/
/* Private methods declaration */
/*============================================================================*/
static void Increment_Clock_Second( const Clock* Me );
static void Increment_Clock_Minute( const Clock* Me );
static void Increment_Clock_Hour( const Clock* Me );
static void Increment_Clock_Day( const Clock* Me );


/*============================================================================*/
/* Component_Operations */
/*============================================================================*/
void Clock__Tick( const Clock* Me )
{
    uint32_t micro_timestamp = 0;
    uint32_t elapsed_time;
    
    /* Get microcotroller timestamp */
    micro_timestamp = Get_Timestamp_Millisecond();
     
    /* Compute ellapsed time since last call of Clock_Tick() */
    elapsed_time = My_Time_Carrier + micro_timestamp - My_Clock_Timestamp;

    /* If at least one second has ellapsed */
    if( elapsed_time >= 1000 )
    {
        My_Time_Carrier = elapsed_time - 1000;
        /* Update clock */
        Increment_Clock_Second(Me);
        My_Clock_Timestamp = micro_timestamp;
    }
}


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void Clock__Setting__Increment_Second( const Clock* Me )
{
   if( My_Second < 59 )
    {
        My_Second++;
    }
    else
    {
        My_Second = 0;
    }
}
/*----------------------------------------------------------------------------*/
void Clock__Setting__Increment_Minute( const Clock* Me )
{
    if( My_Minute < 59 )
    {
        My_Minute++;
    }
    else
    {
        My_Minute = 0;
    }
}
/*----------------------------------------------------------------------------*/
void Clock__Setting__Increment_Hour( const Clock* Me )
{
    if( My_Hour < 23 )
    {
        My_Hour++;
    }
    else
    {
        My_Hour = 0;
    }
}
/*----------------------------------------------------------------------------*/
void Clock__Setting__Increment_Day( const Clock* Me )
{
    Increment_Clock_Day(Me);
}
/*----------------------------------------------------------------------------*/
void Clock__Setting__Decrement_Second( const Clock* Me )
{
   if( My_Second > 0 )
    {
        My_Second--;
    }
    else
    {
        My_Second = 59;
    }
}
/*----------------------------------------------------------------------------*/
void Clock__Setting__Decrement_Minute( const Clock* Me )
{
    if( My_Minute > 0 )
    {
        My_Minute--;
    }
    else
    {
        My_Minute = 59;
    }
}
/*----------------------------------------------------------------------------*/
void Clock__Setting__Decrement_Hour( const Clock* Me )
{
    if( My_Hour > 0 )
    {
        My_Hour--;
    }
    else
    {
        My_Hour = 23;
    }
}
/*----------------------------------------------------------------------------*/
void Clock__Setting__Decrement_Day( const Clock* Me )
{
    if( MONDAY==My_Day  )
    {
        My_Day = SUNDAY;
    }
    else if( TUESDAY==My_Day )
    {
        My_Day = MONDAY;
    }
    else if( WEDNESDAY==My_Day )
    {
        My_Day = TUESDAY;
    }
    else if( THURSDAY==My_Day )
    {
        My_Day = WEDNESDAY;
    }
    else if( FRIDAY==My_Day )
    {
        My_Day = THURSDAY;
    }
    else if( SATURDAY==My_Day )
    {
        My_Day = FRIDAY;
    }
    else /* SUNDAY */
    {
        My_Day = SATURDAY;        
    }
}
/*----------------------------------------------------------------------------*/
void Clock__Data__Get_Date(
    const Clock* Me,
    E_Day* day,
    uint8_t* hour,
    uint8_t* minute,
    uint8_t* second )
{
    *day = My_Day;
    *hour = My_Hour;
    *minute = My_Minute;
    *second = My_Second;
}
/*----------------------------------------------------------------------------*/
void Clock__Data__Get_Day( const Clock* Me, E_Day* day )
{
    *day = My_Day;
}
/*----------------------------------------------------------------------------*/
void Clock__Data__Get_Hour( const Clock* Me, uint8_t* hour)
{
    *hour = My_Hour;
}
/*----------------------------------------------------------------------------*/
void Clock__Data__Get_Minute( const Clock* Me, uint8_t* minute )
{
    *minute = My_Minute;
}
/*----------------------------------------------------------------------------*/
void Clock__Data__Get_Second( const Clock* Me, uint8_t* second )
{
    *second = My_Second;
}


/*============================================================================*/
/* Private methods definition */
/*============================================================================*/
static void Increment_Clock_Second( const Clock* Me )
{
   if( My_Second < 59 )
    {
        My_Second++;
    }
    else
    {
        My_Second = 0;
        Increment_Clock_Minute(Me);
    }
}
/*----------------------------------------------------------------------------*/
static void Increment_Clock_Minute( const Clock* Me )
{
    if( My_Minute < 59 )
    {
        My_Minute++;
    }
    else
    {
        My_Minute = 0;
        Increment_Clock_Hour(Me);
    }
}
/*----------------------------------------------------------------------------*/
static void Increment_Clock_Hour( const Clock* Me )
{
    if( My_Hour < 23 )
    {
        My_Hour++;
    }
    else
    {
        My_Hour = 0;
        Increment_Clock_Day(Me);
    }
}
/*----------------------------------------------------------------------------*/
static void Increment_Clock_Day( const Clock* Me )
{
    if( MONDAY==My_Day )
    {
        My_Day = TUESDAY;
    }
    else if( TUESDAY==My_Day )
    {
        My_Day = WEDNESDAY;
    }
    else if( WEDNESDAY==My_Day )
    {
        My_Day = THURSDAY;
    }
    else if( THURSDAY==My_Day )
    {
        My_Day = FRIDAY;
    }
    else if( FRIDAY==My_Day )
    {
        My_Day = SATURDAY;
    }
    else if( SATURDAY==My_Day )
    {
        My_Day = SUNDAY;
    }
    else /* SUNDAY */
    {
        My_Day = MONDAY;
    }
}