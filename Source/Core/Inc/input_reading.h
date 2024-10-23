/*
 * input_processing.h
 *
 *  Created on: Oct 22, 2024
 *      Author: Dat
 */
#include "main.h"
#define NO_OF_BUTTONS	3

#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED			GPIO_PIN_RESET
#define BUTTON_IS_RELEASED			GPIO_PIN_SET

extern  GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
extern  GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
extern  GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
extern  uint8_t	flagForButtonPress1s[NO_OF_BUTTONS];
extern  uint16_t	counterForButtonPress1s[NO_OF_BUTTONS];
extern uint16_t Button_pin[3];

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

void button_reading(void);
unsigned char is_button_pressed(uint8_t index);
unsigned char is_button_pressed_1s (unsigned char index);

#endif /* INC_INPUT_READING_H_ */
