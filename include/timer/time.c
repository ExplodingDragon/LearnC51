//
// Created by dragon on 2021/11/12.
//
#include "time.h"
#include "c52/regx52.h"

void Time0_Init() { // 定时器代码
    TMOD &= 0xF0;
    TMOD |= 0x01; // 处理不可位寻址常用方法
    TF0 = 0;
    TR0 = 1;
    TH0 = 0xFC;
    TL0 = 0x18;
    ET0 = 1;
    EA = 1;
    PT0 = 0;
}
/** 模板
void timer0_routine() __interrupt (1) {
//void timer0_routine() {

TH0 = 0xFC;
TL0 = 0x18;
count++;
if (count >= 1000) {
count = 0;
waitOneS();
}
}
**/