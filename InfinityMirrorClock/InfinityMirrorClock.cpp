/*
 * InfinityMirrorClock.cpp
 *
 *  Created on: 05.07.2019
 *      Author: steff
 */

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DS3231.h>
#include <Wire.h>
#include "Adafruit_NeoPixel.h"
#include "ArduinoIO.h"
#include "ClassicDesign.h"
#include "utilities.h"
#include "SpectrumAnalyzer.h"
#include "RGBDesign.h"

#define NUM_LEDS 136
#define BRIGHTNESS 50

// Clock
DS3231 *Clock = new DS3231();
//Arduino
ArduinoIO Arduino;
//LED Strip
Adafruit_NeoPixel *Strip = new Adafruit_NeoPixel(NUM_LEDS, Arduino.getLedPin(), NEO_GRB + NEO_KHZ800);
//Bluetooth Serial
SoftwareSerial BluetoothSerial(Arduino.getReceivePin(),Arduino.getTransmitPin());
//Clock Design
ClassicDesign ClassicDesign;
//Spectrum Analyzer
SpectrumAnalyzer SpectrumAnalyzer;
//RGBDesign
RGBDesign RGBDesign;

//writeToSerial
uint8_t serialPrintTime = 0;
//System Values
uint8_t systemState = 0;
uint8_t prevSystemState = 1;
//Bluetooth Values
char prog[2] = "00";
String btString;

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
	//Einkommentieren wenn Schallsensor neu kalibiert werden soll
	//SpectrumAnalyzer.calibrateSensor();
	//Initialisiere UART Schnittstellen
	Serial.begin(115200);
	BluetoothSerial.begin(9600);
	while(!BluetoothSerial){}
}

void btSerialEvent(){
	char command;
	if (BluetoothSerial.available() > 0){
		btString = "";
	}
	while(BluetoothSerial.available() > 0){
		command = ((byte)BluetoothSerial.read());
		if(command == ':'){
			break;
		}
		else{
			btString += command;
		}
		delay(1);
	}
}

void evalSerialEvent(){
	char btChar[btString.length() + 1];
	strcpy(btChar, btString.c_str());
	if((btChar[0] == '<') && (btChar[1] == 'P') &&(btChar[4] == '>')){
		char temp[2] = {btChar[2],btChar[3]};
		strcpy(prog, temp);
		if(prog[0] == '0' && prog[1] == '0'){
			systemState = 0;
		}else if(prog[0] == '0' && prog[1] == '1'){
			systemState = 1;
		} else if(prog[0] == '0' && prog[1] == '2'){
			systemState = 2;
		} else if(prog[0] == '0' && prog[1] == '3'){
			systemState = 3;
		} else if(prog[0] == '0' && prog[1] == '4'){
			systemState = 4;
		} else if(prog[0] == '0' && prog[1] == '5'){
			systemState = 5;
		} else if(prog[0] == '0' && prog[1] == '6'){
			systemState = 6;
		}
	}
	if((btChar[0] == '<') && (btChar[1] == 'B') &&(btChar[5] == '>')){
		char temp[3] = {btChar[2], btChar[3], btChar[4]};
		double brightness = (((double) atoi(temp)) / 100.0) * 250.0;
		if(((uint8_t) brightness > 0) && ((uint8_t) brightness < 255)){
			Strip->setBrightness((uint8_t) brightness);
		}
	}
}

void changeProgram(){
	switch(systemState){
	case 0:
		ClassicDesign.setClassicDesignOnStrip(Clock, Strip);
		break;
	case 1:
		SpectrumAnalyzer.analyzeSpectrum(Strip);
		break;
	case 2:
		RGBDesign.setRGBDesign(Strip);
		break;
	case 3: //TODO: Set Time via Bluetooth
		Strip->clear();
		Strip->show();
		break;
	case 4: //TODO: Set Brightness via Bluetooth
		Strip->clear();
		Strip->show();
		break;
	case 5: //TODO: Add ms pointer
		Strip->clear();
		Strip->show();
		break;
	case 6: //TODO Add sleep mode
		Strip->clear();
		Strip->show();
		break;
	default:
		Strip->clear();
		Strip->show();
		break;
	}
}

void loop() {
	btSerialEvent();
	evalSerialEvent();
	changeProgram();
}


