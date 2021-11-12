#include <uart/uart.h>
#include "utils/delay.h"
#include "c52/regx52.h"
#include "num/num.h"
unsigned int show = 'A';

int main() {
    UartInit();
    while (1){
        Num_Display(show);
    }
    return 0;

}


void uart_get()

__interrupt (4) {
//void uart_get() {
if (RI == 1){
show = SBUF;
Send_Byte(SBUF);
RI = 0;
}

}