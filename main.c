#include<mcs51/8051.h>

void delay(unsigned int t) {
    unsigned int a, b;
    for (a = t; a > 0; a--) {
        for (b = 100; b > 0; b--);
    }
}

int main() {
    P2 = 0xFF;
    int d = 500;
    while (1) {
        P2 = 0xFF; // 1111 1111
        delay(d);
        P2 = 0xFE; // 1111 1110
        delay(d);
        P2 = 0xFD; // 1111 1101
        delay(d);
        P2 = 0xFB; // 1111 1011
        delay(d);
        P2 = 0xF7; // 1111 0111
        delay(d);
        P2 = 0xEF; // 1110 1111
        delay(d);
        P2 = 0xDF; // 1101 1111
        delay(d);
        P2 = 0xBF; // 1011 1111
        delay(d);
        P2 = 0x7F; // 0111 1111
        delay(d);

    }
    return 0;
}
