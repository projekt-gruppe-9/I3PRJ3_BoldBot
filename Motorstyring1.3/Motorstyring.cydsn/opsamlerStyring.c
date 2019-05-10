#include "project.h"
#include "opsamlerStyring.h"

void stepper_init(){
    stepper_up(12);
}
void stepper_up(uint8_t steps) {
    
    Steps_1_Write(steps);
    Stepper_control_Write(0b00000000);
}
void stepper_down(uint8_t steps) {
    Steps_1_Write(steps);
    Stepper_control_Write(0b00000010);
}

void stepper_stop(){
Stepper_control_Write(0b00000001);
}
/* [] END OF FILE */
