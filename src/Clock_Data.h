#ifndef CLOCK_DATA_H
#define CLOCK_DATA_H

/* Data type */
#include <stdint.h>
#include "E_Day.h"


/*============================================================================*/
/* Client_Server_Interface */
/*============================================================================*/
typedef struct {
    void (*Get_Date) (
        E_Day* day,
        uint8_t* hour,
        uint8_t* minute,
        uint8_t* second );
    void( *Get_Day) ( E_Day* day );
    void (*Get_Hour) ( uint8_t* hour );
    void (*Get_Minute) ( uint8_t* minute );
    void (*Get_Second) ( uint8_t* second );
} Clock_Data;

#endif