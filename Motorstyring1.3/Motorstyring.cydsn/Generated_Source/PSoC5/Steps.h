/*******************************************************************************
* File Name: Steps.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Steps_H) /* Pins Steps_H */
#define CY_PINS_Steps_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Steps_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Steps__PORT == 15 && ((Steps__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Steps_Write(uint8 value);
void    Steps_SetDriveMode(uint8 mode);
uint8   Steps_ReadDataReg(void);
uint8   Steps_Read(void);
void    Steps_SetInterruptMode(uint16 position, uint16 mode);
uint8   Steps_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Steps_SetDriveMode() function.
     *  @{
     */
        #define Steps_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Steps_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Steps_DM_RES_UP          PIN_DM_RES_UP
        #define Steps_DM_RES_DWN         PIN_DM_RES_DWN
        #define Steps_DM_OD_LO           PIN_DM_OD_LO
        #define Steps_DM_OD_HI           PIN_DM_OD_HI
        #define Steps_DM_STRONG          PIN_DM_STRONG
        #define Steps_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Steps_MASK               Steps__MASK
#define Steps_SHIFT              Steps__SHIFT
#define Steps_WIDTH              1u

/* Interrupt constants */
#if defined(Steps__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Steps_SetInterruptMode() function.
     *  @{
     */
        #define Steps_INTR_NONE      (uint16)(0x0000u)
        #define Steps_INTR_RISING    (uint16)(0x0001u)
        #define Steps_INTR_FALLING   (uint16)(0x0002u)
        #define Steps_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Steps_INTR_MASK      (0x01u) 
#endif /* (Steps__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Steps_PS                     (* (reg8 *) Steps__PS)
/* Data Register */
#define Steps_DR                     (* (reg8 *) Steps__DR)
/* Port Number */
#define Steps_PRT_NUM                (* (reg8 *) Steps__PRT) 
/* Connect to Analog Globals */                                                  
#define Steps_AG                     (* (reg8 *) Steps__AG)                       
/* Analog MUX bux enable */
#define Steps_AMUX                   (* (reg8 *) Steps__AMUX) 
/* Bidirectional Enable */                                                        
#define Steps_BIE                    (* (reg8 *) Steps__BIE)
/* Bit-mask for Aliased Register Access */
#define Steps_BIT_MASK               (* (reg8 *) Steps__BIT_MASK)
/* Bypass Enable */
#define Steps_BYP                    (* (reg8 *) Steps__BYP)
/* Port wide control signals */                                                   
#define Steps_CTL                    (* (reg8 *) Steps__CTL)
/* Drive Modes */
#define Steps_DM0                    (* (reg8 *) Steps__DM0) 
#define Steps_DM1                    (* (reg8 *) Steps__DM1)
#define Steps_DM2                    (* (reg8 *) Steps__DM2) 
/* Input Buffer Disable Override */
#define Steps_INP_DIS                (* (reg8 *) Steps__INP_DIS)
/* LCD Common or Segment Drive */
#define Steps_LCD_COM_SEG            (* (reg8 *) Steps__LCD_COM_SEG)
/* Enable Segment LCD */
#define Steps_LCD_EN                 (* (reg8 *) Steps__LCD_EN)
/* Slew Rate Control */
#define Steps_SLW                    (* (reg8 *) Steps__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Steps_PRTDSI__CAPS_SEL       (* (reg8 *) Steps__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Steps_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Steps__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Steps_PRTDSI__OE_SEL0        (* (reg8 *) Steps__PRTDSI__OE_SEL0) 
#define Steps_PRTDSI__OE_SEL1        (* (reg8 *) Steps__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Steps_PRTDSI__OUT_SEL0       (* (reg8 *) Steps__PRTDSI__OUT_SEL0) 
#define Steps_PRTDSI__OUT_SEL1       (* (reg8 *) Steps__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Steps_PRTDSI__SYNC_OUT       (* (reg8 *) Steps__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Steps__SIO_CFG)
    #define Steps_SIO_HYST_EN        (* (reg8 *) Steps__SIO_HYST_EN)
    #define Steps_SIO_REG_HIFREQ     (* (reg8 *) Steps__SIO_REG_HIFREQ)
    #define Steps_SIO_CFG            (* (reg8 *) Steps__SIO_CFG)
    #define Steps_SIO_DIFF           (* (reg8 *) Steps__SIO_DIFF)
#endif /* (Steps__SIO_CFG) */

/* Interrupt Registers */
#if defined(Steps__INTSTAT)
    #define Steps_INTSTAT            (* (reg8 *) Steps__INTSTAT)
    #define Steps_SNAP               (* (reg8 *) Steps__SNAP)
    
	#define Steps_0_INTTYPE_REG 		(* (reg8 *) Steps__0__INTTYPE)
#endif /* (Steps__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Steps_H */


/* [] END OF FILE */
