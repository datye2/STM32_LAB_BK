/*
 * input_processing.c
 *
 *  Created on: Oct 22, 2024
 *      Author: Dat
 */

#include "main.h"
#include "input_reading.h"
#include "input_processing.h"
enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
enum ButtonState  buttonState = BUTTON_RELEASED;

void fsm_for_input_processing(void)
{
	switch (buttonState)
	{
	case BUTTON_RELEASED:
		if(is_button_pressed(0))
		{
			buttonState = BUTTON_PRESSED;
			// tang gia tri cua port A len
		}
		break;
	case BUTTON_PRESSED:
		if(!is_button_pressed_1s(0))
		{
			buttonState = BUTTON_RELEASED;
		}
		else
		{
			buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND;
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!is_button_pressed_1s(0))
		{
			buttonState = BUTTON_RELEASED;
		}
		break;
	}
}
