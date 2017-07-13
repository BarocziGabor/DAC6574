/*
 Name:		DAC6574.cpp
 Created:	6/27/2017 1:27:25 PM
 Author:	Baroczi Gabor
 Editor:	http://www.visualmicro.com
*/

#include "DAC6574.h"

DAC6574::DAC6574()
{
	_i2caddr = ADDRESS_4C_DEFAULT;	
}

DAC6574::DAC6574(uint8_t addr)
{
	_i2caddr = addr;	
}

void DAC6574::begin()
{
	Wire.begin();
	powerDownAllCH(_100K_TO_GND);
}

void DAC6574::storeData1CH(uint8_t channel,uint16_t data)
{
	Wire.beginTransmission(_i2caddr);
	Wire.write(channel << 1);
	Wire.write((uint8_t)((data&0b1111111100)>>2));
	Wire.write(((uint8_t)(data & 0b11))<<6);
	Wire.endTransmission();
}

void DAC6574::setOutput1CH(uint8_t channel, uint16_t data)
{
	Wire.beginTransmission(_i2caddr);
	Wire.write((CMD_SET_OUTPUT << 4) | (channel << 1));
	Wire.write((uint8_t)((data & 0b1111111100) >> 2));
	Wire.write(((uint8_t)(data & 0b11)) << 6);
	Wire.endTransmission();
}

void DAC6574::setOutputAllCH(uint16_t data)
{
	Wire.beginTransmission(_i2caddr);
	Wire.write(0b00110100);
	Wire.write((uint8_t)((data & 0b1111111100) >> 2));
	Wire.write(((uint8_t)(data & 0b11)) << 6);
	Wire.endTransmission();
}

void DAC6574::powerDown1CH(uint8_t channel, uint8_t mode)
{
	Wire.beginTransmission(_i2caddr);
	Wire.write((CMD_SET_OUTPUT << 4) | (channel << 1) | POWER_DOWN);
	Wire.write(mode<<6);
	Wire.write(0);
	Wire.endTransmission();

}

void DAC6574::powerDownAllCH(uint8_t mode)
{
	Wire.beginTransmission(_i2caddr);
	Wire.write(0b00110101);
	//Wire.write(mode << 6);
	Wire.write(0b10000000);
	Wire.write(0);
	Wire.endTransmission();
}
