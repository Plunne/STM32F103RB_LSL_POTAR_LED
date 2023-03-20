#include "main.h"
#include "lsl_init_regs.h"
#include "lsl_utils.h"
#include "lsl_io.h"
#include "lsl_display.h"

int main(void) {

	/* Init Registers */
	LSL_Init_Registers();

	/* Init ADC7/1 */
	// Enable ADC1
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

	// Set ADC Frequency (max allowed 14Mhz)
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;

	// Run ADC1 (ADON)
	ADC1->CR2 |= ADC_CR2_ADON;

	// Set number of conversions for ADC1
	ADC1->SQR1 &= ~(0xF << 20);	// Clear number of conversions
	ADC1->SQR1 |= (0x1 << 20);	// Set number of conversions (1 in this case)

	// Set conversion order for ADC1
	ADC1->SQR3 |= (7 << (5 * 0)); // Select ADC7 for the first conversion (ADC1_SQR3_SQ1 = 7)

	// Calibrate ADC1
	ADC1->CR2 |= ADC_CR2_CAL; // Calibrate ADC
	while(ADC1->CR2 & ADC_CR2_CAL); // Waiting for calibration

	/* Init Variables */
	uint16_t adc_value = 0;

	/* Super Loop */
	while (1) {

		// ADC1 Capture
		ADC1->CR2 |= ADC_CR2_ADON;			// Launch ADC capture
		while(!(ADC1->SR & ADC_SR_EOC));	// Waiting for capture
		ADC1->SR &= ~ADC_SR_EOC;			// Reset end of conversion flag

		// ADC1 Data
		adc_value = (uint16_t)(ADC1->DR & ~(0xF << 12)); // Get ADC Data without MSB Bits 12 -> 15 (because it's a 12bits ADC not 16)

		// Delay
		LSL_DIGITAL_Write(&LED, TOGGLE);
		LSL_UTILS_DelayMs(adc_value); 					// Delay (Be careful sw_cpt value depends of this delay)
	}
	
	return 0;
}