#include "Test.h"
#include <stdint.h>

void Test_program(void) {
	//Test_Led();
	Test_Show_points();
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

void Test_Show_points(void) {
	uint8_t L_points;
	uint8_t R_points;
	/* Loop through all possible point combinations */
	for(L_points = 0; L_points <= 4; L_points++) {
		for(R_points = 0; R_points <= 4; R_points++) {
			Show_points(L_points, R_points);
		}
	}
	return;
}
