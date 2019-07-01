/*
------------------------------------------------------------------------------
~ File   : STEP_MOTOR.c
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

#include "STEP_MOTOR.h"

/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Variables ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

uint8_t wave_mode_step = _WD_STEP_1; /* Variable for change step */
uint8_t half_mode_step = _HD_STEP_1_VECTOR; /* Variable for change step */

const uint8_t half_drive_steps[_NUMBER_OF_STEP_IN_HALF_MODE] = { _HD_STEP_1 , _HD_STEP_2 , _HD_STEP_3 , _HD_STEP_4 , _HD_STEP_5 , _HD_STEP_6 , _HD_STEP_7 , _HD_STEP_8}; /* Array for Half Drive Step values */

/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Functions ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

void StepMotor_WaveDriveChangeStep(int16_t number_of_step , uint16_t step_time) /* This function is for change step in wave drive mode */
{
	
	/* ------------------- Create Variable ------------------- */
	
	uint8_t previous_value; /* Variable for get previous value */
	
	/* ------------------------------------------------------- */
	
	if (number_of_step > 0) /* Check angle */
	{
		
		/* ------------------------------------------------------ */
		
		previous_value = (uint8_t)( (_MOTOR_GPIO_READ_REGISTER(_MOTOR_OUTPUT_REGISTER) >> _MOTOR_PIN_A) & _NIBBLE ); /* Get previous value */
		
		switch (previous_value)
		{
			
			case _PREVIOUS_STEP_NULL: /* Check step */
			{
				wave_mode_step = _WD_STEP_1; /* Set new step */
			}
			break;
			case _WD_STEP_1: /* Check step */
			{
				wave_mode_step = _WD_STEP_2; /* Set new step */
			}
			break;
			case _WD_STEP_2: /* Check step */
			{
				wave_mode_step = _WD_STEP_3; /* Set new step */
			}
			break;
			case _WD_STEP_3: /* Check step */
			{
				wave_mode_step = _WD_STEP_4; /* Set new step */
			}
			break;
			case _WD_STEP_4: /* Check step */
			{
				wave_mode_step = _WD_STEP_1; /* Set new step */
			}
			break;
			
			default:
			break;
			
		}
		
		/* ------------------------------------------------------ */
		
		for ( ; number_of_step > 0 ; number_of_step-- ) /* Loop for change angle */
		{
			
			_MOTOR_GPIO_WritePin(_MOTOR_PORT , (_NIBBLE << _MOTOR_PIN_A) , _GPIO_PIN_RESET); /* Reset port */
			_MOTOR_GPIO_WritePin(_MOTOR_PORT , (wave_mode_step << _MOTOR_PIN_A) , _GPIO_PIN_SET); /* Write new step in port */
			
			/* ---------------------------------- */
			
			wave_mode_step = (wave_mode_step << 1); /* Change step */
			
			if (wave_mode_step == _OUT_OF_STEP_RANGE) /* Check step */
			{
				wave_mode_step = _WD_STEP_1; /* Set new step */
			}
			
			/* ---------------------------------- */
			
			_STEP_DELAY(step_time);
			
		}
		
	}
	else
	{
		
		/* ------------------------------------------------------ */
		
		previous_value = (uint8_t)( (_MOTOR_GPIO_READ_REGISTER(_MOTOR_OUTPUT_REGISTER) >> _MOTOR_PIN_A) & _NIBBLE ); /* Get previous value */
		
		switch (previous_value)
		{
			
			case _PREVIOUS_STEP_NULL: /* Check step */
			{
				wave_mode_step = _WD_STEP_3; /* Set new step */
			}
			break;
			case _WD_STEP_1: /* Check step */
			{
				wave_mode_step = _WD_STEP_4; /* Set new step */
			}
			break;
			case _WD_STEP_2: /* Check step */
			{
				wave_mode_step = _WD_STEP_1; /* Set new step */
			}
			break;
			case _WD_STEP_3: /* Check step */
			{
				wave_mode_step = _WD_STEP_2; /* Set new step */
			}
			break;
			case _WD_STEP_4: /* Check step */
			{
				wave_mode_step = _WD_STEP_3; /* Set new step */
			}
			break;
			
			default:
			break;
			
		}
		
		/* ------------------------------------------------------ */
		
		for ( ; number_of_step < 0 ; number_of_step++ ) /* Loop for change angle */
		{
			
			_MOTOR_GPIO_WritePin(_MOTOR_PORT , (_NIBBLE << _MOTOR_PIN_A) , _GPIO_PIN_RESET);
			_MOTOR_GPIO_WritePin(_MOTOR_PORT , (wave_mode_step << _MOTOR_PIN_A) , _GPIO_PIN_SET);
			
			/* ---------------------------------- */
			
			wave_mode_step = (wave_mode_step >> 1); /* Change step */
			
			if (wave_mode_step == _PREVIOUS_STEP_NULL) /* Check step */
			{
				wave_mode_step = _WD_STEP_4; /* Set new step */
			}
			
			/* ---------------------------------- */
			
			_STEP_DELAY(step_time);
			
		}
		
	}
	
}

void StepMotor_WaveDriveChangeAngle(float angle , uint16_t step_time) /* This function is for change angle in wave drive mode */
{
	
	/* ------------------- Create Variable ------------------- */
	
	uint8_t previous_value; /* Variable for get previous value */
	int16_t angle_counter = angle / _WAVE_DRIVE_STEP_VALUE; /* Variable for calculate number of step */
	
	/* ------------------------------------------------------- */
	
	if (angle > 0) /* Check angle */
	{
		
		/* ------------------------------------------------------ */
		
		previous_value = (uint8_t)( (_MOTOR_GPIO_READ_REGISTER(_MOTOR_OUTPUT_REGISTER) >> _MOTOR_PIN_A) & _NIBBLE ); /* Get previous value */
		
		switch (previous_value)
		{
			
			case _PREVIOUS_STEP_NULL: /* Check step */
			{
				wave_mode_step = _WD_STEP_1; /* Set new step */
			}
			break;
			case _WD_STEP_1: /* Check step */
			{
				wave_mode_step = _WD_STEP_2; /* Set new step */
			}
			break;
			case _WD_STEP_2: /* Check step */
			{
				wave_mode_step = _WD_STEP_3; /* Set new step */
			}
			break;
			case _WD_STEP_3: /* Check step */
			{
				wave_mode_step = _WD_STEP_4; /* Set new step */
			}
			break;
			case _WD_STEP_4: /* Check step */
			{
				wave_mode_step = _WD_STEP_1; /* Set new step */
			}
			break;
			
			default:
			break;
			
		}
		
		/* ------------------------------------------------------ */
		
		for ( ; angle_counter > 0 ; angle_counter-- ) /* Loop for change angle */
		{
			
			_MOTOR_GPIO_WritePin(_MOTOR_PORT , (_NIBBLE << _MOTOR_PIN_A) , _GPIO_PIN_RESET); /* Reset port */
			_MOTOR_GPIO_WritePin(_MOTOR_PORT , (wave_mode_step << _MOTOR_PIN_A) , _GPIO_PIN_SET); /* Write new step in port */
			
			/* ---------------------------------- */
			
			wave_mode_step = (wave_mode_step << 1); /* Change step */
			
			if (wave_mode_step == _OUT_OF_STEP_RANGE) /* Check step */
			{
				wave_mode_step = _WD_STEP_1; /* Set new step */
			}
			
			/* ---------------------------------- */
			
			_STEP_DELAY(step_time);
			
		}
		
	}
	else
	{
		
		/* ------------------------------------------------------ */
		
		previous_value = (uint8_t)( (_MOTOR_GPIO_READ_REGISTER(_MOTOR_OUTPUT_REGISTER) >> _MOTOR_PIN_A) & _NIBBLE ); /* Get previous value */
		
		switch (previous_value)
		{
			
			case _PREVIOUS_STEP_NULL: /* Check step */
			{
				wave_mode_step = _WD_STEP_3; /* Set new step */
			}
			break;
			case _WD_STEP_1: /* Check step */
			{
				wave_mode_step = _WD_STEP_4; /* Set new step */
			}
			break;
			case _WD_STEP_2: /* Check step */
			{
				wave_mode_step = _WD_STEP_1; /* Set new step */
			}
			break;
			case _WD_STEP_3: /* Check step */
			{
				wave_mode_step = _WD_STEP_2; /* Set new step */
			}
			break;
			case _WD_STEP_4: /* Check step */
			{
				wave_mode_step = _WD_STEP_3; /* Set new step */
			}
			break;
			
			default:
			break;
			
		}
		
		/* ------------------------------------------------------ */
		
		for ( ; angle_counter < 0 ; angle_counter++ ) /* Loop for change angle */
		{
			
			_MOTOR_GPIO_WritePin(_MOTOR_PORT , (_NIBBLE << _MOTOR_PIN_A) , _GPIO_PIN_RESET);
			_MOTOR_GPIO_WritePin(_MOTOR_PORT , (wave_mode_step << _MOTOR_PIN_A) , _GPIO_PIN_SET);
			
			/* ---------------------------------- */
			
			wave_mode_step = (wave_mode_step >> 1); /* Change step */
			
			if (wave_mode_step == _PREVIOUS_STEP_NULL) /* Check step */
			{
				wave_mode_step = _WD_STEP_4; /* Set new step */
			}
			
			/* ---------------------------------- */
			
			_STEP_DELAY(step_time);
			
		}
		
	}
	
}
