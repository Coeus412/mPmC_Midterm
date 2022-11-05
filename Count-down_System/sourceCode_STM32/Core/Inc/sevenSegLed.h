/*
 * sevenSegLed.h
 *
 *  Created on: 5 thg 11, 2022
 *      Author: Sy Phan
 */

#ifndef INC_SEVENSEGLED_H_
#define INC_SEVENSEGLED_H_

#include "main.h"

void setLedCounter(int count);
int getLedCounter();
void display7SEG(int num);

void update7SEG (int index);



#endif /* INC_SEVENSEGLED_H_ */
