#ifndef LSL_CONFIG_H
#define LSL_CONFIG_H

#include "lsl_adc.h"
#include "lsl_digital.h"
#include "lsl_timer.h"
#include "lsl_usart.h"
#include "lsl_display.h"

/* Analog */
LSL_Pinout POTAR;               // POTAR
// LSL_Pinout POTAR2;

/* Digital */
LSL_Pinout LED;                  // LED
LSL_Pinout Display[DIODE_NB];    // DISPLAY

/* Digital Quantity */
#define QTY_DIGITAL_PINOUTS     DIODE_NB + 1

/* Config Features */
void LSL_CONFIG_Init(void);
void LSL_CONFIG_Pinout(LSL_Pinout* pinout, GPIO_TypeDef* PORTx, uint8_t pin, uint8_t mode);

#endif // LSL_CONFIG_H