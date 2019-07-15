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

uint8_t serialPrintTime = 0;

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


void loop() {

	ClassicDesign.setClassicDesignOnStrip(Clock, Strip);
	//SpectrumAnalyzer.analyzeSpectrum(Strip);
	//RGBDesign.setRGBDesign(Strip);
	//serialPrintTime = writeToSerial(serialPrintTime, Clock);
}


