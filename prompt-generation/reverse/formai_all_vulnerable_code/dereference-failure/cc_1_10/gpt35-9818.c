//FormAI DATASET v1.0 Category: Poker Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_CARDS 52

// A Card struct representing a playing card with a rank and a suit
typedef struct Card {
    int rank;
    char suit;
} Card;

// A Hand struct representing a player's hand with an array of cards and the number of cards in the hand
typedef struct Hand {
    Card* cards;
    int numCards;
} Hand;

// A Deck struct representing a deck of playing cards with an array of cards and the number of cards in the deck
typedef struct Deck {
    Card* cards;
    int numCards;
} Deck;

// Helper function to print the rank and suit of a card
void printCard(Card card) {
    char* rankStr;
    switch (card.rank) {
        case 1:
            rankStr = "Ace";
            break;
        case 11:
            rankStr = "Jack";
            break;
        case 12:
            rankStr = "Queen";
            break;
        case 13:
            rankStr = "King";
            break;
        default:
            rankStr = malloc(sizeof(char) * 2);
            sprintf(rankStr, "%d", card.rank);
            break;
    }

    printf("%s of %c\n", rankStr, card.suit);
}

// Helper function to create a new card with the given rank and suit
Card newCard(int rank, char suit) {
    Card card = {rank, suit};
    return card;
}

// Helper function to create a new deck of playing cards
Deck newDeck() {
    Deck deck;
    deck.cards = malloc(sizeof(Card) * NUM_CARDS);
    deck.numCards = NUM_CARDS;

    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        int rank = i % 13 + 1;
        char suit;
        if (i < 13) {
            suit = 'S';
        } else if (i < 26) {
            suit = 'H';
        } else if (i < 39) {
            suit = 'C';
        } else {
            suit = 'D';
        }
        deck.cards[i] = newCard(rank, suit);
    }

    return deck;
}

// Helper function to shuffle a deck of playing cards randomly
void shuffleDeck(Deck* deck) {
    srand(time(NULL));
    int i;
    for (i = deck->numCards - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// Helper function to deal a card from the top of a deck
Card dealCard(Deck* deck) {
    Card card = deck->cards[deck->numCards - 1];
    deck->numCards--;
    return card;
}

// Recursive function to play a hand of poker
void playHand(Deck* deck, Hand* hand, int numCardsToDraw) {
    // Base case: no more cards to draw
    if (numCardsToDraw == 0) {
        printf("Your hand:\n");
        int i;
        for (i = 0; i < hand->numCards; i++) {
            printCard(hand->cards[i]);
        }
        return;
    }

    // Draw a card from the deck and add it to the hand
    Card card = dealCard(deck);
    hand->numCards++;
    hand->cards = realloc(hand->cards, sizeof(Card) * hand->numCards);
    hand->cards[hand->numCards - 1] = card;

    // Recursive step: draw one fewer card next time
    playHand(deck, hand, numCardsToDraw - 1);
}

int main() {
    // Create a new deck and shuffle it
    Deck deck = newDeck();
    shuffleDeck(&deck);

    // Create a new hand and play a hand of poker
    Hand hand = {NULL, 0};
    playHand(&deck, &hand, 5);

    // Clean up memory used by the deck and the hand
    free(deck.cards);
    free(hand.cards);
    return 0;
}