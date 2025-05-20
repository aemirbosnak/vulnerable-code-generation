//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
  int **numbers;
  int wins;
  char **marks;
} BingoCard;

BingoCard *createBingoCard() {
  BingoCard *card = malloc(sizeof(BingoCard));
  card->numbers = malloc(NUM_ROWS * sizeof(int *));
  for (int r = 0; r < NUM_ROWS; r++) {
    card->numbers[r] = malloc(NUM_COLS * sizeof(int));
  }
  card->marks = malloc(NUM_ROWS * sizeof(char *));
  for (int r = 0; r < NUM_ROWS; r++) {
    card->marks[r] = malloc(NUM_COLS * sizeof(char));
  }
  card->wins = 0;
  return card;
}

void drawBingoNumber(BingoCard *card) {
  int number = rand() % 90 + 1;
  if (card->numbers[0][number] == 0 && card->marks[0][number] == ' ') {
    card->numbers[0][number] = 1;
    card->marks[0][number] = 'X';
  }
}

void checkBingo(BingoCard *card) {
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      if (card->numbers[r][c] == 1 && card->marks[r][c] == 'X') {
        card->wins++;
      }
    }
  }
}

int main() {
  BingoCard *card = createBingoCard();
  for (int i = 0; i < 10; i++) {
    drawBingoNumber(card);
  }
  checkBingo(card);
  printf("Number of wins: %d\n", card->wins);
  return 0;
}