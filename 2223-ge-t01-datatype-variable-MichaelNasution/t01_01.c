// 12S24003 - Michael Pratama Nasution
// 12S24019 - Winda N.V Sitorus

#include <stdio.h>

int main(int _argc, char **_argv)
{
  int nilai_numerik;
  char karakter_ASCII;
  int nilaibolean;
  unsigned int nilai_tidak_negatif;
  float doubleback;

scanf("%d\n", &nilai_numerik);

scanf("%c\n", &karakter_ASCII);

scanf("%d\n", &nilaibolean);

scanf("%u\n", &nilai_tidak_negatif);

scanf("%f", &doubleback);




printf("%d\n", nilai_numerik);
printf("%c\n", karakter_ASCII);
printf("%d\n", nilaibolean);
printf("%u\n", nilai_tidak_negatif);
printf("%.2f\n", doubleback);

  return 0;
}
