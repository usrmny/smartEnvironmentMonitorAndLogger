#include "log.h"

FATFS fatfs;
FIL fil;
FRESULT fr;
UINT bytesWritten;

void log_init(UART_HandleTypeDef *huart){

	    // Give a work area to the default drive
	    for (int i = 0; i < 3; i++){
	    	fr = f_mount(&fatfs, ":0", 1);
	    	if (fr == FR_OK) break;

	    	HAL_Delay(500);
	    }
	    if (fr != FR_OK) printf("WARNING: fatfs counldn't initialize\n");

	    char uart_msg[64] = "------NEW CODE------\n\r";
	    HAL_UART_Transmit(huart, (uint8_t*)uart_msg, strlen(uart_msg), 100);
}


void log_store(UART_HandleTypeDef *huart, float *lux, float *temperature, float *humidity){

	fr = f_open(&fil, "0:/smart_environment_monitor.txt", FA_OPEN_ALWAYS | FA_WRITE);

	if(fr == FR_OK){
		char uart_msg[64];
		snprintf(uart_msg, sizeof(uart_msg), "Temp: %.2f C, Humidity: %.2f %%\r\nLight: %.2f Lux\r\n", *temperature, *humidity, *lux);
		HAL_UART_Transmit(huart, (uint8_t*)uart_msg, strlen(uart_msg), 100);
		f_write(&fil, uart_msg, strlen(uart_msg), &bytesWritten);

		//can add error check for f_write with bytes + check if FR_OK
	}

	char uart_msg[64];
	snprintf(uart_msg, sizeof(uart_msg), "Temp: %.2f C, Humidity: %.2f %%\r\nLight: %.2f Lux\r\n", *temperature, *humidity, *lux);
	HAL_UART_Transmit(huart, (uint8_t*)uart_msg, strlen(uart_msg), 100);

	f_close(&fil);
	f_mount(NULL, "", 0);
}

