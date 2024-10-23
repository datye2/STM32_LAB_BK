
#include "7SEG.h"

uint8_t segment_value[] = {0x40,0x79,0x24,0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
uint16_t gpio_pins[] = {GPIO_PIN_0,GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4,
												GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_8,
												GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12,
												GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15};

void Display7SEG(uint8_t number,int offset)
{
	number = segment_value[number];
	HAL_GPIO_WritePin(GPIOB,gpio_pins[8 -  offset],number & (0x01));
	HAL_GPIO_WritePin(GPIOB,gpio_pins[9 -  offset],number & (0x02));
	HAL_GPIO_WritePin(GPIOB,gpio_pins[10 - offset],number & (0x04));
	HAL_GPIO_WritePin(GPIOB,gpio_pins[11 - offset],number & (0x08));
	HAL_GPIO_WritePin(GPIOB,gpio_pins[12 - offset],number & (0x10));
	HAL_GPIO_WritePin(GPIOB,gpio_pins[13 - offset],number & (0x20));
	HAL_GPIO_WritePin(GPIOB,gpio_pins[14 - offset],number & (0x40));
}
