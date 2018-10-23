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
	clear();
}

//Drawing methods

void HTDriver::setPixel(short x, short y, unsigned char state) {
	unsigned int number;
	if (x < 8) {
		number = _matrix[15 - y];
		_matrix[15 - y] ^= (-state ^ number) & (1 << (7 - x));
	} else {
		number = _matrix[31 - y];
		_matrix[31 - y] ^= (-state ^ number) & (1 << (15 - x));
	}
}

void HTDriver::setMatrix(unsigned char matrix[16][16]) {
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			setPixel(i, j, matrix[i][j]);
		}
	}
}

void HTDriver::update() {
  for(int i = 0;i < 16;i++)
  {
    digitalWrite(_pin_oe, HIGH);   
    sendData(_matrix[i+16]);
    sendData(_matrix[i]);
    digitalWrite(_pin_st, HIGH);          
    delayMicroseconds(1);
    digitalWrite(_pin_st, LOW);
    delayMicroseconds(1);
    setDatalineWord(i);             
    digitalWrite(_pin_oe, LOW);
    delayMicroseconds(100);   
  } 
}

void HTDriver::clear() {
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			setPixel(i, j, LOW);
		}
	}
}

//Auxiliar

void HTDriver::sendData(unsigned int data) {
  digitalWrite(_pin_clk, LOW);
  delayMicroseconds(1);; 
  digitalWrite(_pin_st, LOW);
  delayMicroseconds(1);
  for(int i = 0 ; i < 8 ; i++ )
  {
    digitalWrite(_pin_di, !(data & (1 << i)));  
    delayMicroseconds(1);
    digitalWrite(_pin_clk, HIGH);         
    delayMicroseconds(1);
    digitalWrite(_pin_clk, LOW);
    delayMicroseconds(1);   
  }     
}

void HTDriver::setDatalineWord(unsigned int word) { 
  digitalWrite(_pin_a, word & 0b0001);
  digitalWrite(_pin_b, word & 0b0010);
  digitalWrite(_pin_c, word & 0b0100);
  digitalWrite(_pin_d, word & 0b1000);
}


