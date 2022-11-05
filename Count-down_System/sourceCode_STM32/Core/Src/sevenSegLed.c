/*
 * sevenSegLed.c
 *
 *  Created on: 5 thg 11, 2022
 *      Author: Sy Phan
 */

#include "sevenSegLed.h"

static int led_counter = 4;
void setLedCounter(int count)
{
  if (count > 9) count = 0;
  else if (count < 0) count = 9;
  else count = count;
  led_counter = count;
  return;
}
int getLedCounter()
{
  return led_counter;
}

static const uint8_t sevenSegLedDriver[10] = {0x01, 0x4f, 0x12, 0x06, 0x4C, 0x24, 0x20, 0x0f, 0x00, 0x04};
void display7SEG(int num)
{
	if (num < 0 || num > 9) return;

	uint8_t number = sevenSegLedDriver[num];

	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, number & 0x40);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, number & 0x20);
	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, number & 0x10);
	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, number & 0x08);
	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, number & 0x04);
	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, number & 0x02);
	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, number & 0x01);
	return;
}

void update7SEG (int index)
{
	display7SEG(led_counter);
}

