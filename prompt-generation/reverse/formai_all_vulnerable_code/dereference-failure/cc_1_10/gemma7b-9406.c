//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 20
#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
  int **numbers;
  int **markedNumbers;
  int score;
  char **bingoCalls;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
  card->numbers = (int **)malloc(NUM_ROWS * sizeof(int *));
  card->markedNumbers = (int **)malloc(NUM_ROWS * sizeof(int *));
  card->bingoCalls = (char **)malloc(NUM_ROWS * sizeof(char *));

  for (int r = 0; r < NUM_ROWS; r++) {
    card->numbers[r] = (int *)malloc(NUM_COLS * sizeof(int));
    card->markedNumbers[r] = (int *)malloc(NUM_COLS * sizeof(int));
    card->bingoCalls[r] = (char *)malloc(MAX_NUM * sizeof(char));
  }

  card->score = 0;
}

void generateBingoCard(BingoCard *card) {
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      card->numbers[r][c] = rand() % MAX_NUM + 1;
    }
  }
}

void markNumber(BingoCard *card, int number) {
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      if (card->numbers[r][c] == number) {
        card->markedNumbers[r][c] = 1;
      }
    }
  }
}

int checkBingo(BingoCard *card) {
  for (int r = 0; r < NUM_ROWS; r++) {
    if (card->markedNumbers[r][0] == 1 && card->markedNumbers[r][1] == 1 && card->markedNumbers[r][2] == 1) {
      return 1;
    }
  }

  return 0;
}

int main() {
  BingoCard *card = malloc(sizeof(BingoCard));
  initializeBingoCard(card);
  generateBingoCard(card);

  // Simulate bingo calls
  for (int i = 0; i < 20; i++) {
    int number = rand() % MAX_NUM + 1;
    markNumber(card, number);

    if (checkBingo(card)) {
      printf("Bingo! Score: %d\n", card->score);
      card->score++;
    }
  }

  free(card);

  return 0;
}