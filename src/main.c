#include <c52/regx52.h>
#include "lcd/LCD1602.h"
#include "key/key.h"
#include "utils/delay.h"

void Time0_Init() {
//    TMOD = 0b00000001;
    TMOD = TMOD & 0xF0;
    TMOD = TMOD | 0x01; // 处理不可位寻址常用方法

    TF0 = 0;
    TR0 = 1;
    TH0 = 64535 / 256;
    TL0 = 64535 % 256;
    ET0 = 1;
    EA = 1;
    PT0 = 0;
}

unsigned int count = 0;

int main() {
    Time0_Init();
    while (1) {

    }
    return 0;
}


void timer0_routine()

__interrupt (1) {
//void timer0_routine() {
TH0 = 64535 / 256;
TL0 = 64535 % 256;
count++;
if(count>=1000){
count = 0;
P2_0 = !P2_0;
}
}