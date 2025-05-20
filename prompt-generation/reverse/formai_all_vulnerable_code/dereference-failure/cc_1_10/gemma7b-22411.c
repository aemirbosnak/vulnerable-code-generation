//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BALLS 20

typedef struct Ball {
  int number;
  struct Ball* next;
} Ball;

typedef struct BingoCard {
  int numCards;
  Ball** cards;
} BingoCard;

void initializeBingoCard(BingoCard* card) {
  card->numCards = 0;
  card->cards = NULL;
}

void addBallToBingoCard(BingoCard* card, int number) {
  Ball* newBall = malloc(sizeof(Ball));
  newBall->number = number;
  newBall->next = NULL;

  if (card->cards == NULL) {
    card->cards = malloc(sizeof(Ball*) * MAX_NUM_BALLS);
  }

  card->cards[card->numCards++] = newBall;
}

void drawBall(BingoCard* card) {
  int ballNumber = rand() % MAX_NUM_BALLS;

  for (Ball* ball = card->cards[0]; ball; ball = ball->next) {
    if (ball->number == ballNumber) {
      printf("Ball drawn: %d\n", ball->number);
      free(ball);
      break;
    }
  }
}

int main() {
  BingoCard* card = malloc(sizeof(BingoCard));
  initializeBingoCard(card);

  for (int i = 0; i < 10; i++) {
    addBallToBingoCard(card, rand() % MAX_NUM_BALLS);
  }

  drawBall(card);
  drawBall(card);

  free(card);

  return 0;
}