#include "lsl_timer.h"

void LSL_TIMER_Init(TIM_TypeDef* TIMER, uint16_t tim_pre, uint16_t tim_cpt, IRQn_Type tim_irq) {

    /* Enable Timer RCC */
    if (TIMER == TIM1) RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    else if (TIMER == TIM2) RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    else if (TIMER == TIM3) RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    else if (TIMER == TIM4) RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

    //Choisir le prescaler 
	TIMER->PSC = tim_pre; // diviser la frequence source par tim_pre + 1

	//Choisir la valeur du conteur 
	TIMER->ARR = tim_cpt; // interruption tous les tim_cpt + 1

	// mise a jour des valeurs psc, arr
	TIMER->EGR |= TIM_EGR_UG;
	
	// Activer les interruptions -> flags UIE
	TIMER->DIER |= TIM_DIER_UIE;

    // Enable interrupt tim_irq
	NVIC_EnableIRQ(tim_irq);
	
	//start le timer
	TIMER->CR1 |= TIM_CR1_CEN;
}