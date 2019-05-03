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
void stepper_forward(uint8 steps);
void stepper_reverse(uint8 steps);
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        stepper_forward(10);
        
        CyDelay(3000);
    }
}

void stepper_init(){


}

void stepper_forward(uint8 steps) {

    Steps_Write(steps);
    Stepper_control_Write(0b00000001);
    Stepper_control_Write(0b00000000);

}

void stepper_reverse(uint8 steps) {

    Steps_Write(steps);
    Stepper_control_Write(0b00000011);
    Stepper_control_Write(0b00000010);

}


/* [] END OF FILE */
