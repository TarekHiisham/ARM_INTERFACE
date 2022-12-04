/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MGPIO_interface.h
 *       Module:  Input Output Peripheral
 *
 *  Description:  This file to interface GPIO 
 *                
 *                    
 *  
 *********************************************************************************************************************/

#ifndef  __MGPIO_interface_H__
#define  __MGPIO_interface_H__

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#define PORTA        (0)
#define PORTB        (1)
#define PORTC        (2)
#define PORTD        (3)
#define PORTE        (4)
#define PORTF        (5)

#define PIN0         (0x1)          
#define PIN1         (0x2)          
#define PIN2         (0x4)          
#define PIN3         (0x8)          
#define PIN4         (0x10)         
#define PIN5         (0x20)         
#define PIN6         (0x40)         
#define PIN7         (0x80)         

#define INPUT                (0)
#define OUTPUT               (1)

#define LOW                  (0) 
#define HIGH                 (1) 

#define BOTH_EDGES           (0)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void mgpio_SetPinStatus (u8_t au8_Port , u8_t au8_Pin , u8_t au8_Status);

void mgpio_SetPinValue  (u8_t au8_Port , u8_t au8_Pin , u8_t  au8_Value);

void mgpio_GetPinValue  (u8_t au8_Port , u8_t au8_Pin , u8_t* au8_Value);

void mgpio_TogglePinValue (u8_t au8_Port , u8_t au8_Pin );

void mgpio_enableinterrupt (u8_t au8_Port , u8_t au8_Pin , u8_t au8_Mode);

void mgpio_takeAction( void(*ptr_action2)(void) , void(*ptr_action1)(void));
 
#endif  /* __MGPIO_interface_H__ */

/**********************************************************************************************************************
 *  END OF FILE: MGPIO_interface_H
 *********************************************************************************************************************/
