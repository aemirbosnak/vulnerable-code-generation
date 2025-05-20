//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 25

typedef struct BingoCard {
  int numbers[MAX_NUM];
  int cards[MAX_NUM];
  int wins[MAX_NUM];
  int current_num;
  int current_card;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
  card->current_num = 0;
  card->current_card = 0;
  for (int i = 0; i < MAX_NUM; i++) {
    card->numbers[i] = 0;
    card->cards[i] = 0;
    card->wins[i] = 0;
  }
}

void drawBingoNumber(BingoCard *card) {
  card->current_num++;
  card->numbers[card->current_num] = 1;
}

int checkBingo(BingoCard *card) {
  for (int i = 0; i < MAX_NUM; i++) {
    if (card->cards[i] == 5 && card->wins[i] == 0) {
      card->wins[i] = 1;
      return 1;
    }
  }
  return 0;
}

int main() {
  BingoCard *card = malloc(sizeof(BingoCard));
  initializeBingoCard(card);

  for (int i = 0; i < 10; i++) {
    drawBingoNumber(card);
    if (checkBingo(card)) {
      printf("Bingo!\n");
    }
  }

  free(card);

  return 0;
}