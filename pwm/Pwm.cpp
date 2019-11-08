#include "Pwm.h"




Pwm::Pwm(TYPE_PWM type, PIN_NUMBER pin, int dutyCycle, float frequency) {
    // it's important to configure the port direction with the GPIO class
    /* GPIO pin(uint8_t(pinNumber), GPIO::OUTPUT); */
    /* this->pwmOut = &pin; // or implement the `new` operator */

    DDRB |= (1<<7);
    DDRB &= ~(1<<6); 

    updateDutyCycle(dutyCycle);

    // Always set OC0A to be cleared and set OC0A at bottom
    TCCR0A = (1<<COM0A1);

    if ( type == 0 ) {
        setFastPwm();
    } else {
        setPhasePwm();
    }

    //PARTE DA FREQUENCIA
    // if (pin == 13 || pin == 4){
        // TCCR0B = (TCCR0B & 0xF8) | value;
    // }else if (pin == 11 || pin == 12){
        // TCCR1B = (TCCR1B & 0xF8) | value;
    // }else if (pin == 9 || pin == 10){
        // TCCR2B = (TCCR2B & 0xF8) | value;
    // }else if (pin == 2 || pin == 3 || pin == 5){
        // TCCR3B = (TCCR3B & 0xF8) | value;
    // }else if (pin == 6 || pin == 7 || pin == 8){
        // TCCR4B = (TCCR4B & 0xF8) | value;
    // }else if (pin == 44 || pin == 45 || pin == 46){
        // TCCR5B = (TCCR5B & 0xF8) | value;
    // }else{
    // 	mata o codigo, kill acaba aqui, frequencia incorreta
    // }
    
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
