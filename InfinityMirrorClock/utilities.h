/*
 * utilities.h
 *
 *  Created on: 24.02.2018
 *      Author: steff
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_
#include <Arduino.h>
#include <DS3231.h>

void linspace(double a, double b, uint8_t n, double* arr);

uint8_t writeToSerial(uint8_t serialPrintTime, DS3231 clock);

#endif /* UTILITIES_H_ */
