// 12S24003 - Michael P. Pratama Nasution
// 12S24019 - Winda N. V. Sitorus

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char nama[MAX_LENGTH];
    int bobot;
    int nilai;
} KomponenPenilaian;

void bacaInput(KomponenPenilaian *komponen, int k) {
    for (int i = 0; i < k; i++) {
        // Read the input line
        char input[MAX_LENGTH];
        fgets(input, sizeof(input), stdin);
        // Parse the input
        sscanf(input, "%[^#]#%d#%d", komponen[i].nama, &komponen[i].bobot, &komponen[i].nilai);
    }
}

void tampilkanKomponen(KomponenPenilaian *komponen, int k) {
    for (int i = 0; i < k; i++) {
        printf("%s;%d;%d\n", komponen[i].nama, komponen[i].bobot, komponen[i].nilai);
    }
}

float hitungNilaiAkhir(KomponenPenilaian *komponen, int k) {
    float totalNilai = 0;
    int totalBobot = 0;
    for (int i = 0; i < k; i++) {
        totalNilai += komponen[i].bobot * komponen[i].nilai;
        totalBobot += komponen[i].bobot;
    }
    return totalBobot > 0 ? totalNilai / totalBobot : 0.0;
}

void cekKelulusan(float nilaiAkhir) {
    if (nilaiAkhir >= 50.0) {
        printf("passed\n");
    } else {
        printf("failed\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2 || atoi(argv[1]) < 1 || atoi(argv[1]) > 5) {
        printf("Invalid argument\n");
        return 1;
    }

    int k = atoi(argv[1]);
    KomponenPenilaian komponen[k];

    // Read input
    bacaInput(komponen, k);
    
    // Display components
    tampilkanKomponen(komponen, k);

    // Calculate final score
    float nilaiAkhir = hitungNilaiAkhir(komponen, k);
    printf("%.1f\n", nilaiAkhir);

    // Check pass/fail status
    cekKelulusan(nilaiAkhir);

    return 0;
}