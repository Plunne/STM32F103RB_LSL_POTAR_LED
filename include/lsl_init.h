#ifndef LSL_INIT_H
#define LSL_INIT_H

#include "lsl_config.h"

/* Init All */
void LSL_Init_Registers(void);

/* Init Features */
void LSL_Init_RCC(void);
void LSL_Init_GPIO(void);
void LSL_Init_ADC(void);
void LSL_Init_DIGITAL(void);
void LSL_Init_TIMERS(void);

/* Digital Handler */
LSL_Pinout *LSL_IO_Digital[QTY_DIGITAL_PINOUTS];

/* Analog Handler */
LSL_ADC_Handler LSL_IO_Adc;

#endif // LSL_INIT_H