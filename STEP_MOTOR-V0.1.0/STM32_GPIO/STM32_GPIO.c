/*
------------------------------------------------------------------------------
~ File   : STM32_GPIO.c
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

#include "STM32_GPIO.h"

/* ----------- Functions ----------- */

uint32_t HAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx) /* This function is for read all data in GPIOx */
{
	
	return (GPIOx -> IDR); /* Return Pin state*/
	
}
/* Example :
			
			uint32_t port_value;
			
			port_value = HAL_GPIO_ReadPort( GPIOB );

*/

/* --------------------- */

uint32_t HAL_GPIO_ReadRegister(GPIO_TypeDef *GPIOx , GPIO_RegisterNameTypeDef REGISTERx) /* This function is for read all data in GPIOx , Registerx */
{
	
	switch (REGISTERx)
	{
		case _GPIO_INPUT_DATA_REGISTER:
		{
			return (GPIOx->IDR);
		}
		break;
		case _GPIO_OUTPUT_DATA_REGISTER:
		{
			return (GPIOx->ODR);
		}
		break;
		case _GPIO_CONFIGURATION_REGISTER_HIGH:
		{
			return (GPIOx->CRH);
		}
		break;
		case _GPIO_CONFIGURATION_REGISTER_LOW:
		{
			return (GPIOx->CRL);
		}
		break;
		case _GPIO_BIT_SET_RESET_REGISTER:
		{
			return (GPIOx->BSRR);
		}
		break;
		case _GPIO_BIT_RESET_REGISTER:
		{
			return (GPIOx->BRR);
		}
		break;
		case _CONFIGURATION_LOCK_REGISTER:
		{
			return (GPIOx->LCKR);
		}
		break;
		
		default:
		break;
	}
	
	return 0;
	
	/* Function End */
}
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
