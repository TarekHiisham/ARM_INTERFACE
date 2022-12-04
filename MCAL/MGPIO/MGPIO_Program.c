#include "LSTD_TYPES.h"
#include "MGPIO_private.h"
#include "MGPIO_cfg.h"
#include "MGPIO_interface.h"

static void(*gptr_function1)(void) = NULL;
static void(*gptr_function2)(void) = NULL;

void mgpio_SetPinStatus(u8_t au8_Port , u8_t au8_Pin , u8_t au8_Status)
{
    /*checking the port by if elif */
    if(au8_Port == PORTF)
    { 
        /*switching on value*/
        switch (au8_Status)
            {
            case OUTPUT:

                /*setting Pin Direction*/
                PORTF_GPIODIR |= au8_Pin ;

                /*Enable Pin as digital I/O*/
                PORTF_GPIODEN |= au8_Pin ; 
                
                /*Breaking Switch*/
                break;

            case INPUT:

                /*setting Pin Direction*/
                PORTF_GPIODIR &= (~au8_Pin) ;

                /*Enable Pin as digital I/O*/
                PORTF_GPIODEN |= au8_Pin ; 

                /*Breaking Switch*/
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
        if((PORTF_GPIODATA (au8_Pin) & (u32_t)au8_Pin) == (0xFFFF & (u32_t)au8_Pin ))
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

void mgpio_enableinterrupt (u8_t au8_Port , u8_t au8_Pin , u8_t au8_Mode )
{
    if (au8_Port == PORTF)
    {

        switch (au8_Mode)
        {

        case BOTH_EDGES:

            PORTF_GPIOLOCK &= 0 ;
            PORTF_GPIOIM   |= 0x00  ;
            PORTF_GPIOIS   |= au8_Pin ;
            PORTF_GPIOIBE  |= au8_Pin ;
            PORTF_GPIOIM   |= au8_Pin  ;

            break;
        
        default:
            break;
        }
    }

    /*Return Function*/
    return;
}
void mgpio_takeAction( void(*ptr_action2)(void) , void(*ptr_action1)(void))
{
    gptr_function1 = ptr_action1 ;
    gptr_function2 = ptr_action2 ;

    return ;
}

void GPIOF_Handler(void)
{
    if((PORTF_GPIOMIS & 0x01) == 0x01)
    {
        gptr_function1(); 
        PORTF_GPIOICR |= 0x01 ;
    }
    else if((PORTF_GPIOMIS & 0x10) == 0x10)
    {
        gptr_function2(); 
        PORTF_GPIOICR |= 0x10 ;
    }
}