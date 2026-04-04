// 12S24003 - Michael Pratama Nasution
// 12S24019 - Winda N.V Sitorus

#include <stdio.h>

int main() {
    float n1, n2, n3, n4, n5, jumlah, rata_rata;

    scanf("%f %f %f %f %f", &n1, &n2, &n3, &n4, &n5);

    jumlah = n1 + n2 + n3 + n4 + n5;
    rata_rata = jumlah / 5.0;

    printf("Jumlah: %.3f\n", jumlah);
    printf("Rata-rata: %.3f\n", rata_rata);

    return 0;
}

