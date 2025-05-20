//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BINGO 9
#define NUM_BALLS 20

typedef struct Ball {
  int number;
  struct Ball* next;
} Ball;

typedef struct BingoCard {
  int** cards;
  int rows;
  int columns;
  Ball* balls_drawn;
} BingoCard;

BingoCard* createBingoCard() {
  BingoCard* card = malloc(sizeof(BingoCard));
  card->rows = 5;
  card->columns = 5;
  card->cards = malloc(card->rows * sizeof(int*));
  for (int r = 0; r < card->rows; r++) {
    card->cards[r] = malloc(card->columns * sizeof(int));
  }
  card->balls_drawn = NULL;
  return card;
}

void drawBall(BingoCard* card) {
  Ball* new_ball = malloc(sizeof(Ball));
  new_ball->number = rand() % NUM_BALLS + 1;
  new_ball->next = card->balls_drawn;
  card->balls_drawn = new_ball;
}

void checkBingo(BingoCard* card) {
  for (int r = 0; r < card->rows; r++) {
    for (int c = 0; c < card->columns; c++) {
      if (card->cards[r][c] == card->balls_drawn->number) {
        card->cards[r][c] = -1;
      }
    }
  }
  if (card->balls_drawn->number == MAX_NUM_BINGO) {
    printf("Bingo!!!\n");
  }
}

int main() {
  BingoCard* card = createBingoCard();
  for (int i = 0; i < 10; i++) {
    drawBall(card);
    checkBingo(card);
  }
  return 0;
}