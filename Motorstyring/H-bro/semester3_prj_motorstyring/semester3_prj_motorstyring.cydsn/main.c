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
#include "project.h"
void korFrem(int calL, int calR, int PWML, int PWMR);
void fastStop();
void stop();
void kortilbage(int calL, int calR,int PWML, int PWMR);
void drejVenstre(int calL, int calR, int PWML, int PWMR);
void drejHojre(int calL, int calR, int PWML, int PWMR);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    Motorpwm_Left_Init();
    Motorpwm_right_Init();
    Motorpwm_right_Start();
    Motorpwm_Left_Start();
    ADC_calL_Init();
    ADC_calR_Init();
    ADC_calL_Start();
    ADC_calR_Start();
    ADC_calL_StartConvert();
    ADC_calR_StartConvert();
    
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        korFrem(ADC_calL_GetResult8(), ADC_calR_GetResult8(), 0, 0);
    }
}

void korFrem(int calL, int calR, int PWML, int PWMR) {
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
