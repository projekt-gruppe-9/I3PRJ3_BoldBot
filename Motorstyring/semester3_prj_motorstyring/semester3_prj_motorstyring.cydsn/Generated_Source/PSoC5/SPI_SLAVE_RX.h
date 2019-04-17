/*******************************************************************************
* File Name: SPI_SLAVE_RX.h  
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

#if !defined(CY_PINS_SPI_SLAVE_RX_H) /* Pins SPI_SLAVE_RX_H */
#define CY_PINS_SPI_SLAVE_RX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SPI_SLAVE_RX_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SPI_SLAVE_RX__PORT == 15 && ((SPI_SLAVE_RX__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SPI_SLAVE_RX_Write(uint8 value);
void    SPI_SLAVE_RX_SetDriveMode(uint8 mode);
uint8   SPI_SLAVE_RX_ReadDataReg(void);
uint8   SPI_SLAVE_RX_Read(void);
void    SPI_SLAVE_RX_SetInterruptMode(uint16 position, uint16 mode);
uint8   SPI_SLAVE_RX_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SPI_SLAVE_RX_SetDriveMode() function.
     *  @{
     */
        #define SPI_SLAVE_RX_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SPI_SLAVE_RX_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SPI_SLAVE_RX_DM_RES_UP          PIN_DM_RES_UP
        #define SPI_SLAVE_RX_DM_RES_DWN         PIN_DM_RES_DWN
        #define SPI_SLAVE_RX_DM_OD_LO           PIN_DM_OD_LO
        #define SPI_SLAVE_RX_DM_OD_HI           PIN_DM_OD_HI
        #define SPI_SLAVE_RX_DM_STRONG          PIN_DM_STRONG
        #define SPI_SLAVE_RX_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SPI_SLAVE_RX_MASK               SPI_SLAVE_RX__MASK
#define SPI_SLAVE_RX_SHIFT              SPI_SLAVE_RX__SHIFT
#define SPI_SLAVE_RX_WIDTH              1u

/* Interrupt constants */
#if defined(SPI_SLAVE_RX__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SPI_SLAVE_RX_SetInterruptMode() function.
     *  @{
     */
        #define SPI_SLAVE_RX_INTR_NONE      (uint16)(0x0000u)
        #define SPI_SLAVE_RX_INTR_RISING    (uint16)(0x0001u)
        #define SPI_SLAVE_RX_INTR_FALLING   (uint16)(0x0002u)
        #define SPI_SLAVE_RX_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SPI_SLAVE_RX_INTR_MASK      (0x01u) 
#endif /* (SPI_SLAVE_RX__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SPI_SLAVE_RX_PS                     (* (reg8 *) SPI_SLAVE_RX__PS)
/* Data Register */
#define SPI_SLAVE_RX_DR                     (* (reg8 *) SPI_SLAVE_RX__DR)
/* Port Number */
#define SPI_SLAVE_RX_PRT_NUM                (* (reg8 *) SPI_SLAVE_RX__PRT) 
/* Connect to Analog Globals */                                                  
#define SPI_SLAVE_RX_AG                     (* (reg8 *) SPI_SLAVE_RX__AG)                       
/* Analog MUX bux enable */
#define SPI_SLAVE_RX_AMUX                   (* (reg8 *) SPI_SLAVE_RX__AMUX) 
/* Bidirectional Enable */                                                        
#define SPI_SLAVE_RX_BIE                    (* (reg8 *) SPI_SLAVE_RX__BIE)
/* Bit-mask for Aliased Register Access */
#define SPI_SLAVE_RX_BIT_MASK               (* (reg8 *) SPI_SLAVE_RX__BIT_MASK)
/* Bypass Enable */
#define SPI_SLAVE_RX_BYP                    (* (reg8 *) SPI_SLAVE_RX__BYP)
/* Port wide control signals */                                                   
#define SPI_SLAVE_RX_CTL                    (* (reg8 *) SPI_SLAVE_RX__CTL)
/* Drive Modes */
#define SPI_SLAVE_RX_DM0                    (* (reg8 *) SPI_SLAVE_RX__DM0) 
#define SPI_SLAVE_RX_DM1                    (* (reg8 *) SPI_SLAVE_RX__DM1)
#define SPI_SLAVE_RX_DM2                    (* (reg8 *) SPI_SLAVE_RX__DM2) 
/* Input Buffer Disable Override */
#define SPI_SLAVE_RX_INP_DIS                (* (reg8 *) SPI_SLAVE_RX__INP_DIS)
/* LCD Common or Segment Drive */
#define SPI_SLAVE_RX_LCD_COM_SEG            (* (reg8 *) SPI_SLAVE_RX__LCD_COM_SEG)
/* Enable Segment LCD */
#define SPI_SLAVE_RX_LCD_EN                 (* (reg8 *) SPI_SLAVE_RX__LCD_EN)
/* Slew Rate Control */
#define SPI_SLAVE_RX_SLW                    (* (reg8 *) SPI_SLAVE_RX__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SPI_SLAVE_RX_PRTDSI__CAPS_SEL       (* (reg8 *) SPI_SLAVE_RX__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SPI_SLAVE_RX_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SPI_SLAVE_RX__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SPI_SLAVE_RX_PRTDSI__OE_SEL0        (* (reg8 *) SPI_SLAVE_RX__PRTDSI__OE_SEL0) 
#define SPI_SLAVE_RX_PRTDSI__OE_SEL1        (* (reg8 *) SPI_SLAVE_RX__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SPI_SLAVE_RX_PRTDSI__OUT_SEL0       (* (reg8 *) SPI_SLAVE_RX__PRTDSI__OUT_SEL0) 
#define SPI_SLAVE_RX_PRTDSI__OUT_SEL1       (* (reg8 *) SPI_SLAVE_RX__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SPI_SLAVE_RX_PRTDSI__SYNC_OUT       (* (reg8 *) SPI_SLAVE_RX__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SPI_SLAVE_RX__SIO_CFG)
    #define SPI_SLAVE_RX_SIO_HYST_EN        (* (reg8 *) SPI_SLAVE_RX__SIO_HYST_EN)
    #define SPI_SLAVE_RX_SIO_REG_HIFREQ     (* (reg8 *) SPI_SLAVE_RX__SIO_REG_HIFREQ)
    #define SPI_SLAVE_RX_SIO_CFG            (* (reg8 *) SPI_SLAVE_RX__SIO_CFG)
    #define SPI_SLAVE_RX_SIO_DIFF           (* (reg8 *) SPI_SLAVE_RX__SIO_DIFF)
#endif /* (SPI_SLAVE_RX__SIO_CFG) */

/* Interrupt Registers */
#if defined(SPI_SLAVE_RX__INTSTAT)
    #define SPI_SLAVE_RX_INTSTAT            (* (reg8 *) SPI_SLAVE_RX__INTSTAT)
    #define SPI_SLAVE_RX_SNAP               (* (reg8 *) SPI_SLAVE_RX__SNAP)
    
	#define SPI_SLAVE_RX_0_INTTYPE_REG 		(* (reg8 *) SPI_SLAVE_RX__0__INTTYPE)
#endif /* (SPI_SLAVE_RX__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SPI_SLAVE_RX_H */


/* [] END OF FILE */
