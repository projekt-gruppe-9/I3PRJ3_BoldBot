/*******************************************************************************
* File Name: Steps_PM.c
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

#include "Steps.h"

/* Check for removal by optimization */
#if !defined(Steps_Sync_ctrl_reg__REMOVED)

static Steps_BACKUP_STRUCT  Steps_backup = {0u};

    
/*******************************************************************************
* Function Name: Steps_SaveConfig
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
void Steps_SaveConfig(void) 
{
    Steps_backup.controlState = Steps_Control;
}


/*******************************************************************************
* Function Name: Steps_RestoreConfig
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
void Steps_RestoreConfig(void) 
{
     Steps_Control = Steps_backup.controlState;
}


/*******************************************************************************
* Function Name: Steps_Sleep
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
void Steps_Sleep(void) 
{
    Steps_SaveConfig();
}


/*******************************************************************************
* Function Name: Steps_Wakeup
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
void Steps_Wakeup(void)  
{
    Steps_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
