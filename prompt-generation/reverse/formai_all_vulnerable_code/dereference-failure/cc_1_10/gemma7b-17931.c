//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52

// Card Struct
typedef struct Card {
    int number;
    char suit;
} Card;

// Deck Struct
typedef struct Deck {
    Card cards[NUM_CARDS];
    int top;
} Deck;

void shuffle(Deck *deck) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        int r = rand() % NUM_CARDS;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[r];
        deck->cards[r] = temp;
    }
}

void deal(Deck *deck, int numCards) {
    for (int i = 0; i < numCards; i++) {
        printf("%d %c ", deck->cards[i].number, deck->cards[i].suit);
    }
    printf("\n");
}

int main() {
    Deck *deck = malloc(sizeof(Deck));
    deck->top = -1;

    // Create a deck
    for (int i = 0; i < NUM_CARDS; i++) {
        Card card;
        card.number = i + 1;
        card.suit = 'h' + i % 4;
        deck->cards[i] = card;
    }

    // Shuffle the deck
    shuffle(deck);

    // Deal 5 cards
    deal(deck, 5);

    return 0;
}