#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "main.h"

#define ADC_CONVERSIONS 3 //Quantidade de leituras analógicas que desejamos fazer

//Estrutura com as informações do ADC
typedef struct {
	uint32_t buffer[ADC_CONVERSIONS];
	uint32_t data[ADC_CONVERSIONS];
	uint32_t apps, bse;
} adc_t;


//void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc); //Callback do ADC
void ADC_Init(uint32_t *ADC_Buffer); //Iniciar o ADC
void ADC_GetValues(uint32_t *ADC_Buffer, uint32_t *ADC_Result); //Ler dados do ADC


#endif /* INC_ADC_H_ */



