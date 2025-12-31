#ifndef BH1750_H
#define BH1750_H

#include "stm32f4xx_hal.h"
#include "string.h"
#include "stdio.h"

void bh1750_init(I2C_HandleTypeDef *hi2c);
void bh1750_read(I2C_HandleTypeDef *hi2c, float *lux);

#endif /* BH1750_H */
