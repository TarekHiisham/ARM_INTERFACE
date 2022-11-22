#include "LSTD_TYPES.h"
#include "MGPIO_interface.h"
#include "HLED_interface.h"
#include "HLED_cfg.h"

void hled_ON (u8_t au8_Led)
{

    /*switching on Led*/
    switch (au8_Led)
    {

    /*case LED 1*/        
    case LED1:

        mgpio_SetPinStatus(PORTF , PIN1 , OUTPUT);
        mgpio_SetPinValue (PORTF , PIN1 , HIGH);
    
        /*Breaking switch*/
        break;

    /*case LED 2*/            
    case LED2:
    
        mgpio_SetPinStatus(PORTF , PIN2 , OUTPUT);
        mgpio_SetPinValue (PORTF , PIN2 , HIGH);
    
        /*Breaking switch*/
        break;

    /*case LED 3*/        
    case LED3:

        mgpio_SetPinStatus(PORTF , PIN3 , OUTPUT);
        mgpio_SetPinValue (PORTF , PIN3 , HIGH);
        
        /*Breaking switch*/
        break;

    default:
        break;
    }

/*Return Function*/
return;
} 

void hled_OFF (u8_t au8_Led)
{

    /*switching on Led*/
    switch (au8_Led)
    {

    /*case LED 1*/    
    case LED1:

        mgpio_SetPinStatus(PORTF , PIN1 , OUTPUT);
        mgpio_SetPinValue (PORTF , PIN1 , LOW);
    
        /*Breaking switch*/
        break;

    /*case LED 2*/        
    case LED2:
    
        mgpio_SetPinStatus(PORTF , PIN2 , OUTPUT);
        mgpio_SetPinValue (PORTF , PIN2 , LOW);
    
        /*Breaking switch*/
        break;

    /*case LED 3*/    
    case LED3:

        mgpio_SetPinStatus(PORTF , PIN3 , OUTPUT);
        mgpio_SetPinValue (PORTF , PIN3 , LOW);
        
        /*Breaking switch*/
        break;

    default:
        break;
    }
    
/*Return Function*/
return;
} 

void hled_TOGGLE (u8_t au8_Led)
{

		/*switching on Led*/
		switch (au8_Led)
    {
    
    /*case LED 1*/    
    case LED1:

        mgpio_SetPinStatus(PORTF , PIN1 , OUTPUT);
        mgpio_TogglePinValue (PORTF , PIN1 );
    
        /*Breaking switch*/
        break;
    
    /*case LED 2*/    
    case LED2:
    
        mgpio_SetPinStatus(PORTF , PIN2 , OUTPUT);
        mgpio_TogglePinValue (PORTF , PIN2 );
    
        /*Breaking switch*/
        break;

    /*case LED 3*/    
    case LED3:

        mgpio_SetPinStatus(PORTF , PIN3 , OUTPUT);
        mgpio_TogglePinValue (PORTF , PIN3 );
        
        /*Breaking switch*/
        break;

    default:
        break;
    }
    
/*Return Function*/
return;
} 

