/* 
 * File:   main.cpp
 * Author: aluno
 *
 * Created on 21 de Agosto de 2019, 08:31
 */

#define F_CPU 16000000UL

#include<avr/io.h>
#include<util/delay.h>

/*
 * 
 */
int main() {
    
    DDRB |= (1<<7);
    DDRB &= ~(1<<6);
    
    for(;;){
        if(PINB & (1<<6)){
            PORTB |= (1<<7);
        }
        else{
            PORTB &= ~(1<<7); 
        }
    }
    return 0;
}
/*
int main() {
    
    DDRB = 0xFF;
    DDRF = 0x00;
    
    for(;;){
        if(PINF){
            PORTB = 0xFF;
        }
        else{
            PORTB = 0x00; 
        }
    }
    return 0;
}*/