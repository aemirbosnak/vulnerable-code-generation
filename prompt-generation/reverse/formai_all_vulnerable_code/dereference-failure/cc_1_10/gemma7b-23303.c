//Gemma-7B DATASET v1.0 Category: Table Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_OF_PILES 5
#define MAX_NUM_OF_CARDS_IN_A_PILE 10

typedef struct Card {
  int number;
  struct Card* next;
} Card;

typedef struct Pile {
  Card* head;
  int numCards;
} Pile;

Pile* createPile(int numCards) {
  Pile* pile = malloc(sizeof(Pile));
  pile->head = NULL;
  pile->numCards = numCards;
  return pile;
}

void addCardToPile(Pile* pile, int number) {
  Card* newCard = malloc(sizeof(Card));
  newCard->number = number;
  newCard->next = pile->head;
  pile->head = newCard;
  pile->numCards++;
}

int drawCardFromPile(Pile* pile) {
  if (pile->numCards == 0) {
    return -1;
  }
  Card* card = pile->head;
  pile->head = card->next;
  pile->numCards--;
  return card->number;
}

int main() {
  Pile* pile1 = createPile(MAX_NUM_OF_CARDS_IN_A_PILE);
  addCardToPile(pile1, 1);
  addCardToPile(pile1, 2);
  addCardToPile(pile1, 3);
  addCardToPile(pile1, 4);
  addCardToPile(pile1, 5);

  int cardNumber = drawCardFromPile(pile1);
  if (cardNumber != -1) {
    printf("You drew card number %d.\n", cardNumber);
  } else {
    printf("The pile is empty.\n");
  }

  return 0;
}