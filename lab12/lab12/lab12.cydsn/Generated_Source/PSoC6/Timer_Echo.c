/*******************************************************************************
* File Name: Timer_Echo.c
* Version 1.0
*
* Description:
*  This file provides the source code to the API for the Timer_Echo
*  component
*
********************************************************************************
* Copyright 2016-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Timer_Echo.h"

/** Indicates whether or not the Timer_Echo has been initialized. 
*  The variable is initialized to 0 and set to 1 the first time 
*  Timer_Echo_Start() is called. This allows the Component to 
*  restart without reinitialization after the first call to 
*  the Timer_Echo_Start() routine.
*/
uint8_t Timer_Echo_initVar = 0U;

/** The instance-specific configuration structure. This should be used in the 
*  associated Timer_Echo_Init() function.
*/ 
cy_stc_tcpwm_counter_config_t const Timer_Echo_config =
{
        .period = 32768UL,
        .clockPrescaler = 0UL,
        .runMode = 0UL,
        .countDirection = 0UL,
        .compareOrCapture = 2UL,
        .compare0 = 16384UL,
        .compare1 = 16384UL,
        .enableCompareSwap = false,
        .interruptSources = 0UL,
        .captureInputMode = 0UL,
        .captureInput = CY_TCPWM_INPUT_CREATOR,
        .reloadInputMode = 1UL,
        .reloadInput = CY_TCPWM_INPUT_CREATOR,
        .startInputMode = 0UL,
        .startInput = CY_TCPWM_INPUT_CREATOR,
        .stopInputMode = 1UL,
        .stopInput = CY_TCPWM_INPUT_CREATOR,
        .countInputMode = 3UL,
        .countInput = CY_TCPWM_INPUT_CREATOR,
};


/*******************************************************************************
* Function Name: Timer_Echo_Start
****************************************************************************//**
*
*  Calls the Timer_Echo_Init() when called the first time and enables 
*  the Timer_Echo. For subsequent calls the configuration is left 
*  unchanged and the component is just enabled.
*
* \globalvars
*  \ref Timer_Echo_initVar
*
*******************************************************************************/
void Timer_Echo_Start(void)
{
    if (0U == Timer_Echo_initVar)
    {
        (void)Cy_TCPWM_Counter_Init(Timer_Echo_HW, Timer_Echo_CNT_NUM, &Timer_Echo_config); 

        Timer_Echo_initVar = 1U;
    }

    Cy_TCPWM_Enable_Multiple(Timer_Echo_HW, Timer_Echo_CNT_MASK);
    
    #if (Timer_Echo_INPUT_DISABLED == 0UL)
        Cy_TCPWM_TriggerStart(Timer_Echo_HW, Timer_Echo_CNT_MASK);
    #endif /* (Timer_Echo_INPUT_DISABLED == 0UL) */    
}


/* [] END OF FILE */
