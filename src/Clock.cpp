#include "Clock.h"

/**************************************************************************************************/
/* Constructor */
Clock::Clock( i_Microcontroller_Timestamp* microcontroller_timestamp )
{
    this->Microcontroller_Timestamp = microcontroller_timestamp;
    this->Clock_Settings = Clock_Settings_Class(this);
    this->clock_timestamp = 0;
    this->day = MONDAY;
    this->hour = 0; 
    this->minute = 0;
    this->second = 0;
    this->Clock_Data = Clock_Data_Class(this);
    this->Clock_Settings = Clock_Settings_Class(this);
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Component_Type_Operations */
void Clock::Tick( void )
{
    uint32_t micro_timestamp = 0;
    uint32_t ellapsed_time;
	static uint32_t time_carrier = 0;
	
    /* Get microcotroller timestamp */
    this->Microcontroller_Timestamp->Get_Timestamp_Ms( &micro_timestamp );                             

    /* Compute ellapsed time since last call of Clock_Tick() */
    ellapsed_time = time_carrier + micro_timestamp - this->clock_timestamp;

    /* If at least one second has ellapsed */
    if( ellapsed_time >= 1000 )
    {
        
		time_carrier = ellapsed_time -1000;
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
    return (i_Clock_Data*)&(this->Clock_Data);
}
/*------------------------------------------------------------------------------------------------*/
i_Clock_Settings* Clock::Get_Port__Settings( void )
{
    return (i_Clock_Settings*)&(this->Clock_Settings);
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
void Clock::Clock_Settings_Class::Increment_Second( void )
{
   if( this->parent->second < 59 )
    {
        this->parent->second++;
    }
    else
    {
        this->parent->second = 0;
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Clock_Settings_Class::Increment_Minute( void )
{
    if( this->parent->minute < 59 )
    {
        this->parent->minute++;
    }
    else
    {
        this->parent->minute = 0;
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Clock_Settings_Class::Increment_Hour( void )
{
    if( this->parent->hour < 23 )
    {
        this->parent->hour++;
    }
    else
    {
        this->parent->hour = 0;
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Clock_Settings_Class::Increment_Day( void )
{
    this->parent->Increment_Day();
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Clock_Settings_Class::Decrement_Second( void )
{
   if( this->parent->second > 0 )
    {
        this->parent->second--;
    }
    else
    {
        this->parent->second = 59;
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Clock_Settings_Class::Decrement_Minute( void )
{
    if( this->parent->minute > 0 )
    {
        this->parent->minute--;
    }
    else
    {
        this->parent->minute = 59;
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Clock_Settings_Class::Decrement_Hour( void )
{
    if( this->parent->hour > 0 )
    {
        this->parent->hour--;
    }
    else
    {
        this->parent->hour = 23;
    }
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Clock_Settings_Class::Decrement_Day( void )
{
    if( this->parent->day == MONDAY )
    {
        this->parent->day = SUNDAY;
    }
    else if( this->parent->day == TUESDAY )
    {
        this->parent->day = MONDAY;
    }
    else if( this->parent->day == WEDNESDAY )
    {
        this->parent->day = TUESDAY;
    }
    else if( this->parent->day == THURSDAY )
    {
        this->parent->day = WEDNESDAY;
    }
    else if( this->parent->day == FRIDAY )
    {
        this->parent->day = THURSDAY;
    }
    else if( this->parent->day == SATURDAY )
    {
        this->parent->day = FRIDAY;
    }
	else /* SUNDAY */
	{
        this->parent->day = SATURDAY;		
	}
}
/**************************************************************************************************/
/* Clock_Data:i_Clock */
/**************************************************************************************************/
void Clock::Clock_Data_Class::Get_Date( 
    E_DAY* day, uint8_t* hour, uint8_t* minute, uint8_t* second )
{
    *day = this->parent->day;
    *hour = this->parent->hour;
    *minute = this->parent->minute;
    *second = this->parent->second;
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Clock_Data_Class::Get_Day( E_DAY* day )
{
    *day = this->parent->day;
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Clock_Data_Class::Get_Hour( uint8_t* hour)
{
    *hour = this->parent->hour;
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Clock_Data_Class::Get_Minute( uint8_t* minute )
{
    *minute = this->parent->minute;
}
/*------------------------------------------------------------------------------------------------*/
void Clock::Clock_Data_Class::Get_Second( uint8_t* second )
{
    *second = this->parent->second;
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Received events */
/**************************************************************************************************/