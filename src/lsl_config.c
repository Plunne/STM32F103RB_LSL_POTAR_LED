#include "lsl_config.h"

/* Init */
void LSL_CONFIG_Init(void) {

    /******************
     *     ANALOG     *
     ******************/

    // POTAR
    LSL_CONFIG_Pinout(&POTAR, GPIOA, 7, ADC_MODE);
    LSL_CONFIG_Pinout(&POTAR2, GPIOA, 6, ADC_MODE);

    /*******************
     *     DIGITAL     *
     *******************/

    // LED
    LSL_CONFIG_Pinout(&LED, GPIOA, 5, OUTPUT_MODE);

    // DISPLAY
    LSL_CONFIG_Pinout(&Display[0], GPIOA, 8,  OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[1], GPIOB, 10, OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[2], GPIOA, 10, OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[3], GPIOB, 5,  OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[4], GPIOB, 1,  OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[5], GPIOB, 15, OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[6], GPIOB, 14, OUTPUT_MODE);
    LSL_CONFIG_Pinout(&Display[7], GPIOB, 13, OUTPUT_MODE);

    /*****************
     *     USART     *
     *****************/

    // USART2
    LSL_CONFIG_Pinout(&USART2_TX, GPIOA, 2, USART_TX);
    LSL_CONFIG_Pinout(&USART2_RX, GPIOA, 3, USART_RX);

}

/* Pinout */
void LSL_CONFIG_Pinout(LSL_Pinout* pinout, GPIO_TypeDef* PORTx, uint8_t pin, uint8_t mode) {

    /* Setup Pinout */
    pinout->PORTx = PORTx;
    pinout->pin = pin;
    pinout->mode = mode;

    /* Init Pinout */
    LSL_PINOUTS_InitPinout(pinout);

}