#include "lsl_clock.h"

/* Enable Clocks */
void LSL_CLOCK_EnableHSI(void) {

    //Activation HSI (HSION)
	RCC->CR &= ~RCC_CR_HSION;
	RCC->CR |= RCC_CR_HSION;
	//Attendre l'activation de HSI (HSIRDY)
	while(!(RCC->CR & RCC_CR_HSIRDY));
}

void LSL_CLOCK_EnablePLL(void) {

    //Activation PLL (PLLON)
	RCC->CR |= RCC_CR_PLLON;
	//Attendre l'activation de la PLL (PLLRDY)
	while(!(RCC->CR & RCC_CR_PLLRDY));
}

/* PLL Config */
void LSL_CLOCK_InitPLL(uint8_t multiplier) {

    LSL_CLOCK_EnablePLL();
    LSL_CLOCK_MultiplierPLL(multiplier);
    LSL_CLOCK_Select(RCC_CFGR_SW_PLL);
}

void LSL_CLOCK_MultiplierPLL(uint8_t multiplier) {

    RCC->CFGR &= ~RCC_CFGR_PLLMULL_Msk;
    RCC->CFGR |= (multiplier << RCC_CFGR_PLLMULL_Pos);
}

/* Select Clock */
void LSL_CLOCK_Select(uint8_t clock) {

    //Mettre PLL comme clock source /SW
	RCC->CFGR &= ~RCC_CFGR_SW_Msk;
	RCC->CFGR |= clock;
	//Attendre le changement de clock source /SWS
	while(!(RCC->CFGR & (clock << 2))){};
}

/* Prescaling */
void LSL_CLOCK_PrescaleAPB(uint8_t apb_clk, uint8_t prescale) {

    RCC->CFGR &= ~(0b111 << apb_clk);
    RCC->CFGR |= (prescale << apb_clk);
}
