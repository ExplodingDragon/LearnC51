//
// Created by dragon on 2021/11/11.
//
#include <mcs51/8051.h>

unsigned int num[] = {
        0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0xF7, 0xFF, 0xB9, 0b10111111, 0b11111001, 0b11110001
};

void delay(unsigned int t) {
    unsigned int a, b;
    for (a = t; a > 0; a--) {
        for (b = 100; b > 0; b--);
    }
}


void displayNum(int index, int number) {
    switch (index) {
        case 0:
            P2_2 = 1;
            P2_3 = 1;
            P2_4 = 1;
            break;
        case 1:
            P2_2 = 0;
            P2_3 = 1;
            P2_4 = 1;
            break;
        case 2:
            P2_2 = 1;
            P2_3 = 0;
            P2_4 = 1;
            break;
        case 3:
            P2_2 = 0;
            P2_3 = 0;
            P2_4 = 1;
            break;
        case 4:
            P2_2 = 1;
            P2_3 = 1;
            P2_4 = 0;
            break;
        case 5:
            P2_2 = 0;
            P2_3 = 1;
            P2_4 = 0;
            break;
        case 6:
            P2_2 = 1;
            P2_3 = 0;
            P2_4 = 0;
            break;
        case 7:
            P2_2 = 0;
            P2_3 = 0;
            P2_4 = 0;
            break;
    }
    P0 = num[number];
    delay(1);
    P0 = 0x00;


}
