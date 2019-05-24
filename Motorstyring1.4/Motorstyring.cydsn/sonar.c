#include "sonarSensor.h"

uint16_t getDistance(){
	I2C_Master_MasterSendStart(0x70, I2C_Master_WRITE_XFER_MODE);
	I2C_Master_MasterWriteByte(0x51);
	CyDelay(100);
	I2C_Master_MasterSendRestart(0x70, 1);
    uint8_t first = I2C_Master_MasterReadByte(I2C_Master_ACK_DATA);
    uint8_t second = I2C_Master_MasterReadByte(I2C_Master_NAK_DATA);
	uint16_t distCM = first*256+second;
	I2C_Master_MasterSendStop();
	
	return distCM;
}

void sendData(){
    int minimum = 40; 
	int dist = getDistance();
	if(dist < minimum){
		sonarOutput_Write(1);
       UART_1_PutString("HIGH\n");  //for teting 
	} 
    else {
        UART_1_PutString("LOW\n"); //for testing
		sonarOutput_Write(0);
	}
}

/* [] END OF FILE */
