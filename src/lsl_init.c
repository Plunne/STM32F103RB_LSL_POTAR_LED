#include "lsl_init.h"

void LSL_Init_Registers(void) {

    LSL_Init_RCC();
    LSL_Init_GPIO();

}

void LSL_Init_RCC(void) {

	/* RCC Settings */

}

void LSL_Init_GPIO(void) {
    
	LSL_DIGITAL_Init(LSL_IO_Digital, QTY_DIGITAL_PINOUTS);
	LSL_ADC_InitSingle(&LSL_IO_Adc);

}