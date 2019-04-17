/*******************************************************************************
* File Name: Right_calibrator_PM.c
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

#include "Right_calibrator.h"


/***************************************
* Local data allocation
***************************************/

static Right_calibrator_BACKUP_STRUCT  Right_calibrator_backup =
{
    Right_calibrator_DISABLED
};


/*******************************************************************************
* Function Name: Right_calibrator_SaveConfig
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
void Right_calibrator_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Right_calibrator_RestoreConfig
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
void Right_calibrator_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Right_calibrator_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The Right_calibrator_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Right_calibrator_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void Right_calibrator_Sleep(void)
{
    if((Right_calibrator_PWRMGR_SAR_REG  & Right_calibrator_ACT_PWR_SAR_EN) != 0u)
    {
        if((Right_calibrator_SAR_CSR0_REG & Right_calibrator_SAR_SOF_START_CONV) != 0u)
        {
            Right_calibrator_backup.enableState = Right_calibrator_ENABLED | Right_calibrator_STARTED;
        }
        else
        {
            Right_calibrator_backup.enableState = Right_calibrator_ENABLED;
        }
        Right_calibrator_Stop();
    }
    else
    {
        Right_calibrator_backup.enableState = Right_calibrator_DISABLED;
    }
}


/*******************************************************************************
* Function Name: Right_calibrator_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  Right_calibrator_Sleep() was called. If the component was enabled before the
*  Right_calibrator_Sleep() function was called, the
*  Right_calibrator_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Right_calibrator_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void Right_calibrator_Wakeup(void)
{
    if(Right_calibrator_backup.enableState != Right_calibrator_DISABLED)
    {
        Right_calibrator_Enable();
        #if(Right_calibrator_DEFAULT_CONV_MODE != Right_calibrator__HARDWARE_TRIGGER)
            if((Right_calibrator_backup.enableState & Right_calibrator_STARTED) != 0u)
            {
                Right_calibrator_StartConvert();
            }
        #endif /* End Right_calibrator_DEFAULT_CONV_MODE != Right_calibrator__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
