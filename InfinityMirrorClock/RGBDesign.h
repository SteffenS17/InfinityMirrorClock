/*
 * RGBDesign.h
 *
 *  Created on: 11.07.2019
 *      Author: steff
 */

#ifndef RGBDESIGN_H_
#define RGBDESIGN_H_

#include <Arduino.h>
#include "Adafruit_NeoPixel.h"

#define NUMBER_OF_MODES 6

class RGBDesign{
public:
	RGBDesign();
	void colorWipe(Adafruit_NeoPixel* strip, uint32_t c, uint8_t wait);
	void whiteOverRainbow(Adafruit_NeoPixel* strip, uint8_t wait, uint8_t whiteSpeed, uint8_t whiteLength);
	void pulseWhite(Adafruit_NeoPixel* strip, uint8_t wait);
	void rainbowFade2White(Adafruit_NeoPixel* strip, uint8_t wait, int rainbowLoops, int whiteLoops);
	void setRGBDesign(Adafruit_NeoPixel* strip);
private:
	uint32_t Wheel(Adafruit_NeoPixel* strip, byte WheelPos);
	void fullWhite(Adafruit_NeoPixel* strip);
	void rainbowCycle(Adafruit_NeoPixel* strip, uint8_t wait);
	void rainbow(Adafruit_NeoPixel* strip, uint8_t wait);
	uint8_t red(uint32_t c);
	uint8_t green(uint32_t c);
	uint8_t blue(uint32_t c);
	uint8_t m_modeCounter;
	byte* m_neopix_gamma;
};



#endif /* RGBDESIGN_H_ */
