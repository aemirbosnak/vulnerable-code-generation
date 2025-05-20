//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

typedef struct BingoCard {
  int **numbers;
  int rows;
  int cols;
  int winning_line;
} BingoCard;

void initialize_bingo_card(BingoCard *card) {
  card->numbers = (int **)malloc(card->rows * sizeof(int *));
  for (int r = 0; r < card->rows; r++) {
    card->numbers[r] = (int *)malloc(card->cols * sizeof(int));
  }

  for (int r = 0; r < card->rows; r++) {
    for (int c = 0; c < card->cols; c++) {
      card->numbers[r][c] = rand() % MAX_NUM + 1;
    }
  }
}

void check_bingo(BingoCard *card) {
  for (int i = 0; i < card->winning_line; i++) {
    if (card->numbers[i][0] == card->numbers[i][1] &&
        card->numbers[i][0] == card->numbers[i][2] &&
        card->numbers[i][0] == card->numbers[i][3] &&
        card->numbers[i][0] == card->numbers[i][4]) {
      card->numbers[i][0] = -1;
    }
  }
}

int main() {
  BingoCard card;
  card.rows = 5;
  card.cols = 5;
  card.winning_line = 3;

  initialize_bingo_card(&card);

  check_bingo(&card);

  printf("Bingo! Line %d won!\n", card.winning_line);

  return 0;
}