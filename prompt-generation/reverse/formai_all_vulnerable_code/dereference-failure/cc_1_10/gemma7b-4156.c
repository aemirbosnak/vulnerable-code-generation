//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_WORDS 1000

typedef struct WordCount {
  char **words;
  int wordCount;
} WordCount;

WordCount *wordCount_create() {
  WordCount *wc = malloc(sizeof(WordCount));
  wc->words = NULL;
  wc->wordCount = 0;
  return wc;
}

void wordCount_add(WordCount *wc, char *word) {
  int i = 0;
  for (i = 0; wc->words[i] != NULL && strcmp(wc->words[i], word) != 0; i++) {}
  if (wc->words[i] == NULL) {
    wc->words = realloc(wc->words, (wc->wordCount + 1) * sizeof(char *));
    wc->words[wc->wordCount++] = strdup(word);
  }
}

int wordCount_get(WordCount *wc, char *word) {
  int i = 0;
  for (i = 0; wc->words[i] != NULL && strcmp(wc->words[i], word) != 0; i++) {}
  if (wc->words[i] != NULL) {
    return i + 1;
  } else {
    return 0;
  }
}

int main() {
  WordCount *wc = wordCount_create();
  wordCount_add(wc, "hello");
  wordCount_add(wc, "world");
  wordCount_add(wc, "how");
  wordCount_add(wc, "are");
  wordCount_add(wc, "you?");

  printf("The word 'how' appears %d times.\n", wordCount_get(wc, "how"));

  free(wc);

  return 0;
}