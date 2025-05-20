//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct Word {
  char **words;
  int num_words;
  int max_words;
} Word;

Word *create_word(int max_words) {
  Word *word = malloc(sizeof(Word));
  word->words = malloc(max_words * sizeof(char *));
  word->num_words = 0;
  word->max_words = max_words;
  return word;
}

void add_word(Word *word, char *word_str) {
  word->words[word->num_words++] = strdup(word_str);
  if (word->num_words == word->max_words) {
    word->max_words *= 2;
    word->words = realloc(word->words, word->max_words * sizeof(char *));
  }
}

int translate(Word *word, char *cat_phrase) {
  char **words = word->words;
  int i = 0, j = 0, num_words = word->num_words;

  for (i = 0; i < num_words && words[i] && strstr(words[i], cat_phrase) != NULL; i++) {
    for (j = 0; words[i][j] && words[i][j] != '\0'; j++) {
      if (words[i][j] == 'C') {
        words[i][j] = 'H';
      }
    }
  }

  return 0;
}

int main() {
  Word *word = create_word(MAX_WORDS);
  add_word(word, "Meow C Cat");
  add_word(word, "Crazy Cat");
  add_word(word, "Cute Cat");

  translate(word, "Meow C Cat");

  printf("Updated words:");
  for (int i = 0; i < word->num_words; i++) {
    printf(" %s", word->words[i]);
  }

  return 0;
}