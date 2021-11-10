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

/* Define states for state machine*/
typedef enum
{
	Start,
	MoveRight,
	MoveLeft
} states;

static states State, NextState;

void Pingpong(void) {
	bool ButtonPressed; // To remember that buttons is pressed

	uint32_t Varv, Speed; // Ball speed
	uint8_t Led; // LED nr

	State = Start; // Initiate State to Start
	NextState = Start;

	Speed = 500000; // Number of loops

	/* Infinite loop */
	while(1)
	{

		State = NextState;

		switch (State) // State machine
		{
		case Start:
			Led_on(0); // Turn off all LEDs

			if(L_hit() == true) // L serve
			{
				Led = 1;
				NextState = MoveRight;
				while (L_hit() == true); // wait until button is released
			}
			else if (R_hit() == true) // R serve
			{
				Led = 8;
				NextState = MoveLeft;
				while (R_hit() == true); // wait until button is released
			}
			else
				NextState = Start; // Stay in Start state
			break;
		case MoveRight:
		{
			Led_on(Led);
			Varv = Speed;

			while(Varv != 0)
			{
				if(R_hit()) ButtonPressed = true; // R hit
				Varv --;
			}

			if(ButtonPressed) // R pressed
			{
				if(Led == 8) // and LED8 activated
				{
					NextState = MoveLeft; // return ball
					Led = 7;
				}
				else
					NextState = Start; // hit too early
			}
			else
			{
				if(Led == 9) // no hit or too late
					NextState = Start;
				else
					NextState = MoveRight; // ball continues to move right
			}
			if(!ButtonPressed) Led++; // prepare to turn next LED on
			ButtonPressed = false;
		}
		break;

		case MoveLeft:
		{
			Led_on(Led);
			Varv = Speed;

			while(Varv != 0)
			{
				if(L_hit()) ButtonPressed = true; // L hit
				Varv--;
			}

			if(ButtonPressed) // L pressed
			{
				if(Led == 1) // and LED1 active
				{
					NextState = MoveRight; // return ball
					Led = 2;
				}
				else
					NextState = Start; // hit too early
			}
			else
			{
				if(Led == 0) // no hit or too late
					NextState = Start;
				else
					NextState = MoveLeft; // ball continues to move left
			}
			if(!ButtonPressed) Led--; // prepare to turn net LED on
			ButtonPressed = false;

		}
		break;

		default:
			break;
		}
	}

}
 // End of function Pingpong
