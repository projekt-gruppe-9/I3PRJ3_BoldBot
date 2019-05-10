//Include filer 
#include "project.h"
#include "motorStyring.h"
#include "opsamlerStyring.h"
#include "sonarSensor.h" 
#include "stdio.h"
//SPI variabler
#define searchBall_ 0b00000001  //1
#define forwards    0b00000010  //2
#define backwards   0b00000011  //3
#define stop_       0b00000100  //4
#define turn_right  0b00000101  //5
#define turn_left   0b00000110  //6
#define stop_f      0b00000111  //7
#define pickup_down 0b00001000  //8 
#define pickup_up   0b00001001  //9
#define pickup_stop 0b00001010  //10
uint8_t slave_bytesRecieved; //spi read
//motorFunktioner variabler
int calR = 0; 
int calL = 0; 
int PWML = 165; 
int PWMR = 165;
//uart variabler
uint8_t uart_out; // global variable for UART output (for testing) 
//Prototyper
CY_ISR_PROTO(ISR_SPIS_rx_handler);
CY_ISR_PROTO(ISR_UART_rx_handler); 
CY_ISR_PROTO(ISR_I2C_MASTER_rx_handler); 
void slaveBytesRecieve(uint8_t rec);  
void uart_out_func(uint8_t rec); 

int main(void){
    /* Initiering af diverse funktioner, pins, SPI, I2C, UART */
    CyGlobalIntEnable; //Enable global interrupts. 
    SPIS_1_Start(); //Enable SPI
    SPIS_1_FIFO_CLR;
    ISR_SLAVE_RX_StartEx(ISR_SPIS_rx_handler); //enable SPI interrupt
    UART_rx_StartEx(ISR_UART_rx_handler); //Enable Uart (for test purposes)
    UART_1_Start(); //Enable Uart (for test purposes)
    I2C_Master_Start(); //Enable I2C for Sonar module
    stepper_init(); //Initiering af stepper motor
    init_motorFunktioner(); //motorfunktioner initiering
    /* Initiering slut */ 
  
    for(;;){
        sendData();
        slaveBytesRecieve(slave_bytesRecieved); //spi
        //uart_out_func(uart_out); //uart (for testing)
    }
}
//SPI interrupt 
CY_ISR(ISR_SPIS_rx_handler){
        slave_bytesRecieved = SPIS_1_ReadRxData(); //Læser dataen fra SPIS rx
        char buff[128];
        snprintf(buff,sizeof(buff),"Byte received: %d\n",slave_bytesRecieved); //Formaterer data fra integer til string 
        UART_1_PutString(buff); //Skriver dataen ud på UART

        uint8_t num = 75;
        SPIS_1_WriteTxData(num);
        SPIS_1_ClearFIFO();
        //SPIS_1_ClearRxBuffer();
        
        CyDelay(300);
}
//I2C interrupt
CY_ISR(ISR_I2C_Master_rx_handler){
    sendData();  
}

//UART interrupt (for testing only) 
CY_ISR(ISR_UART_rx_handler){
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uart_out = UART_1_ReadRxData();
        UART_1_WriteTxData(uart_out); // echo back
        
        bytesToRead--;
         
    }
}
//Switch case for spi 
void slaveBytesRecieve(uint8_t rec){
    switch(rec){ 
        case searchBall_: 
        {
            searchBall(calL, calR, PWML, PWMR);   
        }
        break; 
        case forwards:
        {
            korFrem(10, calR, PWML, PWMR);
        }
        break;
        case backwards:
        {
            korTilbage(calL, calR, PWML, PWMR);
        }
        break;
        case turn_left:
        {
            drejVenstre(calL, calR, 0, 170);  
        }
        break;
        case turn_right:
        {
            drejHojre(calL, calR, 170, 0); 
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
        case pickup_down: 
        {
   
            stepper_down(12); 
        }
        break;
         case pickup_up: 
        {
            stepper_up(12); 
        }
        break;
         case pickup_stop: 
        {
            stepper_stop(); 
          
        }
        break;
        default: 
        {}
        break; 
    }
}

//switch case for uart (only for testing) 
void uart_out_func(uint8_t rec){
    switch(rec){ 
        case '1': 
            {
               searchBall(calL, calR, PWML, PWMR);  
            }
            break; 
        case '2': 
            {
               korFrem(calL, calR, PWML, PWMR); 
            }
            break;
        case '3': 
            {
               korTilbage(calL, calR, PWML, PWMR);  
            }
            break;
        case '4': 
            {
               stop();  
            }
            break;
        case '5': 
            {
               drejHojre(calL, calR, 175, 0);  
            }
            break;
         case '6': 
            {
               drejVenstre(calL, calR, 0, 170); 
            }
            break;
        case '7': 
            {
               fastStop();  
            }
            break;
        case '8': 
            {
               stepper_down(12); 
            }
            break;
        case '9': 
            {
               stepper_up(12); 
            }
            break;
             case 'a': 
            {
               stepper_stop(); 
            }
            break;
        default: 
        {}
        break; 
       }
} 

