/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "motorFunktioner.h"
#define PWML 50
#define PWMR 50

void korFrem(int calL, int calR) {
mode_Write(0b00000000);
Motorpwm_Left_WriteCompare (calL + PWML);
Motorpwm_right_WriteCompare(calR + PWMR);

Enable_Right_Write(1);
Enable_Left_Write(1);
}

void fastStop() {

Enable_Right_Write(1);
Enable_Left_Write(1);
mode_Write(0b00000001);
}

void stop(){
Enable_Right_Write(0);
Enable_Left_Write(0);

}

void kortilbage(int calL, int calR, int PWML, int PWMR) {
mode_Write(0b00000110);
Motorpwm_Left_WriteCompare (calL + PWML);
Motorpwm_right_WriteCompare(calR + PWMR);
Enable_Right_Write(1);
Enable_Left_Write(1);

}

void drejVenstre(int calL, int calR, int PWML, int PWMR){

mode_Write(0b00000010);
Motorpwm_Left_WriteCompare (calL + PWML);
Motorpwm_right_WriteCompare(calR + PWMR);
Enable_Right_Write(1);
Enable_Left_Write(1);

}

void drejHojre(int calL, int calR, int PWML, int PWMR){

mode_Write(0b00000100);
Motorpwm_Left_WriteCompare (calL + PWML);
Motorpwm_right_WriteCompare(calR + PWMR);

}

/* [] END OF FILE */
