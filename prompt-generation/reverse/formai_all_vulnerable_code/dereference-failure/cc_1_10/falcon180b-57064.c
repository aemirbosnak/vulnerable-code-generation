//Falcon-180B DATASET v1.0 Category: Poker Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define NUM_PLAYERS 2
#define NUM_CARDS_PER_PLAYER 5

typedef struct {
    char suit;
    char rank;
    int value;
} Card;

typedef struct {
    Card hand[NUM_CARDS_PER_PLAYER];
    int num_cards;
} Player;

void shuffleDeck(Card deck[DECK_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCard(Card deck[DECK_SIZE], Player player[NUM_PLAYERS], int num_cards_in_deck) {
    Card card = deck[num_cards_in_deck - 1];
    deck[num_cards_in_deck - 1] = deck[0];
    deck[0] = card;
    player[0].hand[player[0].num_cards++] = card;
    num_cards_in_deck--;
}

int main() {
    Card deck[DECK_SIZE];
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i].suit = 'H';
        deck[i].rank = 'A';
        deck[i].value = 14;
    }
    shuffleDeck(deck);

    Player player[NUM_PLAYERS];
    int num_cards_in_deck = DECK_SIZE;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_CARDS_PER_PLAYER; j++) {
            dealCard(deck, player, num_cards_in_deck);
        }
    }

    printf("Player 1's hand: ");
    for (int i = 0; i < player[0].num_cards; i++) {
        printf("%c%c ", player[0].hand[i].suit, player[0].hand[i].rank);
    }
    printf("\n");

    printf("Player 2's hand: ");
    for (int i = 0; i < player[1].num_cards; i++) {
        printf("%c%c ", player[1].hand[i].suit, player[1].hand[i].rank);
    }
    printf("\n");

    return 0;
}