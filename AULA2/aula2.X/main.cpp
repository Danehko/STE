/* 
 * File:   main.cpp
 * Author: aluno
 *
 * Created on 28 de Agosto de 2019, 08:02
 */

#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR (F_CPU/16/BAUD-1)

#define led 13
#define a 0.001112272865
#define b 0.0002375809102
#define c 0.00000006852858650
#define r10k 10000
#define vin 5

#include<avr/io.h>
#include<util/delay.h>

using namespace std;

void ADC_Init(){
    ADCSRA = (1<<ADEN)|(7<<ADPS0);
    ADLAR = 0;
}

void USART_Init( unsigned int ubrr){
    // Set baud rate
    //UBRR0H = (unsigned char)(ubrr>>8);
    //UBRR0L = (unsigned char)ubrr;
    UBRR0 = ubrr;
    //Set frame format: 8data
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
    // Enable receiver and transmitter
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
}

unsigned char USART_Receive( void ){
    //Wait for data to be received
    while ( !(UCSR0A & (1<<RXC0)) );
    //Get and return received data from buffer
    return UDR0;
}

void USART_Transmit( unsigned char data ){
    //Wait for empty transmit buffer
    while ( !( UCSR0A & (1<<UDRE0)) );
    //Put data into buffer, sends the data
    UDR0 = data;
}

int main() {
    unsigned int vout_d = 0;
    unsigned int  vout = 0;
    unsigned int  tempk = 0;
    unsigned int  tempc = 0;
    unsigned int  rntc = 0;
    USART_Init(MYUBRR);
    DDRB |= (1<<7);
    
    unsigned char buffer;
    for(;;){
        PORTB |= (1<<7);
        vout_d = ADC;
        vout = (5 * vout_d)/1023;
        rntc = r10k*((vin/vout)-1);
        tempk = 1/(a + (b*(log(rntc))) + (c*(log(rntc))*(log(rntc))*(log(rntc))));
        tempc = tempk - 273.15;
        buffer = USART_Receive();
        USART_Transmit(buffer+1);
        PORTB &= ~(1<<7);
    }
    return 0;
}