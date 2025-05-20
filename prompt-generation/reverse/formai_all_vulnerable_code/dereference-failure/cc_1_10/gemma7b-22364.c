//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct Word {
  char **words;
  int size;
  int capacity;
} Word;

Word *word_create() {
  Word *w = malloc(sizeof(Word));
  w->words = NULL;
  w->size = 0;
  w->capacity = MAX_WORDS;
  return w;
}

void word_add(Word *w, char *word) {
  w->words = realloc(w->words, (w->size + 1) * sizeof(char *));
  w->words[w->size++] = strdup(word);
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
  Word *w = word_create();
  word_add(w, "hello");
  word_add(w, "world");
  word_add(w, "foo");
  word_add(w, "bar");

  if (word_search(w, "hello") == 1) {
    printf("hello is in the list\n");
  }

  if (word_search(w, "foo") == 1) {
    printf("foo is in the list\n");
  }

  if (word_search(w, "quux") == 0) {
    printf("quux is not in the list\n");
  }

  return 0;
}