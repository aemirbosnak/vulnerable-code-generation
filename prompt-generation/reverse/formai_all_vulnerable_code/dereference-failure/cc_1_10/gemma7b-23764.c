//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_CARDS 52

// Define the Card Struct
typedef struct Card {
    int number;
    char suit;
} Card;

// Define the Deck Struct
typedef struct Deck {
    Card cards[MAX_NUM_CARDS];
    int numCards;
} Deck;

// Function to shuffle the deck
void shuffleDeck(Deck *deck) {
    for (int i = 0; i < deck->numCards; i++) {
        int r = rand() % deck->numCards;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[r];
        deck->cards[r] = temp;
    }
}

// Function to deal the cards
void dealCards(Deck *deck, int numCards) {
    for (int i = 0; i < numCards; i++) {
        printf("%d %c ", deck->cards[i].number, deck->cards[i].suit);
    }
    printf("\n");
}

int main() {
    // Create a deck of cards
    Deck *deck = malloc(sizeof(Deck));
    deck->numCards = 52;
    for (int i = 0; i < MAX_NUM_CARDS; i++) {
        deck->cards[i].number = i + 1;
        deck->cards[i].suit = 'c' + i % 4;
    }

    // Shuffle the deck
    shuffleDeck(deck);

    // Deal the cards
    dealCards(deck, 5);

    return 0;
}