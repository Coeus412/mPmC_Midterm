/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Sy Phan
 */


#include "button.h"

static int buttonBuffer [NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
//static int debounceButtonBuffer0 [NO_OF_BUTTONS] = {BUTTON_IS_RELEASED};
static int debounceButtonBuffer1 [NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};
static int debounceButtonBuffer2 [NO_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};

static int flagForButtonPress3s [NO_OF_BUTTONS] = {0, 0, 0};

static int counterForButtonPress3s [NO_OF_BUTTONS] = {0, 0, 0};

static GPIO_TypeDef* ButtonPort[NO_OF_BUTTONS] = {RESET_GPIO_Port, INC_GPIO_Port, DEC_GPIO_Port};
static uint16_t ButtonPin[NO_OF_BUTTONS] = {RESET_Pin, INC_Pin, DEC_Pin};

void button_reading(void)
{
    for ( int i = 0; i < NO_OF_BUTTONS ; i ++)
    {
        //debounceButtonBuffer0 [i] = debounceButtonBuffer1 [i];
        debounceButtonBuffer1 [i] = debounceButtonBuffer2 [i];
        debounceButtonBuffer2 [i] = HAL_GPIO_ReadPin (ButtonPort[i], ButtonPin[i]);
        //if ((debounceButtonBuffer0[i] == debounceButtonBuffer1[i])&&(debounceButtonBuffer0[i] == debounceButtonBuffer2[i]))
        if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
        {
            buttonBuffer [i] = debounceButtonBuffer2 [i];
            if( buttonBuffer [i] == BUTTON_IS_PRESSED )
            {
                // if a button is pressed , we start counting
                if( counterForButtonPress3s [ i ] < 300 )
                {
                    counterForButtonPress3s [ i ]++;
                }
                else
                {
                    // the flag is turned on when 3 second has passed
                    // since the button is pressed .
                    flagForButtonPress3s [i] = 1;
                    counterForButtonPress3s [i] = 0;
                    //TODO
                }
            }
            else
            {
                counterForButtonPress3s[i] = 0;
                flagForButtonPress3s [i] = 0;
            }
        }
    }
}

int is_button_pressed ( int index )
{
    if( index >= NO_OF_BUTTONS ) return 0;
    return ( buttonBuffer [ index ] == BUTTON_IS_PRESSED );
}

int is_button_pressed_3s ( int index )
{
    if( index >= NO_OF_BUTTONS ) return 0;
    return ( flagForButtonPress3s [ index ] == 1);
}

