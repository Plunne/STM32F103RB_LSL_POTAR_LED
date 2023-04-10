#include "lsl_config.h"

/* Init */
void LSL_CONFIG_Init(void) {

    /******************
     *     ANALOG     *
     ******************/

    // POTAR
    LSL_CONFIG_Pinout(&POTAR, GPIOA, 7, ADC_MODE);
    // LSL_CONFIG_Pinout(&POTAR2, GPIOA, 6, ADC_MODE);

    /*******************
     *     DIGITAL     *
     *******************/

    // LED
    LSL_CONFIG_Pinout(&LED, GPIOA, 5, OUTPUT_MODE);

    // DISPLAY
    LSL_CONFIG_Pinout(&Display[0], GPIOB, 12, OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[1], GPIOB, 11, OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[2], GPIOB, 14, OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[3], GPIOB, 15, OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[4], GPIOB, 1,  OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[5], GPIOA, 11, OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[6], GPIOA, 12, OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[7], GPIOB, 13, OUTPUT_MODE);

}

/* Pinout */
void LSL_CONFIG_Pinout(LSL_Pinout* pinout, GPIO_TypeDef* PORTx, uint8_t pin, uint8_t mode) {

    pinout->PORTx = PORTx;
    pinout->pin = pin;
    pinout->mode = mode;

}