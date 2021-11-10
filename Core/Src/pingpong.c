/**
******************************************************************************
@brief Pingpong statemachine for Pingpong-program
@file pingpong.c
@author Maria Halvarsson, Hamta Dezfoli
@version 1.0
@date 09-November-2021
@brief Functions and structures for program Pingpong
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "Pingpong.h"
#include "stdbool.h"
#include "gpio.h"

/* Define states for state machine*/
typedef enum
{
	Start,
	MoveRight,
	MoveLeft,
	Serve,
	ShowPoints,
} states;

static states State, NextState;

/**
@brief Pingpong, game logic and game states of Pingpong
@param void
@return void, no return value
**/
void Pingpong(void) {
	bool ButtonPressed; // To remember that buttons is pressed
	bool Serve_L; // Indicates if it is left players time to serve

	uint32_t Varv, Speed; // Ball speed
	uint8_t Led; // LED nr

	uint8_t L_points; // Left players points
	uint8_t R_points; // Right players points

	State = Start; // Initiate State to Start
	NextState = Start;

	Speed = 500000; // Number of loops

	/* Infinite loop */
	while(1) {

		State = NextState;

		switch (State) { // State machine

		case Start: {
			Led_on(0); // Turn off all LEDs
			L_points = 0; // Set points to 0
			R_points = 0; // Set points to 0
			Serve_L = true; // R player turn
			ButtonPressed = false;

			if(L_hit() == true) { // L serve
				Led = 1;
				Serve_L = false; // If left serve, left can't serve next time
				NextState = MoveRight;
				while (L_hit() == true); // wait until button is released
			}
			else if (R_hit() == true) { // R serve
				Led = 8;
				Serve_L = true;		// Left player's turn next time
				NextState = MoveLeft;
				while (R_hit() == true); // wait until button is released
			}
			else
				NextState = Start; // Stay in Start state
		}
		break;

		case MoveRight: {
			Led_on(Led);
			Varv = Speed;

			while(Varv != 0) {
				if(R_hit()) ButtonPressed = true; // R hit
				Varv --;
			}

			if(ButtonPressed) { // R pressed
				if(Led == 8) { // and LED8 activated
					NextState = MoveLeft; // return ball
					Led = 7;
				}
				else {
					L_points++;
					NextState = ShowPoints; // hit too early
				}
			}
			else {
				if(Led == 9) { // no hit or too late
					L_points++;
					NextState = ShowPoints;
				}

				else
					NextState = MoveRight; // ball continues to move right
			}
			if(!ButtonPressed) Led++; // prepare to turn next LED on
			ButtonPressed = false;
		}
		break;

		case MoveLeft: {
			Led_on(Led);
			Varv = Speed;

			while(Varv != 0) {
				if(L_hit()) ButtonPressed = true; // L hit
				Varv--;
			}

			if(ButtonPressed) { // L pressed
				if(Led == 1) { // and LED1 active
					NextState = MoveRight; // return ball
					Led = 2;
				}

				else {
					R_points++;
					NextState = ShowPoints; // hit too early
				}
			}

			else {
				if(Led == 0) { // no hit or too late
					R_points++;
					NextState = ShowPoints;
				}

				else
					NextState = MoveLeft; // ball continues to move left
			}

			if(!ButtonPressed) Led--; // prepare to turn next LED on
			ButtonPressed = false;
		}
		break;

		case ShowPoints: {
			Show_points(4, 4);
			HAL_Delay(1000);
			Led_on(0); // turn off leds

			if(L_points == 4 || R_points == 4 ) { // Show winner and reset game to start
				Show_points(L_points, R_points);
				HAL_Delay(5000);	// 5000 ms (5 s)
				Led_on(0); // turn off leds
				NextState = Start;
			}
			else {
				Show_points(L_points, R_points);
				HAL_Delay(3000);	// 2000 ms (2 s)
				Led_on(0); // turn off leds
				NextState = Serve;
			}
		}
		break;

		case Serve: {
			if (Serve_L == true) { // left player serves
				Serve_L = false;
				Led_on(1);
				Led = 1;
				NextState = MoveRight;
				while (L_hit() != true); // wait until button is pressed
			}
			else { // right player serves
				Serve_L = true;
				Led_on(8);
				Led = 8;
				NextState = MoveLeft;
				while (R_hit() != true); // wait until button is pressed
			}
		}
		break;

		default:
			break;
		}
	}
} // End of function Pingpong
