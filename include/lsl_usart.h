#ifndef LSL_USART_H
#define LSL_USART_H

#include "lsl_pinouts.h"

typedef struct {
    USART_TypeDef *usart;
    uint32_t bauds;
    uint8_t dataSize;
    uint8_t parity;
    uint8_t stop;
    LSL_Pinout *usart_pinout[2];

} LSL_USART_Handler;

/* Init */
void LSL_USART_Init(LSL_USART_Handler* USART_Handler);

/* Baudrate */
void LSL_USART_Baudrate(USART_TypeDef* USART, uint32_t baudrate);
void LSL_USART_SetBaudrate(USART_TypeDef* USART, uint16_t *baudTable, uint32_t baudrate);

/* Data Size */
void LSL_USART_DataSize(USART_TypeDef* USART, uint8_t data_size);

/* Parity */
void LSL_USART_Parity(USART_TypeDef* USART, uint8_t data_size, uint8_t parity);
void LSL_USART_EnableParity(USART_TypeDef* USART, uint8_t data_size);
void LSL_USART_SetParity(USART_TypeDef* USART, uint8_t parity);

/* Stop */
void LSL_USART_Stop(USART_TypeDef* USART, uint8_t stop);

/* Transmit */
void LSL_USART_Tx(LSL_USART_Handler* USART_Handler, uint8_t data);

/* Receive */
uint8_t LSL_USART_Rx(LSL_USART_Handler* USART_Handler);

#endif // LSL_USART_H