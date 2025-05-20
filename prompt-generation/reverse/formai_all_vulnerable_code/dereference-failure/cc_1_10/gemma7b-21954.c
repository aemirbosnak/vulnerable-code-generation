//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 20

typedef struct BingoCard {
  int numbers[MAX_NUM];
  int isWinner;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
  for (int i = 0; i < MAX_NUM; i++) {
    card->numbers[i] = 0;
  }
  card->isWinner = 0;
}

void markBingoCard(BingoCard *card, int number) {
  for (int i = 0; i < MAX_NUM; i++) {
    if (card->numbers[i] == number) {
      card->numbers[i] = -1;
    }
  }
}

int checkBingoCard(BingoCard *card) {
  for (int i = 0; i < MAX_NUM; i++) {
    if (card->numbers[i] != -1) {
      return 0;
    }
  }
  return 1;
}

int main() {
  BingoCard *bingoCards[10];
  for (int i = 0; i < 10; i++) {
    bingoCards[i] = malloc(sizeof(BingoCard));
    initializeBingoCard(bingoCards[i]);
  }

  // Draw numbers
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    int number = rand() % MAX_NUM + 1;
    for (int j = 0; j < 10; j++) {
      markBingoCard(bingoCards[j], number);
    }
  }

  // Check for winners
  for (int i = 0; i < 10; i++) {
    if (checkBingoCard(bingoCards[i]) == 1) {
      printf("Winner! Player %d\n", i + 1);
    }
  }

  // Free memory
  for (int i = 0; i < 10; i++) {
    free(bingoCards[i]);
  }

  return 0;
}