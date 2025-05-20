//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 52
#define DEAL_CARDS 5
#define BET_SIZE 100

typedef struct Card {
  int number;
  char suit;
} Card;

void dealCards(Card **cards, int numCards);
void shuffleCards(Card **cards);
int calculateWin(Card **cards, int betSize);

int main() {
  srand(time(NULL));
  Card **cards = (Card **)malloc(MAX_CARDS * sizeof(Card));
  dealCards(cards, DEAL_CARDS);
  shuffleCards(cards);
  int win = calculateWin(cards, BET_SIZE);
  if (win) {
    printf("You win!");
  } else {
    printf("You lose.");
  }
  free(cards);
  return 0;
}

void dealCards(Card **cards, int numCards) {
  for (int i = 0; i < numCards; i++) {
    cards[i] = (Card *)malloc(sizeof(Card));
    cards[i]->number = rand() % 13 + 1;
    cards[i]->suit = 'H' + rand() % 4;
  }
}

void shuffleCards(Card **cards) {
  for (int i = 0; i < MAX_CARDS; i++) {
    int r = rand() % MAX_CARDS;
    Card *t = cards[i];
    cards[i] = cards[r];
    cards[r] = t;
  }
}

int calculateWin(Card **cards, int betSize) {
  int handTotal = cards[0]->number + cards[1]->number + cards[2]->number;
  if (handTotal >= betSize) {
    return 1;
  } else {
    return 0;
  }
}