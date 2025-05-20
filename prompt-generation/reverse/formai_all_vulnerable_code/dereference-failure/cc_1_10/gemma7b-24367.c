//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
  int **numbers;
  int wins;
} BingoCard;

BingoCard *createBingoCard() {
  BingoCard *card = malloc(sizeof(BingoCard));
  card->numbers = malloc(NUM_ROWS * sizeof(int *));
  for (int r = 0; r < NUM_ROWS; r++) {
    card->numbers[r] = malloc(NUM_COLS * sizeof(int));
  }
  card->wins = 0;
  return card;
}

void printBingoCard(BingoCard *card) {
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      printf("%d ", card->numbers[r][c]);
    }
    printf("\n");
  }
}

void playBingo(BingoCard *card) {
  // Generate random numbers
  int num_drawn = 0;
  int drawn_numbers[NUM_ROWS * NUM_COLS];
  for (int i = 0; i < NUM_ROWS * NUM_COLS; i++) {
    drawn_numbers[i] = rand() % 90 + 1;
  }

  // Check if the number is drawn
  for (int r = 0; r < NUM_ROWS; r++) {
    for (int c = 0; c < NUM_COLS; c++) {
      if (card->numbers[r][c] == drawn_numbers[num_drawn]) {
        card->numbers[r][c] = -1;
        num_drawn++;
      }
    }
  }

  // Check if the card has won
  if (card->wins == 0 && num_drawn == NUM_ROWS * NUM_COLS - 1) {
    card->wins = 1;
  }
}

int main() {
  BingoCard *card = createBingoCard();
  printBingoCard(card);

  playBingo(card);

  printBingoCard(card);

  printf("Wins: %d\n", card->wins);

  return 0;
}