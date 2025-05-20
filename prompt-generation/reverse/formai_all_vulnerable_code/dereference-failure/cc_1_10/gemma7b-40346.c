//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 25

typedef struct BingoCard {
  int **numbers;
  int rows;
  int cols;
  int current_number;
  int is_bingo;
} BingoCard;

void generate_bingo_card(BingoCard *card) {
  card->numbers = (int **)malloc(card->rows * sizeof(int *));
  for (int i = 0; i < card->rows; i++) {
    card->numbers[i] = (int *)malloc(card->cols * sizeof(int));
  }

  srand(time(NULL));
  for (int i = 0; i < card->rows; i++) {
    for (int j = 0; j < card->cols; j++) {
      card->numbers[i][j] = rand() % MAX_NUM + 1;
    }
  }
}

void check_bingo(BingoCard *card) {
  card->is_bingo = 0;

  // Check rows
  for (int i = 0; i < card->rows; i++) {
    int is_bingo = 1;
    for (int j = 0; j < card->cols; j++) {
      if (card->numbers[i][j] != card->current_number) {
        is_bingo = 0;
      }
    }

    if (is_bingo) {
      card->is_bingo = 1;
      break;
    }
  }

  // Check columns
  for (int j = 0; j < card->cols; j++) {
    int is_bingo = 1;
    for (int i = 0; i < card->rows; i++) {
      if (card->numbers[i][j] != card->current_number) {
        is_bingo = 0;
      }
    }

    if (is_bingo) {
      card->is_bingo = 1;
      break;
    }
  }

  // Check diagonals
  if (card->rows == 5 && card->cols == 5) {
    int is_bingo = 1;
    for (int i = 0; i < 5; i++) {
      if (card->numbers[i][i] != card->current_number) {
        is_bingo = 0;
      }
    }

    if (is_bingo) {
      card->is_bingo = 1;
    }
  }
}

int main() {
  BingoCard *card = malloc(sizeof(BingoCard));
  card->rows = 5;
  card->cols = 5;
  generate_bingo_card(card);

  for (int i = 0; i < 10; i++) {
    card->current_number = rand() % MAX_NUM + 1;
    check_bingo(card);

    if (card->is_bingo) {
      printf("Bingo! You won!\n");
      break;
    }
  }

  return 0;
}