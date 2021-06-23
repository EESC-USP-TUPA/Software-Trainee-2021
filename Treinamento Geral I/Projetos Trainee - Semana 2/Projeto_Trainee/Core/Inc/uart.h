#ifndef SRC_UART_H_
#define SRC_UART_H_

#include "main.h"

typedef struct {
	char message[30];
} uart_t;


void UART_SendMessage(char *message);



#endif /* SRC_UART_H_ */
