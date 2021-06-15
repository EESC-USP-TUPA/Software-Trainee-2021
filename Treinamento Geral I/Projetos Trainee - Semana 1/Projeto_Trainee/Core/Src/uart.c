#include "uart.h"

/**
  * @brief Envio de dados via UART
  * @param Endereço do Handler do UART e String a ser enviada
  * @retval None
  */
void UART_SendMessage(UART_HandleTypeDef *huart1, char *message) {
	HAL_UART_Transmit(huart1, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
}
