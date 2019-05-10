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

void searchBall(int calL, int calR, int PWML, int PWMR)
{
    mode_Write(0b00001010);
    Motorpwm_Left_WriteCompare (calL + PWML);
    Motorpwm_right_WriteCompare(calR + PWMR);   
}

void korFrem(int calL, int calR, int PWML, int PWMR) {
mode_Write(0b00001000);
Motorpwm_Left_WriteCompare (calL + PWML);
Motorpwm_right_WriteCompare(calR + PWMR);
}

void fastStop() {
mode_Write(0b00001001);
}

void stop(){
mode_Write(0b00000000);
}

void kortilbage(int calL, int calR, int PWML, int PWMR) {
mode_Write(0b00011110);
Motorpwm_Left_WriteCompare (calL + PWML);
Motorpwm_right_WriteCompare(calR + PWMR);
}

void drejHojre(int calL, int calR, int PWML, int PWMR){

mode_Write(0b00001010);
Motorpwm_Left_WriteCompare (calL + PWML);
Motorpwm_right_WriteCompare(calR + PWMR);
}

void drejVenstre(int calL, int calR, int PWML, int PWMR){

mode_Write(0b00001100);
Motorpwm_Left_WriteCompare (calL + PWML);
Motorpwm_right_WriteCompare(calR + PWMR);
}

/* [] END OF FILE */
