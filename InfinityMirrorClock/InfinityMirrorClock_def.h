/*
 * InfinityMirrorClock_def.h
 *
 *  Created on: 12.08.2019
 *      Author: steff
 */

#ifndef INFINITYMIRRORCLOCK_DEF_H_
#define INFINITYMIRRORCLOCK_DEF_H_

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
extern SoftwareSerial *BluetoothSerial;
SoftwareSerial *BluetoothSerial = new SoftwareSerial(Arduino.getReceivePin(),Arduino.getTransmitPin());
//Clock Design
ClassicDesign ClassicDesign;
//Spectrum Analyzer
SpectrumAnalyzer SpectrumAnalyzer;
//RGBDesign
RGBDesign RGBDesign;
//writeToSerial
extern uint8_t serialPrintTime;
//System Values
extern uint8_t systemState;
extern uint8_t prevSystemState;
//Bluetooth Values
extern char prog[];

/************************************************************************************
 *
 * Function Name: changeProgram
 *
 * Description:
 *
 * Function Limitations:
 *
 ************************************************************************************/

void changeProgram(){
	switch(systemState){
	case 0:
		ClassicDesign.setClassicDesignOnStrip(Clock, Strip);
		break;
	case 1:
		SpectrumAnalyzer.analyzeSpectrum(Strip);
		break;
	case 2:
		RGBDesign.setRGBDesign(Strip, BluetoothSerial);
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

/************************************************************************************
 *
 * Function Name: evalSerialEvent
 *
 * Description:
 *
 * Function Limitations:
 *
 ************************************************************************************/
uint8_t systemState = 0;
uint8_t prevSystemState = 0;
char prog[] = "00";

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

	if((btChar[0] == '<') && (btChar[1] == 'T') &&(btChar[14] == '>')){
		byte temp1, temp2;
		byte year, month, day, hour, minute, second;
		//year
		temp1 = (byte)btChar[2] - 48;
		temp2 = (byte)btChar[3] - 48;
		year = temp1*10 + temp2;
		//month
		temp1 = (byte)btChar[4] - 48;
		temp2 = (byte)btChar[5] - 48;
		month = temp1*10 + temp2;
		//year
		temp1 = (byte)btChar[6] - 48;
		temp2 = (byte)btChar[7] - 48;
		day = temp1*10 + temp2;
		//hour
		temp1 = (byte)btChar[8] - 48;
		temp2 = (byte)btChar[9] - 48;
		hour = temp1*10 + temp2;
		//minute
		temp1 = (byte)btChar[10] - 48;
		temp2 = (byte)btChar[11] - 48;
		minute = temp1*10 + temp2;
		//second
		temp1 = (byte)btChar[12] - 48;
		temp2 = (byte)btChar[13] - 48;
		second = temp1*10 + temp2;
		//Debug
		//		Serial.print(year);
		//		Serial.println(":");
		//		Serial.print(month);
		//		Serial.println(":");
		//		Serial.print(day);
		//		Serial.println(":");
		//		Serial.print(hour);
		//		Serial.println(":");
		//		Serial.print(minute);
		//		Serial.println(":");
		//		Serial.print(second);
		//		Serial.println("\n");
		Clock->setClockMode(true); // set to 12h
		Clock->setYear(year);
		Clock->setMonth(month);
		Clock->setDate(day);
		Clock->setHour(hour);
		Clock->setMinute(minute);
		Clock->setSecond(second);
	}
}

#endif /* INFINITYMIRRORCLOCK_DEF_H_ */
