#include "Test.h"
#include <stdint.h>

void Test_program(void) {
	Test_Led();
}

void Test_Led(void) {
	int8_t Lednr;
	/* Loop checking that all LEDs can be turned on */
	for(Lednr = 1; Lednr <= 8; Lednr++) {
		Led_on(Lednr);
		HAL_Delay(500);
	}
	Led_on(9); // Turn off LED 8
	HAL_Delay(1000);
	return;
}
