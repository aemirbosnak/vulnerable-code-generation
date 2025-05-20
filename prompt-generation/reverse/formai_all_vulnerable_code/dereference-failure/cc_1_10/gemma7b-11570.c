//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 9
#define NUM_CARDS 5

typedef struct Card {
  int **numbers;
  int win_row;
  int win_col;
  int win_diag;
} Card;

void initialize_card(Card *card) {
  card->numbers = (int **)malloc(MAX_NUM * sizeof(int *));
  for (int i = 0; i < MAX_NUM; i++) {
    card->numbers[i] = (int *)malloc(NUM_CARDS * sizeof(int));
  }
  card->win_row = -1;
  card->win_col = -1;
  card->win_diag = -1;
}

void generate_card(Card *card) {
  for (int i = 0; i < MAX_NUM; i++) {
    for (int j = 0; j < NUM_CARDS; j++) {
      card->numbers[i][j] = rand() % MAX_NUM + 1;
    }
  }
}

void check_win(Card *card) {
  // Check rows
  for (int i = 0; i < MAX_NUM; i++) {
    int win = 1;
    for (int j = 0; j < NUM_CARDS; j++) {
      if (card->numbers[i][j] != card->numbers[i][0]) {
        win = 0;
      }
    }
    if (win) {
      card->win_row = i;
      return;
    }
  }

  // Check columns
  for (int j = 0; j < NUM_CARDS; j++) {
    int win = 1;
    for (int i = 0; i < MAX_NUM; i++) {
      if (card->numbers[i][j] != card->numbers[0][j]) {
        win = 0;
      }
    }
    if (win) {
      card->win_col = j;
      return;
    }
  }

  // Check diagonal
  int win = 1;
  for (int i = 0; i < MAX_NUM; i++) {
    if (card->numbers[i][i] != card->numbers[0][0]) {
      win = 0;
    }
  }
  if (win) {
    card->win_diag = 1;
    return;
  }

  return;
}

int main() {
  srand(time(NULL));

  Card cards[NUM_CARDS];
  for (int i = 0; i < NUM_CARDS; i++) {
    initialize_card(&cards[i]);
    generate_card(&cards[i]);
  }

  for (int i = 0; i < NUM_CARDS; i++) {
    check_win(&cards[i]);
  }

  for (int i = 0; i < NUM_CARDS; i++) {
    if (cards[i].win_row != -1) {
      printf("Card %d won in row %d\n", i + 1, cards[i].win_row);
    } else if (cards[i].win_col != -1) {
      printf("Card %d won in column %d\n", i + 1, cards[i].win_col);
    } else if (cards[i].win_diag != -1) {
      printf("Card %d won in diagonal\n", i + 1);
    }
  }

  return 0;
}