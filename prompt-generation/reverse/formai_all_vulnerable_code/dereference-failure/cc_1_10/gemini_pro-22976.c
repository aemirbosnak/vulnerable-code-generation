//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

char *translate(char *input) {
  char *output = (char *)malloc(MAX_SIZE);
  int i = 0;
  int j = 0;

  while (input[i] != '\0') {
    switch (input[i]) {
      case 'a':
        output[j++] = 'm';
        break;
      case 'e':
        output[j++] = 'o';
        break;
      case 'i':
        output[j++] = 'u';
        break;
      case 'o':
        output[j++] = 'a';
        break;
      case 'u':
        output[j++] = 'e';
        break;
      default:
        output[j++] = input[i];
        break;
    }
    i++;
  }

  output[j] = '\0';

  return output;
}

int main() {
  char input[MAX_SIZE];
  char *output;

  printf("Enter a string to translate: ");
  fgets(input, MAX_SIZE, stdin);

  output = translate(input);

  printf("Translated string: %s", output);

  free(output);

  return 0;
}