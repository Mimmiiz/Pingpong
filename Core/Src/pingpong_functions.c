/**
******************************************************************************
@brief Pingpong, functions for Pingpong-program
@file pingpong_functions.c
@author Maria Halvarsson, Hamta Dezfoli
@version 1.0
@date 09-November-2021
@brief Functions and structures for program Pingpong
******************************************************************************
*/

#include "Pingpong.h"
#include <stdint.h>
#include "gpio.h"


/**
@brief Led_on, turn one of the pingpong leds on
@param uint8_t Lednr , number to the Led that is turned on
 Lednr can be 1-8, all other values turns all leds off
@return void
*/
void Led_on(uint8_t Lednr) {
	uint8_t i;
	for(i = 1; i <= 8; i++) {
		switch(i) {
		case 1: // Led 1
			if (Lednr==i) HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
			break;
		case 2: // Led 2
			if (Lednr==i) HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
			break;
		case 3: // Led 3
			if (Lednr==i) HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
			break;
		case 4: // Led 4
			if (Lednr==i) HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
			break;
		case 5: // Led 5
			if (Lednr==i) HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
			break;
		case 6: // Led 6
			if (Lednr==i) HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
			break;
		case 7: // Led 7
			if (Lednr==i) HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_RESET);
			break;
		case 8: // Led 8
			if (Lednr==i) HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_RESET);
			break;
		default:
			;
		} // end of switch
	} // end for-loop
	return;
} // End of functions Led_on

/**
@brief Show_points, shows points after missed ball
@param1 uint8_t L_points points for left player
@param2 uint8_t R_points points for right player
@return void, no return value
*/
void Show_points(uint8_t L_points, uint8_t R_points) {
	for(uint8_t i = 1; i <= L_points; i++) {
		Set_led(i);
	}
	/*for(uint8_t j = 8; j > R_points + 4; j--) {
		Led_on(j);
	}*/
	//HAL_Delay(5000);
	return;
}

void Set_led(uint8_t Lednr) {
		if (Lednr==1) HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		if (Lednr==2) HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		if (Lednr==3) HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
		if (Lednr==4) HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
		if (Lednr==5) HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
		if (Lednr==6) HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);
		if (Lednr==7) HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_SET);
		if (Lednr==8) HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_SET);
		else return;
		return;
}

void Reset_led(void) {
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_RESET);
}
