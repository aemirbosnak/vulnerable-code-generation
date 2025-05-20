//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct WordCount {
  char **words;
  int word_count;
} WordCount;

WordCount *word_count_init() {
  WordCount *word_count = malloc(sizeof(WordCount));
  word_count->words = malloc(MAX_WORDS * sizeof(char *));
  word_count->word_count = 0;
  return word_count;
}

void word_count_add(WordCount *word_count, char *word) {
  word_count->words[word_count->word_count++] = word;
}

int word_count_get(WordCount *word_count, char *word) {
  for (int i = 0; i < word_count->word_count; i++) {
    if (strcmp(word_count->words[i], word) == 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  WordCount *word_count = word_count_init();

  // Multiplayer code
  // Connect to server
  // Get list of words from server
  // Add words to word_count
  // Send word counts to server

  // Example usage
  word_count_add(word_count, "Hello");
  word_count_add(word_count, "World");
  word_count_add(word_count, "!");

  int word_index = word_count_get(word_count, "Hello");
  if (word_index != -1) {
    printf("Word index of 'Hello' is %d\n", word_index);
  }

  free(word_count->words);
  free(word_count);

  return 0;
}