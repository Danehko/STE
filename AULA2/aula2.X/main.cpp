/* 
 * File:   main.cpp
 * Author: aluno
 *
 * Created on 28 de Agosto de 2019, 08:02
 */

#include<avr/io.h>
#include<util/delay.h>
#include <stdio.h>

#define FOSC 16000000
#define BAUD 9600
#define MYUBRR (FOSC/16/BAUD)-1

using namespace std;

void ADC_Init(){
    ADCSRA = (1<<ADEN)|(7<<ADPS0);
    ADLAR = 0;
	ADMUX |= (1<<REFS0);
}

uint16_t ADC_Read(uint8_t channel){
  	channel &= 0b00000111;  
  	ADMUX = (ADMUX & 0xF8)|channel; 
	ADCSRA |= (1<<ADSC);       
	while(ADCSRA & (1<<ADSC));
	return ADCW;               
}

void USART_Init( unsigned int ubrr){
    //UBRR0H = (unsigned char)(ubrr>>8);
    //UBRR0L = (unsigned char)ubrr;
    UBRR0 = ubrr;    // Set baud rate
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);	//Set frame format: 8data
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);   	// Enable receiver and transmitter
}

unsigned char USART_Receive( void ){
    while ( !(UCSR0A & (1<<RXC0)) );	//Wait for data to be received
    return UDR0;						//Get and return received data from buffer
}

void USART_Transmit( uint8_t data ){
    while ( !( UCSR0A & (1<<UDRE0)) );	//Wait for empty transmit buffer
    UDR0 = data;     					//Put data into buffer, sends the data
}

/*
#define led 13
#define B 39500000
#define r10k 10000
#define vin 10230000
#define rinf 176
unsigned long rntc = 0;
unsigned long vout_d = 0;
unsigned int tempk = 0;
unsigned int lnr = 0;
byte tempc = 0;

digitalWrite(led, HIGH); // turn on pullup resistors
  vout_d = analogRead(A1);
  rntc = r10k*((vin/vout_d)-10000);
  lnr = log(rntc/rinf)*100;
  tempk = B/(lnr);
  tempc = (tempk - 27315)/100;
  digitalWrite(led, LOW); // turn on pullup resistors
*/
int main() {
	ADC_Init();
    USART_Init(MYUBRR);
    void loop() {
	  uint16_t vout_d = ADC_Read(0);
	  float rntc = 10000.0*((1023.0/vout_d));
	  lnr = log(rntc/rinf)*100;
	  tempk = B/(lnr);
	  tempc = (tempk - 27315)/100;
	  digitalWrite(led, LOW); // turn on pullup resistors
	  delay(2000);  
	}
	return 0;
}
