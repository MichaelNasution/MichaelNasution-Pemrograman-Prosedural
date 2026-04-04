// 12S24003 - Michael Pratama Nasution
// 12S24019 - Winda N. V. Sitorus

#include <stdio.h>

int main(int _argc, char **_argv) {
  int x;
  const char *bulan[] = {

    "January" , "February" , "March" , "April" , "May" , "Juni" , "July" ,
    "August" , "September" , "October" , "November" , "December"

     };

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    scanf("%d", &x);
    x = x - 1;

    printf("%s\n", bulan[x % 12]);

    if (x == 10)
    {
      printf("%s\n", bulan[(x + 1) % 12]);
      printf("New year\n");
      printf("%s\n", bulan[(x + 2) % 12]);

    } else if (x == 11){
      printf("New year\n");
      printf("%s\n", bulan[(x + 1) % 12]);
      printf("%s\n", bulan[(x + 2) % 12]);

    } else if (x == x){
      printf("%s\n", bulan[(x + 1) % 12]);
      printf("%s\n", bulan[(x + 2) % 12]);
    }

return 0;
}
