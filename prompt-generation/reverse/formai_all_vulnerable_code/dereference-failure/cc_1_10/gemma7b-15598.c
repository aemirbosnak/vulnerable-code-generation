//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PILES 10
#define MAX_CARDS_PER_PILE 52

typedef struct Card {
  int number;
  struct Card* next;
} Card;

typedef struct Pile {
  Card* head;
  int cards_left;
} Pile;

void shuffle_cards(Pile* p) {
  for (int i = 0; i < p->cards_left; i++) {
    int r = rand() % p->cards_left;
    Card* c = p->head;
    for (int j = 0; j < r; j++) {
      c = c->next;
    }
    Card* t = c->next;
    c->next = p->head;
    p->head = t;
  }
}

void deal_cards(Pile* p, int n) {
  for (int i = 0; i < n; i++) {
    if (p->cards_left > 0) {
      Card* c = p->head;
      p->head = c->next;
      p->cards_left--;
      printf("%d ", c->number);
    } else {
      printf("Sorry, no cards left.\n");
    }
  }
}

int main() {
  srand(time(NULL));

  Pile* p = malloc(sizeof(Pile));
  p->head = NULL;
  p->cards_left = MAX_CARDS_PER_PILE * MAX_PILES;

  shuffle_cards(p);

  deal_cards(p, 5);

  printf("\n");

  return 0;
}