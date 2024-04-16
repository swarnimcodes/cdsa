// CodeChef: https://www.codechef.com/problems/CIELRCPT

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int P;  // total bill at ciel's restaurant
        scanf("%d", &P);
        int currentMenuItemPrice = 2048;
        int menuCount = 0;
        while (P > 0) {
            if (P >= currentMenuItemPrice) {
                P -= currentMenuItemPrice;
                ++menuCount;
            } else {
                currentMenuItemPrice >>= 1; // division by 2
            }
        }
        printf("%d\n", menuCount);
    }
    return 0;
}
