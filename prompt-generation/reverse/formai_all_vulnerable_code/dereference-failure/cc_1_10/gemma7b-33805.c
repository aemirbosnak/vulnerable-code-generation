//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_GUESSES 5

char **words = NULL;
int word_index = 0;
int guesses = MAX_GUESSES;

void initialize_game() {
  words = malloc(MAX_WORDS * sizeof(char *));
  for (int i = 0; i < MAX_WORDS; i++) {
    words[i] = malloc(20 * sizeof(char));
  }

  word_index = rand() % MAX_WORDS;
  guesses = MAX_GUESSES;

  printf("Welcome to the Memory Game!\n");
  printf("Guess the word: ");
}

void play_game() {
  char guess;
  char **guess_history = malloc(MAX_GUESSES * sizeof(char *));
  for (int i = 0; i < MAX_GUESSES; i++) {
    guess_history[i] = malloc(20 * sizeof(char));
  }

  for (int i = 0; guesses > 0 && guess_history[i] != words[word_index]; i++) {
    guess = getchar();
    guess_history[i] = guess;

    if (guess == words[word_index]) {
      printf("Congratulations! You won!\n");
      guesses = 0;
    } else if (guess_history[i] == words[word_index]) {
      printf("Sorry, that guess has already been made.\n");
    } else {
      printf("Incorrect guess. Try again.\n");
    }
  }

  free(guess_history);
}

int main() {
  initialize_game();
  play_game();

  free(words);

  return 0;
}