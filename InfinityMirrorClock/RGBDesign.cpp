/*
 * RGBDesign.cpp
 *
 *  Created on: 11.07.2019
 *      Author: steff
 */

#include "RGBDesign.h"

RGBDesign :: RGBDesign(){
	m_modeCounter = 0;
}

void RGBDesign :: setRGBDesign(Adafruit_NeoPixel* strip, SoftwareSerial* BluetoothSerial){
	switch(m_modeCounter){
	// Some example procedures showing how to display to the pixels:
	case 0:
		colorWipe(strip, strip->Color(255, 0, 0), 50, BluetoothSerial); // Red
		break;
	case 1:
		colorWipe(strip, strip->Color(0, 255, 0), 50, BluetoothSerial); // Green
		break;
	case 2:
		colorWipe(strip, strip->Color(0, 0, 255), 50, BluetoothSerial); // Blue
		break;
	case 3:
		colorWipe(strip, strip->Color(255, 255, 255), 50, BluetoothSerial); // White
		break;
	case 4:
		whiteOverRainbow(strip, 20,75,5, BluetoothSerial);
		break;
	case 5:
		//pulseWhite(strip, 5, BluetoothSerial);
		break;
		// fullWhite();
		// delay(2000);
	case 6:
		rainbowFade2White(strip, 3,3,1, BluetoothSerial);
		break;
	default:
		break;
	}
	m_modeCounter++;
	if(m_modeCounter > NUMBER_OF_MODES){
		m_modeCounter = 0;
	}
}

void RGBDesign :: colorWipe(Adafruit_NeoPixel* strip, uint32_t c, uint8_t wait, SoftwareSerial* BluetoothSerial) {
	for(uint16_t i = 0; i < strip->numPixels(); i++) {
		strip->setPixelColor(i, c);
		strip->show();
		delay(wait);
		btSerialEvent(BluetoothSerial);
		if(stringComplete){
			return;
		}
	}
}

void RGBDesign :: pulseWhite(Adafruit_NeoPixel* strip, uint8_t wait, SoftwareSerial* BluetoothSerial) {
	for(int j = 0; j < 256 ; j++){
		for(uint16_t i=0; i<strip->numPixels(); i++) {
			//strip->setPixelColor(i, strip->Color(m_neopix_gamma[j],m_neopix_gamma[j],m_neopix_gamma[j] ) );
			strip->setPixelColor(i, strip->Color(255,255,255 ) );
		}
		delay(wait);
		strip->show();
		btSerialEvent(BluetoothSerial);
		if(stringComplete){
			return;
		}
	}

	for(int j = 255; j >= 0 ; j--){
		for(uint16_t i=0; i<strip->numPixels(); i++) {
			//strip->setPixelColor(i, strip->Color(m_neopix_gamma[j],m_neopix_gamma[j],m_neopix_gamma[j] ) );
			strip->setPixelColor(i, strip->Color(255,255,255 ) );
		}
		delay(wait);
		strip->show();
		btSerialEvent(BluetoothSerial);
		if(stringComplete){
			return;
		}
	}
}

void RGBDesign :: rainbowFade2White(Adafruit_NeoPixel* strip, uint8_t wait, int rainbowLoops, int whiteLoops, SoftwareSerial* BluetoothSerial) {
	float fadeMax = 100.0;
	int fadeVal = 0;
	uint32_t wheelVal;
	int redVal, greenVal, blueVal;
	for(int k = 0 ; k < rainbowLoops ; k ++){
		for(int j=0; j<256; j++) { // 5 cycles of all colors on wheel
			for(int i=0; i< strip->numPixels(); i++) {
				wheelVal = Wheel(strip, ((i * 256 / strip->numPixels()) + j) & 255);
				redVal = red(wheelVal) * float(fadeVal/fadeMax);
				greenVal = green(wheelVal) * float(fadeVal/fadeMax);
				blueVal = blue(wheelVal) * float(fadeVal/fadeMax);
				strip->setPixelColor( i, strip->Color( redVal, greenVal, blueVal ) );
			}
			//First loop, fade in!
			if(k == 0 && fadeVal < fadeMax-1) {
				fadeVal++;
			}
			//Last loop, fade out!
			else if(k == rainbowLoops - 1 && j > 255 - fadeMax ){
				fadeVal--;
			}
			strip->show();
			delay(wait);
			btSerialEvent(BluetoothSerial);
			if(stringComplete){
				return;
			}
		}
	}
	delay(500);
	for(int k = 0 ; k < whiteLoops ; k ++){
		for(int j = 0; j < 256 ; j++){
			for(uint16_t i=0; i < strip->numPixels(); i++) {
				//strip->setPixelColor(i, strip->Color(m_neopix_gamma[j],m_neopix_gamma[j],m_neopix_gamma[j] ) );
				strip->setPixelColor(i, strip->Color(255,255,255 ) );
			}
			strip->show();
		}
		btSerialEvent(BluetoothSerial);
		if(stringComplete){
			return;
		}
		delay(2000);
		for(int j = 255; j >= 0 ; j--){
			for(uint16_t i=0; i < strip->numPixels(); i++) {
				//strip->setPixelColor(i, strip->Color(m_neopix_gamma[j],m_neopix_gamma[j],m_neopix_gamma[j] ) );
				strip->setPixelColor(i, strip->Color(255,255,255 ) );
			}
			strip->show();
		}
	}
	delay(500);
}


void RGBDesign :: whiteOverRainbow(Adafruit_NeoPixel* strip, uint8_t wait, uint8_t whiteSpeed, uint8_t whiteLength, SoftwareSerial* BluetoothSerial ) {
	if(whiteLength >= strip->numPixels()) whiteLength = strip->numPixels() - 1;
	int head = whiteLength - 1;
	int tail = 0;
	int loops = 3;
	int loopNum = 0;
	static unsigned long lastTime = 0;
	while(true){
		for(int j=0; j<256; j++) {
			for(uint16_t i=0; i<strip->numPixels(); i++) {
				if((i >= tail && i <= head) || (tail > head && i >= tail) || (tail > head && i <= head) ){
					strip->setPixelColor(i, strip->Color(255,255,255) );
				}
				else{
					strip->setPixelColor(i, Wheel(strip, ((i * 256 / strip->numPixels()) + j) & 255));
				}

			}
			if(millis() - lastTime > whiteSpeed) {
				head++;
				tail++;
				if(head == strip->numPixels()){
					loopNum++;
				}
				lastTime = millis();
			}
			if(loopNum == loops) return;
			head%=strip->numPixels();
			tail%=strip->numPixels();
			strip->show();
			delay(wait);
			btSerialEvent(BluetoothSerial);
			if(stringComplete){
				return;
			}
		}
	}
}

void RGBDesign :: fullWhite(Adafruit_NeoPixel* strip) {
	for(uint16_t i=0; i<strip->numPixels(); i++) {
		strip->setPixelColor(i, strip->Color(255,255,255 ) );
	}
	strip->show();
}

// Slightly different, this makes the rainbow equally distributed throughout
void RGBDesign :: rainbowCycle(Adafruit_NeoPixel* strip, uint8_t wait) {
	uint16_t i, j;
	for(j=0; j<256 * 5; j++) { // 5 cycles of all colors on wheel
		for(i=0; i< strip->numPixels(); i++) {
			strip->setPixelColor(i, Wheel(strip, ((i * 256 / strip->numPixels()) + j) & 255));
		}
		strip->show();
		delay(wait);
	}
}

void RGBDesign :: rainbow(Adafruit_NeoPixel* strip, uint8_t wait) {
	uint16_t i, j;

	for(j=0; j<256; j++) {
		for(i=0; i<strip->numPixels(); i++) {
			strip->setPixelColor(i, Wheel(strip, (i+j) & 255));
		}
		strip->show();
		delay(wait);
	}
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t RGBDesign :: Wheel(Adafruit_NeoPixel* strip, byte WheelPos) {
	WheelPos = 255 - WheelPos;
	if(WheelPos < 85) {
		return strip->Color(255 - WheelPos * 3, 0, WheelPos * 3,0);
	}
	if(WheelPos < 170) {
		WheelPos -= 85;
		return strip->Color(0, WheelPos * 3, 255 - WheelPos * 3,0);
	}
	WheelPos -= 170;
	return strip->Color(WheelPos * 3, 255 - WheelPos * 3, 0,0);
}
uint8_t RGBDesign :: red(uint32_t c) {
	return (c >> 16);
}
uint8_t RGBDesign :: green(uint32_t c) {
	return (c >> 8);
}
uint8_t RGBDesign :: blue(uint32_t c) {
	return (c);
}
