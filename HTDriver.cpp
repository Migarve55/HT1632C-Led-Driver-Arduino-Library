/*
  HTDriver.cpp - Library for controlling the HT1652C Led driver.
  Created by Miguel Garnacho Velez, 23 of november.
  Released into the public domain.
*/

#include "Arduino.h"
#include "HTDriver.h"

HTDriver::HTDriver(short pin_a, short pin_b, short pin_c, short pin_d, short pin_oe, short pin_di, short pin_clk, short pin_st)
{
  _pin_a = pin_a;
  _pin_b = pin_b;
  _pin_c = pin_c;
  _pin_d = pin_d;
  _pin_oe = pin_oe;
  _pin_di = pin_di;
  _pin_clk = pin_clk;
  _pin_st = pin_st;
}

void HTDriver::begin()
{
	pinMode(_pin_a, OUTPUT);
	pinMode(_pin_b, OUTPUT);
	pinMode(_pin_c, OUTPUT);
	pinMode(_pin_d, OUTPUT);
	pinMode(_pin_oe, OUTPUT);
	pinMode(_pin_di, OUTPUT);
	pinMode(_pin_clk, OUTPUT);
	pinMode(_pin_st, OUTPUT);
}

//Drawing methods

void HTDriver::setPixel(short x, short y, short state) {
	_matrix[y] &= state << x;
}

void HTDriver::setRow(short row, unsigned int values) {
	_matrix[row] = values;
}

void HTDriver::setMatrix(unsigned int matrix[16]) {
	_matrix = matrix;
}

void HTDriver::update() {
	
}

//Auxiliar

void HTDriver::sendData(unsigned int data) {
	
}

void HTDriver::setDatalineWord(unsigned int word) { 
  digitalWrite(_pin_a, word & 0b0001);
  digitalWrite(_pin_b, word & 0b0010);
  digitalWrite(_pin_c, word & 0b0100);
  digitalWrite(_pin_d, word & 0b1000);
}


