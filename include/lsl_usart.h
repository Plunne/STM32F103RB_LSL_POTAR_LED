#ifndef LSL_USART_H
#define LSL_USART_H

#include "stm32f103xb.h"

// Table used for USART1
// MCU freq = 72MHz
// LSL_USART72_BAUD[x][0] = <MCU freq> / (<Baudrate> * 16)
// LSL_USART72_BAUD[x][1] = [decimals of "<MCU freq> / (<Baudrate> * 16)"] * 16
static uint16_t LSL_USART72_BAUD [5][2] = {
    {1875, 0},  // 2400 Bauds
    {468, 12},  // 9600 Bauds
    {234, 6},   // 19200 Bauds
    {78, 2},    // 57600 Bauds
    {39, 1}     // 115200 Bauds
};

// Table used for USART2 & USART3
// MCU freq = 36MHz
// LSL_USART36_BAUD[x][0] = <MCU freq> / (<Baudrate> * 16)
// LSL_USART36_BAUD[x][1] = [decimals of "<MCU freq> / (<Baudrate> * 16)"] * 16
static uint16_t LSL_USART36_BAUD [5][2] = {
    {937, 8},   // 2400 Bauds
    {234, 6},   // 9600 Bauds
    {117, 3},   // 19200 Bauds
    {39, 1},    // 57600 Bauds
    {19, 8}     // 115200 Bauds
};

/* Init */
void LSL_USART_Init(USART_TypeDef* USART, uint32_t baudrate, uint8_t data_size, uint8_t parity, uint8_t stop);

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
void LSL_USART_Tx(USART_TypeDef* USART, uint8_t data);

/* Receive */
uint8_t LSL_USART_Rx(USART_TypeDef* USART);

#endif // LSL_USART_H