//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the card structure
typedef struct {
    int rank;
    int suit;
} Card;

// Define the deck of cards
typedef struct {
    Card cards[52];
    int top;
} Deck;

// Initialize the deck
Deck initDeck() {
    Deck deck;
    deck.top = -1;

    for (int i = 0; i < 52; i++) {
        deck.cards[i].rank = i;
        deck.cards[i].suit = i % 4;
    }

    return deck;
}

// Shuffle the deck
void shuffle(Deck* deck) {
    int j;
    for (int i = deck->top - 1; i >= 0; i--) {
        j = rand() % (i + 1);
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// Deal a card from the deck
void dealCard(Deck* deck) {
    if (deck->top == -1) {
        printf("Deck is empty\n");
        return;
    }

    printf("Dealt: %d of %d\n", deck->cards[deck->top].rank, deck->cards[deck->top].suit);
    deck->top--;
}

// Check for a winning hand
bool isWinningHand(Deck* deck, Card* hand, int numCards) {
    if (numCards < 5) {
        return false;
    }

    bool hasStraightFlush = false;
    bool hasFourOfAKind = false;
    bool hasFullHouse = false;
    bool hasThreeOfAKind = false;
    bool hasTwoPair = false;
    bool hasOnePair = false;

    for (int i = 0; i < numCards; i++) {
        Card currentCard = hand[i];

        if (currentCard.rank == 14 && currentCard.suit == 0) {
            hasStraightFlush = true;
        } else if (currentCard.rank == 4 && currentCard.suit == 0) {
            hasFourOfAKind = true;
        } else if (currentCard.rank == 3 && currentCard.suit == 0) {
            hasFullHouse = true;
        } else if (currentCard.rank == 2 && currentCard.suit == 0) {
            hasThreeOfAKind = true;
        } else if (currentCard.rank == 2 && currentCard.suit!= 0) {
            hasTwoPair = true;
        } else if (currentCard.rank == 2 && currentCard.suit == 0) {
            hasOnePair = true;
        }
    }

    if (hasStraightFlush) {
        return true;
    } else if (hasFourOfAKind || hasFullHouse || hasThreeOfAKind || hasTwoPair || hasOnePair) {
        return true;
    }

    return false;
}

// Play a round of poker
void playRound(Deck* deck, Card* hand, int numCards) {
    printf("Dealing\n");
    shuffle(deck);
    for (int i = 0; i < numCards; i++) {
        dealCard(deck);
        hand[i] = deck->cards[deck->top];
        deck->top--;
    }

    if (isWinningHand(deck, hand, numCards)) {
        printf("Player wins!\n");
    } else {
        printf("Player loses\n");
    }
}

// Main function
int main() {
    Deck deck = initDeck();
    Card hand[5];

    playRound(&deck, hand, 5);

    return 0;
}