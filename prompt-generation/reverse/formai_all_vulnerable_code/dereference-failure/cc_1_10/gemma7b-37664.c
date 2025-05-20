//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct BingoCard {
  int **numbers;
  int rows;
  int cols;
  int filled;
} BingoCard;

BingoCard *createBingoCard(int r, int c) {
  BingoCard *card = malloc(sizeof(BingoCard));
  card->rows = r;
  card->cols = c;
  card->numbers = malloc(r * c * sizeof(int));
  card->filled = 0;
  return card;
}

void fillBingoCard(BingoCard *card) {
  srand(time(NULL));
  for (int i = 0; i < card->rows; i++) {
    for (int j = 0; j < card->cols; j++) {
      card->numbers[i][j] = rand() % 90 + 1;
    }
  }
}

void checkBingo(BingoCard *card) {
  for (int i = 0; i < card->rows; i++) {
    for (int j = 0; j < card->cols; j++) {
      if (card->numbers[i][j] == card->numbers[0][0]) {
        card->filled = 1;
      }
    }
  }
}

int main() {
  BingoCard *card = createBingoCard(5, 5);
  fillBingoCard(card);
  checkBingo(card);

  if (card->filled) {
    printf("Bingo!\n");
  } else {
    printf("Try again.\n");
  }

  return 0;
}