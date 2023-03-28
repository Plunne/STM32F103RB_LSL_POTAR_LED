#ifndef __LSL_ANALOG_H
#define __LSL_ANALOG_H

#include "lsl_pinouts.h"

#define NB_ADC_CHANNELS 16

typedef struct {
    ADC_TypeDef *adc;
    uint8_t nbChannels;
    LSL_Pinout *adc_pinout[NB_ADC_CHANNELS];
    uint16_t adc_channel[NB_ADC_CHANNELS];

} LSL_ANALOG_ADC_Handler;

/* Input */
void LSL_ANALOG_ADC_Init(LSL_ANALOG_ADC_Handler* ADC_Handler);
void LSL_ANALOG_ADC_Start(ADC_TypeDef* ADC);
void LSL_ANALOG_ADC_SetupDMA(ADC_TypeDef* ADC, uint16_t data_size, uint32_t data);
void LSL_ANALOG_ADC_SetConvNumber(ADC_TypeDef* ADC, uint8_t nbConv);
void LSL_ANALOG_ADC_SetSequence(ADC_TypeDef* ADC, uint8_t sequence, uint8_t channel);
void LSL_ANALOG_ADC_MultipleSequences(LSL_ANALOG_ADC_Handler* ADC_Handler);
void LSL_ANALOG_ADC_Calibrate(ADC_TypeDef* ADC);
uint16_t LSL_ANALOG_ADC_Read(ADC_TypeDef* ADC);

/* Output */
void LSL_ANALOG_Write(LSL_Pinout *pinout);

#endif // __LSL_DIGITAL_H