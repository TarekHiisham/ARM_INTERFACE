#include "LSTD_TYPES.h"
#include "MSYSCLK_interface.h"
#include "MSYSTICK_interface.h"
#include "MINT_interface.h"
#include "MGPIO_interface.h"
#include "HLED_interface.h"

void init_system(void);
void Led_off (void) ;
void Led_on (void) ;
void Blinkled(u8_t au8_timeON_S , u8_t au8_timeOFF_s);

/*using two static variables to detrmine time on and off for blinking*/
static u8_t TIME_ON  ;
static u8_t TIME_OFF ;       

void Led_off (void)
{
   	
    hled_OFF(LED1);
    msystick_asydelay(TIME_OFF , Led_on);

    return ; 
}

void Led_on (void)
{

     hled_ON(LED1);
     msystick_asydelay(TIME_ON , Led_off);
    
    return ;
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
	
  /*Return Function*/
  return ;
}

int main(void)
{
   	/*initialization the system*/
    init_system();

    /*beginnig program*/
    Blinkled( 3 , 5 ) ;

    while(1);

}

