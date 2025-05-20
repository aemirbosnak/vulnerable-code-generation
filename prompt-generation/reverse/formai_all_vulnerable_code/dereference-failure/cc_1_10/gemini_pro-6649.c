//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// Function to translate a string from English to Cat Language
char *translate_to_cat(char *str) {
  char *cat_str = malloc(strlen(str) + 1);
  int i;

  for (i = 0; i < strlen(str); i++) {
    switch (str[i]) {
      case 'a':
        cat_str[i] = 'm';
        break;
      case 'e':
        cat_str[i] = 'i';
        break;
      case 'i':
        cat_str[i] = 'a';
        break;
      case 'o':
        cat_str[i] = 'u';
        break;
      case 'u':
        cat_str[i] = 'e';
        break;
      default:
        cat_str[i] = str[i];
    }
  }

  cat_str[strlen(str)] = '\0';

  return cat_str;
}

// Function to test the Cat Language Translator
int main() {
  char str[MAX_STR_LEN];
  char *cat_str;

  printf("Enter a string to translate: ");
  gets(str);

  cat_str = translate_to_cat(str);

  printf("Cat Language Translation: %s\n", cat_str);

  free(cat_str);

  return 0;
}