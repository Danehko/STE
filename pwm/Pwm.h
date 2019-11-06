#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h> // ????????????
#include "GPIO.h"

#define F_CPU 16000000UL // ??????????

class Pwm {
public:
    Pwm(bool isFastPwm, int pinNumber, int dutyCycle, float frequency);
    ~Pwm();

    bool updateDutyCycle(int newDutyCycle);
private:
    GPIO *pwmOut;


    void setFastPwm();
    void setPhasePwm();

};


#endif /* PWM_H_ */
