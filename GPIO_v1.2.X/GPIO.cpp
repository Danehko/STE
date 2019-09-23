/*
 * GPIO.cpp
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#include <avr/io.h>
#include "GPIO.h"

GPIO::GPIO(uint8_t id, PortDirection_t dir):
_id(id)
{
	switch (_id) {
	case 0:
	case 1:
		_bit = (1 << id);
		_PIN = &PINE;
		_DDR = &DDRE;
		_PORT = &PORTE;
		break;

	case 2:
	case 3:
		_bit = (1 << (id + 2));
		_PIN = &PINE;
		_DDR = &DDRE;
		_PORT = &PORTE;
		break;

	case 4:
		_bit = (1 << DDG5);
		_PIN = &PING;
		_DDR = &DDRG;
		_PORT = &PORTG;
		break;

	case 5:
		_bit = (1 << DDE3);
		_PIN = &PINE;
		_DDR = &DDRE;
		_PORT = &PORTE;
		break;

	case 6:
	case 7:
	case 8:
	case 9:
		_bit = (1 << (id - 3));
		_PIN = &PINH;
		_DDR = &DDRH;
		_PORT = &PORTH;
		break;

	case 10:
	case 11:
	case 12:
	case 13:
		_bit = (1 << (id - 6));
		_PIN = &PINB;
		_DDR = &DDRB;
		_PORT = &PORTB;
		break;

	}

	if (dir)
		*_DDR |= _bit;
	else
		*_DDR &= ~_bit;

}

GPIO::~GPIO() {}


bool GPIO::get() {
	return (bool) _PIN & _bit;
}


void GPIO::set(bool val) {
	if (val)
		*_PORT |= _bit;
	else
		*_PORT &= ~_bit;
}

void GPIO::clear() {
	this->set(0);
}

void GPIO::toggle() {
	*_PIN = _bit;
}