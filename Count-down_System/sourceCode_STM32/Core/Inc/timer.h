/*
 * timer.h
 *
 *  Created on: 5 thg 11, 2022
 *      Author: Sy Phan
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TIMER_CYCLE 10

//int timer1Counter = 0;
//extern int timer1Flag;
void setTimer1(int duration);
void runTimer1();
int getTimer1Flag();

//int timer2Counter = 0;
//extern int timer2Flag;
void setTimer2(int duration);
void runTimer2();
int getTimer2Flag();

//int timer3Counter = 0;
//extern int timer3Flag;
void setTimer3(int duration);
void runTimer3();
int getTimer3Flag();



#endif /* INC_TIMER_H_ */
