/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MSYSCLK_PRIVATE
 *       Module:  System clock Registers
 *
 *  Description:  This file to define address of Registers     
 *  
 *********************************************************************************************************************/

#ifndef __MSYSCLK_PRIVATE_H__
#define __MSYSCLK_PRIVATE_H__



#define CLK_REG_BASE            (0x400FE000)

/**********************************************************************************************************************
 *  GLOBAL REGISTERS
 *********************************************************************************************************************/

/*Run-Mode Clock Configuration (RCC)*/
#define RCC                         *((volatile u32_t *)(CLK_REG_BASE + 0x060))

/* Run-Mode Clock Configuration 2 (RCC2)*/
#define RCC2                        *((volatile u32_t *)(CLK_REG_BASE + 0x070))

/*Main Oscillator Control (MOSCCTL)*/
#define MOSCCTL                     *((volatile u32_t *)(CLK_REG_BASE + 0x07C))

/*Raw Interrupt Status (RIS)*/
#define RIS                         *((volatile u32_t *)(CLK_REG_BASE + 0x050))

/*General-Purpose Input/Output Deep-Sleep Mode Clock Gating Control (DCGCGPIO)*/
#define DCGCGPIO                    *((volatile u32_t *)(CLK_REG_BASE + 0x608))



#endif  /* __MSYSCLK_PRIVATE_H__ */

/**********************************************************************************************************************
 *  END OF FILE: MSYSCLK_PRIVATE.h
 *********************************************************************************************************************/
