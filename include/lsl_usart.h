#ifndef __LSL_USART_H
#define __LSL_USART_H

#include "stm32f103xb.h"

// Table used for USART1
static uint16_t LSL_USART72_BAUD [5][2] = {
    {1875, 0},
    {468, 12},
    {234, 6},
    {78, 2},
    {39, 1}
};

// Table used for USART2 & USART3
static uint16_t LSL_USART36_BAUD [5][2] = {
    {937, 8},
    {234, 6},
    {117, 3},
    {39, 1},
    {19, 8}
};

/* Init */
void LSL_USART_Init(USART_TypeDef* USART, uint32_t baudrate, uint8_t nb_bits, uint8_t parity, uint8_t stop);

/* Baudrate */
void LSL_USART_InitBaudrate(USART_TypeDef* USART, uint32_t baudrate);
void LSL_USART_SetBaudrate(USART_TypeDef* USART, uint16_t *baudTable, uint32_t baudrate);

/* Transmit */
void LSL_USART_Tx(USART_TypeDef* USART, uint8_t c);

/* Receive */
uint8_t LSL_USART_Rx(USART_TypeDef* USART);

#endif // __LSL_USART_H