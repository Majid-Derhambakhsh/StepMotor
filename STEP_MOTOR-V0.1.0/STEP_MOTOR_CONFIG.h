/*
------------------------------------------------------------------------------
~ File   : STEP_MOTOR_CONFIG.h
~ Author : Majid Derhambakhsh
~ Version: V0.1.0
~ Created: 06/16/2019 01:09:00 AM
~ Brief  :
~ Support: Majid.do16@gmail.com
------------------------------------------------------------------------------
~ Description:

~ Attention  :
------------------------------------------------------------------------------
*/

#ifndef __STEP_MOTOR_CONFIG_H_
#define __STEP_MOTOR_CONFIG_H_

/* -------------------- Config -------------------- */

/* --- Config Port --- */

#define _MOTOR_PORT     &PORTB
#define _MOTOR_PIN_A    1

/*
	Example :
			
			AVR : 
					#define _MOTOR_PORT     &PORTB
					#define _MOTOR_PIN_A    1
					
			ARM : 
					#define _MOTOR_PORT     GPIOA
					#define _MOTOR_PIN_A    1
					
*/

/* --- Config Angle --- */

#define _FULL_ANGLE     360.0f
#define _STEP_QUANTITY  200.0f

/*
	Example :
				#define _FULL_ANGLE     360.0f
				#define _STEP_QUANTITY  25.0f
*/

/* --- Config Driver --- */
#define _STM32_HAL_DRIVER  "STM32_GPIO/STM32_GPIO.h"

/*
	Example :
				#define _STM32_HAL_DRIVER  "STM32_GPIO/STM32_GPIO.h"
*/

/* ------------------------------------------------ */

#endif /* __STEP_MOTOR_CONFIG_H_ */
