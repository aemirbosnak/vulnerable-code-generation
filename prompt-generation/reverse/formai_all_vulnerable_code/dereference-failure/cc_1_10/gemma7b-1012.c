//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARD_SIZE 5

typedef struct BingoCard {
  int **numbers;
  int size;
  int wins;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
  card->numbers = malloc(card->size * sizeof(int *));
  for (int i = 0; i < card->size; i++) {
    card->numbers[i] = malloc(MAX_BINGO_CARD_SIZE * sizeof(int));
  }
  card->wins = 0;
}

void generateBingoNumbers(BingoCard *card) {
  for (int i = 0; i < card->size; i++) {
    for (int j = 0; j < MAX_BINGO_CARD_SIZE; j++) {
      card->numbers[i][j] = rand() % 90 + 1;
    }
  }
}

void markBingoNumber(BingoCard *card, int number) {
  for (int i = 0; i < card->size; i++) {
    for (int j = 0; j < MAX_BINGO_CARD_SIZE; j++) {
      if (card->numbers[i][j] == number) {
        card->numbers[i][j] = -1;
      }
    }
  }
}

int checkBingo(BingoCard *card) {
  for (int i = 0; i < card->size; i++) {
    if (card->numbers[i][0] == -1 && card->numbers[i][1] == -1 &&
        card->numbers[i][2] == -1 && card->numbers[i][3] == -1 &&
        card->numbers[i][4] == -1) {
      return 1;
    }
  }
  return 0;
}

int main() {
  BingoCard *card = malloc(sizeof(BingoCard));
  initializeBingoCard(card);
  generateBingoNumbers(card);

  // Simulate drawing numbers
  for (int i = 0; i < 20; i++) {
    int number = rand() % 90 + 1;
    markBingoNumber(card, number);

    if (checkBingo(card)) {
      printf("Bingo! You win!\n");
      card->wins++;
    }
  }

  printf("Number of wins: %d\n", card->wins);

  return 0;
}