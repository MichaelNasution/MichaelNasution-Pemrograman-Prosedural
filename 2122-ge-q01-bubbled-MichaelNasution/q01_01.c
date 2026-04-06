// 12S24003 - Michael Pratama Nasution
// 12S24019 - Winda N. V. Sitorus 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[101]; 
    scanf("%100s", str);

    char huruf[101]; 
    int j = 0;


    for (int i = 0; str[i]; i++) {
        if (str[i] != ',') {
            huruf[j++] = str[i];
        }
    }

    for (int i = 0; i < j-1; i++) {
        for (int k = 0; k < j-i-1; k++) {
            if (huruf[k] > huruf[k+1]) {
                char coba = huruf[k];
                huruf[k] = huruf[k+1];
                huruf[k+1] = coba;
            }
        }
    }

    j = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ',') {
            str[i] = huruf[j++];

        }
    }

        int huruf_pertama = 1;
    for (int i = 0; str[i]; i++) {
        if (huruf_pertama && str[i] == ',') {
            continue;
        }
        huruf_pertama = 0;
        printf("%c", str[i]);
        if (str[i] != ',' && str[i+1] != '\0' && str[i+1] != ',' && str[i+1] != '\n') {
            printf(",");
        }
    }
    printf("\n");

    return 0;
}