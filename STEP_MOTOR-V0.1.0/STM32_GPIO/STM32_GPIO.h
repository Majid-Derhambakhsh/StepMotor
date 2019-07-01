/*
------------------------------------------------------------------------------
~ File   : STM32_GPIO.h
~ Author : Majid Derhambakhsh
~ Version: V0.1.0
~ Created: 06/29/2019 04:47:00 AM
~ Brief  :
~ Support: Majid.do16@gmail.com
------------------------------------------------------------------------------
~ Description:

~ Attention  :

~ Changes    :
				Add : HAL_GPIO_ReadRegister Function for read data of register
				Add : CONFIG header for Set HAL DRIVER
------------------------------------------------------------------------------
*/

#ifndef __STM32_GPIO_H_
#define __STM32_GPIO_H_

/* ------------------------------------- Includes ------------------------------------- */

#include "STM32_GPIO_CONFIG.h" /* Import config file */
#include <stdint.h> /* Import standard int */

/* ------------------------------------------------------- */

#ifdef USE_HAL_DRIVER  /* Check compiler */

#include _STM32_HAL_DRIVER        /* Import HAL library */

#endif /* USE_HAL_DRIVER */

/* ------------------------------------- Enum ------------------------------------- */

typedef enum /* Enum for define registers */
{
	
	_GPIO_CONFIGURATION_REGISTER_LOW   = 0, /* CRL Register */
	_GPIO_CONFIGURATION_REGISTER_HIGH  = 1, /* CRH Register */
	_GPIO_INPUT_DATA_REGISTER		   = 2, /* IDR Register */
	_GPIO_OUTPUT_DATA_REGISTER		   = 3, /* ODR Register */
	_GPIO_BIT_SET_RESET_REGISTER	   = 4, /* BSRR Register */
	_GPIO_BIT_RESET_REGISTER		   = 5, /* BRR Register */
	_CONFIGURATION_LOCK_REGISTER	   = 6  /* LCKR Register */
	
}GPIO_RegisterNameTypeDef;

/* ------------------------------------ Prototypes ------------------------------------ */

uint32_t HAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx); /* This function is for read all data in GPIOx */
/* Example :
			
			uint32_t port_value;
			
			port_value = HAL_GPIO_ReadPort( GPIOB );

*/

uint32_t HAL_GPIO_ReadRegister(GPIO_TypeDef *GPIOx , GPIO_RegisterNameTypeDef REGISTERx); /* This function is for read all data in GPIOx , Registerx */
/* Example :
			
			uint32_t register_value;
			
			register_value = HAL_GPIO_ReadRegister( GPIOB , _GPIO_OUTPUT_DATA_REGISTER);
			
			REGISTERx is this values
			
										_GPIO_CONFIGURATION_REGISTER_LOW
										_GPIO_CONFIGURATION_REGISTER_HIGH
										_GPIO_INPUT_DATA_REGISTER
										_GPIO_OUTPUT_DATA_REGISTER
										_GPIO_BIT_SET_RESET_REGISTER
										_GPIO_BIT_RESET_REGISTER
										_CONFIGURATION_LOCK_REGISTER
										
*/

#endif /* __STM32_GPIO_H_ */
