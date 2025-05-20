//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUMBERS_PER_CARD 24

typedef struct BingoCard {
  int **numbers;
  int size;
  char **markedNumbers;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
  card->numbers = malloc(sizeof(int *) * card->size);
  for (int i = 0; i < card->size; i++) {
    card->numbers[i] = malloc(sizeof(int) * card->size);
  }
  card->markedNumbers = malloc(sizeof(char *) * card->size);
  for (int i = 0; i < card->size; i++) {
    card->markedNumbers[i] = malloc(sizeof(char) * card->size);
  }

  for (int i = 0; i < card->size; i++) {
    for (int j = 0; j < card->size; j++) {
      card->numbers[i][j] = 0;
      card->markedNumbers[i][j] = 0;
    }
  }
}

void printBingoCard(BingoCard *card) {
  for (int i = 0; i < card->size; i++) {
    for (int j = 0; j < card->size; j++) {
      printf("%d ", card->numbers[i][j]);
    }
    printf("\n");
  }
}

int main() {
  BingoCard *card = malloc(sizeof(BingoCard));
  initializeBingoCard(card);

  card->size = 5;
  card->numbers = malloc(sizeof(int *) * card->size);
  for (int i = 0; i < card->size; i++) {
    card->numbers[i] = malloc(sizeof(int) * card->size);
  }

  for (int i = 0; i < card->size; i++) {
    for (int j = 0; j < card->size; j++) {
      card->numbers[i][j] = rand() % MAX_NUMBERS_PER_CARD + 1;
    }
  }

  printBingoCard(card);

  return 0;
}