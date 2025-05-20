//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct to represent a card
struct Card {
    char suit;
    char rank;
};

// Define a struct to represent a deck of cards
struct Deck {
    struct Card* cards;
    int size;
};

// Function to initialize a new deck of cards
void initDeck(struct Deck* deck) {
    deck->size = 52;
    deck->cards = (struct Card*) malloc(deck->size * sizeof(struct Card));
    
    for (int i = 0; i < deck->size; i++) {
        deck->cards[i].suit = 'S';
        deck->cards[i].rank = 'A';
    }
}

// Function to shuffle a deck of cards
void shuffleDeck(struct Deck* deck) {
    int n = deck->size;
    int j, t;

    for (int i = 0; i < n - 1; i++) {
        j = i + rand() / (RAND_MAX / (n - i));
        t = deck->cards[i].rank;
        deck->cards[i].rank = deck->cards[j].rank;
        deck->cards[j].rank = t;
    }
}

// Function to deal a card from a deck
struct Card dealCard(struct Deck* deck) {
    int i = rand() % deck->size;
    struct Card card = deck->cards[i];
    deck->cards[i] = deck->cards[deck->size - 1];
    deck->size--;

    return card;
}

// Function to print a card
void printCard(struct Card card) {
    printf("%c%c\n", card.suit, card.rank);
}

// Function to print a deck of cards
void printDeck(struct Deck deck) {
    printf("Deck size: %d\n", deck.size);

    for (int i = 0; i < deck.size; i++) {
        printf("Card %d:\n", i + 1);
        printCard(deck.cards[i]);
    }
}

int main() {
    struct Deck deck;
    initDeck(&deck);

    printf("Initial deck:\n");
    printDeck(deck);

    shuffleDeck(&deck);

    printf("Shuffled deck:\n");
    printDeck(deck);

    struct Card card = dealCard(&deck);

    printf("Dealt card: ");
    printCard(card);

    return 0;
}