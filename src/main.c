#include "lsl_init.h"

/* Globals */
static int counter = 0;

/* Interrupts */
void TIM2_IRQHandler(void);

/* Main */
int main(void) {

	/* Init Registers */
	LSL_Init_Registers();

	/* Init Variables */
	uint16_t adc_value = 0;
	uint8_t letter = 'L';

	/* Super Loop */
	while (1) {

		LSL_DISPLAY_Display7Seg(Display, counter, anode);
		LSL_USART_Tx(&LSL_INIT_USART2, letter);
		LSL_UTILS_DelayMs(2000);
		/*
		adc_value = LSL_ADC_ReadSingleRange(&LSL_INIT_ADC1, 2, 7); // Get ADC Data without MSB Bits 12 -> 15 (because it's a 12bits ADC not 16)
		
		// Delay
		LSL_DISPLAY_Display7Seg(Display, adc_value, anode);
		LSL_DIGITAL_Write(&LED, TOGGLE);
		LSL_UTILS_DelayMs(adc_value); 					// Delay (Be careful sw_cpt value depends of this delay)
		*/

		// LSL_DIGITAL_Write(&LED, TOGGLE);		
		// LSL_UTILS_DelayMs(LSL_ANALOG_ADC_Read(&ANALOG_ADC_Handler, &POTAR));
		// LSL_DIGITAL_Write(&LED, LOW);		
		// LSL_UTILS_DelayMs(LSL_ANALOG_ADC_Read(&ANALOG_ADC_Handler, &POTAR2));
	}
	
	return 0;
}

/**********************
 *     Interrupts     *
 **********************/

void TIM2_IRQHandler(void) {
	
	if (TIM2->SR & TIM_SR_UIF) {
		
		/* Interrupt instruction */
		counter = (1 + counter) % 10;
		
		/* Reset IRQ flag */
		TIM2->SR &= ~TIM_SR_UIF;
	}
}