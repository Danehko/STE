/* 
 * File:   USART.cpp
 * Author: aluno
 * 
 * Created on 16 de Setembro de 2019, 08:32
 */

#include "USART.h"
namespace USART { 
    
    USART::USART(uint32_t baud, DataBits_t db, ParityBits_t parity, StopBits_t sb) {
    }

    USART::~USART() {
    }
    
    void put(uint8_t data);
    void puts(const char * msg);
    uint8_t get();
}

