//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_COLUMNS 5
#define NUM_ROWS 5

typedef struct BingoCard {
  int **numbers;
  int wins;
} BingoCard;

BingoCard *createBingoCard() {
  BingoCard *card = malloc(sizeof(BingoCard));
  card->numbers = malloc(NUM_ROWS * sizeof(int *));
  for (int r = 0; r < NUM_ROWS; r++) {
    card->numbers[r] = malloc(NUM_COLUMNS * sizeof(int));
  }
  card->wins = 0;
  return card;
}

void drawNumber(BingoCard *card) {
  int number = rand() % 90 + 1;
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLUMNS; c++) {
      if (card->numbers[r][c] == number) {
        card->numbers[r][c] = -1;
      }
    }
  }
}

void checkWin(BingoCard *card) {
  // Horizontal win
  for (int r = 0; r < NUM_ROWS; r++) {
    if (card->numbers[r][0] == -1 && card->numbers[r][1] == -1 && card->numbers[r][2] == -1 && card->numbers[r][3] == -1 && card->numbers[r][4] == -1) {
      card->wins++;
    }
  }

  // Vertical win
  for (int c = 0; c < NUM_COLUMNS; c++) {
    if (card->numbers[0][c] == -1 && card->numbers[1][c] == -1 && card->numbers[2][c] == -1 && card->numbers[3][c] == -1 && card->numbers[4][c] == -1) {
      card->wins++;
    }
  }

  // Diagonal win
  if (card->numbers[0][0] == -1 && card->numbers[1][1] == -1 && card->numbers[2][2] == -1 && card->numbers[3][3] == -1 && card->numbers[4][4] == -1) {
    card->wins++;
  }
}

int main() {
  BingoCard *card = createBingoCard();
  for (int i = 0; i < 10; i++) {
    drawNumber(card);
    checkWin(card);
  }

  printf("Wins: %d\n", card->wins);
  free(card->numbers);
  free(card);

  return 0;
}