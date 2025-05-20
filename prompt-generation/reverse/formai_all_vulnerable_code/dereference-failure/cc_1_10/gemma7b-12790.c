//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIENS_LANG_MAX_WORDS 20
#define ALIENS_LANG_WORD_MAX_LENGTH 20

typedef struct AlienWord {
  char *word;
  int length;
} AlienWord;

AlienWord *alien_word_create(int length) {
  AlienWord *word = malloc(sizeof(AlienWord));
  word->word = malloc(sizeof(char) * length);
  word->length = length;
  return word;
}

void alien_word_set(AlienWord *word, char *str) {
  strcpy(word->word, str);
}

void alien_word_print(AlienWord *word) {
  printf("%s", word->word);
}

int alien_word_compare(AlienWord *a, AlienWord *b) {
  return strcmp(a->word, b->word);
}

int main() {
  AlienWord *alien_words = alien_word_create(ALIENS_LANG_MAX_WORDS);

  // Fill the alien words
  alien_word_set(alien_words, "Blorgnak");
  alien_word_set(alien_words + 1, "Zork");
  alien_word_set(alien_words + 2, "Quzark");

  // Print the alien words
  alien_word_print(alien_words);

  // Compare the alien words
  if (alien_word_compare(alien_words, alien_words + 1) == 0) {
    printf("The words are the same.\n");
  } else {
    printf("The words are not the same.\n");
  }

  return 0;
}