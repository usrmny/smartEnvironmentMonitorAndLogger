#ifndef INC_LOG_H_
#define INC_LOG_H_

#include "stm32f4xx_hal.h"
#include "string.h"
#include "stdio.h"
#include "ff.h"
#include "diskio.h"

void log_init(UART_HandleTypeDef *huart);
void log_store(UART_HandleTypeDef *huart, float *lux, float *temperature, float *humidity);

#endif /* INC_LOG_H_ */
