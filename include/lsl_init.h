#ifndef LSL_INIT_H
#define LSL_INIT_H

#include "main.h"

/* Init All */
void LSL_Init_Registers(void);

/* Init Features */
void LSL_Init_RCC(void);
void LSL_Init_GPIO(void);
void LSL_Init_TIMERS(void);

#endif // LSL_INIT_REGS_H