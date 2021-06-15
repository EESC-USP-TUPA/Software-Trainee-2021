#include "adc.h"

/**
  * @brief Inicia a leitura analógico-digital
  * @param Endereço do Handler do ADC e vetor de Buffer
  * @retval None
  */
void ADC_Init(ADC_HandleTypeDef *hadc1, uint32_t *ADC_Buffer) {
	HAL_ADC_Start_DMA(hadc1, ADC_Buffer, ADC_CONVERSIONS);

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

