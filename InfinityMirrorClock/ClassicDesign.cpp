/*
 * ClassicDesign.cpp
 *
 *  Created on: 05.07.2019
 *      Author: steff
 */

/*
 * ClassicDesign.cpp
 *
 *  Created on: 28.01.2018
 *      Author: steff
 */

#include "ClassicDesign.h"
#include "utilities.h"

ClassicDesign::ClassicDesign(){

}

void ClassicDesign::setHourDesignOnStrip(Adafruit_NeoPixel* strip){
	double hourPosArr[13];
	uint16_t pixelBrightness = 255;//strip->getBrightness();
	linspace(0.0, (double) strip->numPixels(), 13, hourPosArr);
	for(uint8_t i = 0; i < 12; i++){
		uint8_t hPos = (uint8_t) round(hourPosArr[i]);
		strip->setPixelColor(hPos-1,strip->Color(pixelBrightness/4,pixelBrightness/4,pixelBrightness/4));
		strip->setPixelColor(hPos,strip->Color(pixelBrightness,pixelBrightness,pixelBrightness));
		strip->setPixelColor(hPos+1,strip->Color(pixelBrightness/4,pixelBrightness/4,pixelBrightness/4));
	}
}

void ClassicDesign::setTimeOnStrip(DS3231* clock, Adafruit_NeoPixel* strip){

	//Variable Declaration
	double secPosArr[60];
	double hourPosArr[13];

	uint16_t pixelBrightness = 255;// strip->getBrightness();
	uint16_t NUM_LEDS =  strip->numPixels();
	uint8_t second = clock->getSecond();
	uint8_t minute = clock->getMinute();
	bool h12, PM;
	uint8_t hour = clock->getHour(h12,PM);

	//Filling hour/second position array on strip
	linspace(0.0, (double) NUM_LEDS, 13, hourPosArr);
	linspace(0.0, (double) NUM_LEDS, 60, secPosArr);

	//Get Position from array
	//Shift um Uhrzeit auf 12 Uhr darzustellen nicht auf 6
	uint8_t sPos = (uint8_t) round(NUM_LEDS/2 + secPosArr[second]);
	uint8_t mPos = (uint8_t) round(NUM_LEDS/2 + secPosArr[minute]);
	uint8_t hPos = (uint8_t) round(NUM_LEDS/2 + hourPosArr[hour]);

	if(sPos > NUM_LEDS){
		sPos = (uint8_t) round(secPosArr[second] - NUM_LEDS/2);
	}
	if(mPos > NUM_LEDS){
		mPos = (uint8_t) round(secPosArr[minute] - NUM_LEDS/2);
	}
	if(hPos > NUM_LEDS){
		hPos = (uint8_t) round(hourPosArr[hour] - NUM_LEDS/2);
	}

	strip->setPixelColor(sPos-1,strip->Color(pixelBrightness/4,0,0));
	strip->setPixelColor(sPos,strip->Color(pixelBrightness,0,0));
	strip->setPixelColor(sPos+1,strip->Color(pixelBrightness/4,0,0));

	strip->setPixelColor(mPos-1,strip->Color(0,pixelBrightness/4,0));
	strip->setPixelColor(mPos,strip->Color(0,pixelBrightness,0));
	strip->setPixelColor(mPos+1,strip->Color(0,pixelBrightness/4,0));

	strip->setPixelColor(hPos-1,strip->Color(0,0,pixelBrightness/4));
	strip->setPixelColor(hPos,strip->Color(0,0,pixelBrightness));
	strip->setPixelColor(hPos+1,strip->Color(0,0,pixelBrightness/4));

	if(mPos==sPos){
		strip->setPixelColor(sPos-1,strip->Color(pixelBrightness/4,0,0));
		strip->setPixelColor(sPos+1,strip->Color(pixelBrightness/4,0,0));
	}
	if(hPos==sPos){
		strip->setPixelColor(sPos-1,strip->Color(pixelBrightness/4,0,0));
		strip->setPixelColor(sPos+1,strip->Color(pixelBrightness/4,0,0));
	}
	if(hPos==mPos){
		strip->setPixelColor(mPos-1,strip->Color(0,pixelBrightness/4,0));
		strip->setPixelColor(mPos+1,strip->Color(0,pixelBrightness/4,0));
	}
	if(hPos == mPos && hPos == sPos){
		strip->setPixelColor(sPos-1,strip->Color(pixelBrightness/4,0,0));
		strip->setPixelColor(sPos+1,strip->Color(pixelBrightness/4,0,0));
	}
}

void ClassicDesign::setClassicDesignOnStrip(DS3231* clock, Adafruit_NeoPixel* strip){
	strip->clear();
	setHourDesignOnStrip(strip);
	setTimeOnStrip(clock, strip);
	strip->show();
	delay(10);
}





