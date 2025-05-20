//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024
#define MAX_WORD_LENGTH 256

typedef struct AlienWord {
  char **words;
  int size;
  int capacity;
} AlienWord;

AlienWord *alienWord_init(int capacity) {
  AlienWord *word = malloc(sizeof(AlienWord));
  word->words = malloc(sizeof(char *) * capacity);
  word->size = 0;
  word->capacity = capacity;
  return word;
}

void alienWord_add(AlienWord *word, char *new_word) {
  if (word->size == word->capacity) {
    word->words = realloc(word->words, sizeof(char *) * word->capacity * 2);
    word->capacity *= 2;
  }
  word->words[word->size++] = new_word;
}

char **alienWord_get(AlienWord *word, int index) {
  if (index < 0 || index >= word->size) {
    return NULL;
  }
  return word->words[index];
}

int main() {
  AlienWord *alien_words = alienWord_init(MAX_WORDS);

  char *alien_phrase = "Q'ux'r'z'k'w'l'n't'x'p'h't'a'l'h'c'r'g";
  char **words = alienWord_get(alien_words, 0);
  printf("%s\n", words);

  alienWord_add(alien_words, "Plo'k'c'r'h'a'n");
  words = alienWord_get(alien_words, 1);
  printf("%s\n", words);

  free(alien_words);
  return 0;
}