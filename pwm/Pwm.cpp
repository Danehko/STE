#include <avr/io.h>

#define F_CPU 16000000UL

class Pwm {
    Pwm(bool isFastPwm) {
        // it's important to configure the port direction with the GPIO class

        // OCR0 is what controls the duty cycle
        // OCR0 = 45% of 255 = 114.75 = 115

        // Always set OC0A to be cleared and set OC0A at bottom
        TCCR0A = (1<<COMA1)
        if isFastPwm {
            setFastPwm()
        } else {
            setPhasePwm()
        }


    // The COM01:0 pins come into play here. We see that by setting it to “10” or “11”, the output pin OC0 is either set or cleared (in other words, it determines whether the PWM is in inverted mode, or in non-inverted mode).
        
    }

    void setFastPwm() {
        TCCR0A = ((1<<WGM01)|(1<<WGM00)); 
    }

    void setPhasePwm() {
        TCCR0A = ((0<<WGM01)|(1<<WGM00)); 
    }


};
