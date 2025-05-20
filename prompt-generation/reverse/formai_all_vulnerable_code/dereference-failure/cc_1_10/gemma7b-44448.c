//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
  int **numbers;
  int **marks;
  int cards_won;
} BingoCard;

BingoCard *create_bingo_card() {
  BingoCard *card = malloc(sizeof(BingoCard));
  card->numbers = malloc(NUM_ROWS * sizeof(int *));
  card->marks = malloc(NUM_ROWS * sizeof(int *));
  card->cards_won = 0;

  for (int r = 0; r < NUM_ROWS; r++) {
    card->numbers[r] = malloc(NUM_COLS * sizeof(int));
    card->marks[r] = malloc(NUM_COLS * sizeof(int));
  }

  return card;
}

void print_bingo_card(BingoCard *card) {
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      printf("%d ", card->numbers[r][c]);
    }
    printf("\n");
  }
}

void mark_bingo_card(BingoCard *card, int number) {
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      if (card->numbers[r][c] == number) {
        card->marks[r][c] = 1;
      }
    }
  }
}

int check_bingo(BingoCard *card) {
  // Check rows
  for (int r = 0; r < NUM_ROWS; r++) {
    if (card->marks[r][0] == 1 && card->marks[r][1] == 1 && card->marks[r][2] == 1 && card->marks[r][3] == 1 && card->marks[r][4] == 1) {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < NUM_COLS; c++) {
    if (card->marks[0][c] == 1 && card->marks[1][c] == 1 && card->marks[2][c] == 1 && card->marks[3][c] == 1 && card->marks[4][c] == 1) {
      return 1;
    }
  }

  // Check diagonals
  if (card->marks[0][0] == 1 && card->marks[1][1] == 1 && card->marks[2][2] == 1 && card->marks[3][3] == 1 && card->marks[4][4] == 1) {
    return 1;
  }

  return 0;
}

int main() {
  BingoCard *card = create_bingo_card();

  // Populate the card with numbers
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      card->numbers[r][c] = rand() % 90 + 1;
    }
  }

  // Print the card
  print_bingo_card(card);

  // Mark the card
  mark_bingo_card(card, 25);

  // Check if the card has won
  if (check_bingo(card)) {
    printf("Winner!");
  } else {
    printf("Sorry, no win.");
  }

  return 0;
}