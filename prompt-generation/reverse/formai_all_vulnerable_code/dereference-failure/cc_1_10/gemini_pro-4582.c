//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of bingo cards to generate
#define NUM_CARDS 4

// Define the range of numbers to use for the bingo balls
#define MIN_BALL 1
#define MAX_BALL 75

// Function to generate a random bingo ball
int generate_ball() {
  return (rand() % (MAX_BALL - MIN_BALL + 1)) + MIN_BALL;
}

// Function to create a new bingo card
int** create_card() {
  // Allocate memory for the card
  int** card = malloc(CARD_SIZE * sizeof(int*));
  for (int i = 0; i < CARD_SIZE; i++) {
    card[i] = malloc(CARD_SIZE * sizeof(int));
  }

  // Initialize the card with random numbers
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      card[i][j] = generate_ball();
    }
  }

  // Return the card
  return card;
}

// Function to print a bingo card
void print_card(int** card) {
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      printf("%2d ", card[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a card has won
int check_card(int** card, int ball) {
  // Check if the ball is on the card
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      if (card[i][j] == ball) {
        // Mark the ball as called
        card[i][j] = -1;

        // Check if the card has won
        if (check_row(card, i) || check_column(card, j) || check_diagonal(card)) {
          return 1;
        }
      }
    }
  }

  // The card has not won
  return 0;
}

// Function to check if a row has won
int check_row(int** card, int row) {
  for (int i = 0; i < CARD_SIZE; i++) {
    if (card[row][i] != -1) {
      return 0;
    }
  }

  // The row has won
  return 1;
}

// Function to check if a column has won
int check_column(int** card, int col) {
  for (int i = 0; i < CARD_SIZE; i++) {
    if (card[i][col] != -1) {
      return 0;
    }
  }

  // The column has won
  return 1;
}

// Function to check if a diagonal has won
int check_diagonal(int** card) {
  // Check the main diagonal
  for (int i = 0; i < CARD_SIZE; i++) {
    if (card[i][i] != -1) {
      return 0;
    }
  }

  // Check the secondary diagonal
  for (int i = 0; i < CARD_SIZE; i++) {
    if (card[i][CARD_SIZE - 1 - i] != -1) {
      return 0;
    }
  }

  // The diagonal has won
  return 1;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create the bingo cards
  int** cards[NUM_CARDS];
  for (int i = 0; i < NUM_CARDS; i++) {
    cards[i] = create_card();
  }

  // Print the bingo cards
  for (int i = 0; i < NUM_CARDS; i++) {
    printf("Card %d:\n", i + 1);
    print_card(cards[i]);
    printf("\n");
  }

  // Generate bingo balls until a card wins
  int ball;
  int winner = -1;
  while (winner == -1) {
    ball = generate_ball();
    printf("Ball: %d\n", ball);

    // Check each card for a win
    for (int i = 0; i < NUM_CARDS; i++) {
      if (check_card(cards[i], ball)) {
        winner = i + 1;
        break;
      }
    }
  }

  // Print the winning card
  printf("Card %d has won!\n", winner);
  print_card(cards[winner - 1]);

  // Free the memory allocated for the bingo cards
  for (int i = 0; i < NUM_CARDS; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      free(cards[i][j]);
    }
    free(cards[i]);
  }

  return 0;
}