//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 25
#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
  int **numbers;
  int **marked;
  int wins;
} BingoCard;

BingoCard *createBingoCard() {
  BingoCard *card = malloc(sizeof(BingoCard));
  card->numbers = malloc(NUM_ROWS * sizeof(int *));
  for (int r = 0; r < NUM_ROWS; r++) {
    card->numbers[r] = malloc(NUM_COLS * sizeof(int));
  }
  card->marked = malloc(NUM_ROWS * sizeof(int *));
  for (int r = 0; r < NUM_ROWS; r++) {
    card->marked[r] = malloc(NUM_COLS * sizeof(int));
  }
  card->wins = 0;
  return card;
}

void generateBingoNumbers(BingoCard *card) {
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      card->numbers[r][c] = rand() % MAX_NUM + 1;
    }
  }
}

void markCard(BingoCard *card, int number) {
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      if (card->numbers[r][c] == number && card->marked[r][c] == 0) {
        card->marked[r][c] = 1;
      }
    }
  }
}

int checkWin(BingoCard *card) {
  // Check rows
  for (int r = 0; r < NUM_ROWS; r++) {
    if (card->marked[r][0] == 1 && card->marked[r][1] == 1 && card->marked[r][2] == 1 && card->marked[r][3] == 1 && card->marked[r][4] == 1) {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < NUM_COLS; c++) {
    if (card->marked[0][c] == 1 && card->marked[1][c] == 1 && card->marked[2][c] == 1 && card->marked[3][c] == 1 && card->marked[4][c] == 1) {
      return 1;
    }
  }

  // Check diagonals
  if (card->marked[0][0] == 1 && card->marked[1][1] == 1 && card->marked[2][2] == 1 && card->marked[3][3] == 1 && card->marked[4][4] == 1) {
    return 1;
  }

  // No win
  return 0;
}

int main() {
  BingoCard *card = createBingoCard();
  generateBingoNumbers(card);

  // Simulate drawing numbers
  for (int i = 0; i < 20; i++) {
    int number = rand() % MAX_NUM + 1;
    markCard(card, number);

    if (checkWin(card)) {
      card->wins++;
      printf("Bingo! You won %d times!\n", card->wins);
    }
  }

  free(card);
  return 0;
}