//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *word_list = NULL;

void add_word(char *word) {
  Word *new_word = malloc(sizeof(Word));
  new_word->word = strdup(word);
  new_word->next = NULL;

  if (word_list) {
    word_list->next = new_word;
  } else {
    word_list = new_word;
  }
}

char *translate_word(char *word) {
  char *translated_word = NULL;

  for (Word *current_word = word_list; current_word; current_word = current_word->next) {
    if (strcmp(word, current_word->word) == 0) {
      translated_word = strdup(current_word->word);
    }
  }

  return translated_word;
}

int main() {
  add_word("cat");
  add_word("dog");
  add_word("fish");

  char *translated_word = translate_word("cat");

  if (translated_word) {
    printf("%s\n", translated_word);
  } else {
    printf("Word not found.\n");
  }

  return 0;
}