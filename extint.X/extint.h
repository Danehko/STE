/* 
 * File:   extint.h
 * Author: aluno
 *
 * Created on 9 de Outubro de 2019, 08:17
 */

#ifndef EXTINT_H
#define	EXTINT_H

#include <avr/io.h>
#include <avr/interrupt.h>

namespace EXT_INT {

typedef void (*CALLBACK_t) (void);

class ExtInt {
public:
	enum ISC_t {		//Interrupt Sense Control
		LOW_LEVEL = 0,
		ANY_EDGE = 1,
		FALLING = 2,
		RISING = 3
	};

	enum INT_ID_t {		//Interrupt Sense Control
		INT_0 = 0,
		INT_1 = 1,
		INT_2 = 2,
		INT_3 = 3,
		INT_4 = 4,
		INT_5 = 5,
		INT_6 = 6,
		INT_7 = 7,
	};

	ExtInt(INT_ID_t id,
		   ISC_t cfg,
		   CALLBACK_t pCallback);
	~ExtInt();

	void enable();
	void disable();

	void callback(){(*_pCallback)();}

	static ExtInt * _ExtInt_singletons[8];

private:
	uint8_t _id;
	uint8_t _msk;
	CALLBACK_t _pCallback;


};

}

#endif	/* EXTINT_H */

