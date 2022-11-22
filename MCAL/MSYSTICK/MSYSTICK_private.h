/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MSYSTICK_PRIVATE
 *       Module:  System Timer Registers address
 *
 *  Description:  This file to define address of Registers     
 *  
 *********************************************************************************************************************/

#ifndef __MSYSTICK_PRIVATE_H__
#define __MSYSTICK_PRIVATE_H__


#define SYSTICK_BASE_ADD            (0xE000E000)

/**********************************************************************************************************************
 *  GLOBAL REGISTERS
 *********************************************************************************************************************/

/*SysTick Control and Status Register (STCTRL)*/
#define STCTRL                     *((volatile u32_t*)(SYSTICK_BASE_ADD + 0x010))

/* SysTick Reload Value Register (STRELOAD)*/
#define STRELOAD                   *((volatile u32_t*)(SYSTICK_BASE_ADD + 0x014))

/*SysTick Current Value Register (STCURRENT)*/
#define STCURRENT                  *((volatile u32_t*)(SYSTICK_BASE_ADD + 0x018))


#endif  /* __MSYSTICK_PRIVATE_H__ */

/**********************************************************************************************************************
 *  END OF FILE: MSYSTICK_PRIVATE.h
 *********************************************************************************************************************/
