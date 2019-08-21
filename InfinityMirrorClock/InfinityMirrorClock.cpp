/*
 * InfinityMirrorClock.cpp
 *
 *  Created on: 05.07.2019
 *      Author: steff
 */

#include "InfinityMirrorClock_def.h"

/************************************************************************************
 *
 * Function Name: btSerialEvent
 *
 * Description:
 *
 * Function Limitations:
 *
 ************************************************************************************/

void setup() {
	//Initialisiere Arduino Schnittstellen
	Arduino.initArduino();
	//Starte I2C Protokoll
	Wire.begin();
	//Initialisiere LED Strip
	Strip->clear();
	Strip->setBrightness(BRIGHTNESS);
	Strip->begin();
	Strip->show();
	//#########################################
	//Einkommentieren wenn Uhr gesetzt werden soll
	Clock->setClockMode(true); // set to 12h
	Clock->setYear(2019);
	Clock->setMonth(8);
	Clock->setDate(21);
	Clock->setHour(10);
	Clock->setMinute(18);
	Clock->setSecond(59);
	//############################################
	//Einkommentieren wenn Schallsensor neu kalibiert werden soll
	//SpectrumAnalyzer.calibrateSensor();
	//Initialisiere UART Schnittstellen
	Serial.begin(115200);
	BluetoothSerial->begin(9600);
	while(!BluetoothSerial){}
}

void loop() {
	btSerialEvent(BluetoothSerial);
	if(stringComplete){
		stringComplete = false;
		evalSerialEvent();
	}
	changeProgram();
	//writeToSerial(Clock);
}


