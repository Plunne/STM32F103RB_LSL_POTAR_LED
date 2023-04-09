#include "lsl_usart.h"

/* Init */
void LSL_USART_Init(USART_TypeDef* USART, uint32_t baudrate, uint8_t data_size, uint8_t parity, uint8_t stop) {

	/* Enable USART Clock */
	if (USART == USART1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN; 		// Enable clock USART1
	else if (USART == USART2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN; // Enable clock USART2
	else if (USART == USART3) RCC->APB1ENR |= RCC_APB1ENR_USART3EN; // Enable clock USART3

	/* Setup USART */
	LSL_USART_Baudrate(USART, baudrate);
	LSL_USART_DataSize(USART, data_size);
	LSL_USART_Parity(USART, data_size, parity);
	LSL_USART_Stop(USART, stop);

	USART->CR1 |= USART_CR1_TE | USART_CR1_RE; 	// Enable Tx & Rx (TODO : Auto GPIO enabling)

}

/* Baudrate */
void LSL_USART_Baudrate(USART_TypeDef* USART, uint32_t baudrate) {

	if (USART == USART1) LSL_USART_SetBaudrate(USART, *LSL_USART72_BAUD, baudrate);
	else if (USART == USART2) LSL_USART_SetBaudrate(USART, *LSL_USART36_BAUD, baudrate);
	else if (USART == USART3) LSL_USART_SetBaudrate(USART, *LSL_USART36_BAUD, baudrate);
	
}

void LSL_USART_SetBaudrate(USART_TypeDef* USART, uint16_t *baudTable, uint32_t baudrate) {

	uint8_t i = 0;

	switch (baudrate)
	{
		case 2400: 		i = 0; break;
		case 9600: 		i = 1; break;
		case 19200: 	i = 2; break;
		case 57600: 	i = 3; break;
		case 115200:	i = 4; break;
		default: break;
	}

    USART->BRR |= (baudTable[i*2] << 4) | (baudTable[i*2+1] << 0); // Set Bauds Rate Register DIV_Mantissa and DIV_fraction

}

/* Data Size */
void LSL_USART_DataSize(USART_TypeDef* USART, uint8_t data_size) {

	USART->CR1 |= USART_CR1_UE;	// Enable USART
	
	switch (data_size)
	{
	case 7:
		USART->CR1 &= ~USART_CR1_M;	// Disable 9 bits mode (Parity on 8th bit)
		break;

	case 8:
	case 9:
		USART->CR1 |= USART_CR1_M;	// Enable 9 bits mode (Parity on 9th bit or shall be disabled for 9 bits data)
		break;
	
	default:
		break;
	}
}

/* Parity */
void LSL_USART_Parity(USART_TypeDef* USART, uint8_t data_size, uint8_t parity) {

	LSL_USART_EnableParity(USART, data_size);
	LSL_USART_SetParity(USART, parity);
}

void LSL_USART_EnableParity(USART_TypeDef* USART, uint8_t data_size) {

	switch (data_size)
	{
	case 7:
	case 8:
		USART->CR1 |= USART_CR1_PCE;	// Parity Control Enable (USART_CR1_PCE = 1)
		break;
	
	case 9:								// Parity shall be disabled for 9 bits mode
		USART->CR1 &= ~USART_CR1_PCE;	// Parity Control Disable (USART_CR1_PCE = 0)
		break;

	default:
		break;
	}
}

void LSL_USART_SetParity(USART_TypeDef* USART, uint8_t parity) {

	if (parity == 1) USART->CR1 |= USART_CR1_PS;		// Parity Selection Even (USART_CR1_PS = 0)
	else if (parity == 0) USART->CR1 &= ~USART_CR1_PS;	// Parity Selection Odd (USART_CR1_PS = 1)
}

/* Stop */
void LSL_USART_Stop(USART_TypeDef* USART, uint8_t stop) {

	if (stop == 1) USART->CR2 &= ~USART_CR2_STOP; 			// 1 Stop (USART_CR2_STOP = 0b00)
	else if (stop == 2) USART->CR2 &= ~USART_CR2_STOP_1;	// 2 Stop (USART_CR2_STOP = 0b10)
}

/* Transmit */
void LSL_USART_Tx(USART_TypeDef* USART, uint8_t data) {

    USART->DR = data;
    while (!(USART->SR & USART_SR_TC));
}

/* Receive */
uint8_t LSL_USART_Rx(USART_TypeDef* USART) {

    while (!(USART->SR & USART_SR_RXNE));
    return USART->DR & 0xFF;
}