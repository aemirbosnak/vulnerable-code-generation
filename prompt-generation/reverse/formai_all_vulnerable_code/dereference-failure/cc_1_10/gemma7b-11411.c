//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUMBER_OF_BALLS 20

typedef struct BingoCard {
  int numbers[MAX_BINGO_CARD_SIZE];
  int markedNumbers[MAX_BINGO_CARD_SIZE];
  int isWinner;
} BingoCard;

void generateBingoCard(BingoCard *card) {
  for (int i = 0; i < MAX_BINGO_CARD_SIZE; i++) {
    card->numbers[i] = rand() % MAX_NUMBER_OF_BALLS + 1;
  }
  card->isWinner = 0;
}

void markBingoCard(BingoCard *card, int number) {
  for (int i = 0; i < MAX_BINGO_CARD_SIZE; i++) {
    if (card->numbers[i] == number) {
      card->markedNumbers[i] = 1;
    }
  }
}

int checkBingo(BingoCard *card) {
  for (int i = 0; i < MAX_BINGO_CARD_SIZE; i++) {
    if (card->markedNumbers[i] == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  BingoCard *card = malloc(sizeof(BingoCard));
  generateBingoCard(card);

  // Draw balls
  for (int i = 0; i < MAX_NUMBER_OF_BALLS; i++) {
    int number = rand() % MAX_NUMBER_OF_BALLS + 1;
    markBingoCard(card, number);
  }

  // Check if winner
  if (checkBingo(card)) {
    printf("You won!");
  } else {
    printf("Sorry, you lose.");
  }

  free(card);
  return 0;
}