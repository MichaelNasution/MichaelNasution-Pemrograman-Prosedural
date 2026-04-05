#include <stdio.h>
#include <string.h>

struct dictionary_t
{
  char word[20];
  char meaning[80];
};

int main(int _argv, char **_argc)
{
  struct dictionary_t kamus[5];
  int i=0;

    while (0 == 0)
    {
      char masukan[50];
    scanf("%s", masukan);
      if (strcmp(masukan, "find") == 0) {
        char kata[20];
        scanf("%s", kata);
        int x;
        for(x = 0; x < 5; x++) {
          if(strcmp(kata, kamus[x].word) == 0) {
              printf("%s#%s\n", kamus[x].word, kamus[x].meaning);
          }
        }
      } else if (strcmp(masukan, "register") == 0) {
        char kata[20];
        char arti[80];
          scanf("%s\n", kata);
          scanf("%[^\n]", arti);
          strcpy(kamus[i].word, kata);
          strcpy(kamus[i].meaning, arti);
        i++;
      } else if (strcmp(masukan, "---") == 0)
      {
        return 0;
      }     
    }
return 0; 
}