/*
 * LAB3.h
 *
 *  Created on: Oct 22, 2024
 *      Author: Dat
 */

#ifndef INC_LAB3_H_
#define INC_LAB3_H_

#include "main.h"
extern uint8_t time_red, time_yellow, time_green;
void Normal_mode(uint8_t time_red, uint8_t time_yellow, uint8_t time_green);
void Mod_Led_Red(uint8_t time_red_changed);
void blink_led_red(void);
void blink_led_green(void);
void blink_led_yellow(void);
void init_lab3(void);
void clear_all_led(void);
void Mod_Led_Red(uint8_t time_red_changed);
void Mod_Led_Yellow(uint8_t time_yellow_changed);
void Mod_Led_Green(uint8_t time_green_changed);
#endif /* INC_LAB3_H_ */
