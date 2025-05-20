//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

int main(void) {
  char input[MAX_WORD_LENGTH];
  char *words[MAX_WORDS];
  int frequency[MAX_WORDS] = {0};
  int index = 0;
  
  printf("Enter a string: ");

  // Read in input string and tokenize it
  fgets(input, MAX_WORD_LENGTH, stdin);
  char *token = strtok(input, " ");
  while (token != NULL && index < MAX_WORDS) {
    // Remove any non-alphabetic characters and convert to lowercase
    int len = strlen(token);
    for (int i = 0; i < len; i++) {
      char c = tolower(token[i]);
      if (isalpha(c)) {
        input[i] = c;
      } else {
        input[i] = ' ';
      }
    }
    // Add the word to the list of words and increase its frequency
    int i;
    for (i = 0; i < index; i++) {
      if (strcmp(words[i], token) == 0) {
        frequency[i]++;
        break;
      }
    }
    if (i == index) {
      words[index] = strdup(token);
      frequency[index] = 1;
      index++;
    }
    // Get the next token
    token = strtok(NULL, " ");
  }
  
  // Print the list of words and their frequencies
  printf("\n");
  for (int i = 0; i < index; i++) {
    printf("%s: %d\n", words[i], frequency[i]);
    free(words[i]);
  }

  return 0;
}