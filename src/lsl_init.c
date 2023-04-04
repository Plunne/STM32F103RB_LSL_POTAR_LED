#include "lsl_init.h"

void LSL_Init_Registers(void) {

    LSL_Init_RCC();
    LSL_Init_GPIO();
	LSL_Init_TIMERS();

}

void LSL_Init_RCC(void) {

	/* RCC Setup */
	LSL_CLOCK_InitPLL(PLL_x9);					// PLL Multiplier x9
    LSL_CLOCK_PrescaleAPB(APB1_CLK, APB_DIV2); 	// APB1 Prescale /2

}

void LSL_Init_GPIO(void) {
	
	/* GPIO Setup */
	LSL_DIGITAL_Init(LSL_IO_Digital, QTY_DIGITAL_PINOUTS);
	LSL_ADC_InitSingle(&LSL_IO_Adc);

}

void LSL_Init_TIMERS(void) {

	/* TIMERS Setup */
	LSL_TIMER_Init(TIM2, 35999, 999, TIM2_IRQn);

}