/**
******************************************************************************
@brief Test file for the functions in the Pingpong-program
@file test.c
@author Maria Halvarsson, Hamta Dezfoli
@version 1.0
@date 09-November-2021
@brief Includes test files that thests the functions for the program Pingpong
******************************************************************************
*/

#include "Test.h"
#include <stdint.h>
#include "gpio.h"
#include "Pingpong.h"
#include "stdbool.h"

void Test_program(void) {
	//Test_Led();
	//Test_Show_points();
	Test_buttons();
}

/**
 * @brief Test for function Led_on. Tests if all LEDs can be turned on by looping through each LED
 * @param None
 * @return None
 */
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

/**
 * @brief Test for function Show_points. Tests if all possible point combinations can be displayed in.
 * @param None
 * @return NOne
 */
void Test_Show_points(void) {
	uint8_t L_points;
	uint8_t R_points;
	/* Loop through all possible point combinations */
	for(L_points = 0; L_points <= 4; L_points++) {
		for(R_points = 0; R_points <= 4; R_points++) {
			Show_points(L_points, R_points);
			HAL_Delay(1000);
			Led_on(9); // Turn off all LEDs
		}
	}
	return;
}

/**
 * @brief Test for function L_hit and R_hit. Tests if left and right buttons work by changing the LEDs.
 * @param None
 * @return None
 */
void Test_buttons(void) {
	int8_t j;

	/* Checking buttons */

	j = 4;
	Led_on(j); // Light on

	while(j < 9 && j > 0) // Wait for left button hit
	{
		if(L_hit() == true)
		{
			j++;	// next led to the right
			Led_on(j); // Light on
			HAL_Delay(100);
			while (L_hit() == true); // Wait for button release
			HAL_Delay(100);
		}

		if(R_hit() == true) // Wait for right button hit
		{
			j--; // next led to the left
			Led_on(j); // Light on
			HAL_Delay(100);
			while(R_hit() == true); // Wait for button release
			HAL_Delay(100);
			if (j < 1) j = 0; // start again from left
		}
	}
}
