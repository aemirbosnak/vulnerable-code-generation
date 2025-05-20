//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORDS 5
#define NUM_COLUMNS 5

typedef struct BingoCard {
  int **numbers;
  int cards_won;
} BingoCard;

void initialize_bingo_card(BingoCard *card) {
  card->numbers = (int **)malloc(NUM_WORDS * sizeof(int *));
  for (int i = 0; i < NUM_WORDS; i++) {
    card->numbers[i] = (int *)malloc(NUM_COLUMNS * sizeof(int));
  }

  card->cards_won = 0;
}

void mark_bingo_card(BingoCard *card, int number) {
  for (int i = 0; i < NUM_WORDS; i++) {
    for (int j = 0; j < NUM_COLUMNS; j++) {
      if (card->numbers[i][j] == number) {
        card->numbers[i][j] = -1;
      }
    }
  }
}

int check_bingo_card(BingoCard *card) {
  for (int i = 0; i < NUM_WORDS; i++) {
    if (card->numbers[i][0] == -1 && card->numbers[i][1] == -1 && card->numbers[i][2] == -1) {
      return 1;
    }
  }

  return 0;
}

int main() {
  BingoCard card;
  initialize_bingo_card(&card);

  // Generate random numbers
  srand(time(NULL));
  for (int i = 0; i < 20; i++) {
    int number = rand() % 25 + 1;
    mark_bingo_card(&card, number);
  }

  // Check if the card has won
  if (check_bingo_card(&card)) {
    printf("You have won!");
  } else {
    printf("You have not won.");
  }

  return 0;
}