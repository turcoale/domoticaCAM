/** ###################################################################
**     Filename  : fade2.C
**     Project   : fade2
**     Processor : MC9S08SH8CPJ
**     Version   : Driver 01.11
**     Compiler  : CodeWarrior HCS08 C Compiler
**     Date/Time : 11/06/2014, 19:13
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE fade2 */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "PWM1.h"
#include "Cap1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

void FadeOut(unsigned int inicio); 
void FadeIn(unsigned int inicio); 


byte estado;
byte band, time;

unsigned int i;

/* User includes (#include below this line is not maintained by Processor Expert) */
void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

PE_low_level_init();

Cap1_Enable();

estado = Cap1_GetPinValue();
band = 0;
PWM1_Enable();
time = 1;

//if(estado)
//{PTAD_PTAD1 = 1;} else {PTAD_PTAD1 = 0;}

 
for(;;)
{
 if(band && time)
  {
   clrReg8Bits(TPM1SC, 0x80);    
   band = 0;
   time = 0;
    if(estado)
       {    
        FadeIn(0x0000);
       } else 
          {
           FadeOut(0xFFFF);
          }
  }
  
        
}

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

void FadeIn(unsigned int inicio) 
{
for(i = inicio; i <= 0xFFFE;i++)
  {
   PWM1_SetRatio16(i);
   Cpu_Delay100US(2);
   //if(!estado){ band = 0; FadeOut(i);
  }
   PWM1_SetRatio16(0xFFFF);
}

void FadeOut(unsigned int inicio) 
{
for(i = inicio; i >= 0x0001;i--)
  {
   PWM1_SetRatio16(i);
   Cpu_Delay100US(1);
   if(estado){ band = 0; FadeIn(i);}
  }
   PWM1_SetRatio16(0x0000);
   band = 0;
   time = 1;
}



/* END fade2 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.07 [04.34]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
