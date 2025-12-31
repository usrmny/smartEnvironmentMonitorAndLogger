#ifndef INC_LOG_H_
#define INC_LOG_H_

#include "stm32f4xx_hal.h"
#include "string.h"
#include "stdio.h"

void log_init(UART_HandleTypeDef *huart);
void log_store(UART_HandleTypeDef *huart);

#endif /* INC_LOG_H_ */
