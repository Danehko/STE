#include <avr/io.h>
#include <avr/interrupt.h>
#include "GPIO.h"
#include "GPIO_Port.h"
#include "Timer.h"
 
 
GPIO p2(2, GPIO::OUTPUT);
GPIO p3(3, GPIO::OUTPUT);
GPIO p4(4, GPIO::OUTPUT);
GPIO p5(5, GPIO::OUTPUT);
 
//void timeout2_handler(void){
//	p2.toggle();
//}
// 
//void timeout3_handler(void){
//	p3.toggle();
//}
// 
//void timeout4_handler(void){
//	p4.toggle();
//}
// 
//void timeout5_handler(void){
//	p5.toggle();
//}
// 
// 
//Timer t = Timer(1000);

// *** correção A3 ****

GPIO led13(13, GPIO::OUTPUT);
GPIO_PORT::GPIO_Port * PK = GPIO_PORT::AllPorts[9];
uint8_t pk_value = 0x01;

Timer t = Timer(1000);

GPIO sv54(54,GPIO::INPUT);

UART uart(9600, UART::EIGHT_08, UART::NONE_PAR, UART::ONE_S8, UART::DS_DISABLE);

uint8_t pk_value = 0x01;

const char msg[]="O valor atual da porta PK e: ";

void rotate_pk(void){

    PK->write_byte(pk_value);
    
    if(pk_value == 128)
        pk_value = 0x01;
    else
        pk_value <<= 1;
}

void check_sw(void){
    
    //char s[5];
    char s[4];
    if(sw54.get()){
        uart.puts(msg);
        //sprinf(s, "%d\n", pk_value);
        itoa(pk_value,s,10);
        s[3] = '\0';
        uart.puts(s);
        uart.put('\n');
    }
}



int main(){
 
//	sei();
//	t.addTimeout(1000, &timeout2_handler);
//	t.addTimeout(2000, &timeout3_handler);
//	t.addTimeout(3000, &timeout4_handler);
//	t.addTimeout(4000, &timeout5_handler);
//	while(true){
//		t.timeoutManager();
//	}
    
    led13.clear();
    
    PK->dir_byte(1);
    
    t.addTimeout(2000,&rotate_pk);
    t.addTimeout(200,&check_sw);

    sei();
    
    for(;;){
    
        t.timeoutMannager();
    }   
    
    
}