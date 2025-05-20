//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: surrealist
#include <stdio.h>
#include <string.h>

void alien_translator(char *alien_text)
{
  char **translations = malloc(10 * sizeof(char *));
  translations[0] = "Buzzing quasar";
  translations[1] = "Mumbling nebula";
  translations[2] = "Groaning supergiant";
  translations[3] = "Dancing neutron star";
  translations[4] = "Fuming black hole";
  translations[5] = "Whispering dwarf star";
  translations[6] = "Twinkling asteroid";
  translations[7] = "Gurgling wormhole";
  translations[8] = "Roiling quagmire";
  translations[9] = "Mightiest cosmic void";

  int i = 0;
  for (i = 0; alien_text[i] != '\0'; i++)
  {
    switch (alien_text[i])
    {
      case 'a':
        alien_text[i] = translations[0][0];
        break;
      case 'b':
        alien_text[i] = translations[1][0];
        break;
      case 'c':
        alien_text[i] = translations[2][0];
        break;
      case 'd':
        alien_text[i] = translations[3][0];
        break;
      case 'e':
        alien_text[i] = translations[4][0];
        break;
      case 'f':
        alien_text[i] = translations[5][0];
        break;
      case 'g':
        alien_text[i] = translations[6][0];
        break;
      case 'h':
        alien_text[i] = translations[7][0];
        break;
      case 'i':
        alien_text[i] = translations[8][0];
        break;
      case 'j':
        alien_text[i] = translations[9][0];
        break;
    }
  }

  free(translations);
}

int main()
{
  char alien_text[] = "Frgl spzt zrt wosh wubbd phblx drgn thry flwr";
  alien_translator(alien_text);
  printf("%s\n", alien_text);

  return 0;
}