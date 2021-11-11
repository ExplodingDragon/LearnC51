#include <mcs51/8051.h>
#include "delay.h"


int main() {
    unsigned int n = 0;
    unsigned int k = 0;
    while (1){

        displayNum(0, 10);
        displayNum(1, 11);
        displayNum(2, 12);
        displayNum(3, 13);
        displayNum(4, 14);
        displayNum(5, 15);
    }

    return 0;
}
