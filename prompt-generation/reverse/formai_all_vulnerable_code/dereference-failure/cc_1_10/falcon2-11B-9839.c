//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct Card {
    int value;
    char suit;
} Card;

typedef struct Deck {
    int numCards;
    Card* cards;
} Deck;

void shuffleDeck(Deck* deck) {
    int i, j;
    for (i = deck->numCards - 1; i > 0; i--) {
        j = rand() % (i + 1);
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void dealCard(Deck* deck, Card* card) {
    int index = rand() % deck->numCards;
    Card temp = deck->cards[index];
    deck->cards[index] = deck->cards[deck->numCards - 1];
    deck->numCards--;
    card->value = temp.value;
    card->suit = temp.suit;
}

int main() {
    int numPlayers = 2;
    Deck deck;
    Deck* playerDecks[numPlayers];
    Card* playerCards[numPlayers][5];

    deck.numCards = 52;
    deck.cards = (Card*)malloc(sizeof(Card) * deck.numCards);
    for (int i = 0; i < deck.numCards; i++) {
        deck.cards[i].value = 'A' + i % 13;
        deck.cards[i].suit = i / 13 + 'S';
    }

    shuffleDeck(&deck);

    for (int i = 0; i < numPlayers; i++) {
        playerDecks[i] = (Deck*)malloc(sizeof(Deck));
        playerDecks[i]->numCards = 0;
        playerDecks[i]->cards = (Card*)malloc(sizeof(Card) * 5);
    }

    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < 5; j++) {
            dealCard(&deck, playerCards[i][j]);
        }
        playerDecks[i]->numCards = 5;
    }

    // Game logic goes here

    for (int i = 0; i < numPlayers; i++) {
        free(playerDecks[i]->cards);
        free(playerDecks[i]);
    }
    free(deck.cards);
    free(deck.cards);

    return 0;
}