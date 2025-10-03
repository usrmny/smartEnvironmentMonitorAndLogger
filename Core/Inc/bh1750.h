#ifndef BH1750_H
#define BH1750_H

#include "stm32f4xx_hal.h"
#include "string.h"
#include "stdio.h"

void bh1750_init(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef *huart);
void bh1750_read(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef *huart);

#endif /* BH1750_H */
