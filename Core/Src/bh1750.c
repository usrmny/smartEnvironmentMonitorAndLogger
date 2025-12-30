#include "bh1750.h"


//might not work, since haven't decided on pins yet...
void bh1750_init(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef *huart){

	//Power on (maybe add power off later on)
	uint8_t power_cmd = 0x01;
	HAL_I2C_Master_Transmit(hi2c, 0x23 << 1, &power_cmd, 1, 100);
}

void bh1750_read(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef *huart){

	uint8_t raw_data[2];
	uint8_t mode_cmd = 0x10;

	//write to sensor
	 HAL_I2C_Master_Transmit(hi2c, 0x23 << 1, &mode_cmd, 1, 100);
	 HAL_Delay(200);

	 HAL_I2C_Master_Receive(hi2c, 0x23 << 1, raw_data, 2, 100);

	 uint16_t raw_lux = ((uint16_t) raw_data[0] << 8) | ((uint16_t) raw_data[1]);
	 float lux = raw_lux / 1.2;


	 //display values
	 char uart_msg[64];
	 snprintf(uart_msg, sizeof(uart_msg), "Light: %.2f Lux\r\n", lux);
	 HAL_UART_Transmit(huart, (uint8_t*)uart_msg, strlen(uart_msg), 100);

	 /*
	 //check if data is ready to read
	 uint8_t status = 0xFF;
	 HAL_Delay(100);
	 do {
		 HAL_Delay(5);
		 HAL_I2C_Master_Receive(hi2c, 0x5C << 1, &status, 1, 100);
	 } while (status & 0x80);
	 *///ignore for now, get a working device first.


}
//NOTE: transmit and receive expect addresses, not storage/cmds directly
//NOTE2: PAY ATTENTION TO HOW YOU SOLDER!!! L != H
