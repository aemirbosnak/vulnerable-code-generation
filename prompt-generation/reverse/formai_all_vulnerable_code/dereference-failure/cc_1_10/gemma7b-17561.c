//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_NUMBERS 10

typedef struct BingoCard {
  int numbers[MAX_BINGO_NUMBERS];
  int numCards;
  struct BingoCard* nextCard;
} BingoCard;

BingoCard* createBingoCard() {
  BingoCard* card = malloc(sizeof(BingoCard));
  card->numCards = 0;
  card->nextCard = NULL;
  for (int i = 0; i < MAX_BINGO_NUMBERS; i++) {
    card->numbers[i] = 0;
  }
  return card;
}

void addBingoNumber(BingoCard* card, int number) {
  card->numbers[number] = 1;
  card->numCards++;
}

void playBingo(BingoCard* head) {
  int drawnNumbers[MAX_BINGO_NUMBERS] = {0};
  srand(time(NULL));
  for (int i = 0; i < MAX_BINGO_NUMBERS; i++) {
    int number = rand() % MAX_BINGO_NUMBERS + 1;
    if (drawnNumbers[number] == 0) {
      drawnNumbers[number] = 1;
      for (BingoCard* card = head; card; card = card->nextCard) {
        if (card->numbers[number] && card->numCards) {
          printf("Bingo! Number: %d\n", number);
          card->numCards = 0;
        }
      }
    }
  }
}

int main() {
  BingoCard* head = createBingoCard();
  addBingoNumber(head, 1);
  addBingoNumber(head, 3);
  addBingoNumber(head, 5);
  addBingoNumber(head, 7);
  addBingoNumber(head, 9);
  addBingoNumber(head, 11);
  addBingoNumber(head, 13);
  addBingoNumber(head, 15);

  playBingo(head);

  return 0;
}