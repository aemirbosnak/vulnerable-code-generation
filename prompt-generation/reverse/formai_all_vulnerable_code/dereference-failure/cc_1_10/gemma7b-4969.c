//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 20

typedef struct BingoCard {
  int **numbers;
  int rows;
  int cols;
  int wins;
} BingoCard;

BingoCard *createBingoCard(int r, int c) {
  BingoCard *card = malloc(sizeof(BingoCard));
  card->rows = r;
  card->cols = c;
  card->numbers = malloc(sizeof(int *) * r);
  for (int i = 0; i < r; i++) {
    card->numbers[i] = malloc(sizeof(int) * c);
  }
  card->wins = 0;
  return card;
}

void fillBingoCard(BingoCard *card) {
  srand(time(NULL));
  for (int r = 0; r < card->rows; r++) {
    for (int c = 0; c < card->cols; c++) {
      card->numbers[r][c] = rand() % MAX_NUM + 1;
    }
  }
}

int checkBingo(BingoCard *card, int number) {
  for (int r = 0; r < card->rows; r++) {
    for (int c = 0; c < card->cols; c++) {
      if (card->numbers[r][c] == number) {
        return 1;
      }
    }
  }
  return 0;
}

void markBingoCard(BingoCard *card, int number) {
  for (int r = 0; r < card->rows; r++) {
    for (int c = 0; c < card->cols; c++) {
      if (card->numbers[r][c] == number) {
        card->numbers[r][c] = -1;
      }
    }
  }
}

void checkWin(BingoCard *card) {
  if (checkBingo(card, card->numbers[0][0]) ||
    checkBingo(card, card->numbers[0][1]) ||
    checkBingo(card, card->numbers[0][2]) ||
    checkBingo(card, card->numbers[1][0]) ||
    checkBingo(card, card->numbers[1][1]) ||
    checkBingo(card, card->numbers[1][2]) ||
    checkBingo(card, card->numbers[2][0]) ||
    checkBingo(card, card->numbers[2][1]) ||
    checkBingo(card, card->numbers[2][2])) {
    card->wins = 1;
  }
}

int main() {
  BingoCard *card = createBingoCard(3, 3);
  fillBingoCard(card);
  markBingoCard(card, 10);
  markBingoCard(card, 12);
  markBingoCard(card, 14);
  checkWin(card);
  if (card->wins) {
    printf("Congratulations! You won!\n");
  } else {
    printf("Sorry, you lost.\n");
  }
  free(card);
  return 0;
}