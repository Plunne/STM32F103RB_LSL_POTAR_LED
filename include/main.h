#ifndef __MAIN_H
#define __MAIN_H

#include "lsl_io.h"
#include "lsl_display.h"

static LSL_Pinout DISPLAY[DIODE_NB] = {
    { GPIOB, 12, OUTPUT_MODE},
    { GPIOB, 11, OUTPUT_MODE},
    { GPIOB, 14, OUTPUT_MODE},
    { GPIOB, 15, OUTPUT_MODE},
    { GPIOB, 1,  OUTPUT_MODE},
    { GPIOA, 11, OUTPUT_MODE},
    { GPIOA, 12, OUTPUT_MODE},
    { GPIOB, 13, OUTPUT_MODE}
};

static LSL_Pinout POTAR = { GPIOA, 7, ADC_MODE };
// static LSL_Pinout POTAR2 = { GPIOA, 6, ADC_MODE };

static LSL_Pinout LED = { GPIOA, 5, OUTPUT_MODE };

/* DIGITAL */
static LSL_Pinout *DIGITAL_Handler[] = {
    &LED,
    DISPLAY
};

/* ANALOG */
static LSL_ANALOG_ADC_Handler ANALOG_ADC_Handler = {
    .adc        = ADC1,
    .nbChannels = 1,
    .adc_pinout = {
        &POTAR
        // &POTAR2
    }
};

#endif // __MAIN_H