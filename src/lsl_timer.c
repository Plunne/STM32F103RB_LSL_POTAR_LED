#include "lsl_timer.h"

void LSL_TIMER_Init(LSL_TIMER_Handler* TIMER_Handler) {

    /* Enable Timer RCC */
    if (TIMER_Handler->timer == TIM1) RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    else if (TIMER_Handler->timer == TIM2) RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    else if (TIMER_Handler->timer == TIM3) RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    else if (TIMER_Handler->timer == TIM4) RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

    //Choisir le prescaler 
	TIMER_Handler->timer->PSC = TIMER_Handler->prescaler; // diviser la frequence source par tim_pre + 1

	//Choisir la valeur du conteur 
	TIMER_Handler->timer->ARR = TIMER_Handler->counter; // interruption tous les tim_cpt + 1

	// mise a jour des valeurs psc, arr
	TIMER_Handler->timer->EGR |= TIM_EGR_UG;
	
	// Activer les interruptions -> flags UIE
	TIMER_Handler->timer->DIER |= TIM_DIER_UIE;

    // Enable interrupt tim_irq
	NVIC_EnableIRQ(TIMER_Handler->event);
	
	//start le timer
	TIMER_Handler->timer->CR1 |= TIM_CR1_CEN;
}