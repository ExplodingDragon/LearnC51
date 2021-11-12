#include <c52/regx52.h>
#include "lcd/LCD1602.h"
#include "key/key.h"
#include "utils/delay.h"
#include "timer/time.h"

unsigned int count = 0;

unsigned int indexInt = 0;

int main() {
    Time0_Init();
    while (1) {

    }
    return 0;
}

void timer0_routine()

__interrupt (1) {
//void timer0_routine() {

TH0 = 0xFC;
TL0 = 0x18;
count++;
if (count >= 500) {
count = 0;

P2 = (0b00000001 << indexInt) ^ 0xFF;
indexInt++;
if (indexInt > 7) {
indexInt = 0;
}
}
}

