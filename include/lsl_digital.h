#ifndef LSL_DIGITAL_H
#define LSL_DIGITAL_H

#include "lsl_pinouts.h"

typedef enum {LOW, HIGH, TOGGLE} LSL_DIGITAL_State;

/* Input */
uint8_t LSL_DIGITAL_Read(LSL_Pinout *pinout);

/* Output */
void LSL_DIGITAL_Write(LSL_Pinout *pinout, LSL_DIGITAL_State mode);
void LSL_DIGITAL_Set(LSL_Pinout *pinout);
void LSL_DIGITAL_Clear(LSL_Pinout *pinout);
void LSL_DIGITAL_Toggle(LSL_Pinout *pinout);

#endif // LSL_DIGITAL_H