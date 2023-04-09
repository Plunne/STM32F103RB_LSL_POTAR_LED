#ifndef LSL_TIMER_H
#define LSL_TIMER_H

#include "lsl_clock.h"

/* Enable */
void LSL_TIMER_Init(TIM_TypeDef* TIMER, uint16_t tim_pre, uint16_t tim_cpt, IRQn_Type tim_irq);

#endif // LSL_IO_H