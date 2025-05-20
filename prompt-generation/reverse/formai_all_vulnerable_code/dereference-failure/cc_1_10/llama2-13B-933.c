//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MIN_LENGTH 5

// Function to generate a random word
char *generate_word(void) {
  char *word = malloc(MAX_LENGTH * sizeof(char));
  int i, j;

  for (i = 0; i < MAX_LENGTH; i++) {
    word[i] = 'a' + (rand() % 26);
  }

  return word;
}

// Function to play a game of Hangman
void hangman(char *word) {
  int correct = 0;
  int attempts = 0;
  char guess = 0;

  printf("Welcome to Hangman! Guess a letter to reveal the word:\n");

  do {
    // Generate a random letter of the word to display
    int index = rand() % strlen(word);
    char letter = word[index];

    // Display the word with the letter masked
    for (int i = 0; i < strlen(word); i++) {
      if (i == index) {
        printf("_");
      } else {
        printf("%c", letter);
      }
    }

    // Ask the user to guess a letter
    printf("Guess a letter: ");
    scanf("%c", &guess);

    // Check if the user guessed correctly
    for (int i = 0; i < strlen(word); i++) {
      if (guess == word[i]) {
        correct++;
        break;
      }
    }

    // Increment the attempts counter if the user did not guess correctly
    attempts++;

    // Display the word with the correct letters revealed
    for (int i = 0; i < strlen(word); i++) {
      if (correct == i) {
        printf("%c", word[i]);
      } else {
        printf("_");
      }
    }

    // Ask the user to guess again
    printf("Guess another letter: ");
  } while (attempts < 6 && correct < strlen(word));

  // Display the final word and the number of attempts
  printf("The word was: %s\n", word);
  printf("You guessed %d letters correctly out of %d attempts.\n", correct, attempts);
}

int main(void) {
  char *word = generate_word();
  hangman(word);
  free(word);

  return 0;
}