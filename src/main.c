#include "lcd/LCD1602.h"
#include "key/key.h"
#include "utils/delay.h"


int main() {
    int num = 0;
    LCD_Init();
    LCD_ShowString(1, 1, "Input:");
    while (1) {

        int select = selectMatrixKey();
        if (select != 0) {
            num = select;
        }
        LCD_ShowNum(1, 10, num, 2);

    }
    return 0;
}
