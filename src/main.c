#include <uart/uart.h>
#include <mled/mled.h>
#include "utils/delay.h"

int main() {
    unsigned char data[][8] = {
            {0x3C, 0x42, 0xA9, 0x85, 0x85, 0xa9, 0x42, 0x3C},
            {0x3C, 0x42, 0xA1, 0x85, 0x85, 0xa1, 0x42, 0x3C},
            {0x3C, 0x42, 0xA5, 0x89, 0x89, 0xa5, 0x42, 0x3C}
    };

    int show = 0;
    int index = 0;

    MLED_Init();
    while (1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 8; j >= 0; --j) {
                showColumn(j, data[index][j]);
            }
            if (show++ == 15) {
                show = 0;
                if (index++ >= 2) {
                    index = 0;
                }
            }
        }

    }
    return 0;

}

