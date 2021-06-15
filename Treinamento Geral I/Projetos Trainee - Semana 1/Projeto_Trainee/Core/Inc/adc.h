#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "main.h"

#define ADC_CONVERSIONS 2

typedef struct {
	uint32_t buffer[ADC_CONVERSIONS];
	uint32_t data[ADC_CONVERSIONS];
} adc_t;


void ADC_Init(ADC_HandleTypeDef *hadc1, uint32_t *ADC_Buffer);
void ADC_GetValues(uint32_t *ADC_Buffer, uint32_t *ADC_Result);


#endif /* INC_ADC_H_ */



