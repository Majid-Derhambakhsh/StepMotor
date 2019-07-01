/*
------------------------------------------------------------------------------
~ File   : GPIO.h
~ Author : Majid Derhambakhsh
~ Version: V0.2.0
~ Created: 06/29/2019 03:57:00 AM
~ Brief  :
~ Support: Majid.do16@gmail.com
------------------------------------------------------------------------------
~ Description:

~ Attention  :

~ Changes    :
				Add : GPIO_ReadRegister Function for read data of register
------------------------------------------------------------------------------
*/

#ifndef __GPIO_H_
#define __GPIO_H_

/* ----------- Includes ----------- */

/*----------------------------------------------------------*/

#ifdef __CODEVISIONAVR__  /* Chech compiler */

#include <io.h>            /* Import AVR IO library */

/*----------------------------------------------------------*/

#elif defined(__GNUC__)   /* Chech compiler */

#include <avr/io.h>        /* Import AVR IO library */

/*----------------------------------------------------------*/

#else                     /* Compiler not found */

#error Compiler not supported  /* Send error */

#endif

/*----------------------------------------------------------*/

#include <stdint.h>

/* ------------ Define ------------ */

#define _GPIO_PIN_SET   1 /* Define for write state */
#define _GPIO_PIN_RESET 0 /* Define for write state */

/* ----------- Prototypes ----------- */

void GPIO_WritePin(uint8_t *GPIOx , uint8_t GPIO_Pin , uint8_t PinState); /* Function for write data to output */
/* Example :

 GPIO_WritePin( &PORTA , 0xFF , _GPIO_PIN_SET );
 GPIO_WritePin( &PORTA , 0xFF , _GPIO_PIN_RESET );

*/

void GPIO_ClearPin(uint8_t *GPIOx , uint8_t GPIO_Pin); /* Function for clear pin */
/* Example :

 GPIO_ClearPin( &PORTA , 2 );

*/

uint8_t GPIO_ReadPin(uint8_t *GPIOx , uint8_t GPIO_Pin); /* Function for read pin state */
/* Example :

 GPIO_ReadPin( &PINA , 3 );

*/

uint8_t GPIO_ReadPort(uint8_t *GPIOx); /* Function for read port value */
/* Example :
			
			uint8_t port_value;
			
			port_value = GPIO_ReadPort( &PINA );
			
*/

void GPIO_TogglePin(uint8_t *GPIOx , uint8_t GPIO_Pin); /* Function for toggle pin */
/* Example :

 GPIO_TogglePin( &PORTA , 3 );

*/

uint8_t GPIO_ReadRegister(uint8_t *REGISTERx); /* Function for read register value */
/* Example :
			
			uint8_t register_value;
			
			port_value = GPIO_ReadRegister( &DDRA );
			
*/

#endif /* __GPIO_H_ */