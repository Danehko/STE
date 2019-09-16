/* 
 * File:   USART.h
 * Author: aluno
 *
 * Created on 16 de Setembro de 2019, 08:32
 */

#ifndef USART_H
#define	USART_H

class USART {
    enum ParityBits_t{
        NONE = 0,
        EVEN = 32,
        ODD  = 48 
    };
    enum DataBits_t{
        DATABITS_5 = 0,
        DATABITS_6 = 2,
        DATABITS_7 = 4,
        DATABITS_8 = 6
    };
    enum StopBits_t{
        STOPBITS_1 = 0,
        STOPBITS_2 = 8
    };
public:
    USART(uint32_t baud = 19200,
            ParityBits_t parity = NONE,
            DataBits_t db = DATABITS_8,
            StopBits_t sb = STOPBITS_1);
    
    ~USART();
    void put(uint8_t data);
    void puts(const char * msg);
    uint8_t get();
private:
};

#endif	/* USART_H */

