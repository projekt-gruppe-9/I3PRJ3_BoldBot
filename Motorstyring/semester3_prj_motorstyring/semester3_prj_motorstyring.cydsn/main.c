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
#define search 0b00001111
#define backwards 0b00000011
#define stop_ 0b00000001
#define turn_r 0b0000010
#define turn_l 0b00000100
#define stop_f 0b00001000

#include "project.h"
#include "motorFunktioner.h"
#include "stdio.h"
CY_ISR_PROTO(ISR_SPIS_rx_handler);
uint8_t sendB_ = 0;
uint8_t slave_bytesReceived;
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
    SPIS_1_Start();
    SPIS_1_FIFO_CLR;
    ISR_SLAVE_RX_StartEx(ISR_SPIS_rx_handler);
    UART_1_Start();
        
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        switch(slave_bytesReceived){
            case search:
            {
                korFrem(ADC_calL_GetResult8(), ADC_calR_GetResult8(), 0, 0);
            }
            break;
            
            case backwards:
            {
                kortilbage();
            }
            break;
            case turn_l:
            {
                drejVenstre();
            }
            break;
            case turn_r:
            {
                drejHojre();
            }
            break;
            case stop_:
            {
                stop();
            }
            break;
            case stop_f:
            {
                fastStop();
            }
            break;
        }
    }
}

CY_ISR(ISR_SPIS_rx_handler){
        slave_bytesReceived = SPIS_1_ReadRxData(); //Læser dataen fra SPIS rx
        char buff[128];
        snprintf(buff,sizeof(buff),"Byte received: %d\n",slave_bytesReceived); //Formaterer data fra integer til string 
        UART_1_PutString(buff); //Skriver dataen ud på UART

        uint8_t num = 75;
        SPIS_1_WriteTxData(num);
        //sendB_++;
        SPIS_1_ClearFIFO();
        
    
    CyDelay(300);
}   


/* [] END OF FILE */
