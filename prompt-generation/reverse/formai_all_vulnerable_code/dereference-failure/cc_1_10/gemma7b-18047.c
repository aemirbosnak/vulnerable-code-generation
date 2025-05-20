//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52

// Card structure
typedef struct Card {
    int number;
    int suit;
} Card;

// Deck structure
typedef struct Deck {
    Card cards[NUM_CARDS];
    int top;
} Deck;

// Function to shuffle the deck
void shuffle(Deck *deck) {
    int i, j;
    Card temp;

    for (i = 0; i < NUM_CARDS; i++) {
        for (j = i; j < NUM_CARDS; j++) {
            srand(time(NULL));
            int r = rand() % (j - i + 1);
            temp = deck->cards[i];
            deck->cards[i] = deck->cards[j];
            deck->cards[j] = temp;
        }
    }
}

// Function to deal cards
void deal(Deck *deck, int numCards) {
    int i;
    for (i = 0; i < numCards; i++) {
        printf("%d ", deck->cards[deck->top].number);
        printf("%c ", deck->cards[deck->top].suit);
        deck->top--;
    }
    printf("\n");
}

int main() {
    Deck *deck = malloc(sizeof(Deck));
    deck->top = NUM_CARDS - 1;

    // Shuffle the deck
    shuffle(deck);

    // Deal 5 cards
    deal(deck, 5);

    // Deal 3 cards
    deal(deck, 3);

    return 0;
}