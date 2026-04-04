// 12S24003 Michael Pratama Nasution 
// 12S24019 Winda N.V. Sitorus


#include <stdio.h>

int main(int argc, char **argv) {
    int jumlahInput;
    scanf("%d", &jumlahInput);

    int angka[jumlahInput];
    int nilai;
    int nilaiMax, nilaiMin;

    for (int i = 0; i < jumlahInput; i++) {
        scanf("%d", &nilai);
        angka[i] = nilai;
    }

    nilaiMax = angka[0];
    nilaiMin = angka[0];

    for (int i = 1; i < jumlahInput; i++) {
        if (nilaiMax < angka[i]) {
            nilaiMax = angka[i];
        }
        if (nilaiMin > angka[i]) {
            nilaiMin = angka[i];
        }
    }

    float rataRata = (angka[0] + angka[1]) / 2.0;

    printf("%d\n", nilaiMin);
    printf("%d\n", nilaiMax);
    printf("%.2f\n", rataRata);

    return 0;
}