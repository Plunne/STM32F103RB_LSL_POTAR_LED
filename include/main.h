#ifndef __MAIN_H
#define __MAIN_H

#include "lsl_io.h"

static LSL_Pinout POTAR = { GPIOA, 7, ADC_MODE };
static LSL_Pinout POTAR2 = { GPIOA, 6, ADC_MODE };
static LSL_Pinout LED = { GPIOA, 5, OUTPUT_MODE };

/* DIGITAL */
static LSL_Pinout *DIGITAL_Handler[] = {
    &LED
};

/* ANALOG */
static LSL_ANALOG_ADC_Handler ANALOG_ADC_Handler = {
    .adc        = ADC1,
    .nbChannels = 2,
    .adc_pinout = {
        &POTAR,
        &POTAR2
    }
};

#endif // __MAIN_H