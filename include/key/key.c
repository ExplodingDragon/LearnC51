#include "c52/regx52.h"
#include "utils/delay.h"


int selectMatrixKey() {
    int select = 0;

    P1 = 0xFF;
    P1_0 = 0;
    if (P1_7 == 0) {
        delay(20);
        while (P1_7 == 0);
        delay(20);
        select = 4;
    }
    if (P1_6 == 0) {
        delay(20);
        while (P1_6 == 0);
        delay(20);
        select = 8;
    }
    if (P1_5 == 0) {
        delay(20);
        while (P1_5 == 0);
        delay(20);
        select = 12;
    }
    if (P1_4 == 0) {
        delay(20);
        while (P1_4 == 0);
        delay(20);
        select = 16;
    }
    P1 = 0xFF;
    P1_1 = 0;
    if (P1_7 == 0) {
        delay(20);
        while (P1_7 == 0);
        delay(20);
        select = 3;
    }
    if (P1_6 == 0) {
        delay(20);
        while (P1_6 == 0);
        delay(20);
        select = 7;
    }
    if (P1_5 == 0) {
        delay(20);
        while (P1_5 == 0);
        delay(20);
        select = 11;
    }
    if (P1_4 == 0) {
        delay(20);
        while (P1_4 == 0);
        delay(20);
        select = 15;
    }
    P1 = 0xFF;
    P1_2 = 0;
    if (P1_7 == 0) {
        delay(20);
        while (P1_7 == 0);
        delay(20);
        select = 2;
    }
    if (P1_6 == 0) {
        delay(20);
        while (P1_6 == 0);
        delay(20);
        select = 6;
    }
    if (P1_5 == 0) {
        delay(20);
        while (P1_5 == 0);
        delay(20);
        select = 10;
    }
    if (P1_4 == 0) {
        delay(20);
        while (P1_4 == 0);
        delay(20);
        select = 14;
    }
    P1 = 0xFF;
    P1_3 = 0;
    if (P1_7 == 0) {
        delay(20);
        while (P1_7 == 0);
        delay(20);
        select = 1;
    }
    if (P1_6 == 0) {
        delay(20);
        while (P1_6 == 0);
        delay(20);
        select = 5;
    }
    if (P1_5 == 0) {
        delay(20);
        while (P1_5 == 0);
        delay(20);
        select = 9;
    }
    if (P1_4 == 0) {
        delay(20);
        while (P1_4 == 0);
        delay(20);
        select = 13;
    }
    return select;

}