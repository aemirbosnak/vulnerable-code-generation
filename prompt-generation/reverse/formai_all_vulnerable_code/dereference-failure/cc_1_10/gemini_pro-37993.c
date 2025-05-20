//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
  // Get the input from the user.
  char *input = malloc(MAX_LINE_LENGTH);
  printf("Enter your text in Cat Language: ");
  fgets(input, MAX_LINE_LENGTH, stdin);

  // Translate the input to English.
  char *output = malloc(MAX_LINE_LENGTH);
  int i = 0;
  int j = 0;
  while (input[i] != '\0') {
    switch (input[i]) {
      case 'a':
        output[j++] = 'e';
        break;
      case 'e':
        output[j++] = 'i';
        break;
      case 'i':
        output[j++] = 'o';
        break;
      case 'o':
        output[j++] = 'u';
        break;
      case 'u':
        output[j++] = 'a';
        break;
      default:
        output[j++] = input[i];
        break;
    }
    i++;
  }
  output[j] = '\0';

  // Print the output.
  printf("English translation: %s", output);

  // Free the memory that was allocated.
  free(input);
  free(output);

  return 0;
}