#include "lsl_init.h"

/* Globals */
static int counter = 0;

/* Interrupts */
void TIM2_IRQHandler(void);
void USART2_IRQHandler(void);

/* Main */
int main(void) {

	/* Init Registers */
	LSL_Init_Registers();

	/* Init Variables */
	uint16_t adc_value = 0;

	/* User functions */
	LSL_USART_InteruptRx(&LSL_INIT_USART2);

	/* Super Loop */
	while (1) {

		LSL_DIGITAL_Write(&LED, HIGH);		
		LSL_UTILS_DelayMs(LSL_ADC_Read(&LSL_INIT_ADC1, &POTAR));
		LSL_DIGITAL_Write(&LED, LOW);		
		LSL_UTILS_DelayMs(LSL_ADC_Read(&LSL_INIT_ADC1, &POTAR2));

		// LSL_DISPLAY_Display7Seg(Display, counter, anode);
		// LSL_USART_Tx(&LSL_INIT_USART2, 'L');
		// LSL_USART_Tx(&LSL_INIT_USART2, 'E');
		// LSL_USART_Tx(&LSL_INIT_USART2, 'N');
		// LSL_USART_Tx(&LSL_INIT_USART2, 'A');
		// LSL_USART_Tx(&LSL_INIT_USART2, '\n');
		// LSL_UTILS_DelayMs(2000);
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

void USART2_IRQHandler(void) {

	if (USART2->SR & USART_SR_RXNE) {

		/* Interrupt instruction */
		counter = 10;

		/* Reset IRQ flag */
		USART2->SR &= ~USART_SR_RXNE;
	}
}