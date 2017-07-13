/*
 Name:		DAC6574.h
 Created:	6/27/2017 1:27:25 PM
 Author:	gabor.baroczi.ext
 Editor:	http://www.visualmicro.com
*/

#ifndef _DAC6574_h
#define _DAC6574_h

#include <inttypes.h>
#include <Wire.h>

#define CH_A 0B00
#define CH_B 0B01
#define CH_C 0B10
#define CH_D 0B11

#define POWER_NORMAL 0b0
#define POWER_DOWN	0b1

#define CMD_STORE 0b00
#define CMD_SET_OUTPUT 0b01
#define CMD_4CH_SET_OUTPUT 0b10
#define CMD_BROADCAST 0b10

#define ADDRESS_4C_DEFAULT 0x4C
#define ADDRESS_4D 0x4D
#define ADDRESS_4E 0x4E
#define ADDRESS_4F 0x4F

#define HIGH_IMPEDANCE_OUTPUT 0b00
#define _1K_TO_GND 0b01
#define _100K_TO_GND 0b10
#define HIGH_IMPEDANCE 0b11

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
class DAC6574 {
public:
	DAC6574();
	DAC6574(uint8_t addr);
	void begin();
	void storeData1CH(uint8_t channel, uint16_t data);
	void setOutput1CH(uint8_t channel, uint16_t data);
	void setOutputAllCH(uint16_t data);
	void powerDown1CH(uint8_t channel, uint8_t mode);
	void powerDownAllCH(uint8_t mode);


private:
	uint8_t _i2caddr;
};

#endif
