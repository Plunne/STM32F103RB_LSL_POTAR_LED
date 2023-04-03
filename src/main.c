#include "lsl_init_regs.h"
#include "lsl_utils.h"
#include "lsl_display.h"

int main(void) {

	/* Init Registers */
	LSL_Init_Registers();

	/* Init Variables */
	uint16_t adc_value = 0;

	/* Super Loop */
	while (1) {

		adc_value = LSL_ADC_ReadSingleMax(ANALOG_ADC_Handler.adc, 10); // Get ADC Data without MSB Bits 12 -> 15 (because it's a 12bits ADC not 16)
		
		// Delay
		LSL_DISPLAY_Display7Seg(DISPLAY, adc_value, anode);
		LSL_DIGITAL_Write(&LED, TOGGLE);
		LSL_UTILS_DelayMs(1000); 					// Delay (Be careful sw_cpt value depends of this delay)

		/*
		LSL_DIGITAL_Write(&LED, HIGH);		
		LSL_UTILS_DelayMs(LSL_ANALOG_ADC_Read(&ANALOG_ADC_Handler, &POTAR));
		LSL_DIGITAL_Write(&LED, LOW);		
		LSL_UTILS_DelayMs(LSL_ANALOG_ADC_Read(&ANALOG_ADC_Handler, &POTAR2));
		*/
	}
	
	return 0;
}