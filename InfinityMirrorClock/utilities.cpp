/*
 * utilities.cpp
 *
 *  Created on: 24.02.2018
 *      Author: steff
 */

#include "utilities.h"


void linspace(double a, double b, uint8_t n, double* arr){
	double step = (b - a) / (n - 1);
    for(int i = 0; i < n;i++){
    arr[i] = a;
    a += step;
   }
}

uint8_t writeToSerial(uint8_t serialPrintTime, DS3231 clock){
	if(serialPrintTime == 100){
		serialPrintTime = 0;
		Serial.println("Time: ");
		bool h12, PM;
		Serial.print(clock.getHour(h12,PM));
		Serial.println(" : ");
		Serial.print(clock.getMinute());
		Serial.println(" : ");
		Serial.print(clock.getSecond());
		Serial.println("\n");
		Serial.println("System State: ");
		//Serial.print(systemState);
		Serial.println("\n");
	}
	serialPrintTime++;
	return serialPrintTime;
}
