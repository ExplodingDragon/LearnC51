#include <c52/regx52.h>
#include <stdbool.h>
#include "lcd/LCD1602.h"
#include "key/key.h"
#include "utils/delay.h"
#include "timer/time.h"

unsigned int count = 0;


int h = 23, m = 59, s = 55;

void drawTime() {
    displayNum(0, h / 10 % 10);
    displayNum(1, h % 10);

    displayNum(3, m / 10 % 10);
    displayNum(4, m % 10);

    displayNum(6, s / 10 % 10);
    displayNum(7, s % 10);
}

int main() {
    Time0_Init();
    while (1) {
        drawTime();
    }
    return 0;
}


void timer0_routine()

__interrupt (1) {
//void timer0_routine() {
    TH0 = 0xFC;
    TL0 = 0x18;
    count++;
    if (count >= 1000) {
        count = 0;
        s++;
        if (s == 60) {
            s = 0;
            m++;
        }
        if (m == 60) {
            m = 0;
            h++;
        }

        if (h == 24) {
            h = 0;
            m = 0;
            s = 0;
        }
    }
}

