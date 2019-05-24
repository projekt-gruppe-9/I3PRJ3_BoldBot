/*******************************************************************************
* File Name: sonarOutput.h  
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

#if !defined(CY_PINS_sonarOutput_H) /* Pins sonarOutput_H */
#define CY_PINS_sonarOutput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "sonarOutput_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 sonarOutput__PORT == 15 && ((sonarOutput__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    sonarOutput_Write(uint8 value);
void    sonarOutput_SetDriveMode(uint8 mode);
uint8   sonarOutput_ReadDataReg(void);
uint8   sonarOutput_Read(void);
void    sonarOutput_SetInterruptMode(uint16 position, uint16 mode);
uint8   sonarOutput_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the sonarOutput_SetDriveMode() function.
     *  @{
     */
        #define sonarOutput_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define sonarOutput_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define sonarOutput_DM_RES_UP          PIN_DM_RES_UP
        #define sonarOutput_DM_RES_DWN         PIN_DM_RES_DWN
        #define sonarOutput_DM_OD_LO           PIN_DM_OD_LO
        #define sonarOutput_DM_OD_HI           PIN_DM_OD_HI
        #define sonarOutput_DM_STRONG          PIN_DM_STRONG
        #define sonarOutput_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define sonarOutput_MASK               sonarOutput__MASK
#define sonarOutput_SHIFT              sonarOutput__SHIFT
#define sonarOutput_WIDTH              1u

/* Interrupt constants */
#if defined(sonarOutput__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in sonarOutput_SetInterruptMode() function.
     *  @{
     */
        #define sonarOutput_INTR_NONE      (uint16)(0x0000u)
        #define sonarOutput_INTR_RISING    (uint16)(0x0001u)
        #define sonarOutput_INTR_FALLING   (uint16)(0x0002u)
        #define sonarOutput_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define sonarOutput_INTR_MASK      (0x01u) 
#endif /* (sonarOutput__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define sonarOutput_PS                     (* (reg8 *) sonarOutput__PS)
/* Data Register */
#define sonarOutput_DR                     (* (reg8 *) sonarOutput__DR)
/* Port Number */
#define sonarOutput_PRT_NUM                (* (reg8 *) sonarOutput__PRT) 
/* Connect to Analog Globals */                                                  
#define sonarOutput_AG                     (* (reg8 *) sonarOutput__AG)                       
/* Analog MUX bux enable */
#define sonarOutput_AMUX                   (* (reg8 *) sonarOutput__AMUX) 
/* Bidirectional Enable */                                                        
#define sonarOutput_BIE                    (* (reg8 *) sonarOutput__BIE)
/* Bit-mask for Aliased Register Access */
#define sonarOutput_BIT_MASK               (* (reg8 *) sonarOutput__BIT_MASK)
/* Bypass Enable */
#define sonarOutput_BYP                    (* (reg8 *) sonarOutput__BYP)
/* Port wide control signals */                                                   
#define sonarOutput_CTL                    (* (reg8 *) sonarOutput__CTL)
/* Drive Modes */
#define sonarOutput_DM0                    (* (reg8 *) sonarOutput__DM0) 
#define sonarOutput_DM1                    (* (reg8 *) sonarOutput__DM1)
#define sonarOutput_DM2                    (* (reg8 *) sonarOutput__DM2) 
/* Input Buffer Disable Override */
#define sonarOutput_INP_DIS                (* (reg8 *) sonarOutput__INP_DIS)
/* LCD Common or Segment Drive */
#define sonarOutput_LCD_COM_SEG            (* (reg8 *) sonarOutput__LCD_COM_SEG)
/* Enable Segment LCD */
#define sonarOutput_LCD_EN                 (* (reg8 *) sonarOutput__LCD_EN)
/* Slew Rate Control */
#define sonarOutput_SLW                    (* (reg8 *) sonarOutput__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define sonarOutput_PRTDSI__CAPS_SEL       (* (reg8 *) sonarOutput__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define sonarOutput_PRTDSI__DBL_SYNC_IN    (* (reg8 *) sonarOutput__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define sonarOutput_PRTDSI__OE_SEL0        (* (reg8 *) sonarOutput__PRTDSI__OE_SEL0) 
#define sonarOutput_PRTDSI__OE_SEL1        (* (reg8 *) sonarOutput__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define sonarOutput_PRTDSI__OUT_SEL0       (* (reg8 *) sonarOutput__PRTDSI__OUT_SEL0) 
#define sonarOutput_PRTDSI__OUT_SEL1       (* (reg8 *) sonarOutput__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define sonarOutput_PRTDSI__SYNC_OUT       (* (reg8 *) sonarOutput__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(sonarOutput__SIO_CFG)
    #define sonarOutput_SIO_HYST_EN        (* (reg8 *) sonarOutput__SIO_HYST_EN)
    #define sonarOutput_SIO_REG_HIFREQ     (* (reg8 *) sonarOutput__SIO_REG_HIFREQ)
    #define sonarOutput_SIO_CFG            (* (reg8 *) sonarOutput__SIO_CFG)
    #define sonarOutput_SIO_DIFF           (* (reg8 *) sonarOutput__SIO_DIFF)
#endif /* (sonarOutput__SIO_CFG) */

/* Interrupt Registers */
#if defined(sonarOutput__INTSTAT)
    #define sonarOutput_INTSTAT            (* (reg8 *) sonarOutput__INTSTAT)
    #define sonarOutput_SNAP               (* (reg8 *) sonarOutput__SNAP)
    
	#define sonarOutput_0_INTTYPE_REG 		(* (reg8 *) sonarOutput__0__INTTYPE)
#endif /* (sonarOutput__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_sonarOutput_H */


/* [] END OF FILE */
