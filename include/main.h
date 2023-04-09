#ifndef MAIN_H
#define MAIN_H

#include "lsl_io.h"
#include "lsl_timer.h"
#include "lsl_display.h"

/*******************
 *     GLOBALS     *
 *******************/

static int counter = 0;

/*******************
 *     DIGITAL     *
 *******************/

// LED
static LSL_Pinout LED = { GPIOA, 5, OUTPUT_MODE };

// DISPLAY
static LSL_Pinout Display[DIODE_NB] = {
    { GPIOB, 12, OUTPUT_MODE },
    { GPIOB, 11, OUTPUT_MODE },
    { GPIOB, 14, OUTPUT_MODE },
    { GPIOB, 15, OUTPUT_MODE },
    { GPIOB, 1,  OUTPUT_MODE },
    { GPIOA, 11, OUTPUT_MODE },
    { GPIOA, 12, OUTPUT_MODE },
    { GPIOB, 13, OUTPUT_MODE }
};

/* Digital IO quantity */
static const uint8_t QTY_DIGITAL_PINOUTS = DIODE_NB + 1;

/* Digital Handler */
static LSL_Pinout *LSL_IO_Digital[] = {
    &LED,
    &Display[0],
    &Display[1],
    &Display[2],
    &Display[3],
    &Display[4],
    &Display[5],
    &Display[6],
    &Display[7]
};

/******************
 *     ANALOG     *
 ******************/

// POTAR
static LSL_Pinout POTAR = { GPIOA, 7, ADC_MODE };
// static LSL_Pinout POTAR2 = { GPIOA, 6, ADC_MODE };

/* Analog Handler */
static LSL_ADC_Handler LSL_IO_Adc = {
    .adc        = ADC1,
    .nbChannels = 1,
    .adc_pinout = {
        &POTAR
        // &POTAR2
    }
};

#endif // MAIN_H