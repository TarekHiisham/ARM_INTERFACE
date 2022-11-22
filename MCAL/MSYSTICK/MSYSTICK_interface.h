/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MSYSTICK_interface.h
 *       Module:  System Timer
 *
 *  Description:  This file to interface System Timer 
 *               
 *                    
 *  
 *********************************************************************************************************************/

#ifndef __MSYSTICK_interface_H__
#define __MSYSTICK_interface_H__


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**
 * @brief This Finction initialize system Timer 
 * 
 */
void msystick_init(void);

/**
 * @brief This Function to make interrupt after asynchronous time
 * 
 * @param time_s 
 * @param fptr_function 
 */
void msystick_asydelay(u8_t time_s , void(*fptr_function)(void));


#endif  /* __MSYSTICK_interface_H__ */

/**********************************************************************************************************************
 *  END OF FILE: MSYSTICK_interface_H
 *********************************************************************************************************************/
