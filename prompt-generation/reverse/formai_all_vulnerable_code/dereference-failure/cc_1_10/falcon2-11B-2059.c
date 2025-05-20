//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Card {
    int rank;
    char suit;
};

struct Deck {
    int size;
    struct Card *cards;
};

struct Deck *newDeck() {
    struct Deck *deck = malloc(sizeof(struct Deck));
    deck->size = 52;
    deck->cards = malloc(sizeof(struct Card) * deck->size);

    srand(time(0));
    for (int i = 0; i < deck->size; i++) {
        deck->cards[i].rank = rand() % 13 + 1;
        deck->cards[i].suit = 'C';
    }

    return deck;
}

void printDeck(struct Deck *deck) {
    for (int i = 0; i < deck->size; i++) {
        printf("%d of %c\n", deck->cards[i].rank, deck->cards[i].suit);
    }
}

struct Card *deal(struct Deck *deck, int numCards) {
    struct Card *cards = malloc(numCards * sizeof(struct Card));
    for (int i = 0; i < numCards; i++) {
        cards[i].rank = deck->cards[i].rank;
        cards[i].suit = deck->cards[i].suit;
    }
    return cards;
}

void playGame() {
    struct Deck *deck = newDeck();
    printDeck(deck);
    struct Card *hand = deal(deck, 5);
    printf("You have been dealt the following cards:\n");
    printDeck(hand);
    printf("\n");
    free(deck->cards);
    free(deck);
}

int main() {
    playGame();
    return 0;
}