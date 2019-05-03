/*******************************************************************************
* File Name: A_inv.h  
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

#if !defined(CY_PINS_A_inv_H) /* Pins A_inv_H */
#define CY_PINS_A_inv_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "A_inv_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 A_inv__PORT == 15 && ((A_inv__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    A_inv_Write(uint8 value);
void    A_inv_SetDriveMode(uint8 mode);
uint8   A_inv_ReadDataReg(void);
uint8   A_inv_Read(void);
void    A_inv_SetInterruptMode(uint16 position, uint16 mode);
uint8   A_inv_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the A_inv_SetDriveMode() function.
     *  @{
     */
        #define A_inv_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define A_inv_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define A_inv_DM_RES_UP          PIN_DM_RES_UP
        #define A_inv_DM_RES_DWN         PIN_DM_RES_DWN
        #define A_inv_DM_OD_LO           PIN_DM_OD_LO
        #define A_inv_DM_OD_HI           PIN_DM_OD_HI
        #define A_inv_DM_STRONG          PIN_DM_STRONG
        #define A_inv_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define A_inv_MASK               A_inv__MASK
#define A_inv_SHIFT              A_inv__SHIFT
#define A_inv_WIDTH              1u

/* Interrupt constants */
#if defined(A_inv__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in A_inv_SetInterruptMode() function.
     *  @{
     */
        #define A_inv_INTR_NONE      (uint16)(0x0000u)
        #define A_inv_INTR_RISING    (uint16)(0x0001u)
        #define A_inv_INTR_FALLING   (uint16)(0x0002u)
        #define A_inv_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define A_inv_INTR_MASK      (0x01u) 
#endif /* (A_inv__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define A_inv_PS                     (* (reg8 *) A_inv__PS)
/* Data Register */
#define A_inv_DR                     (* (reg8 *) A_inv__DR)
/* Port Number */
#define A_inv_PRT_NUM                (* (reg8 *) A_inv__PRT) 
/* Connect to Analog Globals */                                                  
#define A_inv_AG                     (* (reg8 *) A_inv__AG)                       
/* Analog MUX bux enable */
#define A_inv_AMUX                   (* (reg8 *) A_inv__AMUX) 
/* Bidirectional Enable */                                                        
#define A_inv_BIE                    (* (reg8 *) A_inv__BIE)
/* Bit-mask for Aliased Register Access */
#define A_inv_BIT_MASK               (* (reg8 *) A_inv__BIT_MASK)
/* Bypass Enable */
#define A_inv_BYP                    (* (reg8 *) A_inv__BYP)
/* Port wide control signals */                                                   
#define A_inv_CTL                    (* (reg8 *) A_inv__CTL)
/* Drive Modes */
#define A_inv_DM0                    (* (reg8 *) A_inv__DM0) 
#define A_inv_DM1                    (* (reg8 *) A_inv__DM1)
#define A_inv_DM2                    (* (reg8 *) A_inv__DM2) 
/* Input Buffer Disable Override */
#define A_inv_INP_DIS                (* (reg8 *) A_inv__INP_DIS)
/* LCD Common or Segment Drive */
#define A_inv_LCD_COM_SEG            (* (reg8 *) A_inv__LCD_COM_SEG)
/* Enable Segment LCD */
#define A_inv_LCD_EN                 (* (reg8 *) A_inv__LCD_EN)
/* Slew Rate Control */
#define A_inv_SLW                    (* (reg8 *) A_inv__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define A_inv_PRTDSI__CAPS_SEL       (* (reg8 *) A_inv__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define A_inv_PRTDSI__DBL_SYNC_IN    (* (reg8 *) A_inv__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define A_inv_PRTDSI__OE_SEL0        (* (reg8 *) A_inv__PRTDSI__OE_SEL0) 
#define A_inv_PRTDSI__OE_SEL1        (* (reg8 *) A_inv__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define A_inv_PRTDSI__OUT_SEL0       (* (reg8 *) A_inv__PRTDSI__OUT_SEL0) 
#define A_inv_PRTDSI__OUT_SEL1       (* (reg8 *) A_inv__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define A_inv_PRTDSI__SYNC_OUT       (* (reg8 *) A_inv__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(A_inv__SIO_CFG)
    #define A_inv_SIO_HYST_EN        (* (reg8 *) A_inv__SIO_HYST_EN)
    #define A_inv_SIO_REG_HIFREQ     (* (reg8 *) A_inv__SIO_REG_HIFREQ)
    #define A_inv_SIO_CFG            (* (reg8 *) A_inv__SIO_CFG)
    #define A_inv_SIO_DIFF           (* (reg8 *) A_inv__SIO_DIFF)
#endif /* (A_inv__SIO_CFG) */

/* Interrupt Registers */
#if defined(A_inv__INTSTAT)
    #define A_inv_INTSTAT            (* (reg8 *) A_inv__INTSTAT)
    #define A_inv_SNAP               (* (reg8 *) A_inv__SNAP)
    
	#define A_inv_0_INTTYPE_REG 		(* (reg8 *) A_inv__0__INTTYPE)
#endif /* (A_inv__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_A_inv_H */


/* [] END OF FILE */
