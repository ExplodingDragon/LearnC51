#include <uart/uart.h>
#include "utils/delay.h"


unsigned int size = 'A';

int main() {
    UartInit();
    while (1) {
        size++;
        DelayMs(1000);
        Send_Char(size);
    }
    return 0;
}

