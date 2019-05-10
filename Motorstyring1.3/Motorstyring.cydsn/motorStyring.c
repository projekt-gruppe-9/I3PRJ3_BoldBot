#include "motorStyring.h" 
void init_motorFunktioner() 
{
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
}

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

void korTilbage(int calL, int calR, int PWML, int PWMR) {
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
