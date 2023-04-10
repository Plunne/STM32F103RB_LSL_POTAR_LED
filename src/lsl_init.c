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

	/* Config */	
	LSL_CONFIG_Init();
	LSL_Init_ADC();
	LSL_Init_DIGITAL();

}

void LSL_Init_ADC(void) {

	/* ADC Handler */
    LSL_INIT_ADC1.adc              = ADC1;
    LSL_INIT_ADC1.nbChannels       = 1;
    LSL_INIT_ADC1.adc_pinout[0]    = &POTAR;

	/* ADC Init */
	LSL_ADC_InitSingle(&LSL_INIT_ADC1);

}

void LSL_Init_DIGITAL(void) {

    /* Digital Handler */
	LSL_INIT_Digital[0] = &LED;
    LSL_INIT_Digital[1] = &Display[0];
    LSL_INIT_Digital[2] = &Display[1];
    LSL_INIT_Digital[3] = &Display[2];
    LSL_INIT_Digital[4] = &Display[3];
    LSL_INIT_Digital[5] = &Display[4];
    LSL_INIT_Digital[6] = &Display[5];
    LSL_INIT_Digital[7] = &Display[6];
    LSL_INIT_Digital[8] = &Display[7];

	/* Digital Init */	
	LSL_DIGITAL_Init(LSL_INIT_Digital, QTY_DIGITAL_PINOUTS);

}

void LSL_Init_USART(void) {

	/* USART Handler */
	LSL_INIT_USART1.usart 		= USART1;
	LSL_INIT_USART1.bauds 		= 115200;
	LSL_INIT_USART1.dataSize 	= 8;
	LSL_INIT_USART1.parity 		= 0;
	LSL_INIT_USART1.stop 		= 1;

	/* USART Init */
	LSL_USART_Init(&LSL_INIT_USART1);

}

void LSL_Init_TIMERS(void) {

	/* Timers Handler */
	LSL_INIT_TIMER2.timer = TIM2;
	LSL_INIT_TIMER2.prescaler = 35999;
	LSL_INIT_TIMER2.counter = 999;
	LSL_INIT_TIMER2.event = TIM2_IRQn;

	/* Timers Init */
	LSL_TIMER_Init(&LSL_INIT_TIMER2);

}