#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h> // ????????????
#include "GPIO.h"

#define F_CPU 16000000UL // ??????????

class Pwm {
public:

	enum PIN_NUMBER {
		PIN_2 = 2,
		PIN_3 = 3,
		PIN_4 = 4,
		PIN_5 = 5,
		PIN_6 = 6,
		PIN_7 = 7,
		PIN_8 = 8,
		PIN_9 = 9,
		PIN_10 = 10,
		PIN_11 = 11,
		PIN_12 = 12,
		PIN_13 = 13,
		PIN_44 = 44,
		PIN_45 = 45,
		PIN_46 = 46
	};

    enum DIV_FREQ {
        DIV_FREQ1    = 0x01, 
        DIV_FREQ8    = 0x02,
        DIV_FREQ64   = 0x03,
        DIV_FREQ256  = 0x04,
        DIV_FREQ1024 = 0x05
    };

    enum DIV_FREQ9_10 {
        DIV_FREQ1    = 0x01,
        DIV_FREQ8    = 0x02,
        DIV_FREQ32   = 0x03,
        DIV_FREQ64   = 0x04,
        DIV_FREQ128  = 0x05,
        DIV_FREQ256  = 0x06,
        DIV_FREQ1024 = 0x07
    };

	enum TYPE_PWM {
		FAST = 0,
		PHASECORRET = 1
	};


    //Pwm(bool isFastPwm, int pinNumber, int dutyCycle, float frequency);

    Pwm(TYPE_PWM type, PIN_NUMBER pin, int dutyCycle, float frequency);


    ~Pwm();

    bool updateDutyCycle(int newDutyCycle);
private:
    GPIO *pwmOut;


    void setFastPwm();
    void setPhasePwm();

};


#endif /* PWM_H_ */
