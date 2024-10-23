/*
 * LAB3.c
 *
 *  Created on: Oct 22, 2024
 *      Author: Dat
 */


#include "LAB3.h"
#include "my_STM32F106.h"

enum Led_state{Led_do,Led_xanh,Led_vang} State_led = Led_do;
enum Led_pos{vertical,horizontal} Pos_led = vertical ;
uint16_t counter = 0;

void Normal_mode(void)  // đỏ 5s, vang 2s, xanh 3s
{
	counter++;
	switch (Pos_led)
	{
		case vertical :
		{
			switch(State_led)
			{
				case Led_do :
					if(counter >= 5)
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
					if(counter >= 2)
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
					if(counter >= 3)
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
			break;
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

void Mod_Led_Yellow(void)
{

}

void Mod_Led_Green(void)
{

}
