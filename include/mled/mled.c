//
// Created by dragon on 2021/11/13.
//

#include "mled.h"
#include "c52/regx52.h"
#include "utils/delay.h"


// RCK = 3^5
// SCK = 3^6
// SER = 3^4

/*
 * 74HC595：
 * 初始化：
 * SCK = LOW,
 * SCK = LOW,
 *
 * SER 写入 1 bit
 * SCK 拉高推入，
 * SCK 复位，
 *
 * RCK 拉高推送数据
 * RCK 复位
 */
void write_byte(unsigned char byte) {

    for (int i = 0; i < 8; i++) {
        P3_4 = byte & (0x80 >> i);
        P3_6 = 1;
        P3_6 = 0;
    }
    P3_5 = 1;
    P3_5 = 0;
}


void MLED_Init() {
    P3_6 = 0;
    P3_5 = 0;
}
/**
 * 显示led数据
 *
 * @param index 竖排索引
 * @param data 数据 0b00000000
 */
void showColumn(unsigned int index, unsigned int data) {
    write_byte(data);
    P0 = ~(0x80 >> index);
    int i = 99;
    while (i--);
    P0 = 0xFF;
}