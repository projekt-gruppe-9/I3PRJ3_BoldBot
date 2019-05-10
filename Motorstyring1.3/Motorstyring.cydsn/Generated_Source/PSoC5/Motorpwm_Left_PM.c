/*******************************************************************************
* File Name: Motorpwm_Left_PM.c
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

#include "Motorpwm_Left.h"

static Motorpwm_Left_backupStruct Motorpwm_Left_backup;


/*******************************************************************************
* Function Name: Motorpwm_Left_SaveConfig
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
*  Motorpwm_Left_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Motorpwm_Left_SaveConfig(void) 
{

    #if(!Motorpwm_Left_UsingFixedFunction)
        #if(!Motorpwm_Left_PWMModeIsCenterAligned)
            Motorpwm_Left_backup.PWMPeriod = Motorpwm_Left_ReadPeriod();
        #endif /* (!Motorpwm_Left_PWMModeIsCenterAligned) */
        Motorpwm_Left_backup.PWMUdb = Motorpwm_Left_ReadCounter();
        #if (Motorpwm_Left_UseStatus)
            Motorpwm_Left_backup.InterruptMaskValue = Motorpwm_Left_STATUS_MASK;
        #endif /* (Motorpwm_Left_UseStatus) */

        #if(Motorpwm_Left_DeadBandMode == Motorpwm_Left__B_PWM__DBM_256_CLOCKS || \
            Motorpwm_Left_DeadBandMode == Motorpwm_Left__B_PWM__DBM_2_4_CLOCKS)
            Motorpwm_Left_backup.PWMdeadBandValue = Motorpwm_Left_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(Motorpwm_Left_KillModeMinTime)
             Motorpwm_Left_backup.PWMKillCounterPeriod = Motorpwm_Left_ReadKillTime();
        #endif /* (Motorpwm_Left_KillModeMinTime) */

        #if(Motorpwm_Left_UseControl)
            Motorpwm_Left_backup.PWMControlRegister = Motorpwm_Left_ReadControlRegister();
        #endif /* (Motorpwm_Left_UseControl) */
    #endif  /* (!Motorpwm_Left_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Motorpwm_Left_RestoreConfig
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
*  Motorpwm_Left_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Motorpwm_Left_RestoreConfig(void) 
{
        #if(!Motorpwm_Left_UsingFixedFunction)
            #if(!Motorpwm_Left_PWMModeIsCenterAligned)
                Motorpwm_Left_WritePeriod(Motorpwm_Left_backup.PWMPeriod);
            #endif /* (!Motorpwm_Left_PWMModeIsCenterAligned) */

            Motorpwm_Left_WriteCounter(Motorpwm_Left_backup.PWMUdb);

            #if (Motorpwm_Left_UseStatus)
                Motorpwm_Left_STATUS_MASK = Motorpwm_Left_backup.InterruptMaskValue;
            #endif /* (Motorpwm_Left_UseStatus) */

            #if(Motorpwm_Left_DeadBandMode == Motorpwm_Left__B_PWM__DBM_256_CLOCKS || \
                Motorpwm_Left_DeadBandMode == Motorpwm_Left__B_PWM__DBM_2_4_CLOCKS)
                Motorpwm_Left_WriteDeadTime(Motorpwm_Left_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(Motorpwm_Left_KillModeMinTime)
                Motorpwm_Left_WriteKillTime(Motorpwm_Left_backup.PWMKillCounterPeriod);
            #endif /* (Motorpwm_Left_KillModeMinTime) */

            #if(Motorpwm_Left_UseControl)
                Motorpwm_Left_WriteControlRegister(Motorpwm_Left_backup.PWMControlRegister);
            #endif /* (Motorpwm_Left_UseControl) */
        #endif  /* (!Motorpwm_Left_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Motorpwm_Left_Sleep
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
*  Motorpwm_Left_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Motorpwm_Left_Sleep(void) 
{
    #if(Motorpwm_Left_UseControl)
        if(Motorpwm_Left_CTRL_ENABLE == (Motorpwm_Left_CONTROL & Motorpwm_Left_CTRL_ENABLE))
        {
            /*Component is enabled */
            Motorpwm_Left_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Motorpwm_Left_backup.PWMEnableState = 0u;
        }
    #endif /* (Motorpwm_Left_UseControl) */

    /* Stop component */
    Motorpwm_Left_Stop();

    /* Save registers configuration */
    Motorpwm_Left_SaveConfig();
}


/*******************************************************************************
* Function Name: Motorpwm_Left_Wakeup
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
*  Motorpwm_Left_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Motorpwm_Left_Wakeup(void) 
{
     /* Restore registers values */
    Motorpwm_Left_RestoreConfig();

    if(Motorpwm_Left_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Motorpwm_Left_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
