#include "securityElements.h"
#include "uart.h"

extern errors_t errors;

void startProtocol() {
	//Enquanto o botão não for pressionado, fique preso
	while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) != GPIO_PIN_SET);

	//Após pressionamento do botão, acenda o LED em PB9
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);

	//Seta os valores de erro iniciais para zero
	errors.APPS = 0;
	errors.BPPC = 0;

	//Aciona o LED em PB13 (buzzer) por 2 segundos
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
	HAL_Delay(2000);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);

}


void turnOff() {
	//Envia mensagem de desligamento e trava o código
	char message[20];
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	sprintf(message, "Turning off\r\n");
	UART_SendMessage(message);
	while(1);
}


void APPS_Check(uint32_t *APPS_Data) {
	//Verifica se a diferença entre os pedais é superior a 10%
	if((int)(APPS_Data[0] - APPS_Data[1]) > 10 || (int)(APPS_Data[0] - APPS_Data[1]) < -10) {
		//Caso seja, indica erro e encerra o programa
		errors.APPS = 1;
		turnOff();
	}
}


void BPPC_Check(uint32_t APPS, uint32_t BSE) {
	if((int)APPS > 25 && (int)BSE > 10) {
		errors.BPPC = 1;
		turnOff();
	}
}






