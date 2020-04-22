#ifndef CLOCK_SETTING_H
#define CLOCK_SETTING_H


/*============================================================================*/
/* Client_Server_Interface */
/*============================================================================*/
typedef struct {
    void (*Increment_Day) ( void );
    void (*Increment_Hour) ( void );
    void (*Increment_Minute) ( void );
    void (*Increment_Second) ( void );
    void (*Decrement_Day) ( void );
    void (*Decrement_Hour) ( void );
    void (*Decrement_Minute) ( void );
    void (*Decrement_Second) ( void );
} Clock_Setting;

#endif