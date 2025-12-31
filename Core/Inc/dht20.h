#ifndef DHT20_H
#define DHT20_H

#include "stm32f4xx_hal.h" //Double check if error
#include "string.h"
#include "stdio.h"

void dht20_init(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef *huart);
void dht20_read(I2C_HandleTypeDef *hi2c, float *temperature, float *humidity);

#endif /* DHT20_H */
