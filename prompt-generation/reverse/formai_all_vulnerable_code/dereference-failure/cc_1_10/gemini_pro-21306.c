//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000

typedef struct {
  char *word;
  int count;
} word_t;

int compare_words(const void *a, const void *b) {
  return strcmp(((word_t *)a)->word, ((word_t *)b)->word);
}

int main() {
  char input[100];
  word_t words[MAX_WORDS];
  int num_words = 0;

  printf("Enter some words, separated by spaces: ");
  fgets(input, sizeof(input), stdin);

  char *token = strtok(input, " ");
  while (token != NULL) {
    int found = 0;
    for (int i = 0; i < num_words; i++) {
      if (strcmp(token, words[i].word) == 0) {
        words[i].count++;
        found = 1;
        break;
      }
    }
    if (!found) {
      words[num_words].word = strdup(token);
      words[num_words].count = 1;
      num_words++;
    }
    token = strtok(NULL, " ");
  }

  qsort(words, num_words, sizeof(word_t), compare_words);

  printf("\nWord frequencies:\n");
  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i].word, words[i].count);
  }

  for (int i = 0; i < num_words; i++) {
    free(words[i].word);
  }

  return 0;
}