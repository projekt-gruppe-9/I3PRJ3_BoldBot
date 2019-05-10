/*******************************************************************************
* File Name: Motorpwm_right_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Motorpwm_right.h"

static Motorpwm_right_backupStruct Motorpwm_right_backup;


/*******************************************************************************
* Function Name: Motorpwm_right_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Motorpwm_right_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Motorpwm_right_SaveConfig(void) 
{

    #if(!Motorpwm_right_UsingFixedFunction)
        #if(!Motorpwm_right_PWMModeIsCenterAligned)
            Motorpwm_right_backup.PWMPeriod = Motorpwm_right_ReadPeriod();
        #endif /* (!Motorpwm_right_PWMModeIsCenterAligned) */
        Motorpwm_right_backup.PWMUdb = Motorpwm_right_ReadCounter();
        #if (Motorpwm_right_UseStatus)
            Motorpwm_right_backup.InterruptMaskValue = Motorpwm_right_STATUS_MASK;
        #endif /* (Motorpwm_right_UseStatus) */

        #if(Motorpwm_right_DeadBandMode == Motorpwm_right__B_PWM__DBM_256_CLOCKS || \
            Motorpwm_right_DeadBandMode == Motorpwm_right__B_PWM__DBM_2_4_CLOCKS)
            Motorpwm_right_backup.PWMdeadBandValue = Motorpwm_right_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Motorpwm_right_KillModeMinTime)
             Motorpwm_right_backup.PWMKillCounterPeriod = Motorpwm_right_ReadKillTime();
        #endif /* (Motorpwm_right_KillModeMinTime) */

        #if(Motorpwm_right_UseControl)
            Motorpwm_right_backup.PWMControlRegister = Motorpwm_right_ReadControlRegister();
        #endif /* (Motorpwm_right_UseControl) */
    #endif  /* (!Motorpwm_right_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Motorpwm_right_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Motorpwm_right_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Motorpwm_right_RestoreConfig(void) 
{
        #if(!Motorpwm_right_UsingFixedFunction)
            #if(!Motorpwm_right_PWMModeIsCenterAligned)
                Motorpwm_right_WritePeriod(Motorpwm_right_backup.PWMPeriod);
            #endif /* (!Motorpwm_right_PWMModeIsCenterAligned) */

            Motorpwm_right_WriteCounter(Motorpwm_right_backup.PWMUdb);

            #if (Motorpwm_right_UseStatus)
                Motorpwm_right_STATUS_MASK = Motorpwm_right_backup.InterruptMaskValue;
            #endif /* (Motorpwm_right_UseStatus) */

            #if(Motorpwm_right_DeadBandMode == Motorpwm_right__B_PWM__DBM_256_CLOCKS || \
                Motorpwm_right_DeadBandMode == Motorpwm_right__B_PWM__DBM_2_4_CLOCKS)
                Motorpwm_right_WriteDeadTime(Motorpwm_right_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Motorpwm_right_KillModeMinTime)
                Motorpwm_right_WriteKillTime(Motorpwm_right_backup.PWMKillCounterPeriod);
            #endif /* (Motorpwm_right_KillModeMinTime) */

            #if(Motorpwm_right_UseControl)
                Motorpwm_right_WriteControlRegister(Motorpwm_right_backup.PWMControlRegister);
            #endif /* (Motorpwm_right_UseControl) */
        #endif  /* (!Motorpwm_right_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Motorpwm_right_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Motorpwm_right_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Motorpwm_right_Sleep(void) 
{
    #if(Motorpwm_right_UseControl)
        if(Motorpwm_right_CTRL_ENABLE == (Motorpwm_right_CONTROL & Motorpwm_right_CTRL_ENABLE))
        {
            /*Component is enabled */
            Motorpwm_right_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Motorpwm_right_backup.PWMEnableState = 0u;
        }
    #endif /* (Motorpwm_right_UseControl) */

    /* Stop component */
    Motorpwm_right_Stop();

    /* Save registers configuration */
    Motorpwm_right_SaveConfig();
}


/*******************************************************************************
* Function Name: Motorpwm_right_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Motorpwm_right_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Motorpwm_right_Wakeup(void) 
{
     /* Restore registers values */
    Motorpwm_right_RestoreConfig();

    if(Motorpwm_right_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Motorpwm_right_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
