//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 256

typedef struct Word {
  char **words;
  int size;
  int capacity;
} Word;

Word *word_create(int capacity) {
  Word *w = malloc(sizeof(Word));
  w->words = malloc(sizeof(char *) * capacity);
  w->size = 0;
  w->capacity = capacity;
  return w;
}

void word_add(Word *w, char *word) {
  w->words[w->size++] = strdup(word);
  if (w->size == w->capacity) {
    w->capacity *= 2;
    w->words = realloc(w->words, sizeof(char *) * w->capacity);
  }
}

int word_search(Word *w, char *word) {
  for (int i = 0; i < w->size; i++) {
    if (strcmp(w->words[i], word) == 0) {
      return 1;
    }
  }
  return 0;
}

int main() {
  Word *w = word_create(10);
  word_add(w, "apple");
  word_add(w, "banana");
  word_add(w, "cherry");
  word_add(w, "orange");

  if (word_search(w, "apple") == 1) {
    printf("apple is in the list\n");
  }

  if (word_search(w, "mango") == 0) {
    printf("mango is not in the list\n");
  }

  return 0;
}