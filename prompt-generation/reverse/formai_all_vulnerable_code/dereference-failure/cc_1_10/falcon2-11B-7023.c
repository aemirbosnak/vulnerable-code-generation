//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int suit;
    int rank;
} Card;

typedef struct {
    Card* deck;
    int size;
    int top;
} Deck;

Deck* newDeck() {
    Deck* deck = malloc(sizeof(Deck));
    deck->deck = malloc(52 * sizeof(Card));
    deck->size = 52;
    deck->top = 0;
    return deck;
}

void shuffle(Deck* deck) {
    for (int i = deck->size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card tmp = deck->deck[i];
        deck->deck[i] = deck->deck[j];
        deck->deck[j] = tmp;
    }
}

void deal(Deck* deck, Card* hand, int numCards) {
    for (int i = 0; i < numCards; i++) {
        hand[i] = deck->deck[deck->top++];
    }
}

void printHand(Card* hand, int numCards) {
    for (int i = 0; i < numCards; i++) {
        printf("%c%d\n", 'A' + hand[i].rank / 13, hand[i].rank % 13);
    }
}

int main() {
    srand(time(NULL));
    Deck* deck = newDeck();
    shuffle(deck);

    Card hand[7];
    deal(deck, hand, 7);

    printHand(hand, 7);

    return 0;
}