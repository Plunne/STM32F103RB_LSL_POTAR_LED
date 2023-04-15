#ifndef LSL_CONFIG_H
#define LSL_CONFIG_H

#include "lsl_utils.h"
#include "lsl_adc.h"
#include "lsl_digital.h"
#include "lsl_timer.h"
#include "lsl_usart.h"
#include "lsl_display.h"

/* Analog */
LSL_Pinout POTAR;               // POTAR
LSL_Pinout POTAR2;

/* Digital */
LSL_Pinout LED;                 // LED
LSL_Pinout Display[DIODE_NB];   // DISPLAY

/* USART */
LSL_Pinout USART2_TX;           // USART2 TX (PA2)
LSL_Pinout USART2_RX;           // USART2 RX (PA3)

/* Config Features */
void LSL_CONFIG_Init(void);
void LSL_CONFIG_Pinout(LSL_Pinout* pinout, GPIO_TypeDef* PORTx, uint8_t pin, uint8_t mode);

#endif // LSL_CONFIG_H