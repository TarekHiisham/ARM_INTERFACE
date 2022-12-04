#include "LSTD_TYPES.h"
#include "MGPIO_interface.h"
#include "HSWITCH_interface.h"

void hswitch_init(u8_t au8_switch)
{
    switch (au8_switch)
    {
    case switch1:
 
        mgpio_SetPinStatus(PORTF , PIN4 , INPUT);

        break;
    case switch2:

        mgpio_SetPinStatus(PORTF , PIN0 , INPUT);

        break;
 
    default:
        break;
    }
    return;
}


void hswitch_status (u8_t au8_switch , u8_t* pu8_status)
{
    switch (au8_switch)
    {
    case switch1:
 
        mgpio_GetPinValue(PORTF , PIN4 , pu8_status);

        break;
    case switch2:

        mgpio_GetPinValue(PORTF , PIN0 , pu8_status);

        break;
 
    default:
        break;
    }


}
