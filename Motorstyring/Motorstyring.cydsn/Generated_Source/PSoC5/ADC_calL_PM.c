/*******************************************************************************
* File Name: ADC_calL_PM.c
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

#include "ADC_calL.h"


/***************************************
* Local data allocation
***************************************/

static ADC_calL_BACKUP_STRUCT  ADC_calL_backup =
{
    ADC_calL_DISABLED
};


/*******************************************************************************
* Function Name: ADC_calL_SaveConfig
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
void ADC_calL_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_calL_RestoreConfig
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
void ADC_calL_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_calL_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The ADC_calL_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_calL_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void ADC_calL_Sleep(void)
{
    if((ADC_calL_PWRMGR_SAR_REG  & ADC_calL_ACT_PWR_SAR_EN) != 0u)
    {
        if((ADC_calL_SAR_CSR0_REG & ADC_calL_SAR_SOF_START_CONV) != 0u)
        {
            ADC_calL_backup.enableState = ADC_calL_ENABLED | ADC_calL_STARTED;
        }
        else
        {
            ADC_calL_backup.enableState = ADC_calL_ENABLED;
        }
        ADC_calL_Stop();
    }
    else
    {
        ADC_calL_backup.enableState = ADC_calL_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_calL_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  ADC_calL_Sleep() was called. If the component was enabled before the
*  ADC_calL_Sleep() function was called, the
*  ADC_calL_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_calL_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_calL_Wakeup(void)
{
    if(ADC_calL_backup.enableState != ADC_calL_DISABLED)
    {
        ADC_calL_Enable();
        #if(ADC_calL_DEFAULT_CONV_MODE != ADC_calL__HARDWARE_TRIGGER)
            if((ADC_calL_backup.enableState & ADC_calL_STARTED) != 0u)
            {
                ADC_calL_StartConvert();
            }
        #endif /* End ADC_calL_DEFAULT_CONV_MODE != ADC_calL__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
