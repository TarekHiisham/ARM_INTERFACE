#include "LSTD_TYPES.h"
#include "MGPIO_private.h"
#include "MGPIO_cfg.h"
#include "MGPIO_interface.h"

void mgpio_SetPinStatus(u8_t au8_Port , u8_t au8_Pin , u8_t au8_Status)
{
    /*checking the port by if elif */
    if(au8_Port == PORTF)
    { 
        /*switching on value*/
        switch (au8_Status)
            {
            case OUTPUT:

                /*Enable Pin as digital I/O*/
                PORTF_GPIODEN |= au8_Pin ; 

                /*setting Pin Direction*/
                PORTF_GPIODIR |= au8_Pin ;

                /*Breaking Switch*/
                break;

            case INPUT:

                /*Enable Pin as digital I/O*/
                PORTF_GPIODEN |= au8_Pin ; 

                /*setting Pin Direction*/
                PORTF_GPIODIR &= ~au8_Pin ;


                break;

            default:
                break;
            }
    }
    
    /*Return Function*/
    return;
}

void mgpio_SetPinValue (u8_t au8_Port , u8_t au8_Pin , u8_t  au8_Value)
{
    /*checking the port by if elif */
    if(au8_Port == PORTF)
    {
    /*switching on value*/
    switch (au8_Value)
    {
    case LOW:
        
        /*setting bit value as LOW*/
        PORTF_GPIODATA (au8_Pin)  &= (~au8_Pin) ;

        /*Breaking Switch*/
        break;

    case HIGH:

        /*setting bit value as High*/
		PORTF_GPIODATA (au8_Pin)  |= au8_Pin ;

        /*Breaking Switch*/
        break;
    
    default:
        break;
    }
    }
    /*Return Function*/
    return;

}

void mgpio_TogglePinValue (u8_t au8_Port , u8_t au8_Pin )
{       
    /*checking the port by if elif */
    if(au8_Port == PORTF)
    {
        /* togglling bit value */
        PORTF_GPIODATA(au8_Pin) ^= (au8_Pin);
    }
    
    /*Return Function*/    
    return;
}

void mgpio_GetPinValue  (u8_t au8_Port , u8_t au8_Pin , u8_t* au8_Value)
{
    /*checking the port by if elif */
    if(au8_Port == PORTF)
    { 
        /*Checking the PINx value for a specified port pin if it's LOW or not*/
        if((PORTF_GPIODATA (au8_Pin) & au8_Pin) == HIGH)
        {
            /*getting high from pin*/
            *au8_Value  = HIGH ; 
        }
        else
        {
            /*getting Low from pin*/
            *au8_Value  = LOW ; 
        }
    }
    
    /*Return Function*/
    return;

}

