//Gemma-7B DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void analyze_text(char **text, int size) {
  int i, j, count = 0, word_count = 0;
  char **words = NULL;

  for (i = 0; i < size; i++) {
    for (j = 0; text[i][j] != '\0'; j++) {
      if (text[i][j] >= 'a' && text[i][j] <= 'z') {
        count++;
      }
    }
  }

  words = malloc(count * sizeof(char *));
  for (i = 0; i < count; i++) {
    words[i] = malloc(MAX_SIZE);
  }

  for (i = 0; i < size; i++) {
    for (j = 0; text[i][j] != '\0'; j++) {
      if (text[i][j] >= 'a' && text[i][j] <= 'z') {
        strcpy(words[word_count], &text[i][j]);
        word_count++;
      }
    }
  }

  printf("Total words: %d\n", word_count);
  printf("Most frequent word: %s\n", words[0]);
  free(words);
}

int main() {
  char **text = NULL;
  int size = 0;

  text = malloc(MAX_SIZE * sizeof(char *));
  for (size = 0; text[size] = malloc(MAX_SIZE); size++) {}

  // Fill the text with your own text here

  analyze_text(text, size);

  free(text);

  return 0;
}