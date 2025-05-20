//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 50

typedef struct BingoCard {
  int **numbers;
  int rows;
  int cols;
  int winning_number;
  int is_won;
} BingoCard;

void generate_bingo_card(BingoCard *card) {
  card->numbers = (int **)malloc(card->rows * sizeof(int *));
  for (int i = 0; i < card->rows; i++) {
    card->numbers[i] = (int *)malloc(card->cols * sizeof(int));
  }

  for (int r = 0; r < card->rows; r++) {
    for (int c = 0; c < card->cols; c++) {
      card->numbers[r][c] = rand() % MAX_NUM + 1;
    }
  }
}

void check_bingo(BingoCard *card) {
  for (int r = 0; r < card->rows; r++) {
    for (int c = 0; c < card->cols; c++) {
      if (card->numbers[r][c] == card->winning_number) {
        card->is_won = 1;
      }
    }
  }
}

int main() {
  srand(time(NULL));

  BingoCard *card = malloc(sizeof(BingoCard));
  card->rows = 5;
  card->cols = 5;
  card->winning_number = 23;
  card->is_won = 0;

  generate_bingo_card(card);

  check_bingo(card);

  if (card->is_won) {
    printf("You won!");
  } else {
    printf("Sorry, you lost.");
  }

  free(card);

  return 0;
}