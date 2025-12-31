#include "dht20.h"

void dht20_init(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef *huart){


	// Check if calibration is needed
	  uint8_t status = 0;
	  uint8_t cmdStatus = 0x71;

	  HAL_I2C_Master_Transmit(hi2c, 0x38 << 1, &cmdStatus, 1, 100);
	  HAL_I2C_Master_Receive(hi2c, 0x38 << 1, &status, 1, 100);



	  //should change this (sensor code shouldn't touch UART)
	  if ((status & 0x18) != 0x18) {
	      // Initialization failed, CALIBRATE
	      char fail_msg[] = "Sensor NOT ready!\r\n";
	      HAL_UART_Transmit(huart, (uint8_t*)fail_msg, strlen(fail_msg), 100);

	      //CALIBRATE (found at official website)
	  } else {
	      char ok_msg[] = "Sensor READY!\r\n";
	      HAL_UART_Transmit(huart, (uint8_t*)ok_msg, strlen(ok_msg), 100);
	  }
}

void dht20_read(I2C_HandleTypeDef *hi2c, float *temperature, float *humidity){

	uint8_t raw_data[7];

	//send command to start measuring
	 uint8_t cmd[3] = {0xAC, 0x33, 0x00};
	 HAL_I2C_Master_Transmit(hi2c, 0x38 << 1, cmd, 3, 100);


	 //check if data is ready to read
	 uint8_t status = 0xFF;
	 HAL_Delay(100);
	 do {
		 HAL_Delay(5);
		 HAL_I2C_Master_Receive(hi2c, 0x38 << 1, &status, 1, 100);
	 } while (status & 0x80); //status & 10000000 = ?0000000

	 //get data ([1:5]), [6] is CRC and [0] is state
	 HAL_I2C_Master_Receive(hi2c, 0x38 << 1, raw_data, 7, 100);

	 //convert data to actual values
	 uint32_t raw_humidity = ((uint32_t)(raw_data[1]) << 12) |
							 ((uint32_t)(raw_data[2]) << 4) |
							 ((uint32_t)(raw_data[3]) >> 4);

	 uint32_t raw_temp = (((uint32_t)(raw_data[3] & 0x0F)) << 16) |
						 ((uint32_t)(raw_data[4]) << 8) |
						 ((uint32_t)(raw_data[5]));

	 *humidity = (raw_humidity / 1048576.0f) * 100.0f;
	 *temperature = (raw_temp / 1048576.0f) * 200.0f - 50.0f;
}
