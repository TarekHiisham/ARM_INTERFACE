#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MSYSTICK_private.h"
#include "MSYSTICK_cfg.h"
#include "MSYSTICK_interface.h"

static void(*gptr_function)(void) = NULL ;
static u8_t  gtime_s = 0 ;

void msystick_init(void)
{
    /*Disable The Timer to configure*/
    STCTRL = TIMER_STOP ;

    /*Enable Interrupt and select clock Mode*/
    STCTRL |= INT_ENABLE ;

    /*Reloaded The value "minimum default one second" */
     STRELOAD  = 50 ;  
	//STRELOAD  = DEFAULT_1s ;

    /*Clear the STCURRENT register by writing to it with any value*/
    STCURRENT = CLEAR_VAL ;  

    /*Return from Function*/
    return;
}

void msystick_asydelay(u8_t time_s , void(*fptr_function)(void))
{
    gptr_function = fptr_function ;
    gtime_s = time_s ;

    /*Start counting*/
    STCTRL |= TIMER_START ;  

    /*Return from Function*/
    return;
}

void SysTick_Handler(void)
{
    static u8_t au8_counter = 0 ;
    au8_counter++ ;

    if(au8_counter == gtime_s)
    {
        if( gptr_function != NULL )
        {
        gptr_function(); 
        au8_counter = 0 ;
        }
        else
        {
            /*Do Nothing*/
        } 
    }
    else
    {
        /*Do Nothing*/
    }

}