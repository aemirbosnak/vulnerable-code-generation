//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

void play_game() {
  char **words = (char**)malloc(MAX_WORDS * sizeof(char*));
  for (int i = 0; i < MAX_WORDS; i++) {
    words[i] = (char*)malloc(20 * sizeof(char));
  }

  // Fill the words with random words
  for (int i = 0; i < MAX_WORDS; i++) {
    words[i] = "abc";
  }

  // Shuffle the words
  for (int i = 0; i < MAX_WORDS; i++) {
    int r = rand() % MAX_WORDS;
    char *t = words[i];
    words[i] = words[r];
    words[r] = t;
  }

  // Start the game
  int guesses = 0;
  char guess_word[20];

  printf("Welcome to the Word Guessing Game!\n");
  printf("Guess the word: ");

  // Loop until the word is guessed or the player runs out of guesses
  while (guesses < MAX_WORDS && strcmp(guess_word, words[0]) != 0) {
    scanf("%s", guess_word);

    // Check if the guess word is correct
    if (strcmp(guess_word, words[0]) == 0) {
      printf("Congratulations! You guessed the word!\n");
    } else {
      guesses++;
      printf("Incorrect guess. Try again.\n");
    }
  }

  // Free the memory
  for (int i = 0; i < MAX_WORDS; i++) {
    free(words[i]);
  }
  free(words);
}

int main() {
  play_game();
  return 0;
}