/*******************************************************************************
* File Name: mode_PM.c
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

#include "mode.h"

/* Check for removal by optimization */
#if !defined(mode_Sync_ctrl_reg__REMOVED)

static mode_BACKUP_STRUCT  mode_backup = {0u};

    
/*******************************************************************************
* Function Name: mode_SaveConfig
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
void mode_SaveConfig(void) 
{
    mode_backup.controlState = mode_Control;
}


/*******************************************************************************
* Function Name: mode_RestoreConfig
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
void mode_RestoreConfig(void) 
{
     mode_Control = mode_backup.controlState;
}


/*******************************************************************************
* Function Name: mode_Sleep
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
void mode_Sleep(void) 
{
    mode_SaveConfig();
}


/*******************************************************************************
* Function Name: mode_Wakeup
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
void mode_Wakeup(void)  
{
    mode_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
