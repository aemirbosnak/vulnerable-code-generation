//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_WORDS 10
#define WORDS_PER_ROUND 5

#define ROUNDS_TO_PLAY 3

char **words;
int numWords;
int currentRound = 0;

void initializeGame() {
  words = malloc(MAX_NUM_WORDS * sizeof(char *));
  numWords = 0;
  currentRound = 0;
}

void addWord(char *word) {
  words[numWords++] = word;
}

void playRound() {
  int i;
  char guessWord[WORDS_PER_ROUND];

  printf("Round %d: ", currentRound + 1);

  for (i = 0; i < WORDS_PER_ROUND; i++) {
    guessWord[i] = '_';
  }

  guessWord[WORDS_PER_ROUND - 1] = '\0';

  printf("Guess the word: ");

  scanf("%s", guessWord);

  for (i = 0; i < WORDS_PER_ROUND; i++) {
    if (guessWord[i] == words[currentRound][i]) {
      guessWord[i] = words[currentRound][i];
    }
  }

  printf("Your guess: ");

  for (i = 0; i < WORDS_PER_ROUND; i++) {
    printf("%c ", guessWord[i]);
  }

  printf("\n");
}

void playGame() {
  initializeGame();

  for (currentRound = 0; currentRound < ROUNDS_TO_PLAY; currentRound++) {
    playRound();
  }

  free(words);
}

int main() {
  playGame();

  return 0;
}