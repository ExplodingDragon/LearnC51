#include<mcs51/8051.h>

void delay(unsigned int t) {
    unsigned int a, b;
    for (a = t; a > 0; a--) {
        for (b = 100; b > 0; b--);
    }
}

//10101101
unsigned int num[] = {
        0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

void show(int index, int number) {
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

int main() {
    unsigned int n = 0;
    while (1) {
        if (P3_1 == 0) {
            delay(10);
            if (n-- <= 1) {
                n = 1;
            }

        }
        if (P3_0 == 0) {
            delay(10);
            if (n++ > 200) {
                n = 200;
            }
        }
        show(0, 1);
        show(1, 2);
        show(2, 3);
        show(3, 4);
        show(5, n / 100);
        show(6, n / 10 % 10);
        show(7, n % 10);

        P0 = 0x00;
        delay(n);

    }
    return 0;
}
