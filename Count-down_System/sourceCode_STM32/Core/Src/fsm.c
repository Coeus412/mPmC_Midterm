/*
 * fsm.c
 *
 *  Created on: 5 thg 11, 2022
 *      Author: Sy Phan
 */
#include "fsm.h"
const int defaultTimer1 = 10000;

enum ButtonState{BUTTONS_RELEASED, RESET_PRESSED, INC_PRESSED, DEC_PRESSED, INC_LP, DEC_LP};
enum ButtonState buttonState = BUTTONS_RELEASED;
void fsm_simple_button_run()
{
	switch(buttonState)
	{
	case BUTTONS_RELEASED:

		if (is_button_pressed(0))
		{
		  buttonState = RESET_PRESSED;
		  setLedCounter(0);
		  return;
		}

		if (is_button_pressed(1))
		{
		  buttonState = INC_PRESSED;
		  setLedCounter(getLedCounter()+1);
		  return;
		}

		if (is_button_pressed(2))
		{
		  buttonState = DEC_PRESSED;
		  setLedCounter(getLedCounter()-1);
		  return;
		}

		if (getTimer1Flag() && getLedCounter() != 0)
		{
		  setTimer1(1000);
		  setLedCounter(getLedCounter()-1);
		}

		display7SEG(getLedCounter());
		break;
	case RESET_PRESSED:
		setLedCounter(0);
		if (!is_button_pressed(0)) buttonState = BUTTONS_RELEASED;
		break;
	case INC_PRESSED:
		if (!is_button_pressed(1)) {buttonState = BUTTONS_RELEASED; setTimer1(defaultTimer1); return;}
		if (is_button_pressed_3s(1)) {buttonState = INC_LP; setTimer2(1000); return;}
		display7SEG(getLedCounter());
		break;
	case DEC_PRESSED:
		if (!is_button_pressed(2)) {buttonState = BUTTONS_RELEASED; setTimer1(defaultTimer1); return;}
		if (is_button_pressed_3s(2)) {buttonState = DEC_LP; setTimer2(1000); return;}
		display7SEG(getLedCounter());
		break;
	case INC_LP:
		if (!is_button_pressed(1)) {buttonState = BUTTONS_RELEASED; setTimer1(defaultTimer1); return;}
		if (getTimer2Flag())
		{
		  setTimer2(1000);
		  setLedCounter(getLedCounter()+1);
		}
		display7SEG(getLedCounter());
		break;
	case DEC_LP:
		if (!is_button_pressed(2)) {buttonState = BUTTONS_RELEASED; setTimer1(defaultTimer1); return;}
		if (getTimer2Flag())
		{
		  setTimer2(1000);
		  setLedCounter(getLedCounter()-1);
		}
		display7SEG(getLedCounter());
		break;
	default:
		break;

	}
	return;
}

