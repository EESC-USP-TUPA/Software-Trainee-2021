#include "adc.h"


void ADC_Init(ADC_HandleTypeDef *hadc1, uint32_t *ADC_Buffer) {
	HAL_ADC_Start_DMA(hadc1, ADC_Buffer, ADC_CONVERSIONS);
}


void ADC_GetValues(uint32_t *ADC_Buffer, uint32_t *ADC_Result) {
	for(int i = 0; i < ADC_CONVERSIONS; i++) {
		ADC_Result[i] = 100 * ADC_Buffer[i] / 4095;
	}
}

