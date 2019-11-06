#include "Pwm.h"
#include <avr/delay.h>


int main() {
    unsigned char i=0; //Variavel para ser usada no for()
    Pwm p(false, 13, 100, 0);

    for(;;){
         //Fade up
         for(i=1; i<100;i++){
             p.updateDutyCycle(i);
             _delay_ms(5); //Um pequeno delay
         }

         //Fade down
         for(i=100; i>1;i--){
             p.updateDutyCycle(i);
             _delay_ms(5); //Um pequeno delay
         }
    }

    return 0;
}
