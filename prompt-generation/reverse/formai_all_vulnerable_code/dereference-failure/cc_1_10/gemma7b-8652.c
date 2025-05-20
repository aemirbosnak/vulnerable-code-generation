//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 25

typedef struct BingoCard {
  int numbers[MAX_NUM];
  int freeSpaces;
  int mark[MAX_NUM];
} BingoCard;

void generateBingoCard(BingoCard *card) {
  time_t t = time(NULL);
  srand(t);

  for (int i = 0; i < MAX_NUM; i++) {
    card->numbers[i] = rand() % MAX_NUM + 1;
  }

  card->freeSpaces = MAX_NUM - 5;
  card->mark[MAX_NUM] = 0;
}

void playBingo(BingoCard *card) {
  for (int i = 0; i < 5; i++) {
    int numberDrawn = rand() % MAX_NUM + 1;

    for (int j = 0; j < MAX_NUM; j++) {
      if (card->numbers[j] == numberDrawn && card->mark[j] == 0) {
        card->mark[j] = 1;
      }
    }

    if (card->freeSpaces == 0) {
      printf("Congratulations! You won!");
      break;
    }
  }

  if (card->freeSpaces > 0) {
    printf("Sorry, you lost. Better luck next time.");
  }
}

int main() {
  BingoCard card;
  generateBingoCard(&card);
  playBingo(&card);

  return 0;
}