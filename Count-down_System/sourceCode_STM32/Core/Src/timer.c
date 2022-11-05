/*
 * timer.c
 *
 *  Created on: 5 thg 11, 2022
 *      Author: Sy Phan
 */

#include "timer.h"

int timer1Counter = 0;
int timer1Flag = 0;
void setTimer1(int duration)
{
	timer1Counter = duration / TIMER_CYCLE;
	timer1Flag = 0;
	return;
}
void runTimer1()
{
	if (timer1Counter > 0) timer1Counter--;
	if (timer1Counter <= 0) timer1Flag = 1;
	return;
}

int timer2Counter = 0;
int timer2Flag = 0;
void setTimer2(int duration)
{
	timer2Counter = duration / TIMER_CYCLE;
	timer2Flag = 0;
	return;
}
void runTimer2()
{
	if (timer2Counter > 0) timer2Counter--;
	if (timer2Counter <= 0) timer2Flag = 1;
	return;
}

int timer3Counter = 0;
int timer3Flag = 0;
void setTimer3(int duration)
{
	timer3Counter = duration / TIMER_CYCLE;
	timer3Flag = 0;
	return;
}
void runTimer3()
{
	if (timer3Counter > 0) timer3Counter--;
	if (timer3Counter <= 0) timer3Flag = 1;
	return;
}
