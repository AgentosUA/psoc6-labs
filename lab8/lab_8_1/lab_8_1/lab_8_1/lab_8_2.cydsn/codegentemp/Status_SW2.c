/*******************************************************************************
* File Name: Status_SW2.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Status_SW2.h"

#if !defined(Status_SW2_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: Status_SW2_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 Status_SW2_Read(void) 
{ 
    return Status_SW2_Status;
}


/*******************************************************************************
* Function Name: Status_SW2_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Status_SW2_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Status_SW2_Status_Aux_Ctrl |= Status_SW2_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Status_SW2_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Status_SW2_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Status_SW2_Status_Aux_Ctrl &= (uint8)(~Status_SW2_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Status_SW2_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void Status_SW2_WriteMask(uint8 mask) 
{
    #if(Status_SW2_INPUTS < 8u)
    	mask &= ((uint8)(1u << Status_SW2_INPUTS) - 1u);
	#endif /* End Status_SW2_INPUTS < 8u */
    Status_SW2_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: Status_SW2_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 Status_SW2_ReadMask(void) 
{
    return Status_SW2_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
