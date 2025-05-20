//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_NUMS 20
#define MAX_NUMS_PER_ROW 5

typedef struct BingoCard {
  int **numbers;
  int numRows;
  int numCols;
  int wins;
} BingoCard;

BingoCard* createBingoCard() {
  BingoCard* card = malloc(sizeof(BingoCard));
  card->numbers = malloc(sizeof(int*) * MAX_NUMS_PER_ROW);
  for (int i = 0; i < MAX_NUMS_PER_ROW; i++) {
    card->numbers[i] = malloc(sizeof(int) * MAX_BINGO_NUMS);
  }
  card->numRows = MAX_NUMS_PER_ROW;
  card->numCols = MAX_BINGO_NUMS;
  card->wins = 0;
  return card;
}

void generateBingoNumbers(BingoCard* card) {
  for (int i = 0; i < card->numRows; i++) {
    for (int j = 0; j < card->numCols; j++) {
      card->numbers[i][j] = rand() % MAX_BINGO_NUMS + 1;
    }
  }
}

int checkBingo(BingoCard* card) {
  for (int i = 0; i < card->numRows; i++) {
    for (int j = 0; j < card->numCols; j++) {
      if (card->numbers[i][j] == card->numbers[0][0]) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  BingoCard* card = createBingoCard();
  generateBingoNumbers(card);
  if (checkBingo(card)) {
    printf("Bingo!");
  } else {
    printf("Sorry, no bingo.");
  }
  return 0;
}