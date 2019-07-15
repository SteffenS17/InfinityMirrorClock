/*
 * SpectrumAnalyzer.cpp
 *
 *  Created on: 10.07.2019
 *      Author: steff
 */

#include "SpectrumAnalyzer.h"
#include "utilities.h"

SpectrumAnalyzer :: SpectrumAnalyzer(){
	m_offsetAddress = 65;
	m_offset = EEPROM.read(m_offsetAddress);
}

void SpectrumAnalyzer :: analyzeSpectrum(Adafruit_NeoPixel* strip){
	//TODO Implement Threshold in APP
	int static i = 0;
	static long tt;
	int val;
	int threshold = 15;
	//https://www.ece.louisville.edu/courses/ece412/?tag=frequency-spectrum-analyzer
	//Read Serial and fill array
	if (millis() > tt){
		if (i < 128){
			val = analogRead(0);  // Get Audio from Analog 0
			m_audio[i] = val / 4 - 128; //each element is val/4 - 128
			m_im[i] = 0; //initialize imaginary array
			i++;
		}
		else{ //Start Fourier-Transformation
			fix_fft(m_audio,m_im,7,0); //Perform fix_fft on audio array
			for (i=0; i< 64;i++){ //Separate to 64 frequencies
				double m = sqrt(m_audio[i] * m_audio[i] + m_im[i] * m_im[i]); //Calculate magnitude
				if(m*100 >= threshold*5){ //Find values above threshold
					uint8_t newM = (uint8_t)(m * 100.0); //amplify values
					if(newM > 255){
						newM = 255; //Set Maximum value respectively to Brightness
					}
					setColor(strip, i, newM); //Set Color and Position on Strip
				}
			}
			strip->show();
			strip->clear();
		}
		tt = millis();
	}
}



void SpectrumAnalyzer :: setColor(Adafruit_NeoPixel* strip, int index, uint8_t val){
	/* set Color after Table
	 * 				R	G	B	data[i]	nData	nLEDS	stripPos
	 * Violet		1	0	1	0-10	11		12		0-11
	 * Blue			0	0	1	11-21	11		12		12-23
	 * Turquoise	0	1	1	22-32	11		12		24-35
	 * Red			1	0	0	33-43	11		12		36-47
	 * Green		0	1	0	44-53	10		12		48-59
	 * Yellow		1	1	0	54-63	10		12		60-71
	 *
	 * */
	double pos[64];
	linspace(0.0, 71.0, 64, pos);
	if(index <= 10){ //Violet
		uint8_t adder = 0;
		for(uint8_t i = (uint8_t)round(pos[index]); i < (uint8_t)round(pos[index + 1]); i++){
			uint8_t stripPos = (uint8_t)round(pos[index])+adder;
			strip->setPixelColor(stripPos,strip->Color(val,0,val));
			strip->setPixelColor((strip->numPixels()-1)-stripPos,strip->Color(val,0,val));
			adder++;
		}
	}
	if(index > 10 && index <= 21){ //Blue
		uint8_t adder = 0;
		for(uint8_t i = (uint8_t)round(pos[index]); i < (uint8_t)round(pos[index + 1]); i++){
			uint8_t stripPos = (uint8_t)round(pos[index])+adder;
			strip->setPixelColor(stripPos,strip->Color(0,0,val));
			strip->setPixelColor((strip->numPixels()-1)-stripPos,strip->Color(0,0,val));
			adder++;
		}
	}
	if(index > 21 && index <= 32){ //Turquoise
		uint8_t adder = 0;
		for(uint8_t i = (uint8_t)round(pos[index]); i < (uint8_t)round(pos[index + 1]); i++){
			uint8_t stripPos = (uint8_t)round(pos[index])+adder;
			strip->setPixelColor(stripPos,strip->Color(0,val,val));
			strip->setPixelColor((strip->numPixels()-1)-stripPos,strip->Color(0,val,val));
			adder++;
		}
	}
	if(index > 32 && index <= 43){ //Red
		uint8_t adder = 0;
		for(uint8_t i = (uint8_t)round(pos[index]); i < (uint8_t)round(pos[index + 1]); i++){
			uint8_t stripPos = (uint8_t)round(pos[index])+adder;
			strip->setPixelColor(stripPos,strip->Color(val,0,0));
			strip->setPixelColor((strip->numPixels()-1)-stripPos,strip->Color(val,0,0));
			adder++;
		}
	}
	if(index > 43 && index <= 53){ //Green
		uint8_t adder = 0;
		for(uint8_t i = (uint8_t)round(pos[index]); i < (uint8_t)round(pos[index + 1]); i++){
			uint8_t stripPos = (uint8_t)round(pos[index])+adder;
			strip->setPixelColor(stripPos,strip->Color(0,val,0));
			strip->setPixelColor((strip->numPixels()-1)-stripPos,strip->Color(0,val,0));
			adder++;
		}
	}
	if(index > 53 && index <= 63){ //Yellow
		uint8_t adder = 0;
		for(uint8_t i = (uint8_t)round(pos[index]); i < (uint8_t)round(pos[index + 1]); i++){
			uint8_t stripPos = (uint8_t)round(pos[index])+adder;
			if(stripPos<72){
				strip->setPixelColor((uint8_t)round(pos[index])+adder,strip->Color(val,val,0));
				strip->setPixelColor((strip->numPixels()-1)-stripPos,strip->Color(val,val,0));
				adder++;
			}
		}
	}
}


void SpectrumAnalyzer :: calibrateSensor(void){

}
