#include "LSTD_TYPES.h"
#include "MSYSCLK_interface.h"
#include "MSYSTICK_interface.h"
#include "MINT_interface.h"
#include "MGPIO_interface.h"
#include "HLED_interface.h"
#include "HSWITCH_interface.h"

void init_system(void);
void Led_off (void) ;
void Led_on (void) ;
void Blinkled(u8_t au8_timeON_S , u8_t au8_timeOFF_s);

/*using two static variables to detrmine time on and off for blinking*/
static u8_t TIME_ON  = 2  ;
static u8_t TIME_OFF = 4 ;  

void Action_1(void)
{
  TIME_ON ++ ; 
  TIME_OFF-- ;
}
void Action_2(void)
{
  TIME_ON -- ; 
  TIME_OFF++ ;
}
void Led_off (void)
{
   	
    hled_OFF(LED1);
    msystick_asydelay(TIME_OFF , Led_on);
	
}

void Led_on (void)
{

     hled_ON(LED1);
     msystick_asydelay(TIME_ON , Led_off);
	  
}

void Blinkled(u8_t au8_timeON_S , u8_t au8_timeOFF_S)
{
  TIME_OFF = au8_timeOFF_S ;
  TIME_ON = au8_timeON_S ;

  Led_off();

  return ;
}

void init_system(void)
{
    /*setting clk to system*/
		/*setting by default in simulation*/
    /*msysclk_init();*/
    
		/*Enable global interrupts*/
		interrupts_init();  
	
    /*enable interrupt to systick when overflow*/
		interrupts_Enable(SYSTICK);

    /*enable clk to gpio*/
    msysclk_EnableGPIO(PORTF);
	  
    /*initialize system timer*/
    msystick_init();

		/*Enable External Interrupt for PORT F IN NVIC*/
	  interrupts_Enable(GPIO_PORTF);

		/*Enable interrupts from PIN4 and PIN0*/
  	mgpio_enableinterrupt(PORTF , PIN4 ,BOTH_EDGES);
		mgpio_enableinterrupt(PORTF , PIN0 ,BOTH_EDGES);
		
		/*initializing Led 1*/
		hled_init(LED1);
	
	  /*initializing switch 1*/
		hswitch_init(switch1);
	
		/*initializing switch 2*/
		hswitch_init(switch2);

  /*Return Function*/
  return ;
}

int main(void)

{
   	/*initialization the system*/
    init_system();

    /*setting action would trigger when interrupt from gpio*/
    mgpio_takeAction(Action_1 , Action_2);
    
    /*beginnig program*/
    Blinkled( TIME_ON , TIME_OFF ) ;
    
		while(1);
}

