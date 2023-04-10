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
    LSL_IO_Adc.adc              = ADC1;
    LSL_IO_Adc.nbChannels       = 1;
    LSL_IO_Adc.adc_pinout[0]    = &POTAR;

	/* ADC Init */
	LSL_ADC_InitSingle(&LSL_IO_Adc);

}

void LSL_Init_DIGITAL(void) {

    /* Digital Handler */
	LSL_IO_Digital[0] = &LED;
    LSL_IO_Digital[1] = &Display[0];
    LSL_IO_Digital[2] = &Display[1];
    LSL_IO_Digital[3] = &Display[2];
    LSL_IO_Digital[4] = &Display[3];
    LSL_IO_Digital[5] = &Display[4];
    LSL_IO_Digital[6] = &Display[5];
    LSL_IO_Digital[7] = &Display[6];
    LSL_IO_Digital[8] = &Display[7];

	/* Digital Init */	
	LSL_DIGITAL_Init(LSL_IO_Digital, QTY_DIGITAL_PINOUTS);

}

void LSL_Init_TIMERS(void) {

	/* TIMERS Setup */
	LSL_TIMER_Init(TIM2, 35999, 999, TIM2_IRQn);

}