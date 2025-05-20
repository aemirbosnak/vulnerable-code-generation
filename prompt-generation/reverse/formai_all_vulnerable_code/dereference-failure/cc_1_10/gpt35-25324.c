//FormAI DATASET v1.0 Category: Poker Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_PLAYERS 4
#define NUMBER_OF_CARDS_PER_PLAYER 5
#define NUMBER_OF_CARDS_IN_DECK 52
#define MAX_VALUE_OF_CARD 13
#define NUMBER_OF_SUITS 4

typedef struct Card {
  int value;
  int suit;
} Card;

void initialize_deck(Card *deck) {
  for(int i=0; i<NUMBER_OF_CARDS_IN_DECK; i++) {
    deck[i].value = (i % MAX_VALUE_OF_CARD) + 1;
    deck[i].suit = i / MAX_VALUE_OF_CARD;
  }
}

void shuffle_deck(Card *deck) {
  srand(time(NULL));
  for (int i = NUMBER_OF_CARDS_IN_DECK - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    Card tmp = deck[j];
    deck[j] = deck[i];
    deck[i] = tmp;
  }
}

void deal_cards(Card *deck, Card **players, int n_players, int n_cards) {
  for (int i = 0; i < n_cards; i++) {
    for (int j = 0; j < n_players; j++) {
        players[j][i] = deck[(i * n_players) + j];
    }
  }
}

void print_cards(Card *cards, int n_cards) {
  for (int i=0; i<n_cards; i++) {
    printf("Card %d - Value: %d, Suit: %d\n", i, cards[i].value, cards[i].suit);
  }
}

int main() {
  Card deck[NUMBER_OF_CARDS_IN_DECK];
  initialize_deck(deck);
  shuffle_deck(deck);

  Card *players[NUMBER_OF_PLAYERS];
  for (int i = 0; i < NUMBER_OF_PLAYERS; ++i) {
    players[i] = (Card *)malloc(NUMBER_OF_CARDS_PER_PLAYER * sizeof(Card));
  }

  deal_cards(deck, players, NUMBER_OF_PLAYERS, NUMBER_OF_CARDS_PER_PLAYER);

  for (int i = 0; i < NUMBER_OF_PLAYERS; ++i) {
    printf("Player %d's cards:\n", i);
    print_cards(players[i], NUMBER_OF_CARDS_PER_PLAYER);
    printf("\n");
    free(players[i]);
  }

  return 0;
}