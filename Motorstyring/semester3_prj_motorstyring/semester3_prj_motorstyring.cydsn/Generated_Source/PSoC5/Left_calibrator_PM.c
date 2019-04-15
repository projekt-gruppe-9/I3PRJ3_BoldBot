/*******************************************************************************
* File Name: Left_calibrator_PM.c
* Version 3.10
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Left_calibrator.h"


/***************************************
* Local data allocation
***************************************/

static Left_calibrator_BACKUP_STRUCT  Left_calibrator_backup =
{
    Left_calibrator_DISABLED
};


/*******************************************************************************
* Function Name: Left_calibrator_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Left_calibrator_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Left_calibrator_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Left_calibrator_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Left_calibrator_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The Left_calibrator_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Left_calibrator_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void Left_calibrator_Sleep(void)
{
    if((Left_calibrator_PWRMGR_SAR_REG  & Left_calibrator_ACT_PWR_SAR_EN) != 0u)
    {
        if((Left_calibrator_SAR_CSR0_REG & Left_calibrator_SAR_SOF_START_CONV) != 0u)
        {
            Left_calibrator_backup.enableState = Left_calibrator_ENABLED | Left_calibrator_STARTED;
        }
        else
        {
            Left_calibrator_backup.enableState = Left_calibrator_ENABLED;
        }
        Left_calibrator_Stop();
    }
    else
    {
        Left_calibrator_backup.enableState = Left_calibrator_DISABLED;
    }
}


/*******************************************************************************
* Function Name: Left_calibrator_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  Left_calibrator_Sleep() was called. If the component was enabled before the
*  Left_calibrator_Sleep() function was called, the
*  Left_calibrator_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Left_calibrator_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void Left_calibrator_Wakeup(void)
{
    if(Left_calibrator_backup.enableState != Left_calibrator_DISABLED)
    {
        Left_calibrator_Enable();
        #if(Left_calibrator_DEFAULT_CONV_MODE != Left_calibrator__HARDWARE_TRIGGER)
            if((Left_calibrator_backup.enableState & Left_calibrator_STARTED) != 0u)
            {
                Left_calibrator_StartConvert();
            }
        #endif /* End Left_calibrator_DEFAULT_CONV_MODE != Left_calibrator__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
