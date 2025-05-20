//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
  char *word;
  int count;
} Word;

int compare_words(const void *a, const void *b) {
  const Word *wa = (const Word *)a;
  const Word *wb = (const Word *)b;
  return strcmp(wa->word, wb->word);
}

int main() {
  char *text = "The quick brown fox jumped over the lazy dog. The quick brown fox jumped over the lazy dog. The quick brown fox jumped over the lazy dog.";

  char *words[MAX_WORDS];
  int counts[MAX_WORDS];

  int num_words = 0;

  char *token = strtok(text, " ");
  while (token != NULL) {
    int found = 0;
    for (int i = 0; i < num_words; i++) {
      if (strcmp(token, words[i]) == 0) {
        counts[i]++;
        found = 1;
        break;
      }
    }
    if (!found) {
      words[num_words] = token;
      counts[num_words] = 1;
      num_words++;
    }
    token = strtok(NULL, " ");
  }

  qsort(words, num_words, sizeof(Word), compare_words);

  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i], counts[i]);
  }

  return 0;
}