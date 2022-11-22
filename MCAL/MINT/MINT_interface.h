/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MINT_interface.h
 *       Module:  Interrupts
 *
 *  Description:  This file to interface intterupts and exceptions 
 *                from external periphrals 
 *                    
 *  
 *********************************************************************************************************************/

#ifndef  __MINT_interface_H__
#define  __MINT_interface_H__
 
 
enum vect_num 
{
    SYSTICK = 15 
};

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**
 * @brief This Function to init global interrupts by classifying them to Groups / SubGroups
 * 
 */
void interrupts_init(void);

/**
 * @brief This Function Enable Specfied Interrupt for Peripheral
 * 
 * @param au8_interruptPeripheral 
 */
void interrupts_Enable(u8_t au8_interruptPeripheral);

 
#endif  /* __MINT_interface_H__ */

/**********************************************************************************************************************
 *  END OF FILE: MINT_interface_H
 *********************************************************************************************************************/
