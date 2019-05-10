/*******************************************************************************
* File Name: Stepper_control_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Stepper_control.h"

/* Check for removal by optimization */
#if !defined(Stepper_control_Sync_ctrl_reg__REMOVED)

static Stepper_control_BACKUP_STRUCT  Stepper_control_backup = {0u};

    
/*******************************************************************************
* Function Name: Stepper_control_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Stepper_control_SaveConfig(void) 
{
    Stepper_control_backup.controlState = Stepper_control_Control;
}


/*******************************************************************************
* Function Name: Stepper_control_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Stepper_control_RestoreConfig(void) 
{
     Stepper_control_Control = Stepper_control_backup.controlState;
}


/*******************************************************************************
* Function Name: Stepper_control_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Stepper_control_Sleep(void) 
{
    Stepper_control_SaveConfig();
}


/*******************************************************************************
* Function Name: Stepper_control_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Stepper_control_Wakeup(void)  
{
    Stepper_control_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
