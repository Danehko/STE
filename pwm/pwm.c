#include <avr/io.h>
#include <avr/delay.h>

#define F_CPU 16000000UL

int main(void){
    
    unsigned char i=0; //Variavel para ser usada no for()

    DDRB |= (1<<7);
    DDRB &= ~(1<<6); 
    //Coloca o pino do led/pwm como saida
    //O PD6 é o digital 6 do Arduino
    
    //Configuração do timer
    TCCR0A = ((1<<COM0A1)|(1<<WGM01)|(1<<WGM00)); //Activar o pwm no pino PD e coloca o timer em modo Fast PWM
    TCCR0B = ((1<<CS01)|(1<<CS00));   //Activar o timer com um prescaler de 1:64

    for(;;){
         //Fade up
         for(i=0; i<255;i++){
              OCR0A = i; //Define o novo valor do duty cycle
              _delay_ms(5); //Um pequeno delay
         }

         //Fade down
         for(i=255; i>0;i--){
              OCR0A = i; //Define o novo valor do duty cycle
              _delay_ms(5); //Um pequeno delay
         }
    }

    return 0;
}
