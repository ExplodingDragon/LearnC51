//
// Created by dragon on 2021/11/12.
//
#include "c52/regx52.h"

void UartInit(void)        //9600bps@11.0592MHz
{
    PCON &= 0x7F;        //波特率不倍速
    SCON = 0x50;        //8位数据,可变波特率
    TMOD &= 0x0F;        //设置定时器模式
    TMOD |= 0x20;        //设置定时器模式
    TL1 = 0xFD;        //设置定时初始值
    TH1 = 0xFD;        //设置定时重载值
    ET1 = 0;        //禁止定时器  1 中断
    TR1 = 1;        //定时器1开始计时
}

void Send_Byte(unsigned int byte) {
    SBUF = byte;
    while (TI == 0);
    TI = 0;
}

void Send_Char(unsigned char input) {
    SBUF = (unsigned int) input;
    while (TI == 0);
    TI = 0;
}