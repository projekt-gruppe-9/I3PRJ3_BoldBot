/*******************************************************************************
* File Name: B_inv.h  
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

#if !defined(CY_PINS_B_inv_H) /* Pins B_inv_H */
#define CY_PINS_B_inv_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "B_inv_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 B_inv__PORT == 15 && ((B_inv__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    B_inv_Write(uint8 value);
void    B_inv_SetDriveMode(uint8 mode);
uint8   B_inv_ReadDataReg(void);
uint8   B_inv_Read(void);
void    B_inv_SetInterruptMode(uint16 position, uint16 mode);
uint8   B_inv_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the B_inv_SetDriveMode() function.
     *  @{
     */
        #define B_inv_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define B_inv_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define B_inv_DM_RES_UP          PIN_DM_RES_UP
        #define B_inv_DM_RES_DWN         PIN_DM_RES_DWN
        #define B_inv_DM_OD_LO           PIN_DM_OD_LO
        #define B_inv_DM_OD_HI           PIN_DM_OD_HI
        #define B_inv_DM_STRONG          PIN_DM_STRONG
        #define B_inv_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define B_inv_MASK               B_inv__MASK
#define B_inv_SHIFT              B_inv__SHIFT
#define B_inv_WIDTH              1u

/* Interrupt constants */
#if defined(B_inv__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in B_inv_SetInterruptMode() function.
     *  @{
     */
        #define B_inv_INTR_NONE      (uint16)(0x0000u)
        #define B_inv_INTR_RISING    (uint16)(0x0001u)
        #define B_inv_INTR_FALLING   (uint16)(0x0002u)
        #define B_inv_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define B_inv_INTR_MASK      (0x01u) 
#endif /* (B_inv__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define B_inv_PS                     (* (reg8 *) B_inv__PS)
/* Data Register */
#define B_inv_DR                     (* (reg8 *) B_inv__DR)
/* Port Number */
#define B_inv_PRT_NUM                (* (reg8 *) B_inv__PRT) 
/* Connect to Analog Globals */                                                  
#define B_inv_AG                     (* (reg8 *) B_inv__AG)                       
/* Analog MUX bux enable */
#define B_inv_AMUX                   (* (reg8 *) B_inv__AMUX) 
/* Bidirectional Enable */                                                        
#define B_inv_BIE                    (* (reg8 *) B_inv__BIE)
/* Bit-mask for Aliased Register Access */
#define B_inv_BIT_MASK               (* (reg8 *) B_inv__BIT_MASK)
/* Bypass Enable */
#define B_inv_BYP                    (* (reg8 *) B_inv__BYP)
/* Port wide control signals */                                                   
#define B_inv_CTL                    (* (reg8 *) B_inv__CTL)
/* Drive Modes */
#define B_inv_DM0                    (* (reg8 *) B_inv__DM0) 
#define B_inv_DM1                    (* (reg8 *) B_inv__DM1)
#define B_inv_DM2                    (* (reg8 *) B_inv__DM2) 
/* Input Buffer Disable Override */
#define B_inv_INP_DIS                (* (reg8 *) B_inv__INP_DIS)
/* LCD Common or Segment Drive */
#define B_inv_LCD_COM_SEG            (* (reg8 *) B_inv__LCD_COM_SEG)
/* Enable Segment LCD */
#define B_inv_LCD_EN                 (* (reg8 *) B_inv__LCD_EN)
/* Slew Rate Control */
#define B_inv_SLW                    (* (reg8 *) B_inv__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define B_inv_PRTDSI__CAPS_SEL       (* (reg8 *) B_inv__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define B_inv_PRTDSI__DBL_SYNC_IN    (* (reg8 *) B_inv__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define B_inv_PRTDSI__OE_SEL0        (* (reg8 *) B_inv__PRTDSI__OE_SEL0) 
#define B_inv_PRTDSI__OE_SEL1        (* (reg8 *) B_inv__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define B_inv_PRTDSI__OUT_SEL0       (* (reg8 *) B_inv__PRTDSI__OUT_SEL0) 
#define B_inv_PRTDSI__OUT_SEL1       (* (reg8 *) B_inv__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define B_inv_PRTDSI__SYNC_OUT       (* (reg8 *) B_inv__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(B_inv__SIO_CFG)
    #define B_inv_SIO_HYST_EN        (* (reg8 *) B_inv__SIO_HYST_EN)
    #define B_inv_SIO_REG_HIFREQ     (* (reg8 *) B_inv__SIO_REG_HIFREQ)
    #define B_inv_SIO_CFG            (* (reg8 *) B_inv__SIO_CFG)
    #define B_inv_SIO_DIFF           (* (reg8 *) B_inv__SIO_DIFF)
#endif /* (B_inv__SIO_CFG) */

/* Interrupt Registers */
#if defined(B_inv__INTSTAT)
    #define B_inv_INTSTAT            (* (reg8 *) B_inv__INTSTAT)
    #define B_inv_SNAP               (* (reg8 *) B_inv__SNAP)
    
	#define B_inv_0_INTTYPE_REG 		(* (reg8 *) B_inv__0__INTTYPE)
#endif /* (B_inv__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_B_inv_H */


/* [] END OF FILE */
