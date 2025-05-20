//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024
#define MAX_WORD_LENGTH 256

typedef struct Word {
  char *word;
  int length;
  struct Word *next;
} Word;

Word *word_list = NULL;

void add_word(char *word) {
  Word *new_word = malloc(sizeof(Word));
  new_word->word = strdup(word);
  new_word->length = strlen(word);
  new_word->next = NULL;

  if (word_list == NULL) {
    word_list = new_word;
  } else {
    Word *current = word_list;
    while (current->next) {
      current = current->next;
    }
    current->next = new_word;
  }
}

int count_words() {
  int count = 0;
  Word *current = word_list;
  while (current) {
    count++;
    current = current->next;
  }
  return count;
}

int main() {
  add_word("Hello");
  add_word("World");
  add_word("!");

  int num_words = count_words();

  printf("Number of words: %d\n", num_words);

  return 0;
}