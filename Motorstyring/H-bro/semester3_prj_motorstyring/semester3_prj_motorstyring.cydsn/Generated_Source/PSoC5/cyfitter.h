/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* mode */
#define mode_Sync_ctrl_reg__0__MASK 0x01u
#define mode_Sync_ctrl_reg__0__POS 0
#define mode_Sync_ctrl_reg__1__MASK 0x02u
#define mode_Sync_ctrl_reg__1__POS 1
#define mode_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define mode_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB13_14_CTL
#define mode_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB13_14_CTL
#define mode_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB13_14_CTL
#define mode_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB13_14_CTL
#define mode_Sync_ctrl_reg__16BIT_MASK_MASK_REG CYREG_B0_UDB13_14_MSK
#define mode_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB13_14_MSK
#define mode_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB13_14_MSK
#define mode_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB13_14_MSK
#define mode_Sync_ctrl_reg__2__MASK 0x04u
#define mode_Sync_ctrl_reg__2__POS 2
#define mode_Sync_ctrl_reg__CONTROL_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define mode_Sync_ctrl_reg__CONTROL_REG CYREG_B0_UDB13_CTL
#define mode_Sync_ctrl_reg__CONTROL_ST_REG CYREG_B0_UDB13_ST_CTL
#define mode_Sync_ctrl_reg__COUNT_REG CYREG_B0_UDB13_CTL
#define mode_Sync_ctrl_reg__COUNT_ST_REG CYREG_B0_UDB13_ST_CTL
#define mode_Sync_ctrl_reg__MASK 0x07u
#define mode_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define mode_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define mode_Sync_ctrl_reg__PERIOD_REG CYREG_B0_UDB13_MSK

/* cal_L */
#define cal_L__0__INTTYPE CYREG_PICU2_INTTYPE6
#define cal_L__0__MASK 0x40u
#define cal_L__0__PC CYREG_PRT2_PC6
#define cal_L__0__PORT 2u
#define cal_L__0__SHIFT 6u
#define cal_L__AG CYREG_PRT2_AG
#define cal_L__AMUX CYREG_PRT2_AMUX
#define cal_L__BIE CYREG_PRT2_BIE
#define cal_L__BIT_MASK CYREG_PRT2_BIT_MASK
#define cal_L__BYP CYREG_PRT2_BYP
#define cal_L__CTL CYREG_PRT2_CTL
#define cal_L__DM0 CYREG_PRT2_DM0
#define cal_L__DM1 CYREG_PRT2_DM1
#define cal_L__DM2 CYREG_PRT2_DM2
#define cal_L__DR CYREG_PRT2_DR
#define cal_L__INP_DIS CYREG_PRT2_INP_DIS
#define cal_L__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define cal_L__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define cal_L__LCD_EN CYREG_PRT2_LCD_EN
#define cal_L__MASK 0x40u
#define cal_L__PORT 2u
#define cal_L__PRT CYREG_PRT2_PRT
#define cal_L__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define cal_L__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define cal_L__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define cal_L__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define cal_L__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define cal_L__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define cal_L__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define cal_L__PS CYREG_PRT2_PS
#define cal_L__SHIFT 6u
#define cal_L__SLW CYREG_PRT2_SLW

/* cal_R */
#define cal_R__0__INTTYPE CYREG_PICU2_INTTYPE7
#define cal_R__0__MASK 0x80u
#define cal_R__0__PC CYREG_PRT2_PC7
#define cal_R__0__PORT 2u
#define cal_R__0__SHIFT 7u
#define cal_R__AG CYREG_PRT2_AG
#define cal_R__AMUX CYREG_PRT2_AMUX
#define cal_R__BIE CYREG_PRT2_BIE
#define cal_R__BIT_MASK CYREG_PRT2_BIT_MASK
#define cal_R__BYP CYREG_PRT2_BYP
#define cal_R__CTL CYREG_PRT2_CTL
#define cal_R__DM0 CYREG_PRT2_DM0
#define cal_R__DM1 CYREG_PRT2_DM1
#define cal_R__DM2 CYREG_PRT2_DM2
#define cal_R__DR CYREG_PRT2_DR
#define cal_R__INP_DIS CYREG_PRT2_INP_DIS
#define cal_R__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define cal_R__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define cal_R__LCD_EN CYREG_PRT2_LCD_EN
#define cal_R__MASK 0x80u
#define cal_R__PORT 2u
#define cal_R__PRT CYREG_PRT2_PRT
#define cal_R__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define cal_R__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define cal_R__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define cal_R__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define cal_R__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define cal_R__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define cal_R__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define cal_R__PS CYREG_PRT2_PS
#define cal_R__SHIFT 7u
#define cal_R__SLW CYREG_PRT2_SLW

/* Clock_1 */
#define Clock_1__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define Clock_1__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define Clock_1__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define Clock_1__INDEX 0x00u
#define Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_1__PM_ACT_MSK 0x01u
#define Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_1__PM_STBY_MSK 0x01u

/* ADC_calL */
#define ADC_calL_ADC_SAR__CLK CYREG_SAR0_CLK
#define ADC_calL_ADC_SAR__CSR0 CYREG_SAR0_CSR0
#define ADC_calL_ADC_SAR__CSR1 CYREG_SAR0_CSR1
#define ADC_calL_ADC_SAR__CSR2 CYREG_SAR0_CSR2
#define ADC_calL_ADC_SAR__CSR3 CYREG_SAR0_CSR3
#define ADC_calL_ADC_SAR__CSR4 CYREG_SAR0_CSR4
#define ADC_calL_ADC_SAR__CSR5 CYREG_SAR0_CSR5
#define ADC_calL_ADC_SAR__CSR6 CYREG_SAR0_CSR6
#define ADC_calL_ADC_SAR__PM_ACT_CFG CYREG_PM_ACT_CFG11
#define ADC_calL_ADC_SAR__PM_ACT_MSK 0x01u
#define ADC_calL_ADC_SAR__PM_STBY_CFG CYREG_PM_STBY_CFG11
#define ADC_calL_ADC_SAR__PM_STBY_MSK 0x01u
#define ADC_calL_ADC_SAR__SW0 CYREG_SAR0_SW0
#define ADC_calL_ADC_SAR__SW2 CYREG_SAR0_SW2
#define ADC_calL_ADC_SAR__SW3 CYREG_SAR0_SW3
#define ADC_calL_ADC_SAR__SW4 CYREG_SAR0_SW4
#define ADC_calL_ADC_SAR__SW6 CYREG_SAR0_SW6
#define ADC_calL_ADC_SAR__TR0 CYREG_SAR0_TR0
#define ADC_calL_ADC_SAR__WRK0 CYREG_SAR0_WRK0
#define ADC_calL_ADC_SAR__WRK1 CYREG_SAR0_WRK1
#define ADC_calL_IRQ__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define ADC_calL_IRQ__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define ADC_calL_IRQ__INTC_MASK 0x01u
#define ADC_calL_IRQ__INTC_NUMBER 0u
#define ADC_calL_IRQ__INTC_PRIOR_NUM 7u
#define ADC_calL_IRQ__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define ADC_calL_IRQ__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define ADC_calL_IRQ__INTC_SET_PD_REG CYREG_NVIC_SETPEND0
#define ADC_calL_theACLK__CFG0 CYREG_CLKDIST_ACFG1_CFG0
#define ADC_calL_theACLK__CFG1 CYREG_CLKDIST_ACFG1_CFG1
#define ADC_calL_theACLK__CFG2 CYREG_CLKDIST_ACFG1_CFG2
#define ADC_calL_theACLK__CFG2_SRC_SEL_MASK 0x07u
#define ADC_calL_theACLK__CFG3 CYREG_CLKDIST_ACFG1_CFG3
#define ADC_calL_theACLK__CFG3_PHASE_DLY_MASK 0x0Fu
#define ADC_calL_theACLK__INDEX 0x01u
#define ADC_calL_theACLK__PM_ACT_CFG CYREG_PM_ACT_CFG1
#define ADC_calL_theACLK__PM_ACT_MSK 0x02u
#define ADC_calL_theACLK__PM_STBY_CFG CYREG_PM_STBY_CFG1
#define ADC_calL_theACLK__PM_STBY_MSK 0x02u

/* ADC_calR */
#define ADC_calR_ADC_SAR__CLK CYREG_SAR1_CLK
#define ADC_calR_ADC_SAR__CSR0 CYREG_SAR1_CSR0
#define ADC_calR_ADC_SAR__CSR1 CYREG_SAR1_CSR1
#define ADC_calR_ADC_SAR__CSR2 CYREG_SAR1_CSR2
#define ADC_calR_ADC_SAR__CSR3 CYREG_SAR1_CSR3
#define ADC_calR_ADC_SAR__CSR4 CYREG_SAR1_CSR4
#define ADC_calR_ADC_SAR__CSR5 CYREG_SAR1_CSR5
#define ADC_calR_ADC_SAR__CSR6 CYREG_SAR1_CSR6
#define ADC_calR_ADC_SAR__PM_ACT_CFG CYREG_PM_ACT_CFG11
#define ADC_calR_ADC_SAR__PM_ACT_MSK 0x02u
#define ADC_calR_ADC_SAR__PM_STBY_CFG CYREG_PM_STBY_CFG11
#define ADC_calR_ADC_SAR__PM_STBY_MSK 0x02u
#define ADC_calR_ADC_SAR__SW0 CYREG_SAR1_SW0
#define ADC_calR_ADC_SAR__SW2 CYREG_SAR1_SW2
#define ADC_calR_ADC_SAR__SW3 CYREG_SAR1_SW3
#define ADC_calR_ADC_SAR__SW4 CYREG_SAR1_SW4
#define ADC_calR_ADC_SAR__SW6 CYREG_SAR1_SW6
#define ADC_calR_ADC_SAR__TR0 CYREG_SAR1_TR0
#define ADC_calR_ADC_SAR__WRK0 CYREG_SAR1_WRK0
#define ADC_calR_ADC_SAR__WRK1 CYREG_SAR1_WRK1
#define ADC_calR_IRQ__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define ADC_calR_IRQ__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define ADC_calR_IRQ__INTC_MASK 0x02u
#define ADC_calR_IRQ__INTC_NUMBER 1u
#define ADC_calR_IRQ__INTC_PRIOR_NUM 7u
#define ADC_calR_IRQ__INTC_PRIOR_REG CYREG_NVIC_PRI_1
#define ADC_calR_IRQ__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define ADC_calR_IRQ__INTC_SET_PD_REG CYREG_NVIC_SETPEND0
#define ADC_calR_theACLK__CFG0 CYREG_CLKDIST_ACFG0_CFG0
#define ADC_calR_theACLK__CFG1 CYREG_CLKDIST_ACFG0_CFG1
#define ADC_calR_theACLK__CFG2 CYREG_CLKDIST_ACFG0_CFG2
#define ADC_calR_theACLK__CFG2_SRC_SEL_MASK 0x07u
#define ADC_calR_theACLK__CFG3 CYREG_CLKDIST_ACFG0_CFG3
#define ADC_calR_theACLK__CFG3_PHASE_DLY_MASK 0x0Fu
#define ADC_calR_theACLK__INDEX 0x00u
#define ADC_calR_theACLK__PM_ACT_CFG CYREG_PM_ACT_CFG1
#define ADC_calR_theACLK__PM_ACT_MSK 0x01u
#define ADC_calR_theACLK__PM_STBY_CFG CYREG_PM_STBY_CFG1
#define ADC_calR_theACLK__PM_STBY_MSK 0x01u

/* Motor_L_F */
#define Motor_L_F__0__INTTYPE CYREG_PICU2_INTTYPE4
#define Motor_L_F__0__MASK 0x10u
#define Motor_L_F__0__PC CYREG_PRT2_PC4
#define Motor_L_F__0__PORT 2u
#define Motor_L_F__0__SHIFT 4u
#define Motor_L_F__AG CYREG_PRT2_AG
#define Motor_L_F__AMUX CYREG_PRT2_AMUX
#define Motor_L_F__BIE CYREG_PRT2_BIE
#define Motor_L_F__BIT_MASK CYREG_PRT2_BIT_MASK
#define Motor_L_F__BYP CYREG_PRT2_BYP
#define Motor_L_F__CTL CYREG_PRT2_CTL
#define Motor_L_F__DM0 CYREG_PRT2_DM0
#define Motor_L_F__DM1 CYREG_PRT2_DM1
#define Motor_L_F__DM2 CYREG_PRT2_DM2
#define Motor_L_F__DR CYREG_PRT2_DR
#define Motor_L_F__INP_DIS CYREG_PRT2_INP_DIS
#define Motor_L_F__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Motor_L_F__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Motor_L_F__LCD_EN CYREG_PRT2_LCD_EN
#define Motor_L_F__MASK 0x10u
#define Motor_L_F__PORT 2u
#define Motor_L_F__PRT CYREG_PRT2_PRT
#define Motor_L_F__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Motor_L_F__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Motor_L_F__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Motor_L_F__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Motor_L_F__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Motor_L_F__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Motor_L_F__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Motor_L_F__PS CYREG_PRT2_PS
#define Motor_L_F__SHIFT 4u
#define Motor_L_F__SLW CYREG_PRT2_SLW

/* Motor_L_R */
#define Motor_L_R__0__INTTYPE CYREG_PICU2_INTTYPE5
#define Motor_L_R__0__MASK 0x20u
#define Motor_L_R__0__PC CYREG_PRT2_PC5
#define Motor_L_R__0__PORT 2u
#define Motor_L_R__0__SHIFT 5u
#define Motor_L_R__AG CYREG_PRT2_AG
#define Motor_L_R__AMUX CYREG_PRT2_AMUX
#define Motor_L_R__BIE CYREG_PRT2_BIE
#define Motor_L_R__BIT_MASK CYREG_PRT2_BIT_MASK
#define Motor_L_R__BYP CYREG_PRT2_BYP
#define Motor_L_R__CTL CYREG_PRT2_CTL
#define Motor_L_R__DM0 CYREG_PRT2_DM0
#define Motor_L_R__DM1 CYREG_PRT2_DM1
#define Motor_L_R__DM2 CYREG_PRT2_DM2
#define Motor_L_R__DR CYREG_PRT2_DR
#define Motor_L_R__INP_DIS CYREG_PRT2_INP_DIS
#define Motor_L_R__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Motor_L_R__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Motor_L_R__LCD_EN CYREG_PRT2_LCD_EN
#define Motor_L_R__MASK 0x20u
#define Motor_L_R__PORT 2u
#define Motor_L_R__PRT CYREG_PRT2_PRT
#define Motor_L_R__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Motor_L_R__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Motor_L_R__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Motor_L_R__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Motor_L_R__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Motor_L_R__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Motor_L_R__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Motor_L_R__PS CYREG_PRT2_PS
#define Motor_L_R__SHIFT 5u
#define Motor_L_R__SLW CYREG_PRT2_SLW

/* Motor_R_F */
#define Motor_R_F__0__INTTYPE CYREG_PICU2_INTTYPE1
#define Motor_R_F__0__MASK 0x02u
#define Motor_R_F__0__PC CYREG_PRT2_PC1
#define Motor_R_F__0__PORT 2u
#define Motor_R_F__0__SHIFT 1u
#define Motor_R_F__AG CYREG_PRT2_AG
#define Motor_R_F__AMUX CYREG_PRT2_AMUX
#define Motor_R_F__BIE CYREG_PRT2_BIE
#define Motor_R_F__BIT_MASK CYREG_PRT2_BIT_MASK
#define Motor_R_F__BYP CYREG_PRT2_BYP
#define Motor_R_F__CTL CYREG_PRT2_CTL
#define Motor_R_F__DM0 CYREG_PRT2_DM0
#define Motor_R_F__DM1 CYREG_PRT2_DM1
#define Motor_R_F__DM2 CYREG_PRT2_DM2
#define Motor_R_F__DR CYREG_PRT2_DR
#define Motor_R_F__INP_DIS CYREG_PRT2_INP_DIS
#define Motor_R_F__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Motor_R_F__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Motor_R_F__LCD_EN CYREG_PRT2_LCD_EN
#define Motor_R_F__MASK 0x02u
#define Motor_R_F__PORT 2u
#define Motor_R_F__PRT CYREG_PRT2_PRT
#define Motor_R_F__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Motor_R_F__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Motor_R_F__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Motor_R_F__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Motor_R_F__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Motor_R_F__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Motor_R_F__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Motor_R_F__PS CYREG_PRT2_PS
#define Motor_R_F__SHIFT 1u
#define Motor_R_F__SLW CYREG_PRT2_SLW

/* Motor_R_R */
#define Motor_R_R__0__INTTYPE CYREG_PICU2_INTTYPE2
#define Motor_R_R__0__MASK 0x04u
#define Motor_R_R__0__PC CYREG_PRT2_PC2
#define Motor_R_R__0__PORT 2u
#define Motor_R_R__0__SHIFT 2u
#define Motor_R_R__AG CYREG_PRT2_AG
#define Motor_R_R__AMUX CYREG_PRT2_AMUX
#define Motor_R_R__BIE CYREG_PRT2_BIE
#define Motor_R_R__BIT_MASK CYREG_PRT2_BIT_MASK
#define Motor_R_R__BYP CYREG_PRT2_BYP
#define Motor_R_R__CTL CYREG_PRT2_CTL
#define Motor_R_R__DM0 CYREG_PRT2_DM0
#define Motor_R_R__DM1 CYREG_PRT2_DM1
#define Motor_R_R__DM2 CYREG_PRT2_DM2
#define Motor_R_R__DR CYREG_PRT2_DR
#define Motor_R_R__INP_DIS CYREG_PRT2_INP_DIS
#define Motor_R_R__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Motor_R_R__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Motor_R_R__LCD_EN CYREG_PRT2_LCD_EN
#define Motor_R_R__MASK 0x04u
#define Motor_R_R__PORT 2u
#define Motor_R_R__PRT CYREG_PRT2_PRT
#define Motor_R_R__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Motor_R_R__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Motor_R_R__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Motor_R_R__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Motor_R_R__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Motor_R_R__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Motor_R_R__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Motor_R_R__PS CYREG_PRT2_PS
#define Motor_R_R__SHIFT 2u
#define Motor_R_R__SLW CYREG_PRT2_SLW

/* Enable_Left */
#define Enable_Left__0__INTTYPE CYREG_PICU2_INTTYPE3
#define Enable_Left__0__MASK 0x08u
#define Enable_Left__0__PC CYREG_PRT2_PC3
#define Enable_Left__0__PORT 2u
#define Enable_Left__0__SHIFT 3u
#define Enable_Left__AG CYREG_PRT2_AG
#define Enable_Left__AMUX CYREG_PRT2_AMUX
#define Enable_Left__BIE CYREG_PRT2_BIE
#define Enable_Left__BIT_MASK CYREG_PRT2_BIT_MASK
#define Enable_Left__BYP CYREG_PRT2_BYP
#define Enable_Left__CTL CYREG_PRT2_CTL
#define Enable_Left__DM0 CYREG_PRT2_DM0
#define Enable_Left__DM1 CYREG_PRT2_DM1
#define Enable_Left__DM2 CYREG_PRT2_DM2
#define Enable_Left__DR CYREG_PRT2_DR
#define Enable_Left__INP_DIS CYREG_PRT2_INP_DIS
#define Enable_Left__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Enable_Left__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Enable_Left__LCD_EN CYREG_PRT2_LCD_EN
#define Enable_Left__MASK 0x08u
#define Enable_Left__PORT 2u
#define Enable_Left__PRT CYREG_PRT2_PRT
#define Enable_Left__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Enable_Left__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Enable_Left__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Enable_Left__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Enable_Left__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Enable_Left__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Enable_Left__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Enable_Left__PS CYREG_PRT2_PS
#define Enable_Left__SHIFT 3u
#define Enable_Left__SLW CYREG_PRT2_SLW

/* Enable_Right */
#define Enable_Right__0__INTTYPE CYREG_PICU2_INTTYPE0
#define Enable_Right__0__MASK 0x01u
#define Enable_Right__0__PC CYREG_PRT2_PC0
#define Enable_Right__0__PORT 2u
#define Enable_Right__0__SHIFT 0u
#define Enable_Right__AG CYREG_PRT2_AG
#define Enable_Right__AMUX CYREG_PRT2_AMUX
#define Enable_Right__BIE CYREG_PRT2_BIE
#define Enable_Right__BIT_MASK CYREG_PRT2_BIT_MASK
#define Enable_Right__BYP CYREG_PRT2_BYP
#define Enable_Right__CTL CYREG_PRT2_CTL
#define Enable_Right__DM0 CYREG_PRT2_DM0
#define Enable_Right__DM1 CYREG_PRT2_DM1
#define Enable_Right__DM2 CYREG_PRT2_DM2
#define Enable_Right__DR CYREG_PRT2_DR
#define Enable_Right__INP_DIS CYREG_PRT2_INP_DIS
#define Enable_Right__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Enable_Right__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Enable_Right__LCD_EN CYREG_PRT2_LCD_EN
#define Enable_Right__MASK 0x01u
#define Enable_Right__PORT 2u
#define Enable_Right__PRT CYREG_PRT2_PRT
#define Enable_Right__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Enable_Right__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Enable_Right__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Enable_Right__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Enable_Right__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Enable_Right__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Enable_Right__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Enable_Right__PS CYREG_PRT2_PS
#define Enable_Right__SHIFT 0u
#define Enable_Right__SLW CYREG_PRT2_SLW

/* Motorpwm_Left */
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB14_15_ACTL
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB14_15_CTL
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB14_15_CTL
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB14_15_CTL
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB14_15_CTL
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG CYREG_B0_UDB14_15_MSK
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB14_15_MSK
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB14_15_MSK
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB14_15_MSK
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__7__MASK 0x80u
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__7__POS 7
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB14_ACTL
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__CONTROL_REG CYREG_B0_UDB14_CTL
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB14_ST_CTL
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__COUNT_REG CYREG_B0_UDB14_CTL
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG CYREG_B0_UDB14_ST_CTL
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__MASK 0x80u
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB14_MSK_ACTL
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB14_MSK_ACTL
#define Motorpwm_Left_PWMUDB_genblk1_ctrlreg__PERIOD_REG CYREG_B0_UDB14_MSK
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__0__MASK 0x01u
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__0__POS 0
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB14_15_ACTL
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG CYREG_B0_UDB14_15_ST
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__2__MASK 0x04u
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__2__POS 2
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__3__MASK 0x08u
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__3__POS 3
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__MASK 0x0Du
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__MASK_REG CYREG_B0_UDB14_MSK
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG CYREG_B0_UDB14_MSK_ACTL
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG CYREG_B0_UDB14_MSK_ACTL
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG CYREG_B0_UDB14_ACTL
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__STATUS_CNT_REG CYREG_B0_UDB14_ST_CTL
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG CYREG_B0_UDB14_ST_CTL
#define Motorpwm_Left_PWMUDB_genblk8_stsreg__STATUS_REG CYREG_B0_UDB14_ST
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG CYREG_B0_UDB14_15_A0
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG CYREG_B0_UDB14_15_A1
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG CYREG_B0_UDB14_15_D0
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG CYREG_B0_UDB14_15_D1
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB14_15_ACTL
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG CYREG_B0_UDB14_15_F0
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG CYREG_B0_UDB14_15_F1
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__A0_A1_REG CYREG_B0_UDB14_A0_A1
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__A0_REG CYREG_B0_UDB14_A0
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__A1_REG CYREG_B0_UDB14_A1
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__D0_D1_REG CYREG_B0_UDB14_D0_D1
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__D0_REG CYREG_B0_UDB14_D0
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__D1_REG CYREG_B0_UDB14_D1
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB14_ACTL
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__F0_F1_REG CYREG_B0_UDB14_F0_F1
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__F0_REG CYREG_B0_UDB14_F0
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__F1_REG CYREG_B0_UDB14_F1
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB14_MSK_ACTL
#define Motorpwm_Left_PWMUDB_sP8_pwmdp_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB14_MSK_ACTL

/* Motorpwm_right */
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB12_13_CTL
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB12_13_CTL
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB12_13_CTL
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB12_13_CTL
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG CYREG_B0_UDB12_13_MSK
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB12_13_MSK
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB12_13_MSK
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB12_13_MSK
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__7__MASK 0x80u
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__7__POS 7
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__CONTROL_REG CYREG_B0_UDB12_CTL
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB12_ST_CTL
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__COUNT_REG CYREG_B0_UDB12_CTL
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG CYREG_B0_UDB12_ST_CTL
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__MASK 0x80u
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB12_MSK_ACTL
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB12_MSK_ACTL
#define Motorpwm_right_PWMUDB_genblk1_ctrlreg__PERIOD_REG CYREG_B0_UDB12_MSK
#define Motorpwm_right_PWMUDB_genblk8_stsreg__0__MASK 0x01u
#define Motorpwm_right_PWMUDB_genblk8_stsreg__0__POS 0
#define Motorpwm_right_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define Motorpwm_right_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG CYREG_B0_UDB13_14_ST
#define Motorpwm_right_PWMUDB_genblk8_stsreg__2__MASK 0x04u
#define Motorpwm_right_PWMUDB_genblk8_stsreg__2__POS 2
#define Motorpwm_right_PWMUDB_genblk8_stsreg__3__MASK 0x08u
#define Motorpwm_right_PWMUDB_genblk8_stsreg__3__POS 3
#define Motorpwm_right_PWMUDB_genblk8_stsreg__MASK 0x0Du
#define Motorpwm_right_PWMUDB_genblk8_stsreg__MASK_REG CYREG_B0_UDB13_MSK
#define Motorpwm_right_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define Motorpwm_right_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define Motorpwm_right_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define Motorpwm_right_PWMUDB_genblk8_stsreg__STATUS_CNT_REG CYREG_B0_UDB13_ST_CTL
#define Motorpwm_right_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG CYREG_B0_UDB13_ST_CTL
#define Motorpwm_right_PWMUDB_genblk8_stsreg__STATUS_REG CYREG_B0_UDB13_ST
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG CYREG_B0_UDB13_14_A0
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG CYREG_B0_UDB13_14_A1
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG CYREG_B0_UDB13_14_D0
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG CYREG_B0_UDB13_14_D1
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG CYREG_B0_UDB13_14_F0
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG CYREG_B0_UDB13_14_F1
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__A0_A1_REG CYREG_B0_UDB13_A0_A1
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__A0_REG CYREG_B0_UDB13_A0
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__A1_REG CYREG_B0_UDB13_A1
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__D0_D1_REG CYREG_B0_UDB13_D0_D1
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__D0_REG CYREG_B0_UDB13_D0
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__D1_REG CYREG_B0_UDB13_D1
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__F0_F1_REG CYREG_B0_UDB13_F0_F1
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__F0_REG CYREG_B0_UDB13_F0
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__F1_REG CYREG_B0_UDB13_F1
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define Motorpwm_right_PWMUDB_sP8_pwmdp_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "semester3_prj_motorstyring"
#define CY_VERSION "PSoC Creator  4.2"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 21u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 21u
#define CYDEV_CHIP_MEMBER_4D 16u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 22u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 20u
#define CYDEV_CHIP_MEMBER_4I 26u
#define CYDEV_CHIP_MEMBER_4J 17u
#define CYDEV_CHIP_MEMBER_4K 18u
#define CYDEV_CHIP_MEMBER_4L 25u
#define CYDEV_CHIP_MEMBER_4M 24u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 23u
#define CYDEV_CHIP_MEMBER_4Q 14u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 19u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 15u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 27u
#define CYDEV_CHIP_MEMBER_FM3 31u
#define CYDEV_CHIP_MEMBER_FM4 32u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 28u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 29u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 30u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000003u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
