//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARD 5

typedef struct BingoCard {
  int **numbers;
  int cards_played;
  int is_winner;
} BingoCard;

void generate_bingo_card(BingoCard *card) {
  card->numbers = malloc(MAX_BINGO_CARD * sizeof(int *));
  for (int i = 0; i < MAX_BINGO_CARD; i++) {
    card->numbers[i] = malloc(MAX_BINGO_CARD * sizeof(int));
  }

  for (int i = 0; i < MAX_BINGO_CARD; i++) {
    for (int j = 0; j < MAX_BINGO_CARD; j++) {
      card->numbers[i][j] = rand() % 90 + 1;
    }
  }
}

void print_bingo_card(BingoCard *card) {
  for (int i = 0; i < MAX_BINGO_CARD; i++) {
    for (int j = 0; j < MAX_BINGO_CARD; j++) {
      printf("%d ", card->numbers[i][j]);
    }
    printf("\n");
  }
}

void check_bingo(BingoCard *card) {
  for (int i = 0; i < MAX_BINGO_CARD; i++) {
    for (int j = 0; j < MAX_BINGO_CARD; j++) {
      if (card->numbers[i][j] == card->numbers[0][0]) {
        card->is_winner = 1;
      }
    }
  }
}

int main() {
  BingoCard *card = malloc(sizeof(BingoCard));
  generate_bingo_card(card);
  print_bingo_card(card);
  check_bingo(card);

  if (card->is_winner) {
    printf("You win!");
  } else {
    printf("Sorry, you lose.");
  }

  return 0;
}