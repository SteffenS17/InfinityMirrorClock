/*
 * ClockDesign.h
 *
 *  Created on: 05.07.2019
 *      Author: steff
 */

#ifndef CLOCKDESIGN_H_
#define CLOCKDESIGN_H_

#include"Adafruit_NeoPixel.h"
#include"DS3231.h"

class ClockDesign{
public:
	ClockDesign(){}
	virtual ~ClockDesign(){}
	virtual void setHourDesignOnStrip(){}
	virtual void setTimeOnStrip(){}
};



#endif /* CLOCKDESIGN_H_ */
