#ifndef SRC_UART_H_
#define SRC_UART_H_

#include "main.h"

typedef struct {
	char message[20];
} uart_t;


void UART_SendMessage(UART_HandleTypeDef *huart1, char *message);



#endif /* SRC_UART_H_ */
