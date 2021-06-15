#include "uart.h"


void UART_SendMessage(UART_HandleTypeDef *huart1, char *message) {
	HAL_UART_Transmit(huart1, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
}
