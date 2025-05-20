//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 99

typedef struct BingoCard {
  int numbers[MAX_NUM];
  int numFilled;
  int winningLines;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
  card->numFilled = 0;
  card->winningLines = 0;
  for (int i = 0; i < MAX_NUM; i++) {
    card->numbers[i] = -1;
  }
}

int getRandomNumber() {
  return rand() % MAX_NUM;
}

void markBingoCard(BingoCard *card, int number) {
  for (int i = 0; i < MAX_NUM; i++) {
    if (card->numbers[i] == number) {
      card->numbers[i] = 0;
      card->numFilled++;
    }
  }
}

int checkBingo(BingoCard *card) {
  // Check rows
  for (int i = 0; i < MAX_NUM / 5; i++) {
    int winning = 1;
    for (int j = 0; j < 5; j++) {
      if (card->numbers[i * 5 + j] != 0) {
        winning = 0;
      }
    }
    if (winning) {
      card->winningLines++;
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < 5; i++) {
    int winning = 1;
    for (int j = 0; j < MAX_NUM / 5; j++) {
      if (card->numbers[j * 5 + i] != 0) {
        winning = 0;
      }
    }
    if (winning) {
      card->winningLines++;
      return 1;
    }
  }

  // Check diagonals
  int winning = 1;
  for (int i = 0; i < MAX_NUM / 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (card->numbers[i * 5 + j] != 0) {
        winning = 0;
      }
    }
  }
  if (winning) {
    card->winningLines++;
    return 1;
  }

  return 0;
}

int main() {
  BingoCard *card = malloc(sizeof(BingoCard));
  initializeBingoCard(card);

  // Play the game
  for (int i = 0; card->numFilled < MAX_NUM && i < 100; i++) {
    int number = getRandomNumber();
    markBingoCard(card, number);
    if (checkBingo(card)) {
      printf("Congratulations! You won!\n");
      break;
    }
  }

  // Free the memory
  free(card);

  return 0;
}