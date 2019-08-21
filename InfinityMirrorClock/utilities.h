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
#include <SoftwareSerial.h>


void linspace(double a, double b, uint8_t n, double* arr);

void writeToSerial(DS3231* clock);

extern String btString;
extern bool stringComplete;

void btSerialEvent(SoftwareSerial* BluetoothSerial);

#endif /* UTILITIES_H_ */
