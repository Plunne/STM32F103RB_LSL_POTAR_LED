#include "lsl_usart.h"

/* Init */
void LSL_USART_Init(USART_TypeDef* USART, uint32_t baudrate, uint8_t nb_bits, uint8_t parity, uint8_t stop) {

	/* Enable USART Clock */
	if (USART == USART1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN; 		// Enable clock USART1
	else if (USART == USART2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN; // Enable clock USART2
	else if (USART == USART3) RCC->APB1ENR |= RCC_APB1ENR_USART3EN; // Enable clock USART3

	/* Setup USART */
    USART->CR1 |= USART_CR1_UE | USART_CR1_M;  	// Enable USART with 8,n,1 // M = 8 or 9 bits
    USART->CR1 |= USART_CR1_PCE;     			// Parity Even (PS Cleared)
    USART->CR1 |= USART_CR1_TE | USART_CR1_RE; 	// Enable Tx & Rx

    USART->CR2 &= ~USART_CR2_STOP; // 1 Stop

	LSL_USART_InitBaudrate(USART, baudrate);

}

/* Baudrate */
void LSL_USART_InitBaudrate(USART_TypeDef* USART, uint32_t baudrate) {

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

    USART->BRR |= (baudTable[i*2] << 4) | (baudTable[i*2+1] << 0); // Set 115200 Bauds

}

/* Transmit */
void LSL_USART_Tx(USART_TypeDef* USART, uint8_t c) {

    USART->DR = c;
    while (!(USART->SR & USART_SR_TC));
}

/* Receive */
uint8_t LSL_USART_Rx(USART_TypeDef* USART) {

    while (!(USART->SR & USART_SR_RXNE));
    return USART->DR & 0xFF;
}