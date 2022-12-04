/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MPIO_PRIVATE
 *       Module:  Inpot Output Peripheral
 *
 *  Description:  This file to define address of Registers     
 *  
 *********************************************************************************************************************/
#ifndef __MGPIO_PRIVATE_H__
#define __MGPIO_PRIVATE_H__

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SHIFTTING_BIT_MASK                    (2)
/*GPIO PORTS ADD (APB)*/
#define GPIO_PORTF_Base_ADDR                  (0x40025000)

/**********************************************************************************************************************
 *  GLOBAL REGISTERS
 *********************************************************************************************************************/

/* GPIO Direction (GPIODIR)*/
#define PORTF_GPIODIR                     *((volatile u32_t *)(GPIO_PORTF_Base_ADDR + 0x400))

/* GPIO Digital Enable (GPIODEN)*/
#define PORTF_GPIODEN                     *((volatile u32_t *)(GPIO_PORTF_Base_ADDR + 0x51C))

/*GPIO Data (GPIODATA)*/
#define PORTF_GPIODATA(PIN)               *((volatile u32_t *)(GPIO_PORTF_Base_ADDR | (PIN << SHIFTTING_BIT_MASK)))

/* GPIO Interrupt Sense (GPIOIS)*/
#define PORTF_GPIOIS                      *((volatile u32_t *)(GPIO_PORTF_Base_ADDR + 0x404))

/*GPIO Interrupt Mask (GPIOIM)*/
#define PORTF_GPIOIM                      *((volatile u32_t *)(GPIO_PORTF_Base_ADDR + 0x410))

/*GPIO Interrupt Both Edges (GPIOIBE)*/
#define PORTF_GPIOIBE                     *((volatile u32_t *)(GPIO_PORTF_Base_ADDR + 0x408))

/*GPIO Lock (GPIOLOCK)*/
#define PORTF_GPIOLOCK                    *((volatile u32_t *)(GPIO_PORTF_Base_ADDR + 0x520))

/*: GPIO Masked Interrupt Status (GPIOMIS)*/
#define PORTF_GPIOMIS                     *((volatile u32_t *)(GPIO_PORTF_Base_ADDR + 0x418))

/*GPIO Interrupt Clear (GPIOICR)*/
#define PORTF_GPIOICR                     *((volatile u32_t *)(GPIO_PORTF_Base_ADDR + 0x41C))

#endif  /* __MGPIO_PRIVATE_H__ */

/**********************************************************************************************************************
 *  END OF FILE: MGPIO_PRIVATE.h
 *********************************************************************************************************************/
