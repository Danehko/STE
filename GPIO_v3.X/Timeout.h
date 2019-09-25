/* 
 * File:   Timeout.h
 * Author: aluno
 *
 * Created on 25 de Setembro de 2019, 08:05
 */

#ifndef TIMEOUT_H
#define	TIMEOUT_H

class Timeout {
public:
    Timeout();
    Timeout(const Timeout& orig);
    virtual ~Timeout();
    uint32_t _interval;
private:
    bool _event;
    bool _enable;
    CALLBACK_t _callback;
    uint32_t _counter;

};

#endif	/* TIMEOUT_H */

