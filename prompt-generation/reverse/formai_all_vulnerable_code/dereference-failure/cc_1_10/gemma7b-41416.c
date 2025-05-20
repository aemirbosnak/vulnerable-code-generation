//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PILES 5
#define MAX_CARDS 10

typedef struct Card {
  int number;
  struct Card* next;
} Card;

typedef struct Pile {
  Card* top;
  int cards_left;
  struct Pile* next;
} Pile;

void shuffle(Pile* p) {
  for (int i = 0; i < p->cards_left; i++) {
    int r = rand() % p->cards_left;
    Card* tmp = p->top->next;
    p->top->next = p->top->next->next;
    p->top->next->next = tmp;
  }
}

void deal(Pile* p, int n) {
  for (int i = 0; i < n; i++) {
    if (p->cards_left > 0) {
      Card* new_card = malloc(sizeof(Card));
      new_card->number = p->top->number;
      p->top = p->top->next;
      p->cards_left--;
    } else {
      break;
    }
  }
}

int main() {
  srand(time(NULL));

  Pile* p = malloc(sizeof(Pile));
  p->top = NULL;
  p->cards_left = MAX_CARDS;

  shuffle(p);

  deal(p, 5);

  for (Card* card = p->top; card; card = card->next) {
    printf("%d ", card->number);
  }

  printf("\n");

  return 0;
}