//
// Created by dragon on 2021/11/11.
//
#include "delay.h"
#include "c52/regx52.h"


void Delay1ms()        //@11.0592MHz
{
    unsigned char i, j;
    i = 2;
    j = 199;
    do {
        while (--j);
    } while (--i);
}




void DelayMs(unsigned int t) {
    unsigned int a;
    for (a = t; a > 0; a--) {
        Delay1ms();
    }
}
