// 12S24003 - Michael Pratama Nasution
// 12S24019 - Winda N.V Sitorus

#include <stdio.h>

int main() {
    int x, y, z;
    int shift_hasil;

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    shift_hasil = x << y;
    int hasil = (shift_hasil == z) ? 1 : 0;

    printf("%d\n", shift_hasil);
    printf("%d\n", hasil);

    return 0;
}