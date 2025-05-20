//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PILES 10
#define MAX_CARDS 20

typedef struct Card {
  int number;
  struct Card* next;
} Card;

typedef struct Pile {
  Card* head;
  int cards_num;
} Pile;

void initialize_pile(Pile* p) {
  p->head = NULL;
  p->cards_num = 0;
}

void add_card(Pile* p, int number) {
  Card* new_card = malloc(sizeof(Card));
  new_card->number = number;
  new_card->next = NULL;

  if (p->head == NULL) {
    p->head = new_card;
  } else {
    p->head->next = new_card;
  }

  p->cards_num++;
}

int draw_card(Pile* p) {
  if (p->cards_num == 0) {
    return -1;
  }

  Card* card = p->head;
  p->head = card->next;
  p->cards_num--;

  return card->number;
}

int main() {
  Pile* p1 = malloc(sizeof(Pile));
  initialize_pile(p1);

  // Add cards to the pile
  add_card(p1, 2);
  add_card(p1, 4);
  add_card(p1, 6);
  add_card(p1, 8);

  // Draw cards from the pile
  int card_number = draw_card(p1);
  printf("You drew card number: %d\n", card_number);

  card_number = draw_card(p1);
  printf("You drew card number: %d\n", card_number);

  return 0;
}