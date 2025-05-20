//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_CARD_SIZE 5

// Bingo card data structure
typedef struct {
  int numbers[BINGO_CARD_SIZE][BINGO_CARD_SIZE];
  int marked[BINGO_CARD_SIZE][BINGO_CARD_SIZE];
} BingoCard;

// Function to create a new bingo card
BingoCard* create_bingo_card() {
  BingoCard* card = malloc(sizeof(BingoCard));

  // Initialize the card with random numbers
  for (int i = 0; i < BINGO_CARD_SIZE; i++) {
    for (int j = 0; j < BINGO_CARD_SIZE; j++) {
      card->numbers[i][j] = rand() % 90 + 1;
    }
  }

  // Mark all numbers as unmarked
  for (int i = 0; i < BINGO_CARD_SIZE; i++) {
    for (int j = 0; j < BINGO_CARD_SIZE; j++) {
      card->marked[i][j] = 0;
    }
  }

  return card;
}

// Function to print a bingo card
void print_bingo_card(BingoCard* card) {
  for (int i = 0; i < BINGO_CARD_SIZE; i++) {
    for (int j = 0; j < BINGO_CARD_SIZE; j++) {
      printf("%2d ", card->numbers[i][j]);
    }
    printf("\n");
  }
}

// Function to mark a number on a bingo card
void mark_number(BingoCard* card, int number) {
  for (int i = 0; i < BINGO_CARD_SIZE; i++) {
    for (int j = 0; j < BINGO_CARD_SIZE; j++) {
      if (card->numbers[i][j] == number) {
        card->marked[i][j] = 1;
      }
    }
  }
}

// Function to check if a bingo card has won
int check_for_win(BingoCard* card) {
  // Check for horizontal wins
  for (int i = 0; i < BINGO_CARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < BINGO_CARD_SIZE; j++) {
      if (card->marked[i][j]) {
        count++;
      }
    }
    if (count == BINGO_CARD_SIZE) {
      return 1;
    }
  }

  // Check for vertical wins
  for (int j = 0; j < BINGO_CARD_SIZE; j++) {
    int count = 0;
    for (int i = 0; i < BINGO_CARD_SIZE; i++) {
      if (card->marked[i][j]) {
        count++;
      }
    }
    if (count == BINGO_CARD_SIZE) {
      return 1;
    }
  }

  // Check for diagonal wins
  int count = 0;
  for (int i = 0; i < BINGO_CARD_SIZE; i++) {
    if (card->marked[i][i]) {
      count++;
    }
  }
  if (count == BINGO_CARD_SIZE) {
    return 1;
  }

  count = 0;
  for (int i = 0; i < BINGO_CARD_SIZE; i++) {
    if (card->marked[i][BINGO_CARD_SIZE - 1 - i]) {
      count++;
    }
  }
  if (count == BINGO_CARD_SIZE) {
    return 1;
  }

  return 0;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create a new bingo card
  BingoCard* card = create_bingo_card();

  // Print the bingo card
  printf("Your bingo card:\n");
  print_bingo_card(card);

  // Draw numbers until someone wins
  int number;
  while (!check_for_win(card)) {
    // Draw a random number
    number = rand() % 90 + 1;

    // Mark the number on the bingo card
    mark_number(card, number);

    // Print the drawn number
    printf("Drawn number: %d\n", number);

    // Print the bingo card
    printf("Your bingo card:\n");
    print_bingo_card(card);
  }

  // Congratulate the winner
  printf("Congratulations! You won!\n");

  return 0;
}