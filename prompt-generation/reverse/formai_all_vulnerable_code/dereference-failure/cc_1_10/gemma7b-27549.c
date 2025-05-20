//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARDS 5
#define MAX_NUMS_PER_CARD 5

typedef struct BingoCard {
  int **nums;
  int numCards;
  int winStatus;
} BingoCard;

BingoCard *createBingoCard() {
  BingoCard *card = malloc(sizeof(BingoCard));
  card->nums = malloc(MAX_NUMS_PER_CARD * sizeof(int));
  card->numCards = 0;
  card->winStatus = 0;
  return card;
}

void addNumToCard(BingoCard *card, int num) {
  card->nums[card->numCards++] = num;
}

int checkWin(BingoCard *card) {
  // Check rows
  for (int i = 0; i < MAX_NUMS_PER_CARD; i++) {
    if (card->nums[i] == card->nums[i + MAX_NUMS_PER_CARD]) {
      return 1;
    }
  }

  // Check columns
  for (int i = 0; i < MAX_NUMS_PER_CARD; i++) {
    if (card->nums[i] == card->nums[i + MAX_NUMS_PER_CARD * MAX_NUMS_PER_CARD]) {
      return 1;
    }
  }

  // Check diagonals
  if (card->nums[0] == card->nums[MAX_NUMS_PER_CARD - 1] && card->nums[MAX_NUMS_PER_CARD - 1] == card->nums[MAX_NUMS_PER_CARD * MAX_NUMS_PER_CARD - 1]) {
    return 1;
  }

  return 0;
}

int main() {
  // Create a list of bingo cards
  BingoCard *cards[MAX_BINGO_CARDS];

  // Create and initialize each card
  for (int i = 0; i < MAX_BINGO_CARDS; i++) {
    cards[i] = createBingoCard();
  }

  // Generate random numbers for each card
  srand(time(NULL));
  for (int i = 0; i < MAX_BINGO_CARDS; i++) {
    for (int j = 0; j < MAX_NUMS_PER_CARD; j++) {
      addNumToCard(cards[i], rand() % 90 + 1);
    }
  }

  // Draw numbers
  int drawnNumbers[100];
  int numDrawn = 0;

  // Simulate draw loop
  while (!cards[0]->winStatus) {
    // Draw a number
    drawnNumbers[numDrawn++] = rand() % 90 + 1;

    // Check if the number has been called
    for (int i = 0; i < MAX_BINGO_CARDS; i++) {
      for (int j = 0; j < MAX_NUMS_PER_CARD; j++) {
        if (drawnNumbers[numDrawn - 1] == cards[i]->nums[j]) {
          cards[i]->nums[j] = -1;
        }
      }
    }

    // Check if any card has won
    for (int i = 0; i < MAX_BINGO_CARDS; i++) {
      if (checkWin(cards[i])) {
        cards[i]->winStatus = 1;
      }
    }
  }

  // Print the winner
  for (int i = 0; i < MAX_BINGO_CARDS; i++) {
    if (cards[i]->winStatus) {
      printf("Winner: %d\n", i);
    }
  }

  return 0;
}