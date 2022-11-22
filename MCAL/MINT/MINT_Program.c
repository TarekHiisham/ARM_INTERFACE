#include "LSTD_TYPES.h"
#include "MINT_private.h"
#include "MINT_cfg.h"
#include "MINT_interface.h"


void interrupts_init(void)
{
    /*choose priority Group number and subgroup*/
    APINT = 0x05FA | GROUP1_SUB8   ;

    /*setting priority of Subgroup for SYSTICK*/
    PRI(3) |= 0x0 ;
    
    /*Return Function*/
    return;
}

void interrupts_Enable(u8_t au8_interruptPeripheral)
{
    
    /*switching on interrupt number in vector table to enable it*/
    switch (au8_interruptPeripheral)
    {
    case SYSTICK :

        /*enabling intterupts comes from systick Timer */
        EN(0) |=  0x00008000  ;

        /*Breaking switch*/
        break;
       
    default:
        break;
    }

    return ;
}

