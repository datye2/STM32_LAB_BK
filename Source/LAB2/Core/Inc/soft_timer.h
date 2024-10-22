/*
 * soft_timer.h
 *
 *  Created on: Sep 21, 2024
 *      Author: Admin
 */

#ifndef INC_SOFT_TIMER_H_
#define INC_SOFT_TIMER_H_

#include <stdio.h>
#include <stdlib.h>

void setTimer(int pos, int value);
void runTimer(void);
int getTimerFlag(int pos);

#endif /* INC_SOFT_TIMER_H_ */
