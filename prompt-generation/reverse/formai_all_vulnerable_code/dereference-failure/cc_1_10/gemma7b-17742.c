//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUM_BALLS 10

typedef struct BingoCard {
  int **numbers;
  int rows;
  int columns;
  int currentBall;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
  card->numbers = (int **)malloc(card->rows * sizeof(int *));
  for (int r = 0; r < card->rows; r++) {
    card->numbers[r] = (int *)malloc(card->columns * sizeof(int));
  }
  card->currentBall = 0;
}

void generateBingoBall(BingoCard *card) {
  card->numbers[rand() % card->rows][rand() % card->columns] = 1;
  card->currentBall++;
}

void checkBingo(BingoCard *card) {
  for (int r = 0; r < card->rows; r++) {
    for (int c = 0; c < card->columns; c++) {
      if (card->numbers[r][c] == 1) {
        card->numbers[r][c] = -1;
      }
    }
  }
  if (card->currentBall == MAX_NUM_BALLS) {
    printf("Congratulations! You won!");
  } else {
    printf("Sorry, you lose.");
  }
}

int main() {
  BingoCard card;
  initializeBingoCard(&card);

  for (int i = 0; i < MAX_NUM_BALLS; i++) {
    generateBingoBall(&card);
  }

  checkBingo(&card);

  return 0;
}