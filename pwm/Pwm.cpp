#include "Pwm.h"


Pwm::Pwm(bool isFastPwm, int pinNumber, int dutyCycle, float frequency) {
    // it's important to configure the port direction with the GPIO class
    /* GPIO pin(uint8_t(pinNumber), GPIO::OUTPUT); */
    /* this->pwmOut = &pin; // or implement the `new` operator */

    DDRB |= (1<<7);
    DDRB &= ~(1<<6); 

    updateDutyCycle(dutyCycle);

    // Always set OC0A to be cleared and set OC0A at bottom
    TCCR0A = (1<<COM0A1);
    if (isFastPwm) {
        setFastPwm();
    } else {
        setPhasePwm();
    }
    
    // test
    TCCR0B = ((1<<CS01)|(1<<CS00));


    // TODO: missing frequency configuration
}

Pwm::~Pwm() {}

void Pwm::setFastPwm() {
    TCCR0A |= ((1<<WGM01)|(1<<WGM00)); 
}

void Pwm::setPhasePwm() {
    TCCR0A |= ((0<<WGM01)|(1<<WGM00)); 
}

bool Pwm::updateDutyCycle(int dutyCycle) {
    // OCR0 is what controls the duty cycle
    // OCR0 = 45% of 255 = 114.75 = 115
    if (dutyCycle < 100 && dutyCycle > 0) {
        OCR0A = dutyCycle * 255/100;
        return true;
    } else {
        OCR0A = 0;
        return false;
    }
}
