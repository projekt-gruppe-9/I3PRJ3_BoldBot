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
#include "sonar.h"

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
	int dist = getDistance();
	if(dist < 30){
		Pin1_Write(1);
	} 
    else {
		Pin1_Write(0);
	}
}

/* [] END OF FILE */
