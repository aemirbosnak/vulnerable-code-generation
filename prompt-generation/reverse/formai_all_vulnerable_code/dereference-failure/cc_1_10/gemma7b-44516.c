//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARDS 52

// Card structure
typedef struct Card {
    int number;
    char suit;
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

// Function to deal cards
void deal(Deck *deck, int numCards) {
    for (int i = 0; i < numCards; i++) {
        printf("%d %c ", deck->cards[deck->top].number, deck->cards[deck->top].suit);
        deck->top--;
    }
}

int main() {
    // Create a deck
    Deck *deck = malloc(sizeof(Deck));
    deck->top = NUM_CARDS - 1;
    for (int i = 0; i < NUM_CARDS; i++) {
        deck->cards[i].number = i + 1;
        deck->cards[i].suit = 'H' + i % 4;
    }

    // Shuffle the deck
    shuffle(deck);

    // Deal cards
    deal(deck, 5);

    return 0;
}