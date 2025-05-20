//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 5

typedef struct word_t {
  char *word;
  struct word_t *next;
} word_t;

word_t *head = NULL;

void add_word(char *word) {
  word_t *new_word = malloc(sizeof(word_t));
  new_word->word = strdup(word);
  new_word->next = NULL;

  if (head == NULL) {
    head = new_word;
  } else {
    head->next = new_word;
    head = new_word;
  }
}

void play_game() {
  char guess_word[MAX_WORDS];
  char *word_to_guess;

  printf("Welcome to the Cyberpunk Memory Game!\n");

  word_to_guess = head->word;

  printf("What is the word? ");
  scanf("%s", guess_word);

  if (strcmp(guess_word, word_to_guess) == 0) {
    printf("You win!\n");
  } else {
    printf("You lose. The word was: %s\n", word_to_guess);
  }
}

int main() {
  add_word("cyberpunk");
  add_word("future");
  add_word("technology");
  add_word("society");
  add_word("dreams");

  play_game();

  return 0;
}