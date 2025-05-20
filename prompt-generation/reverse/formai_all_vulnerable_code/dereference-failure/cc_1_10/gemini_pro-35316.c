//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to translate a line of text from English to Cat
char *meow(char *line) {
  char *translated;

  // Allocate memory for the translated line
  translated = malloc(strlen(line) * 2 + 1);

  // Translate the line
  int i = 0;
  int j = 0;
  while (line[i] != '\0') {
    switch (line[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        translated[j++] = 'm';
        translated[j++] = 'e';
        translated[j++] = 'o';
        translated[j++] = 'w';
        break;
      default:
        translated[j++] = line[i];
        break;
    }
    i++;
  }

  translated[j] = '\0';

  // Return the translated line
  return translated;
}

int main() {
  // Get the input text
  char line[MAX_LINE_LENGTH];
  printf("Enter a line of text to translate: ");
  fgets(line, MAX_LINE_LENGTH, stdin);

  // Translate the text
  char *translated = meow(line);

  // Print the translated text
  printf("The translated text is: %s\n", translated);

  // Free the memory allocated for the translated text
  free(translated);

  return 0;
}