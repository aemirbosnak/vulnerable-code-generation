//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARDS 52

typedef struct Card {
  int number;
  struct Card* next;
} Card;

void dealCards(Card* head) {
  // Shuffle the cards
  for (int i = 0; i < MAX_CARDS; i++) {
    int r = rand() % MAX_CARDS;
    Card* tmp = head->next;
    head->next = head->next->next;
    head->next->next = tmp;
    head = tmp;
  }

  // Deal the cards
  for (int i = 0; i < 5; i++) {
    printf("%d ", head->number);
    head = head->next;
  }
  printf("\n");
}

int main() {
  // Create a deck of cards
  Card* head = malloc(sizeof(Card));
  head->number = 0;
  head->next = malloc(sizeof(Card));
  head->next->number = 1;
  head->next->next = malloc(sizeof(Card));
  head->next->next->number = 2;
  head->next->next->next = malloc(sizeof(Card));
  head->next->next->next->number = 3;
  head->next->next->next->next = NULL;

  // Deal the cards
  dealCards(head);

  // Repeat for a game
  for (int i = 0; i < 10; i++) {
    dealCards(head);
  }

  return 0;
}