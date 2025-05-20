//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

struct Card {
    char suit;
    int value;
};

typedef struct Card Card;

struct Deck {
    int size;
    Card* cards;
};

typedef struct Deck Deck;

Deck* newDeck() {
    Deck* deck = malloc(sizeof(Deck));
    deck->size = 52;
    deck->cards = malloc(deck->size * sizeof(Card));
    for (int i = 0; i < deck->size; i++) {
        deck->cards[i].suit = 'S';
        deck->cards[i].value = i + 1;
    }
    return deck;
}

void shuffleDeck(Deck* deck) {
    int n = deck->size;
    for (int i = 0; i < n - 1; i++) {
        int j = rand() % (i + 1);
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void dealCard(Deck* deck, Card* card) {
    card->suit = deck->cards[0].suit;
    card->value = deck->cards[0].value;
    deck->cards[0].suit = 'S';
    deck->cards[0].value = 0;
}

void printDeck(Deck* deck) {
    printf("Deck size: %d\n", deck->size);
    for (int i = 0; i < deck->size; i++) {
        printf("Card %d: %c %d\n", i + 1, deck->cards[i].suit, deck->cards[i].value);
    }
}

int main() {
    Deck* deck = newDeck();
    shuffleDeck(deck);
    printDeck(deck);
    Card card;
    dealCard(deck, &card);
    printf("Card dealt: %c %d\n", card.suit, card.value);
    free(deck->cards);
    free(deck);
    return 0;
}