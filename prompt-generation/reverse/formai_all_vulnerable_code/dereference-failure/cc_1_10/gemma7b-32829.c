//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARDS 52

// Card structure
typedef struct Card {
    int suit;
    int number;
} Card;

// Deck structure
typedef struct Deck {
    Card cards[NUM_CARDS];
    int top;
} Deck;

// Function to shuffle the deck
void shuffle(Deck *deck) {
    for (int i = 0; i < NUM_CARDS; i++) {
        int r = rand() % NUM_CARDS;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[r];
        deck->cards[r] = temp;
    }
}

// Function to deal the cards
void deal(Deck *deck, int numCards) {
    for (int i = 0; i < numCards; i++) {
        printf("%d ", deck->cards[deck->top].number);
        deck->top++;
    }
    printf("\n");
}

int main() {
    Deck *deck = malloc(sizeof(Deck));
    deck->top = 0;

    // Create the deck
    for (int i = 0; i < NUM_CARDS; i++) {
        Card card;
        card.suit = i % 4;
        card.number = i + 1;
        deck->cards[i] = card;
    }

    // Shuffle the deck
    shuffle(deck);

    // Deal the cards
    deal(deck, 5);

    return 0;
}