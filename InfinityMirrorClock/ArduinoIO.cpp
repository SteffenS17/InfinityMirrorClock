/*
 * ArduinoIO.cpp
 *
 *  Created on: 28.01.2018
 *      Author: steff
 */
#include "ArduinoIO.h"

ArduinoIO :: ArduinoIO(uint8_t ledPin, uint8_t buttonPin, uint8_t soundPin, uint8_t TXPin, uint8_t RXPin){
	this->m_ledPin = ledPin;
	this->m_buttonPin = buttonPin;
	this->m_soundPin = soundPin;
	this->m_TX = TXPin;
	this->m_RX = RXPin;
}

ArduinoIO :: ArduinoIO(){
	m_ledPin = 4;
	m_buttonPin = 2;
	m_soundPin = A0;
	m_TX = 10;
	m_RX = 11;
}

void ArduinoIO :: initArduino(void){
	setButton();
	setADC();
}

uint8_t ArduinoIO :: getLedPin(void){
	return m_ledPin;
}

uint8_t ArduinoIO :: getReceivePin(void){
	return m_RX;
}

uint8_t ArduinoIO :: getTransmitPin(void){
	return m_TX;
}

void ArduinoIO :: setButton(void){
	pinMode(m_buttonPin, INPUT_PULLUP);
}

void ArduinoIO :: setADC(void){
	pinMode(m_soundPin, INPUT);
}

