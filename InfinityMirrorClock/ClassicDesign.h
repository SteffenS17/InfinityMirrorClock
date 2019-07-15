/*
 * ClassicDesign.h
 *
 *  Created on: 05.07.2019
 *      Author: steff
 */

#ifndef CLASSICDESIGN_H_
#define CLASSICDESIGN_H_

#include "ClockDesign.h"

class ClassicDesign :
		public ClockDesign{
public:
	ClassicDesign();
	~ClassicDesign(){};
	void setHourDesignOnStrip(Adafruit_NeoPixel* strip);
	void setTimeOnStrip(DS3231* clock, Adafruit_NeoPixel* strip);
	void setClassicDesignOnStrip(DS3231* clock, Adafruit_NeoPixel* strip);
};




#endif /* CLASSICDESIGN_H_ */
