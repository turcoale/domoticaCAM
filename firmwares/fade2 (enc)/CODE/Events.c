/** ###################################################################
**     Filename  : Events.C
**     Project   : fade2
**     Processor : MC9S08SH8CPJ
**     Component : Events
**     Version   : Driver 01.02
**     Compiler  : CodeWarrior HCS08 C Compiler
**     Date/Time : 11/06/2014, 19:13
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Events */


#include "Cpu.h"
#include "Events.h"

extern byte estado;
extern byte band;


/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Cap1_OnCapture (module Events)
**
**     Component   :  Cap1 [Capture]
**     Description :
**         This event is called on capturing of Timer/Counter actual
**         value (only when the bean is enabled - <Enable> and the
**         events are enabled - <EnableEvent>.This event is available
**         only if a <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cap1_OnCapture(void)
{
  /* Write your code here ... */
//estado = Cap1_GetPinValue();
//band = 1;

}



/*
** ===================================================================
**     Event       :  Cpu_OnLvwINT (module Events)
**
**     Component   :  Cpu [MC9S08SH8_20]
**     Description :
**         This event is called when the Low voltage warning (LVW)
**         interrupt had occurred. This event can be enabled only if
**         both <LVD module> and <LVW Interrupt > are enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cpu_OnLvwINT(void)
{
  /* Write your code here ... */
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.07 [04.34]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
