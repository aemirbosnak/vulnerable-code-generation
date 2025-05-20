//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINGO_CARDS 10

typedef struct BingoCard {
  int numbers[5][5];
  int cards_won;
  char **marks;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
  card->cards_won = 0;
  card->marks = malloc(25 * sizeof(char));
  for (int i = 0; i < 25; i++) {
    card->marks[i] = ' ';
  }
}

void markBingoCard(BingoCard *card, int number) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (card->numbers[i][j] == number) {
        card->marks[i * 5 + j] = 'X';
      }
    }
  }
}

int checkBingoCard(BingoCard *card) {
  // Check rows
  for (int i = 0; i < 5; i++) {
    if (card->marks[i * 5] == 'X' && card->marks[i * 5 + 1] == 'X' && card->marks[i * 5 + 2] == 'X' && card->marks[i * 5 + 3] == 'X' && card->marks[i * 5 + 4] == 'X') {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < 5; j++) {
    if (card->marks[j] == 'X' && card->marks[j + 5] == 'X' && card->marks[j + 10] == 'X' && card->marks[j + 15] == 'X' && card->marks[j + 20] == 'X') {
      return 1;
    }
  }

  // Check diagonals
  if (card->marks[0] == 'X' && card->marks[6] == 'X' && card->marks[12] == 'X' && card->marks[18] == 'X' && card->marks[24] == 'X') {
    return 1;
  }

  return 0;
}

int main() {
  BingoCard cards[MAX_BINGO_CARDS];
  for (int i = 0; i < MAX_BINGO_CARDS; i++) {
    initializeBingoCard(&cards[i]);
  }

  // Simulate bingo drawing
  for (int i = 0; i < 10; i++) {
    int number = rand() % 25 + 1;
    for (int j = 0; j < MAX_BINGO_CARDS; j++) {
      markBingoCard(&cards[j], number);
    }

    // Check if anyone won
    for (int j = 0; j < MAX_BINGO_CARDS; j++) {
      if (checkBingoCard(&cards[j]) == 1) {
        printf("Bingo! Card %d won!\n", j);
        cards[j].cards_won++;
      }
    }
  }

  return 0;
}