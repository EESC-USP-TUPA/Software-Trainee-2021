#include "uart.h"
#include "securityElements.h"
#include "adc.h"

extern adc_t adc;
extern uart_t uart;
extern ADC_HandleTypeDef hadc1;


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
    ADC_GetValues(adc.buffer, adc.data); //Faz a leitura dos dados

    sprintf(uart.message, "1: %ld - 2: %ld - 3: %ld\r\n", adc.data[0], adc.data[1], adc.data[2]);
    UART_SendMessage(uart.message);
    //Envia a mensagem via UART

    APPS_Check(adc.data);

    adc.apps = (adc.data[0] + adc.data[1]) / 2;
    BPPC_Check(adc.apps, adc.data[3]);

	return;
}


/**
  * @brief Inicia a leitura analógico-digital
  * @param Endereço do Handler do ADC e vetor de Buffer
  * @retval None
  */
void ADC_Init(uint32_t *ADC_Buffer) {
	HAL_ADC_Start_DMA(&hadc1, ADC_Buffer, ADC_CONVERSIONS);
	HAL_ADC_Start(&hadc1);
}

/**
  * @brief Faz a leitura e conversão do buffer para o vetor de dados
  * @param Vetor de Buffer e Vetor de destino dos dados
  * @retval None
  */
void ADC_GetValues(uint32_t *ADC_Buffer, uint32_t *ADC_Result) {
	for(int i = 0; i < ADC_CONVERSIONS; i++) {
		ADC_Result[i] = 100 * ADC_Buffer[i] / 4095;
	}
}

