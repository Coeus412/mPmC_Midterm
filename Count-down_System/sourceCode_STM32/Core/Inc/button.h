/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Sy Phan
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NO_OF_BUTTONS 3
#define BUTTON_IS_RELEASED GPIO_PIN_SET
#define BUTTON_IS_PRESSED GPIO_PIN_RESET

void process();
void button_reading (void);

int is_button_pressed (int index);
int is_button_pressed_3s (int index);



#endif /* INC_BUTTON_H_ */
