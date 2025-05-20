//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_LETTERS 20

char **words;
int word_count = 0;

void add_word(char *word) {
  words = realloc(words, (word_count + 1) * sizeof(char *));
  words[word_count] = strdup(word);
  word_count++;
}

int main() {
  words = malloc(MAX_WORDS * sizeof(char *));
  for (int i = 0; i < MAX_WORDS; i++) {
    words[i] = NULL;
  }

  add_word("apple");
  add_word("banana");
  add_word("orange");
  add_word("grapefruit");
  add_word("pineapple");

  char guess_word[MAX_LETTERS];

  printf("Guess a word:");
  scanf("%s", guess_word);

  int found = 0;
  for (int i = 0; i < word_count; i++) {
    if (strcmp(guess_word, words[i]) == 0) {
      found = 1;
      break;
    }
  }

  if (found) {
    printf("You guessed the word: %s\n", guess_word);
  } else {
    printf("Sorry, the word was not found.\n");
  }

  free(words);
  return 0;
}