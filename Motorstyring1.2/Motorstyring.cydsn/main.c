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
//Include filer 
#include "project.h"
#include "motorFunktioner.h"
#include "stdio.h"
#include "sonar.h"
//Variabler
#define searchBall_  1 
#define forwards    2
#define backwards   3
#define stop_       4
#define turn_r      5
#define turn_l      6
#define stop_f      7
//Prototyper
CY_ISR_PROTO(ISR_SPIS_rx_handler);
CY_ISR_PROTO(ISR_UART_rx_handler); 
void slaveBytesRec(uint8_t rec);
uint8_t sendB_ = 0;
uint8_t slave_bytesReceived;
uint8_t c; 
int calR = 0; 
int calL = 18; 
int PWML = 165; 
int PWMR = 165; 

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
    UART_rx_StartEx(ISR_UART_rx_handler);
    UART_1_Start(); 
    I2C_Master_Start();
        
    for(;;){
        slaveBytesRec(slave_bytesReceived); 
        //sendData();
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
        //++num; 
        SPIS_1_ClearFIFO();
        
    CyDelay(300);
}

CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        c = UART_1_ReadRxData();
        UART_1_WriteTxData(c); // echo back
        
        bytesToRead--;
    }
}

void slaveBytesRec(uint8_t rec){
    switch(rec){ 
        case searchBall_: 
        {
            searchBall(calL, calR, 150, 150); 
        }
        break; 
        case forwards:
        {
            korFrem(calL, calR, PWML, PWMR);
        }
        break;
        
        case backwards:
        {
            kortilbage(calL, calR, PWML, PWMR);
        }
        break;
        case turn_l:
        {
            drejVenstre(calL, 5, 0, 157);
        }
        break;
        case turn_r:
        {
            drejHojre(calL, calR, 157, 0);
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
        default: 
        {}
        break; 
    }
}
