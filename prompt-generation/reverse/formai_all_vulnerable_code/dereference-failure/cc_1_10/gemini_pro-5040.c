//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5
#define NUM_BINGO_NUMBERS 75

// Function to generate a random bingo number
int generate_bingo_number() {
  return rand() % NUM_BINGO_NUMBERS + 1;
}

// Function to create a new bingo card
int** create_bingo_card() {
  int** bingo_card = malloc(NUM_ROWS * sizeof(int*));
  for (int i = 0; i < NUM_ROWS; i++) {
    bingo_card[i] = malloc(NUM_COLS * sizeof(int));
    for (int j = 0; j < NUM_COLS; j++) {
      bingo_card[i][j] = 0;
    }
  }
  return bingo_card;
}

// Function to fill a bingo card with random numbers
void fill_bingo_card(int** bingo_card) {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      bingo_card[i][j] = generate_bingo_number();
    }
  }
}

// Function to print a bingo card
void print_bingo_card(int** bingo_card) {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      printf("%2d ", bingo_card[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a bingo card has a winning combination
int check_bingo_card(int** bingo_card) {
  // Check rows
  for (int i = 0; i < NUM_ROWS; i++) {
    int count = 0;
    for (int j = 0; j < NUM_COLS; j++) {
      if (bingo_card[i][j] == 0) {
        count++;
      }
    }
    if (count == NUM_COLS) {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < NUM_COLS; i++) {
    int count = 0;
    for (int j = 0; j < NUM_ROWS; j++) {
      if (bingo_card[j][i] == 0) {
        count++;
      }
    }
    if (count == NUM_ROWS) {
      return 1;
    }
  }

  // Check diagonals
  int count_diagonal1 = 0;
  int count_diagonal2 = 0;
  for (int i = 0; i < NUM_ROWS; i++) {
    if (bingo_card[i][i] == 0) {
      count_diagonal1++;
    }
    if (bingo_card[i][NUM_COLS - 1 - i] == 0) {
      count_diagonal2++;
    }
  }
  if (count_diagonal1 == NUM_ROWS || count_diagonal2 == NUM_ROWS) {
    return 1;
  }

  return 0;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a new bingo card
  int** bingo_card = create_bingo_card();

  // Fill the bingo card with random numbers
  fill_bingo_card(bingo_card);

  // Print the bingo card
  printf("Bingo Card:\n");
  print_bingo_card(bingo_card);

  // Check if the bingo card has a winning combination
  if (check_bingo_card(bingo_card)) {
    printf("Bingo!\n");
  } else {
    printf("No bingo yet.\n");
  }

  // Free the memory allocated for the bingo card
  for (int i = 0; i < NUM_ROWS; i++) {
    free(bingo_card[i]);
  }
  free(bingo_card);

  return 0;
}