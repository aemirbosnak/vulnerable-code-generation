//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 25

typedef struct BingoCard {
  int numbers[MAX_NUM];
  int numBingo;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
  for (int i = 0; i < MAX_NUM; i++) {
    card->numbers[i] = 0;
  }
  card->numBingo = 0;
}

void markBingoCard(BingoCard *card, int number) {
  for (int i = 0; i < MAX_NUM; i++) {
    if (card->numbers[i] == number) {
      card->numbers[i] = -1;
    }
  }
}

int checkBingo(BingoCard *card) {
  for (int i = 0; i < MAX_NUM; i++) {
    if (card->numbers[i] != -1) {
      return 0;
    }
  }
  return 1;
}

int main() {
  BingoCard *card = malloc(sizeof(BingoCard));
  initializeBingoCard(card);

  // Generate random numbers
  srand(time(NULL));
  for (int i = 0; i < 20; i++) {
    int number = rand() % MAX_NUM;
    markBingoCard(card, number);
  }

  // Check if the player has won
  if (checkBingo(card)) {
    printf("You have won!\n");
  } else {
    printf("Sorry, you have not won.\n");
  }

  free(card);
  return 0;
}