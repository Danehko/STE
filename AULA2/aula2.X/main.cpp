/* 
 * File:   main.cpp
 * Author: aluno
 *
 * Created on 28 de Agosto de 2019, 08:02
 */

#include<avr/io.h>
#include <stdio.h>
#include <math.h> 

#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR (F_CPU/16/BAUD)-1

using namespace std;

void ADC_Init(){
    ADCSRA = (1<<ADEN)|(7<<ADPS0);
	ADMUX |= (1<<REFS0);
}

uint16_t ADC_Read(uint8_t channel){
  	channel &= 0x07;  
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

#define B 3950
#define r10k 10000.0
#define vin 5
#define rinf 0.0176

int main() {
	ADC_Init();
    USART_Init(MYUBRR);
	char buffer[16];
    float vout = 0;
    float rntc = 0;
    float lnr = 0;
    float tempk = 0;
	float tempc = 0;
	
    for(;;){
	  uint16_t vout_d = ADC_Read(0);
	  sprintf(buffer,"ADC: %d\r\n",vout_d);
	  for(int i = 0; i < 10; i++){
          USART_Transmit(buffer[i]);
      }
	  vout = (vin * vout_d)/1023;
	  rntc = r10k * ((vin/vout)-1);
	  lnr = log(rntc/rinf);
	  tempk = B/(lnr);
	  tempc = (tempk - 273.15);
      snprintf(buffer,10,"T: %d\r\n", (int)(tempc));
      for(int i = 0; i < 10; i++){
        USART_Transmit(buffer[i]);
      }
	}
	return 0;
}
