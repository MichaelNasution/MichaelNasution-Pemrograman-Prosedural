// 12S24003 - Michael Pratama Nasution
// 12S24019 - Winda N.V. Sitorus

#include <stdio.h>
#include <string.h>

int main() {
    char string_input[50];
    int indeks;

    fgets(string_input, sizeof(string_input), stdin);

    string_input[strcspn(string_input, "\n")] = 0;

    for (indeks = 0; indeks < strlen(string_input); indeks++) {
        printf("%03d", string_input[indeks]);
    }

    printf("013\n");

  return 0;
}