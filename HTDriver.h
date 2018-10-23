/*
  HTDriver.h - Library for controlling the HT1652C Led driver.
  Created by Miguel Garnacho Velez, 23 of november, 2018.
  Released into the public domain.
*/

#ifndef HTDriver_h
#define HTDriver_h

#include "Arduino.h"

class HTDriver
{
  public:
    HTDriver(short pin_a, short pin_b, short pin_c, short pin_d, short pin_oe, short pin_di, short pin_clk, short pin_st);
    void begin();
	//Drawing methods
	void setPixel(short x, short y, short state);
	void setRow(short row, unsigned int values);
	void setMatrix(unsigned int matrix[16]);
	void update();
  private:
	//Pins
    short _pin_a;
	short _pin_b;
	short _pin_c;
	short _pin_d;
	short _pin_oe;
	short _pin_di;
	short _pin_clk;
	short _pin_st;
	//Matrix
	unsigned int _matrix[16];
	//Auxiliary methods
	void sendData(unsigned int data);
	void setDatalineWord(unsigned int word);
};

#endif

