/*
 * input_processing.c
 *
 *  Created on: Oct 22, 2024
 *      Author: Dat
 */

#include "main.h"

#define NO_OF_BUTTONS	1
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED			GPIO_PIN_RESET
#define BUTTON_IS_RELEASED			GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];

static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];

static uint8_t	flagForButtonPress1s[NO_OF_BUTTONS];

static uint16_t	counterForButtonPress1s[NO_OF_BUTTONS];

void button_reading(void)
{
	for(char i = 0; i < NO_OF_BUTTONS; i++)
	{
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_PIN);
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
		{
			buttonBuffer[i] = debounceButtonBuffer1[i];
			if(buttonBuffer[i] == BUTTON_IS_PRESSED)
			{
				if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING)
				{
					counterForButtonPress1s[i]++;
				}
				else
				{
					counterForButtonPress1s[i] = 0;
					flagForButtonPress1s[i] = 1;
				}
			}
		}
		else
		{
			counterForButtonPress1s[i] = 0;
			flagForButtonPress1s[i] = 0;
		}
	}
}

unsigned char is_button_pressed(uint8_t index)
{
	if(index >= NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char in_button_pressed_1s (unsigned char index)
{
	if(index >= NO_OF_BUTTONS) return oxff;
	return (flagForButtonPress1s[i] == 1);
}
