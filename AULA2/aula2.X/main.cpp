/* 
 * File:   main.cpp
 * Author: aluno
 *
 * Created on 28 de Agosto de 2019, 08:02
 */

#define F_CPU 16000000UL

#define BAUD 9600
#define MYUBRR (F_CPU/16/BAUD-1)

#include<avr/io.h>
#include<util/delay.h>

using namespace std;

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
    USART_Init(MYUBRR);
    unsigned char buffer;
    for(;;){
        buffer = USART_Receive();
        USART_Transmit(buffer+1);
    }
    return 0;
}