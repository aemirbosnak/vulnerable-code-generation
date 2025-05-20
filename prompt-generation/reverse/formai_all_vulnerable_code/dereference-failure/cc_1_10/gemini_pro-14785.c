//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bingo card dimensions
#define ROWS 5
#define COLS 5

// Range of numbers on the card
#define MIN_NUM 1
#define MAX_NUM 75

// Initialize the random number generator
void init_rand() {
  srand(time(NULL));
}

// Generate a random number within the specified range
int get_rand_num(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

// Create a new bingo card
int** create_card() {
  // Allocate memory for the card
  int** card = malloc(ROWS * sizeof(int*));
  for (int i = 0; i < ROWS; i++) {
    card[i] = malloc(COLS * sizeof(int));
  }

  // Fill the card with random numbers
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      int num;
      do {
        num = get_rand_num(MIN_NUM, MAX_NUM);
      } while (is_num_in_card(card, ROWS, COLS, num));
      card[i][j] = num;
    }
  }

  // Return the card
  return card;
}

// Check if a number is already in the card
int is_num_in_card(int** card, int rows, int cols, int num) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (card[i][j] == num) {
        return 1;
      }
    }
  }
  return 0;
}

// Print the bingo card
void print_card(int** card, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%2d ", card[i][j]);
    }
    printf("\n");
  }
}

// Check if the card has won
int has_won(int** card, int rows, int cols, int called_num) {
  // Check rows
  for (int i = 0; i < rows; i++) {
    int count = 0;
    for (int j = 0; j < cols; j++) {
      if (card[i][j] == called_num) {
        count++;
      }
    }
    if (count == cols) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < cols; j++) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
      if (card[i][j] == called_num) {
        count++;
      }
    }
    if (count == rows) {
      return 1;
    }
  }

  // Check diagonals
  int count_diag1 = 0;
  int count_diag2 = 0;
  for (int i = 0; i < rows; i++) {
    if (card[i][i] == called_num) {
      count_diag1++;
    }
    if (card[i][rows - i - 1] == called_num) {
      count_diag2++;
    }
  }
  if (count_diag1 == rows || count_diag2 == rows) {
    return 1;
  }

  return 0;
}

// Play the bingo game
void play_bingo() {
  // Initialize the random number generator
  init_rand();

  // Create a new bingo card
  int** card = create_card();

  // Print the bingo card
  printf("Your bingo card:\n");
  print_card(card, ROWS, COLS);

  // Start the game loop
  int called_num;
  int won = 0;
  while (!won) {
    // Get a random number
    called_num = get_rand_num(MIN_NUM, MAX_NUM);

    // Check if the number has been called before
    if (is_num_in_card(card, ROWS, COLS, called_num)) {
      // Mark the number on the card
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          if (card[i][j] == called_num) {
            card[i][j] = -1;
          }
        }
      }

      // Check if the card has won
      won = has_won(card, ROWS, COLS, called_num);
    }
  }

  // Print the winning message
  printf("You won!\n");

  // Free the memory allocated for the card
  for (int i = 0; i < ROWS; i++) {
    free(card[i]);
  }
  free(card);
}

int main() {
  // Play the bingo game
  play_bingo();

  return 0;
}