#include "Clock.h"

/**************************************************************************************************/
/* Constructor */
Clock::Clock( i_Microcontroller_Timestamp* microcontroller_timestamp )
{
    this->Microcontroller_Timestamp = microcontroller_timestamp;
    this->clock_timestamp = 0;
    this->day = MONDAY;
    this->hour = 0; 
    this->minute = 0;
    this->second = 0;
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Component_Type_Operations */
void Clock::Tick( void )
{
    uint32_t micro_timestamp = 0;
    uint32_t elapsed_time;
	static uint32_t time_carrier = 0;
	
    /* Get microcotroller timestamp */
    this->Microcontroller_Timestamp->Get_Timestamp_Ms( &micro_timestamp );                             

    /* Compute ellapsed time since last call of Clock_Tick() */
    elapsed_time = time_carrier + micro_timestamp - this->clock_timestamp;

    /* If at least one second has ellapsed */
    if( elapsed_time >= 1000 )
    {
        
		time_carrier = elapsed_time - 1000;
		/* Update clock */
        Increment_Clock_Second();
        this->clock_timestamp = micro_timestamp;
    }
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Event reception points accessors */
/**************************************************************************************************/


/**************************************************************************************************/
/* Provided port accessors */
/**************************************************************************************************/
i_Clock_Data* Clock::Get_Port__Clock_Data( void )
{
    return (i_Clock_Data*)(this);
}
/*------------------------------------------------------------------------------------------------*/
i_Clock_Settings* Clock::Get_Port__Settings( void )
{
    return (i_Clock_Settings*)(this);
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Private methods */
/**************************************************************************************************/
void Clock::Increment_Clock_Second( void )
{
   if( this->second < 59 )
    {
        this->second++;
    }
    else
    {
        this->second = 0;
        Increment_Clock_Minute();
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Increment_Clock_Minute( void )
{
    if( this->minute < 59 )
    {
        this->minute++;
    }
    else
    {
        this->minute = 0;
        Increment_Clock_Hour();
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Increment_Clock_Hour( void )
{
    if( this->hour < 23 )
    {
        this->hour++;
    }
    else
    {
        this->hour = 0;
        Increment_Clock_Day();
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Increment_Clock_Day( void )
{
    if( this->day == MONDAY )
    {
        this->day = TUESDAY;
    }
    else if( this->day == TUESDAY )
    {
        this->day = WEDNESDAY;
    }
    else if( this->day == WEDNESDAY )
    {
        this->day = THURSDAY;
    }
    else if( this->day == THURSDAY )
    {
        this->day = FRIDAY;
    }
    else if( this->day == FRIDAY )
    {
        this->day = SATURDAY;
    }
    else if( this->day == SATURDAY )
	{
        this->day = SUNDAY;
    }
	else /* SUNDAY */
    {
        this->day = MONDAY;
    }
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Provided operations */
/**************************************************************************************************/
/* Clock_Settings:i_Clock_Settings */
/**************************************************************************************************/
void Clock::Increment_Second( void )
{
   if( this->second < 59 )
    {
        this->second++;
    }
    else
    {
        this->second = 0;
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Increment_Minute( void )
{
    if( this->minute < 59 )
    {
        this->minute++;
    }
    else
    {
        this->minute = 0;
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Increment_Hour( void )
{
    if( this->hour < 23 )
    {
        this->hour++;
    }
    else
    {
        this->hour = 0;
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Increment_Day( void )
{
    this->Increment_Clock_Day();
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Decrement_Second( void )
{
   if( this->second > 0 )
    {
        this->second--;
    }
    else
    {
        this->second = 59;
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Decrement_Minute( void )
{
    if( this->minute > 0 )
    {
        this->minute--;
    }
    else
    {
        this->minute = 59;
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Decrement_Hour( void )
{
    if( this->hour > 0 )
    {
        this->hour--;
    }
    else
    {
        this->hour = 23;
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Decrement_Day( void )
{
    if( this->day == MONDAY )
    {
        this->day = SUNDAY;
    }
    else if( this->day == TUESDAY )
    {
        this->day = MONDAY;
    }
    else if( this->day == WEDNESDAY )
    {
        this->day = TUESDAY;
    }
    else if( this->day == THURSDAY )
    {
        this->day = WEDNESDAY;
    }
    else if( this->day == FRIDAY )
    {
        this->day = THURSDAY;
    }
    else if( this->day == SATURDAY )
    {
        this->day = FRIDAY;
    }
	else /* SUNDAY */
	{
        this->day = SATURDAY;		
	}
}
/**************************************************************************************************/
/* Clock_Data:i_Clock */
/**************************************************************************************************/
void Clock::Get_Date( 
    E_DAY* day, uint8_t* hour, uint8_t* minute, uint8_t* second )
{
    *day = this->day;
    *hour = this->hour;
    *minute = this->minute;
    *second = this->second;
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Get_Day( E_DAY* day )
{
    *day = this->day;
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Get_Hour( uint8_t* hour)
{
    *hour = this->hour;
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Get_Minute( uint8_t* minute )
{
    *minute = this->minute;
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Get_Second( uint8_t* second )
{
    *second = this->second;
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Received events */
/**************************************************************************************************/