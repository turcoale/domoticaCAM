/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Cap1.H
**     Project   : fade2
**     Processor : MC9S08SH8CPJ
**     Component : Capture
**     Version   : Component 02.211, Driver 01.27, CPU db: 3.00.062
**     Compiler  : CodeWarrior HCS08 C Compiler
**     Date/Time : 13/01/2015, 17:30
**     Abstract  :
**         This bean "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
**     Settings  :
**             Timer capture encapsulation : Capture
**
**         Timer
**             Timer                   : TPM1
**             Counter shared          : No
**
**         High speed mode
**             Prescaler               : divide-by-4
**           Maximal time for capture register
**             Xtal ticks              : 512
**             microseconds            : 16384
**             milliseconds            : 16
**             seconds (real)          : 0.016384
**             Hz                      : 61
**           One tick of timer is
**             nanoseconds             : 250
**
**         Initialization:
**              Timer                  : Disabled
**              Events                 : Enabled
**
**         Timer registers
**              Capture                : TPM1C0V   [$0026]
**              Counter                : TPM1CNT   [$0021]
**              Mode                   : TPM1SC    [$0020]
**              Run                    : TPM1SC    [$0020]
**              Prescaler              : TPM1SC    [$0020]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       12            |  PTC0_TPM1CH0_ADP8
**             ----------------------------------------------------
**
**         Port name                   : PTC
**         Bit number (in port)        : 0
**         Bit mask of the port        : $0001
**
**         Signal edge/level           : both
**         Priority                    : 
**         Pull option                 : off
**
**     Contents  :
**         Enable          - byte Cap1_Enable(void);
**         Disable         - byte Cap1_Disable(void);
**         Reset           - byte Cap1_Reset(void);
**         GetCaptureValue - byte Cap1_GetCaptureValue(Cap1_TCapturedValue *Value);
**         GetPinValue     - bool Cap1_GetPinValue(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __Cap1
#define __Cap1

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"

/* MODULE Cap1. */

#include "Cpu.h"

/* PUBLISHED CONSTANTS */
#define Cap1_PRESCALER_VALUE           0x04U /* Prescaler value of the timer in high speed mode */
#define Cap1_COUNTER_INPUT_CLOCK_HZ    0x003D0900LU /* Initial counter input clock frequency [Hz] */
#define Cap1_TIMER_INPUT_CLOCK         0x00F42400LU /* Deprecated, Initial timer input clock frequency [Hz] */
#define Cap1_PRESCALER_VALUE_HIGH      0x04U /* Prescaler value of the timer in high speed mode */
#define Cap1_COUNTER_INPUT_CLOCK_HZ_HIGH 0x003D0900LU /* Counter input clock frequency in high speed mode [Hz] */
#define Cap1_TIMER_INPUT_CLOCK_HIGH    0x00F42400LU /* Deprecated, Timer input clock frequency in high speed mode[Hz] */

#ifndef __BWUserType_Cap1_TCapturedValue
#define __BWUserType_Cap1_TCapturedValue
  #define Cap1_TCapturedValue word     /* Type of the captured value */
#endif



byte Cap1_Enable(void);
/*
** ===================================================================
**     Method      :  Cap1_Enable (component Capture)
**
**     Description :
**         This method enables the bean - it starts the capture. Events
**         may be generated (<DisableEvent>/<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte Cap1_Disable(void);
/*
** ===================================================================
**     Method      :  Cap1_Disable (component Capture)
**
**     Description :
**         This method disables the bean - it stops the capture. No
**         events will be generated.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

#define Cap1_Reset() \
  (TPM1CNTH = 0 , (byte)ERR_OK)
/*
** ===================================================================
**     Method      :  Cap1_Reset (component Capture)
**
**     Description :
**         This method resets the counter register (see implementation
**         note in <General Info>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

#define Cap1_GetCaptureValue(Value) \
  (*(Cap1_TCapturedValue*)(Value) = (Cap1_TCapturedValue)TPM1C0V , (byte)ERR_OK)
/*
** ===================================================================
**     Method      :  Cap1_GetCaptureValue (component Capture)
**
**     Description :
**         This method gets the last value captured by enabled timer.
**         Note: one tick of timer is
**               250 ns in high speed mode
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the content of the
**                           capture register
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

#define Cap1_GetPinValue() ((bool)(PTCD & 0x01))
/*
** ===================================================================
**     Method      :  Cap1_GetPinValue (component Capture)
**
**     Description :
**         The method reads the Capture pin value. The method is
**         available only if it is possible to read the pin value
**         (usually not available for internal signals).
**     Parameters  : None
**     Returns     :
**         ---             - Capture pin value.
**                           <true> - high level
**                           <false> - low level.
** ===================================================================
*/

void Cap1_Init(void);
/*
** ===================================================================
**     Method      :  Cap1_Init (component Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the bean internal 
**         variables. The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

__interrupt void Cap1_Interrupt(void);
/*
** ===================================================================
**     Method      :  Interrupt (component Capture)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes of the bean event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


/* END Cap1. */

#endif /* ifndef __Cap1 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.07 [04.34]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
