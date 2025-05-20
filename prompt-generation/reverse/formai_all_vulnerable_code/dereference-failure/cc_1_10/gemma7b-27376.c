//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 20

typedef struct BingoCard {
  int **numbers;
  int rows;
  int cols;
  int win_row;
  int win_col;
  int win_diag;
} BingoCard;

BingoCard* createBingoCard(int r, int c) {
  BingoCard* card = malloc(sizeof(BingoCard));
  card->rows = r;
  card->cols = c;
  card->numbers = (int**)malloc(r * sizeof(int*));
  for (int i = 0; i < r; i++) {
    card->numbers[i] = (int*)malloc(c * sizeof(int));
  }
  return card;
}

void getRandomNumber(BingoCard* card) {
  for (int i = 0; i < card->rows; i++) {
    for (int j = 0; j < card->cols; j++) {
      card->numbers[i][j] = rand() % MAX_NUM + 1;
    }
  }
}

int checkWin(BingoCard* card) {
  // Check rows
  for (int i = 0; i < card->rows; i++) {
    if (card->numbers[i][0] == card->numbers[i][1] && card->numbers[i][0] == card->numbers[i][2]) {
      card->win_row = i;
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < card->cols; j++) {
    if (card->numbers[0][j] == card->numbers[1][j] && card->numbers[0][j] == card->numbers[2][j]) {
      card->win_col = j;
      return 1;
    }
  }

  // Check diagonal
  if (card->numbers[0][0] == card->numbers[1][1] && card->numbers[0][0] == card->numbers[2][2]) {
    card->win_diag = 1;
    return 1;
  }

  return 0;
}

int main() {
  BingoCard* card = createBingoCard(5, 5);
  getRandomNumber(card);

  if (checkWin(card)) {
    printf("You win!");
  } else {
    printf("Sorry, you lose.");
  }

  return 0;
}