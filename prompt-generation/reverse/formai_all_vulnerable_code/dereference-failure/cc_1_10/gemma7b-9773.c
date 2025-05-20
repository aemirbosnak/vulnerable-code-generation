//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUMBERS_PER_ROW 5

typedef struct BingoCard {
  int **numbers;
  int rows;
  int cols;
  int win_status;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
  card->numbers = malloc(card->rows * card->cols * sizeof(int));
  card->rows = card->rows;
  card->cols = card->cols;
  card->win_status = 0;
}

void generateBingoCard(BingoCard *card) {
  for (int r = 0; r < card->rows; r++) {
    for (int c = 0; c < card->cols; c++) {
      card->numbers[r][c] = rand() % MAX_NUMBERS_PER_ROW + 1;
    }
  }
}

int checkBingo(BingoCard *card) {
  for (int r = 0; r < card->rows; r++) {
    for (int c = 0; c < card->cols; c++) {
      if (card->numbers[r][c] == card->numbers[0][0]) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  BingoCard *card = malloc(sizeof(BingoCard));
  initializeBingoCard(card);
  generateBingoCard(card);

  if (checkBingo(card)) {
    printf("Bingo!\n");
  } else {
    printf("Sorry, no bingo.\n");
  }

  free(card);

  return 0;
}