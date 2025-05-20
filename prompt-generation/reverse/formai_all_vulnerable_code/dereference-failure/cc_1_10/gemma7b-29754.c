//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10
#define NUM_BINGO 5

typedef struct BingoCard {
  int **numbers;
  int rows;
  int columns;
} BingoCard;

BingoCard *createBingoCard() {
  BingoCard *card = malloc(sizeof(BingoCard));
  card->rows = NUM_BINGO;
  card->columns = MAX_NUM;
  card->numbers = (int **)malloc(card->rows * sizeof(int *) + card->columns * sizeof(int));
  for (int i = 0; i < card->rows; i++) {
    card->numbers[i] = (int *)malloc(card->columns * sizeof(int));
  }
  return card;
}

void drawBingoNumber(BingoCard *card) {
  srand(time(NULL));
  int number = rand() % MAX_NUM + 1;
  for (int i = 0; i < card->rows; i++) {
    for (int j = 0; j < card->columns; j++) {
      if (card->numbers[i][j] == number) {
        card->numbers[i][j] = 0;
      }
    }
  }
}

void checkBingo(BingoCard *card) {
  int bingo = 0;
  for (int i = 0; i < card->rows; i++) {
    if (card->numbers[i][0] == 0 && card->numbers[i][1] == 0 && card->numbers[i][2] == 0) {
      bingo = 1;
    }
  }
  if (bingo) {
    printf("Bingo!\n");
  }
}

int main() {
  BingoCard *card = createBingoCard();
  drawBingoNumber(card);
  drawBingoNumber(card);
  drawBingoNumber(card);
  checkBingo(card);
  return 0;
}