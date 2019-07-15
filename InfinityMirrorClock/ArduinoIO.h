/*
 * ArduinoIO.h
 *
 *  Created on: 28.01.2018
 *      Author: steff
 */

#ifndef ARDUINOIO_H_
#define ARDUINOIO_H_

#include <Arduino.h>

class ArduinoIO{
public:
	ArduinoIO();
	ArduinoIO(uint8_t ledPin, uint8_t buttonPin, uint8_t soundPin, uint8_t TXPin, uint8_t RXPin);
	void initArduino(void);
	uint8_t getLedPin(void);
	uint8_t getReceivePin(void);
	uint8_t getTransmitPin(void);
private:
	void setButton(void);
	void setADC(void);
	uint8_t m_ledPin;
	uint8_t m_buttonPin;
	uint8_t m_soundPin;
	uint8_t m_TX;
	uint8_t m_RX;
};


#endif /* ARDUINOIO_H_ */
