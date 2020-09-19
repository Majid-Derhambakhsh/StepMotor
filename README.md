# StepMotor Library
Using Step Motor in AVR - ARM Cortex M

### Version : 0.1.0

- #### Type : Embedded Software.

- #### Support : AVR/ARM STM32 series.

- #### Program Language : C

- #### Properties :

### Initialization and de-initialization functions:

### Operation functions:
```c++  
void StepMotor_WaveDriveChangeStep(int16_t number_of_step , uint16_t step_time); /* This function is for change step in wave drive mode */
void StepMotor_WaveDriveChangeAngle(float angle , uint16_t step_time);  /* This function is for change angle in wave drive mode */
``` 
### Macros:
```c++  
#define _MOTOR_PORT  
#define _MOTOR_PIN_A  

#define _FULL_ANGLE  
#define _STEP_QUANTITY  

#define _STM32_HAL_DRIVER  
``` 

## How to use this library

### The Stepper Motor library can be used as follows:
#### 1.  Add .h and source file in project.      
#### 2.  Config GPIO as output in your project.  
#### 3.  Config Stepper Motor in 'STEP_MOTOR_CONFIG.h' header, for example:  
   * Options:  
   
      ```c++
      /* --- Config Port --- */
      #define _MOTOR_PORT     &PORTB
      #define _MOTOR_PIN_A    1

      /* --- Config Angle --- */
      #define _FULL_ANGLE     360.0f
      #define _STEP_QUANTITY  200.0f
      
      /* --- Config Driver --- */
      //#define _STM32_HAL_DRIVER  "STM32_GPIO/STM32_GPIO.h"
      
      ```
          
#### 4.  Using operation methods, for example:  
#### Example 1:  
```c++  
int main(void)
{
	
    while (1) 
    {
  
      StepMotor_WaveDriveChangeStep(10, 250);
      _DELAY_MS(500);
    
      StepMotor_WaveDriveChangeStep(-12, 250);
      _DELAY_MS(500);
    
    }
}
   
``` 
#### Example 2:  
```c++  
int main(void)
{

    while (1) 
    {
    
      StepMotor_WaveDriveChangeStep(10, 250);
      _DELAY_MS(500);
      
      StepMotor_WaveDriveChangeStep(-12, 250);
      _DELAY_MS(500);
      
      StepMotor_WaveDriveChangeAngle(101.0, 250);
      _DELAY_MS(500);
      
      StepMotor_WaveDriveChangeAngle(-150.6, 250);
      _DELAY_MS(500);
    
    }
}
   
``` 

## Tests performed:
- [X] Run on AVR
- [x] Run on STM32 Fx cores 

#### Developer: Majid Derhambakhsh
