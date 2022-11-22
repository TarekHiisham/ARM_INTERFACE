#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MSYSCLK_private.h"
#include "MSYSCLK_interface.h"

void msysclk_init(void)
{
    /*initializing PLL and configuration*/
    RCC  |= 0x0F800FC0 ;
    RCC2 |= 0x80000000 ;

    /*polling to lock PLL*/
    while(!(GET_BIT(RIS , 6 )));

    /*Enable use PLL*/
    RCC  |= 0x00000000 ;
    RCC2 |= 0x00000000 ;

    /*Enabe use main occilator*/
    MOSCCTL |= 0x00000001 ;
    return ;
}

void msysclk_EnableGPIO(u8_t au8_Portx)
{
    switch (au8_Portx)
    {

    case PORTF:

        /*Enabling clk to PORTA*/
        DCGCGPIO |= 0x20 ;
    
        /*Breaking switch case*/
        break;
    
    default:
        break;
    }

    return ;
}
