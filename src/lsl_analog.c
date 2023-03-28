#include "lsl_analog.h"

/* Init */
void LSL_ANALOG_ADC_Init(LSL_ANALOG_ADC_Handler* ADC_Handler) {

	uint16_t data = 0;
	LSL_ANALOG_ADC_Start(ADC_Handler->adc);
	LSL_ANALOG_ADC_SetupDMA(ADC_Handler->adc, ADC_Handler->nbChannels, data);
	LSL_ANALOG_ADC_SetConvNumber(ADC_Handler->adc, ADC_Handler->nbChannels);
	LSL_ANALOG_ADC_MultipleSequences(ADC_Handler);
	LSL_ANALOG_ADC_Calibrate(ADC_Handler->adc);
}

/* Input */
void LSL_ANALOG_ADC_Start(ADC_TypeDef* ADC) {

	// Enable ADC
	if (ADC == ADC1) RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; // Enable ADC1
	else if (ADC == ADC2) RCC->APB2ENR |= RCC_APB2ENR_ADC2EN; // Enable ADC2
	else return;
	
	// Set ADC Frequency (max allowed 14Mhz)
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;

	// Enable scan mode
	ADC->CR1 |= ADC_CR1_SCAN;
	
	// Enable continuous conversion
	//ADC->CR2 |= ADC_CR2_CONT;

	// Run ADC (ADON)
	ADC->CR2 |= ADC_CR2_ADON;

}

void LSL_ANALOG_ADC_SetupDMA(ADC_TypeDef* ADC, uint16_t data_size, uint32_t data) {

	DMA_Channel_TypeDef *DMA;

	if (ADC == ADC1) {
		DMA = DMA1_Channel1; // DMA is DMA1_Channel1 (check reference manual DMA Request mapping)
		RCC->AHBENR |= RCC_AHBENR_DMA1EN; // Enable DMA Clock
	}
	else return;

	// Enable DMA for ADC
	ADC->CR2 |= ADC_CR2_DMA;

	// Data registers sizes
	// 00 = 8b / 01 = 16b / 10 = 32b / 11 = reserved
	DMA->CCR |= (0b01 << DMA_CCR_MSIZE_Pos); // Set Data Memory Acces size (12bits -> 16bits)
	DMA->CCR |= (0b01 << DMA_CCR_PSIZE_Pos); // Set Peripheral ADC Data Register value size (12bits -> 16bits)
	
	// DMA Settings
	DMA->CCR |= DMA_CCR_MINC; 	// Enable Memory Increment to stack data in successive registers
	DMA->CCR |= DMA_CCR_CIRC; 	// Enable Circular mode for ADC
	DMA->CCR |= DMA_CCR_DIR; 	// Set Peripheral read value to Memory

	// DMA Addresses
	DMA->CNDTR = data_size; // Captured value size (12bits -> 16bits)
	DMA->CPAR = &ADC->DR;	// ADC Data register address
	DMA->CMAR = data;		// Data address to DMA Data Register

	// Start DMA
	DMA->CCR |= DMA_CCR_EN; // Enable DMA

}

void LSL_ANALOG_ADC_SetConvNumber(ADC_TypeDef* ADC, uint8_t nbConv) {
		
	// If there is a number of conversion
	if (nbConv && (nbConv <= 16)) { 
		
		nbConv--;
		
		// Set number of conversions for ADC
		ADC->SQR1 &= ~(0xF << 20);	// Clear number of conversions
		if (nbConv && (nbConv <= 16)) ADC->SQR1 |= (nbConv << 20);	// Set number of conversions
	}
}

void LSL_ANALOG_ADC_SetSequence(ADC_TypeDef* ADC, uint8_t sequence, uint8_t channel) {

	// Set conversion
	if ((sequence > 0) && (sequence <= 6)) {
		ADC->SQR3 &= ~(0x1F << (5 * (sequence - 1))); 	// Clear Sequence channel for the conversion (ADCx_SQR3_SQ1_6 = 0)
		ADC->SQR3 |= (channel << (5 * (sequence - 1))); // Select ADC pin 1_6 for the conversion (ADCx_SQR3_SQ1_6 = pin)
	}
	else if ((sequence > 6) && (sequence <= 12)) {
		ADC->SQR2 &= ~(0x1F << (5 * (sequence - 1))); 	// Clear Sequence channel for the conversion (ADCx_SQR2_SQ6_12 = 0)
		ADC->SQR2 |= (channel << (5 * (sequence - 1))); // Select ADC pin 7_12 for the conversion (ADCx_SQR2_SQ6_12 = pin)
	}
	else if ((sequence > 12) && (sequence <= 16)) {
		ADC->SQR1 &= ~(0x1F << (5 * (sequence - 1))); 	// Clear Sequence channel for the conversion (ADCx_SQR1_SQ13_16 = 0)
		ADC->SQR1 |= (channel << (5 * (sequence - 1))); // Select ADC pin 13_16 for the conversion (ADCx_SQR1_SQ13_16) = pin)
	}
}

void LSL_ANALOG_ADC_MultipleSequences(LSL_ANALOG_ADC_Handler* ADC_Handler) {
	for (int i=0; i < ADC_Handler->nbChannels; i++) {
		LSL_PINOUTS_InitPinout(ADC_Handler->adc_pinout[i]);
		LSL_ANALOG_ADC_SetSequence(ADC_Handler->adc, i + 1, ADC_Handler->adc_pinout[i]->pin);
	}
}

void LSL_ANALOG_ADC_Calibrate(ADC_TypeDef* ADC) {

	// Calibrate ADC
	ADC->CR2 |= ADC_CR2_CAL; // Calibrate ADC
	while(ADC->CR2 & ADC_CR2_CAL); // Waiting for calibration
}

uint16_t LSL_ANALOG_ADC_Read(ADC_TypeDef* ADC) {

		// ADC1 Capture
		ADC->CR2 |= ADC_CR2_ADON;			// Launch ADC capture
		while(!(ADC->SR & ADC_SR_EOC));	// Waiting for capture
		ADC->SR &= ~ADC_SR_EOC;			// Reset end of conversion flag

		// ADC1 Data
		return (uint16_t)(ADC->DR & ~(0xF << 12)); // Get ADC Data without MSB Bits 12 -> 15 (because it's a 12bits ADC not 16)
}

/* Output */
void LSL_ANALOG_Write(LSL_Pinout *pinout) {

}