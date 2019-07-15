/*
 * SpectrumAnalyzer.h
 *
 *  Created on: 10.07.2019
 *      Author: steff
 */

#ifndef SPECTRUMANALYZER_H_
#define SPECTRUMANALYZER_H_

#include "Arduino.h"
#include "fix_fft.h"
#include <EEPROM.h>
#include "Adafruit_NeoPixel.h"

class SpectrumAnalyzer{
public:
	SpectrumAnalyzer();
	void analyzeSpectrum(Adafruit_NeoPixel* strip);
	void calibrateSensor(void);
private:
	void SpectrumAnalyzer :: setColor(Adafruit_NeoPixel* strip, int i, uint8_t val);
	char m_im[128];
	char m_audio[128];
	double m_offset;
	int m_offsetAddress;
};




#endif /* SPECTRUMANALYZER_H_ */
