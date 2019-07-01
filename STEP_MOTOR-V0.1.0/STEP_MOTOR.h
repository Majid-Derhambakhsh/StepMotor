/*
------------------------------------------------------------------------------
~ File   : STEP_MOTOR.h
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

#ifndef __STEP_MOTOR_H_
#define __STEP_MOTOR_H_

/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Includes ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

#include <stdint.h> /* Import standard integer lib */
#include "STEP_MOTOR_CONFIG.h" /* Import config file */

/*----------------------------------------------------------*/

#ifdef __CODEVISIONAVR__  /* Check compiler */

#include <io.h> /* Import AVR IO library */
#include <delay.h> /* Import delay lib */
#include "GPIO/GPIO.h"        /* Import AVR GPIO control library */

/*----------------------------------------------------------*/

#elif defined(__GNUC__)  /* Check compiler */

#include <avr/io.h>
#include <util/delay.h> /* Import delay lib */
#include "GPIO/GPIO.h"        /* Import AVR GPIO control library */

/*----------------------------------------------------------*/

#elif defined(USE_HAL_DRIVER)  /* Check compiler */

#include _STM32_HAL_DRIVER        /* Import HAL library */

/*----------------------------------------------------------*/

#else                     /* Compiler not found */

#error Chip or GPIO Library not supported  /* Send error */

#endif /* __CODEVISIONAVR__ */

/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Defines ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

/* --------------------- Computational ---------------------- */

#define _DIVIDER(a , b)         (a / b) /* Divider two value */
#define _MULTIPLICATION(a , b)  (a * b) /* Multiplier two value */

/* ----------------------- Step Motor ----------------------- */

#define _PREVIOUS_STEP_NULL          0 /* Previous step null value */
#define _OUT_OF_STEP_RANGE           0x10 /* Out of step range value */
#define _NUMBER_OF_STEP_IN_HALF_MODE 8 /* Number of step in half drive mode */

#define _WAVE_DRIVE_STEP_VALUE  _DIVIDER(_FULL_ANGLE , _STEP_QUANTITY) /* Step value of Stepper Motor */
#define _HALF_DRIVE_STEP_VALUE  _DIVIDER(_FULL_ANGLE , _MULTIPLICATION(_STEP_QUANTITY , 2.0f)) /* Step value of Stepper Motor */

/* ------------------------- Public ------------------------- */

#ifndef _NIBBLE

 #define _NIBBLE 0xF /* Nibble value */

#endif /* _NIBBLE */

/* -------------------- By user library --------------------- */

#ifdef __CODEVISIONAVR__  /* Check compiler */

#define _MOTOR_GPIO_WritePin(port , pin , state)    GPIO_WritePin(port , pin , state) /* Change function */
#define _MOTOR_GPIO_READ_REGISTER(reg)              GPIO_ReadRegister(reg) /* Change function */
#define _STEP_DELAY(t)                              delay_ms(t) /* Change function */
#define _MOTOR_OUTPUT_REGISTER                      _MOTOR_PORT /* output register */

/* ---------------------------------------------------------- */

#elif defined(__GNUC__)  /* Check compiler */

#define _MOTOR_GPIO_WritePin(port , pin , state)    GPIO_WritePin(port , pin , state) /* Change function */
#define _MOTOR_GPIO_READ_REGISTER(reg)              GPIO_ReadRegister(reg) /* Change function */
#define _STEP_DELAY(t)                              _delay_ms(t) /* Change function */
#define _MOTOR_OUTPUT_REGISTER                      _MOTOR_PORT /* output register */

/* ---------------------------------------------------------- */

#elif defined(USE_HAL_DRIVER)  /* Check compiler */

#define _MOTOR_GPIO_WritePin(port , pin , state)    HAL_GPIO_WritePin(port , pin , state) /* Change function */
#define _MOTOR_GPIO_READ_REGISTER(reg)              HAL_GPIO_ReadRegister(_MOTOR_PORT , reg) /* Change function */
#define _STEP_DELAY(t)                              HAL_Delay(t) /* Change function */
#define _MOTOR_OUTPUT_REGISTER                      _GPIO_OUTPUT_DATA_REGISTER; /* output register */
#define _GPIO_PIN_RESET                             GPIO_PIN_RESET /* Select GPIO reset instruction */
#define _GPIO_PIN_SET                               GPIO_PIN_SET /* Select GPIO set instruction */

/* ---------------------------------------------------------- */

#else                     /* Compiler not found */

#error Chip or GPIO Library not supported  /* Send error */

#endif /* __CODEVISIONAVR__ */

/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Enum ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

typedef enum /* Enum for define Wave Drive mode steps value */
{
	
	_WD_STEP_1 = 0x01, /* Step x value */
	_WD_STEP_2 = 0x02, /* Step x value */
	_WD_STEP_3 = 0x04, /* Step x value */
	_WD_STEP_4 = 0x08  /* Step x value */
	
}StepMotor_WaveDriveStepsTypeDef;

typedef enum /* Enum for define Half Drive mode steps value */
{
	
	_HD_STEP_1 = 0x01, /* Step x value */
	_HD_STEP_2 = 0x03, /* Step x value */
	_HD_STEP_3 = 0x02, /* Step x value */
	_HD_STEP_4 = 0x05, /* Step x value */
	_HD_STEP_5 = 0x04, /* Step x value */
	_HD_STEP_6 = 0x0C, /* Step x value */
	_HD_STEP_7 = 0x08, /* Step x value */
	_HD_STEP_8 = 0x01  /* Step x value */
	
}StepMotor_HalfDriveStepsTypeDef;

typedef enum /* Enum for define Half Drive mode steps vector */
{
	
	_HD_STEP_1_VECTOR = 0, /* Step x vector in half_drive_steps array */
	_HD_STEP_2_VECTOR = 1, /* Step x vector in half_drive_steps array */
	_HD_STEP_3_VECTOR = 2, /* Step x vector in half_drive_steps array */
	_HD_STEP_4_VECTOR = 3, /* Step x vector in half_drive_steps array */
	_HD_STEP_5_VECTOR = 4, /* Step x vector in half_drive_steps array */
	_HD_STEP_6_VECTOR = 5, /* Step x vector in half_drive_steps array */
	_HD_STEP_7_VECTOR = 6, /* Step x vector in half_drive_steps array */
	_HD_STEP_8_VECTOR = 7  /* Step x vector in half_drive_steps array */
	
}StepMotor_HalfDriveStepsVectorTypeDef;

/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Prototype ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

void StepMotor_WaveDriveChangeStep(int16_t number_of_step , uint16_t step_time); /* This function is for change step in wave drive mode */

void StepMotor_WaveDriveChangeAngle(float angle , uint16_t step_time);  /* This function is for change angle in wave drive mode */

#endif /* __STEP_MOTOR_H_ */
