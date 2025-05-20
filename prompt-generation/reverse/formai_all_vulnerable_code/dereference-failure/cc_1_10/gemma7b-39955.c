//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: genius
#include <stdlib.h>
#include <time.h>

#define MAX_PILES 3
#define MAX_CARDS_PER_PILE 5

typedef struct Card {
  int number;
  struct Card* next;
} Card;

typedef struct Pile {
  Card* top;
  int cards_left;
} Pile;

void initialize_pile(Pile* p) {
  p->top = NULL;
  p->cards_left = 0;
}

void add_card_to_pile(Pile* p, int number) {
  Card* new_card = malloc(sizeof(Card));
  new_card->number = number;
  new_card->next = p->top;
  p->top = new_card;
  p->cards_left++;
}

int draw_card_from_pile(Pile* p) {
  if (p->cards_left == 0) {
    return -1;
  }
  Card* old_top = p->top;
  p->top = p->top->next;
  p->cards_left--;
  return old_top->number;
}

int main() {
  srand(time(NULL));

  Pile* piles[MAX_PILES];
  for (int i = 0; i < MAX_PILES; i++) {
    initialize_pile(&piles[i]);
  }

  // Shuffle the cards
  for (int i = 0; i < MAX_CARDS_PER_PILE * MAX_PILES; i++) {
    int number = rand() % MAX_CARDS_PER_PILE + 1;
    add_card_to_pile(&piles[rand() % MAX_PILES], number);
  }

  // Play the game
  int round = 1;
  while (1) {
    // Show the piles
    for (int i = 0; i < MAX_PILES; i++) {
      printf("Pile %d: ", i + 1);
      for (Card* card = piles[i]->top; card; card = card->next) {
        printf("%d ", card->number);
      }
      printf("\n");
    }

    // Draw a card
    int card_number = draw_card_from_pile(&piles[0]);
    if (card_number == -1) {
      printf("No cards left.\n");
      break;
    }

    // Play the card
    printf("You drew card number %d.\n", card_number);

    // Increment the round
    round++;
  }

  return 0;
}