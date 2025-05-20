//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINGO_NUMS 5

typedef struct BingoCard {
  int numbers[MAX_BINGO_NUMS];
  int marked[MAX_BINGO_NUMS];
  int numWins;
} BingoCard;

BingoCard *createBingoCard() {
  BingoCard *card = malloc(sizeof(BingoCard));
  card->numbers[0] = rand() % MAX_BINGO_NUMS + 1;
  for (int i = 1; i < MAX_BINGO_NUMS; i++) {
    card->numbers[i] = rand() % MAX_BINGO_NUMS + 1;
  }
  card->marked[0] = card->marked[1] = card->marked[2] = card->marked[3] = card->marked[4] = 0;
  card->numWins = 0;
  return card;
}

void markBingoCard(BingoCard *card, int num) {
  for (int i = 0; i < MAX_BINGO_NUMS; i++) {
    if (card->numbers[i] == num && card->marked[i] == 0) {
      card->marked[i] = 1;
    }
  }
}

int checkBingoCard(BingoCard *card) {
  for (int i = 0; i < MAX_BINGO_NUMS; i++) {
    if (card->marked[i] == 0) {
      return 0;
    }
  }
  return 1;
}

void playBingo(int numPlayers) {
  BingoCard *cards[numPlayers];
  for (int i = 0; i < numPlayers; i++) {
    cards[i] = createBingoCard();
  }

  // Draw numbers
  for (int round = 0; round < 10; round++) {
    int num = rand() % MAX_BINGO_NUMS + 1;
    for (int i = 0; i < numPlayers; i++) {
      markBingoCard(cards[i], num);
    }
  }

  // Check for wins
  for (int i = 0; i < numPlayers; i++) {
    if (checkBingoCard(cards[i])) {
      cards[i]->numWins++;
    }
  }

  // Print winners
  for (int i = 0; i < numPlayers; i++) {
    if (cards[i]->numWins > 0) {
      printf("Winner: %d\n", cards[i]->numWins);
    }
  }
}

int main() {
  playBingo(2);
  return 0;
}