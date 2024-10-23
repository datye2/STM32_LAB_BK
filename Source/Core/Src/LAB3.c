/*
 * LAB3.c
 *
 *  Created on: Oct 22, 2024
 *      Author: Dat
 */


#include "LAB3.h"
#include "my_STM32F106.h"

enum Led_state{Led_do,Led_xanh,Led_vang} State_led = Led_do;
uint8_t time_red, time_yellow, time_green;
enum Led_pos{vertical,horizontal} Pos_led = vertical ;
uint16_t counter = 0;
void Normal_mode(uint8_t time_red, uint8_t time_yellow, uint8_t time_green)  // đỏ 5s, vang 2s, xanh 3s
{
	counter++;
	switch (Pos_led)
	{
		case vertical :
		{
			switch(State_led)
			{
				case Led_do :
					if(counter >= time_red)
						{
							State_led = Led_xanh;
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
							Pos_led = horizontal;
							counter = 0;
						}

					break;
				case Led_vang :
					if(counter >= time_yellow)
						{
						State_led = Led_do;
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
							Pos_led = horizontal;
							counter = 0;
						}

					break;
				case Led_xanh :
					if(counter >= time_green)
						{
						State_led = Led_vang;
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
							Pos_led = horizontal;
							counter = 0;
						}
					break;
				default : break;
			}
		}
		case horizontal :
		{
			switch(State_led)
			{
				case Led_do :
						{
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_RESET);
							Pos_led = vertical;
						}

					break;
				case Led_vang :
						{
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);
							Pos_led = vertical;
						}

					break;
				case Led_xanh :
						{
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);
							Pos_led = vertical;
						}
					break;
				default : break;
			}
			break;
		}
	}
}


void blink_led_2hz(enum Led_state mau_led)
{
    switch (mau_led)
    {
        case Led_do:

        	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
        	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
            break;
        case Led_xanh:
        	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
        	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
            break;
        case Led_vang:
        	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
        	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
            break;
        default:
            break;
    }
}

void blink_led_red(void)
{
	blink_led_2hz(Led_do);
}
void blink_led_green(void)
{
	blink_led_2hz(Led_xanh);
}
void blink_led_yellow(void)
{
	blink_led_2hz(Led_vang);
}

void clear_all_led(void)
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
}
void Mod_Led_Red(uint8_t time_red_changed)
{
	Normal_mode(time_red_changed,time_yellow,time_green);
}

void Mod_Led_Yellow(uint8_t time_yellow_changed)
{
	Normal_mode(time_red,time_yellow_changed,time_green);
}


void Mod_Led_Green(uint8_t time_green_changed)
{
	Normal_mode(time_red,time_yellow,time_green_changed);
}


void init_lab3(void)
{
	State_led = Led_do;
	Pos_led = vertical;
	time_red = 5;
	time_yellow = 2;
	time_green = 3;
}

