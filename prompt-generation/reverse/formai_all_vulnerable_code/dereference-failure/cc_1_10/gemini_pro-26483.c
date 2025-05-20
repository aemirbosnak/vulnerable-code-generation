//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the bingo card
#define CARD_SIZE 5

// Define the number of rows and columns in the bingo card
#define NUM_ROWS 5
#define NUM_COLS 5

// Define the maximum number that can be on a bingo card
#define MAX_NUM 75

// Define the number of balls to be drawn
#define NUM_BALLS 75

// Define the data structure for a bingo card
typedef struct {
  int numbers[CARD_SIZE][CARD_SIZE];
  int marked[CARD_SIZE][CARD_SIZE];
} BingoCard;

// Function to create a new bingo card
BingoCard *create_card() {
  BingoCard *card = malloc(sizeof(BingoCard));

  // Initialize the numbers on the card
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      card->numbers[i][j] = rand() % MAX_NUM + 1;
    }
  }

  // Initialize the marked numbers on the card
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      card->marked[i][j] = 0;
    }
  }

  return card;
}

// Function to print a bingo card
void print_card(BingoCard *card) {
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      printf("%2d ", card->numbers[i][j]);
    }
    printf("\n");
  }
}

// Function to mark a number on a bingo card
void mark_number(BingoCard *card, int number) {
  for (int i = 0; i < CARD_SIZE; i++) {
    for (int j = 0; j < CARD_SIZE; j++) {
      if (card->numbers[i][j] == number) {
        card->marked[i][j] = 1;
      }
    }
  }
}

// Function to check if a bingo card has won
int check_win(BingoCard *card) {
  // Check for horizontal wins
  for (int i = 0; i < CARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < CARD_SIZE; j++) {
      if (card->marked[i][j]) {
        count++;
      }
    }
    if (count == CARD_SIZE) {
      return 1;
    }
  }

  // Check for vertical wins
  for (int j = 0; j < CARD_SIZE; j++) {
    int count = 0;
    for (int i = 0; i < CARD_SIZE; i++) {
      if (card->marked[i][j]) {
        count++;
      }
    }
    if (count == CARD_SIZE) {
      return 1;
    }
  }

  // Check for diagonal wins
  int count1 = 0;
  for (int i = 0; i < CARD_SIZE; i++) {
    if (card->marked[i][i]) {
      count1++;
    }
  }
  if (count1 == CARD_SIZE) {
    return 1;
  }

  int count2 = 0;
  for (int i = 0; i < CARD_SIZE; i++) {
    if (card->marked[i][CARD_SIZE - i - 1]) {
      count2++;
    }
  }
  if (count2 == CARD_SIZE) {
    return 1;
  }

  // No win
  return 0;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create a new bingo card
  BingoCard *card = create_card();

  // Print the bingo card
  printf("Your bingo card:\n");
  print_card(card);

  // Draw balls until someone wins
  int balls_drawn = 0;
  int winning_number;
  while (balls_drawn < NUM_BALLS) {
    // Draw a new ball
    int ball = rand() % MAX_NUM + 1;
    printf("Ball drawn: %d\n", ball);

    // Mark the ball on the card
    mark_number(card, ball);

    // Check if the card has won
    if (check_win(card)) {
      winning_number = ball;
      break;
    }

    balls_drawn++;
  }

  // Print the winning number
  printf("Winning number: %d\n", winning_number);

  return 0;
}