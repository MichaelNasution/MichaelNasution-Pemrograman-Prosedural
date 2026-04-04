// 12S24003 - Michael Pratama Nasution
// 12S24019 - Winda N.V. Sitorus

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string_input[40];
    char string_pesan[14];
    int indeks;

    scanf("%39s", string_input);

    for (indeks = 0; indeks < strlen(string_input); indeks += 3) {
        int nilai_ascii = atoi(strncpy((char[4]) {0}, string_input + indeks, 3));
        string_pesan[indeks / 3] = (char) nilai_ascii;
    }

    string_pesan[indeks / 3] = '\0';

    printf("%s\n", string_pesan);

    return 0;
}