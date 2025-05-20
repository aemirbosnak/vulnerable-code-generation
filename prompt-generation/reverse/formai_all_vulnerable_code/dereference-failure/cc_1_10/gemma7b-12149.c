//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

#define SQUARE_SIZE 25

typedef struct BingoCard {
  int **numbers;
  int wins;
} BingoCard;

BingoCard *createBingoCard() {
  BingoCard *card = malloc(sizeof(BingoCard));
  card->numbers = malloc(NUM_ROWS * sizeof(int *));
  for (int r = 0; r < NUM_ROWS; r++) {
    card->numbers[r] = malloc(NUM_COLS * sizeof(int));
  }
  card->wins = 0;
  return card;
}

void drawBingoNumber(BingoCard *card) {
  int number = rand() % SQUARE_SIZE + 1;
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      if (card->numbers[r][c] == number) {
        card->numbers[r][c] = -1;
      }
    }
  }
}

int checkBingo(BingoCard *card) {
  for (int r = 0; r < NUM_ROWS; r++) {
    if (card->numbers[r][0] == -1 && card->numbers[r][1] == -1 && card->numbers[r][2] == -1) {
      return 1;
    }
  }

  for (int c = 0; c < NUM_COLS; c++) {
    if (card->numbers[0][c] == -1 && card->numbers[1][c] == -1 && card->numbers[2][c] == -1) {
      return 1;
    }
  }

  return 0;
}

int main() {
  srand(time(NULL));

  BingoCard *card = createBingoCard();

  for (int i = 0; i < 10; i++) {
    drawBingoNumber(card);
    if (checkBingo(card)) {
      card->wins++;
      printf("Bingo! You won %d times!\n", card->wins);
    }
  }

  free(card->numbers);
  free(card);

  return 0;
}