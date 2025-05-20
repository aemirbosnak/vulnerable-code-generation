//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
  int **numbers;
  int **marks;
  int wins;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
  card->numbers = malloc(NUM_ROWS * sizeof(int *));
  card->marks = malloc(NUM_ROWS * sizeof(int *));
  card->wins = 0;

  for (int r = 0; r < NUM_ROWS; r++) {
    card->numbers[r] = malloc(NUM_COLS * sizeof(int));
    card->marks[r] = malloc(NUM_COLS * sizeof(int));
  }

  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      card->numbers[r][c] = rand() % 90 + 1;
    }
  }
}

void markBingoCard(BingoCard *card, int number) {
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      if (card->numbers[r][c] == number) {
        card->marks[r][c] = 1;
      }
    }
  }
}

int checkBingoCard(BingoCard *card) {
  for (int r = 0; r < NUM_ROWS; r++) {
    if (card->marks[r][0] == 1 && card->marks[r][1] == 1 && card->marks[r][2] == 1 && card->marks[r][3] == 1 && card->marks[r][4] == 1) {
      return 1;
    }
  }

  for (int c = 0; c < NUM_COLS; c++) {
    if (card->marks[0][c] == 1 && card->marks[1][c] == 1 && card->marks[2][c] == 1 && card->marks[3][c] == 1 && card->marks[4][c] == 1) {
      return 1;
    }
  }

  if (card->marks[0][0] == 1 && card->marks[1][1] == 1 && card->marks[2][2] == 1 && card->marks[3][3] == 1 && card->marks[4][4] == 1) {
    return 1;
  }

  return 0;
}

int main() {
  BingoCard *card = malloc(sizeof(BingoCard));
  initializeBingoCard(card);

  for (int i = 0; i < 10; i++) {
    markBingoCard(card, rand() % 90 + 1);
  }

  if (checkBingoCard(card)) {
    printf("Bingo! You win!\n");
  } else {
    printf("Sorry, you lose.\n");
  }

  free(card);

  return 0;
}