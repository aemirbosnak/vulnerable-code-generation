//Gemma-7B DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARDS 52
#define MAX_HAND_SIZE 5

typedef struct Card {
  int number;
  char suit;
} Card;

void deal_cards(Card **hand, int hand_size, int num_cards) {
  for (int i = 0; i < hand_size && num_cards > 0; i++) {
    hand[i] = malloc(sizeof(Card));
    hand[i]->number = rand() % MAX_CARDS + 1;
    hand[i]->suit = 'H' + rand() % 4;
    num_cards--;
  }
}

int compare_cards(Card *card1, Card *card2) {
  if (card1->number == card2->number) {
    return 0;
  } else if (card1->number > card2->number) {
    return 1;
  } else {
    return -1;
  }
}

int main() {
  Card **hand1 = NULL;
  Card **hand2 = NULL;
  int num_cards = 10;

  deal_cards(&hand1, MAX_HAND_SIZE, num_cards);
  deal_cards(&hand2, MAX_HAND_SIZE, num_cards);

  for (int i = 0; i < MAX_HAND_SIZE; i++) {
    printf("%d %c ", hand1[i]->number, hand1[i]->suit);
  }

  printf("\n");

  for (int i = 0; i < MAX_HAND_SIZE; i++) {
    printf("%d %c ", hand2[i]->number, hand2[i]->suit);
  }

  printf("\n");

  int winner = compare_cards(hand1[0], hand2[0]);

  if (winner == 0) {
    printf("It's a draw!");
  } else if (winner == 1) {
    printf("Hand 1 wins!");
  } else {
    printf("Hand 2 wins!");
  }

  return 0;
}