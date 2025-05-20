//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *input = "This is an example of a text processing program.";

  // Tokenize the input string into words.
  char *token = strtok(input, " ");
  while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, " ");
  }

  // Create a new string that is the reverse of the input string.
  char *reversed = malloc(strlen(input) + 1);
  int i, j;
  for (i = 0, j = strlen(input) - 1; i < strlen(input); i++, j--) {
    reversed[i] = input[j];
  }
  reversed[strlen(input)] = '\0';
  printf("Reversed string: %s\n", reversed);

  // Create a new string that is the input string with all the vowels removed.
  char *noVowels = malloc(strlen(input) + 1);
  for (i = 0, j = 0; i < strlen(input); i++) {
    if (input[i] != 'a' && input[i] != 'e' && input[i] != 'i' && input[i] != 'o' &&
        input[i] != 'u' && input[i] != 'A' && input[i] != 'E' && input[i] != 'I' &&
        input[i] != 'O' && input[i] != 'U') {
      noVowels[j] = input[i];
      j++;
    }
  }
  noVowels[j] = '\0';
  printf("String with no vowels: %s\n", noVowels);

  // Create a new string that is the input string with all the punctuation removed.
  char *noPunctuation = malloc(strlen(input) + 1);
  for (i = 0, j = 0; i < strlen(input); i++) {
    if (input[i] != '.' && input[i] != ',' && input[i] != '!' && input[i] != '?' &&
        input[i] != ';' && input[i] != ':' && input[i] != '"' && input[i] != '\'') {
      noPunctuation[j] = input[i];
      j++;
    }
  }
  noPunctuation[j] = '\0';
  printf("String with no punctuation: %s\n", noPunctuation);

  // Free the allocated memory.
  free(reversed);
  free(noVowels);
  free(noPunctuation);

  return 0;
}