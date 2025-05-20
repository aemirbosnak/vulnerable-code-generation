//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARD 5
#define MAX_BALLS 30

typedef struct BingoCard {
  int numbers[MAX_BINGO_CARD];
  int marked[MAX_BINGO_CARD];
} BingoCard;

typedef struct BingoBall {
  int number;
  struct BingoBall *next;
} BingoBall;

BingoCard *createBingoCard() {
  BingoCard *card = malloc(sizeof(BingoCard));
  card->numbers[0] = -1;
  for (int i = 1; i < MAX_BINGO_CARD; i++) {
    card->numbers[i] = 0;
  }
  for (int i = 0; i < MAX_BINGO_CARD; i++) {
    card->marked[i] = 0;
  }
  return card;
}

BingoBall *createBingoBall() {
  BingoBall *ball = malloc(sizeof(BingoBall));
  ball->number = rand() % MAX_BALLS + 1;
  ball->next = NULL;
  return ball;
}

void playBingo(BingoCard *card) {
  BingoBall *ball = createBingoBall();
  while (!card->marked[ball->number] && ball->number != -1) {
    ball = createBingoBall();
  }
  if (ball->number != -1) {
    card->marked[ball->number] = 1;
    printf("You have matched number: %d\n", ball->number);
  }
}

int main() {
  BingoCard *card = createBingoCard();
  for (int i = 0; i < MAX_BINGO_CARD; i++) {
    playBingo(card);
  }
  return 0;
}