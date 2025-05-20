//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BINGO_CARD 5
#define MAX_NUM_BALLS 30

typedef struct BingoCard {
  int **numbers;
  int numCards;
  int numBingo;
} BingoCard;

void generateBingoCard(BingoCard *card) {
  card->numbers = (int **)malloc(card->numCards * sizeof(int *));
  for (int i = 0; i < card->numCards; i++) {
    card->numbers[i] = (int *)malloc(MAX_NUM_BINGO_CARD * sizeof(int));
  }
  for (int i = 0; i < card->numCards; i++) {
    for (int j = 0; j < MAX_NUM_BINGO_CARD; j++) {
      card->numbers[i][j] = rand() % MAX_NUM_BALLS + 1;
    }
  }
}

void playBingo(BingoCard *card) {
  int ballsDrawn = 0;
  while (card->numBingo < card->numCards && ballsDrawn < MAX_NUM_BALLS) {
    int numberDrawn = rand() % MAX_NUM_BALLS + 1;
    for (int i = 0; i < card->numCards; i++) {
      for (int j = 0; j < MAX_NUM_BINGO_CARD; j++) {
        if (card->numbers[i][j] == numberDrawn) {
          card->numbers[i][j] = -1;
          ballsDrawn++;
          if (ballsDrawn % 5 == 0) {
            card->numBingo++;
          }
        }
      }
    }
  }
}

int main() {
  BingoCard card;
  card.numCards = 3;
  card.numBingo = 0;
  generateBingoCard(&card);
  playBingo(&card);
  printf("Number of bingo cards won: %d", card.numBingo);
  return 0;
}