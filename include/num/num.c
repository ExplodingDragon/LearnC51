//
// Created by dragon on 2021/11/12.
//

#include "num.h"
#include "utils/delay.h"
#include "c52/regx52.h"

unsigned int pInt[] = {
        0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0xF7, 0xFF, 0xB9, 0b10111111, 0b11111001, 0b11110001
};
unsigned int select[8][3] = {
        {1, 1, 1},
        {0, 1, 1},
        {1, 0, 1},
        {0, 0, 1},
        {1, 1, 0},
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0},
};

void Num_Display(int num) {
    if (num < 0) {
        num = -num;
    }
    Num_DisplayNum(3, num / 10000 % 10);
    Num_DisplayNum(4, num / 1000 % 10);
    Num_DisplayNum(5, num / 100 % 10);
    Num_DisplayNum(6, num / 10 % 10);
    Num_DisplayNum(7, num % 10);
}

void Num_DisplayNum(int index, int number) {
    P2_2 = select[index][0];
    P2_3 = select[index][1];
    P2_4 = select[index][2];
    P0 = pInt[number];
    DelayMs(1);
    P0 = 0x00;


}
