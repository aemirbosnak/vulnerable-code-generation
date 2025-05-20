//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Bingo card dimensions
#define CARD_WIDTH 5
#define CARD_HEIGHT 5

// Number of bingo balls
#define NUM_BALLS 75

// Bingo card data structure
typedef struct {
  int numbers[CARD_WIDTH][CARD_HEIGHT];
  int marked[CARD_WIDTH][CARD_HEIGHT];
} BingoCard;

// Function to create a new bingo card
BingoCard* create_card() {
  BingoCard* card = malloc(sizeof(BingoCard));
  for (int i = 0; i < CARD_WIDTH; i++) {
    for (int j = 0; j < CARD_HEIGHT; j++) {
      card->numbers[i][j] = 0;
      card->marked[i][j] = 0;
    }
  }
  return card;
}

// Function to generate a random bingo ball
int generate_ball() {
  return rand() % NUM_BALLS + 1;
}

// Function to mark a number on a bingo card
void mark_number(BingoCard* card, int number) {
  for (int i = 0; i < CARD_WIDTH; i++) {
    for (int j = 0; j < CARD_HEIGHT; j++) {
      if (card->numbers[i][j] == number) {
        card->marked[i][j] = 1;
      }
    }
  }
}

// Function to check if a bingo card has won
int check_win(BingoCard* card) {
  // Check rows
  for (int i = 0; i < CARD_WIDTH; i++) {
    int count = 0;
    for (int j = 0; j < CARD_HEIGHT; j++) {
      count += card->marked[i][j];
    }
    if (count == CARD_WIDTH) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < CARD_HEIGHT; j++) {
    int count = 0;
    for (int i = 0; i < CARD_WIDTH; i++) {
      count += card->marked[i][j];
    }
    if (count == CARD_HEIGHT) {
      return 1;
    }
  }

  // Check diagonals
  int count_diagonal1 = 0;
  int count_diagonal2 = 0;
  for (int i = 0; i < CARD_WIDTH; i++) {
    count_diagonal1 += card->marked[i][i];
    count_diagonal2 += card->marked[i][CARD_WIDTH - i - 1];
  }
  if (count_diagonal1 == CARD_WIDTH || count_diagonal2 == CARD_WIDTH) {
    return 1;
  }

  return 0;
}

// Function to print a bingo card
void print_card(BingoCard* card) {
  for (int i = 0; i < CARD_WIDTH; i++) {
    for (int j = 0; j < CARD_HEIGHT; j++) {
      printf("%2d ", card->numbers[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create a new bingo card
  BingoCard* card = create_card();

  // Generate random numbers for the bingo card
  for (int i = 0; i < CARD_WIDTH; i++) {
    for (int j = 0; j < CARD_HEIGHT; j++) {
      int number;
      do {
        number = generate_ball();
      } while (card->numbers[i][j] != 0);
      card->numbers[i][j] = number;
    }
  }

  // Print the bingo card
  printf("Your bingo card:\n");
  print_card(card);

  // Play the bingo game
  int ball;
  while ((ball = generate_ball()) != -1) {
    printf("Ball %d called!\n", ball);
    mark_number(card, ball);
    print_card(card);
    if (check_win(card)) {
      printf("You won!\n");
      break;
    }
  }

  // Free the bingo card
  free(card);

  return 0;
}