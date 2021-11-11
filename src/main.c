#include "utils/delay.h"
#include "lcd/LCD1602.h"

int main() {
    LCD_Init();
    LCD_ShowString(1, 1, "Kill You!");
    LCD_ShowBinNum(2, 1, 0xFE, 4);
    while (1) {

    }

    return 0;
}
