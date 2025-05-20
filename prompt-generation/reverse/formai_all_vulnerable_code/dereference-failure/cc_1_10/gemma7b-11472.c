//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUM_BALLS 10

typedef struct BingoCard {
  int **numbers;
  int rows;
  int columns;
  int balls_left;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
  card->numbers = malloc(sizeof(int *) * card->rows);
  for (int r = 0; r < card->rows; r++) {
    card->numbers[r] = malloc(sizeof(int) * card->columns);
  }

  card->balls_left = MAX_NUM_BALLS;
}

void generateBingoBall(BingoCard *card) {
  int number = rand() % MAX_NUM_BALLS + 1;
  for (int r = 0; r < card->rows; r++) {
    for (int c = 0; c < card->columns; c++) {
      if (card->numbers[r][c] == number) {
        card->numbers[r][c] = -1;
        card->balls_left--;
        break;
      }
    }
  }
}

void checkBingo(BingoCard *card) {
  for (int r = 0; r < card->rows; r++) {
    if (card->numbers[r][0] == -1 && card->numbers[r][1] == -1 && card->numbers[r][2] == -1) {
      printf("Bingo! Row %d\n", r + 1);
    }
  }

  for (int c = 0; c < card->columns; c++) {
    if (card->numbers[0][c] == -1 && card->numbers[1][c] == -1 && card->numbers[2][c] == -1) {
      printf("Bingo! Column %d\n", c + 1);
    }
  }

  if (card->numbers[0][0] == -1 && card->numbers[1][1] == -1 && card->numbers[2][2] == -1) {
    printf("Bingo! Full Card\n");
  }
}

int main() {
  BingoCard *card = malloc(sizeof(BingoCard));
  initializeBingoCard(card);

  for (int i = 0; i < MAX_BINGO_CARD_SIZE; i++) {
    generateBingoBall(card);
    checkBingo(card);
  }

  return 0;
}