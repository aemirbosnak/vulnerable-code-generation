//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bingo card dimensions
#define CARD_WIDTH 5
#define CARD_HEIGHT 5

// Minimum and maximum numbers on the card
#define MIN_NUMBER 1
#define MAX_NUMBER 75

// Number of numbers to draw
#define NUMBERS_TO_DRAW 75

// Create a bingo card
int** create_card() {
  // Allocate memory for the card
  int** card = malloc(CARD_HEIGHT * sizeof(int*));
  for (int i = 0; i < CARD_HEIGHT; i++) {
    card[i] = malloc(CARD_WIDTH * sizeof(int));
  }

  // Initialize the card with random numbers
  srand(time(NULL));
  for (int i = 0; i < CARD_HEIGHT; i++) {
    for (int j = 0; j < CARD_WIDTH; j++) {
      card[i][j] = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    }
  }

  // Return the card
  return card;
}

// Print a bingo card
void print_card(int** card) {
  for (int i = 0; i < CARD_HEIGHT; i++) {
    for (int j = 0; j < CARD_WIDTH; j++) {
      printf("%d ", card[i][j]);
    }
    printf("\n");
  }
}

// Draw a number
int draw_number() {
  // Generate a random number
  int number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;

  // Return the number
  return number;
}

// Check if a number is on a card
int check_number(int** card, int number) {
  for (int i = 0; i < CARD_HEIGHT; i++) {
    for (int j = 0; j < CARD_WIDTH; j++) {
      if (card[i][j] == number) {
        return 1;
      }
    }
  }

  // Return 0 if the number is not on the card
  return 0;
}

// Check if a card has won
int check_win(int** card) {
  // Check if any row has won
  for (int i = 0; i < CARD_HEIGHT; i++) {
    int count = 0;
    for (int j = 0; j < CARD_WIDTH; j++) {
      if (card[i][j] == 0) {
        count++;
      }
    }
    if (count == CARD_WIDTH) {
      return 1;
    }
  }

  // Check if any column has won
  for (int j = 0; j < CARD_WIDTH; j++) {
    int count = 0;
    for (int i = 0; i < CARD_HEIGHT; i++) {
      if (card[i][j] == 0) {
        count++;
      }
    }
    if (count == CARD_HEIGHT) {
      return 1;
    }
  }

  // Check if any diagonal has won
  if (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0) {
    return 1;
  }
  if (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0) {
    return 1;
  }

  // Return 0 if the card has not won
  return 0;
}

// Play a game of bingo
void play_bingo() {
  // Create a bingo card
  int** card = create_card();

  // Print the bingo card
  printf("Your bingo card:\n");
  print_card(card);

  // Draw numbers until someone wins
  int numbers_drawn = 0;
  int winning_number = 0;
  while (numbers_drawn < NUMBERS_TO_DRAW) {
    // Draw a number
    int number = draw_number();

    // Check if the number is on the card
    int on_card = check_number(card, number);

    // If the number is on the card, mark it off
    if (on_card) {
      for (int i = 0; i < CARD_HEIGHT; i++) {
        for (int j = 0; j < CARD_WIDTH; j++) {
          if (card[i][j] == number) {
            card[i][j] = 0;
          }
        }
      }
    }

    // Check if the card has won
    int won = check_win(card);

    // If the card has won, print the winning number and break out of the loop
    if (won) {
      winning_number = number;
      break;
    }

    // Increment the number of numbers drawn
    numbers_drawn++;
  }

  // Print the winning number
  printf("The winning number is: %d\n", winning_number);

  // Free the memory allocated for the card
  for (int i = 0; i < CARD_HEIGHT; i++) {
    free(card[i]);
  }
  free(card);
}

// Main function
int main() {
  // Play a game of bingo
  play_bingo();

  return 0;
}