#include<mcs51/8051.h>

void delay(unsigned int t) {
    unsigned int a, b;
    for (a = t; a > 0; a--) {
        for (b = 100; b > 0; b--);
    }
}

int main() {
    P2 = 0xFF;
    int vol = 0;
    while (1) {
        if (P3_1 == 0) {
            delay(50);
            while (P3_1 == 0);
            delay(50);
            vol--;
            if (vol < 0) {
                vol = 0;
            }
            P2 = 0xFF << vol;
        }
        if (P3_0 == 0) {
            delay(50);
            while (P3_0 == 0);
            delay(50);

            vol++;
            if (vol > 8) {
                vol = 8;
            }
            P2 = 0xFF << vol;
        }

    }
    return 0;
}
