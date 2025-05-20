//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_WORD_LENGTH 10

// Function to generate a random word
void generate_word(char *word) {
  int i, j;
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    word[i] = 'a' + (rand() % 26);
  }
}

// Function to check if a word is valid
int is_valid(char *word) {
  int i, j;
  for (i = 0; i < MAX_WORD_LENGTH; i++) {
    if (word[i] == 'a' + (rand() % 26)) {
      continue;
    } else {
      return 0;
    }
  }
  return 1;
}

// Function to display the table
void display_table(char *table[ROWS][COLS]) {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%c ", table[i][j]);
    }
    printf("\n");
  }
}

// Function to get input from the user
char *get_input(void) {
  char *input;
  printf("Enter a word: ");
  fgets(input, MAX_WORD_LENGTH, stdin);
  return input;
}

// Function to play the game
void play_game(char *table[ROWS][COLS]) {
  int i, j;
  char *word;

  // Initialize the table with random words
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      generate_word(table[i][j]);
    }
  }

  // Display the table
  display_table(table);

  // Get input from the user
  word = get_input();

  // Check if the word is valid
  if (is_valid(word)) {
    // Find the first empty space in the table
    for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLS; j++) {
        if (table[i][j] == ' ') {
          break;
        }
      }
      if (j == COLS) {
        break;
      }
    }

    // Place the word in the first empty space
    for (j = 0; j < strlen(word); j++) {
      table[i][j] = word[j];
    }

    // Display the updated table
    display_table(table);

    // Play again?
    printf("Do you want to play again? (y/n): ");
    char answer = getchar();
    if (answer == 'y' || answer == 'Y') {
      play_game(table);
    } else {
      printf("Goodbye!\n");
      return;
    }
  } else {
    printf("Invalid word. Try again.\n");
  }
}

int main() {
  char table[ROWS][COLS];

  // Initialize the table with random words
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      generate_word(table[i][j]);
    }
  }

  // Display the table
  display_table(table);

  // Play the game
  play_game(table);

  return 0;
}