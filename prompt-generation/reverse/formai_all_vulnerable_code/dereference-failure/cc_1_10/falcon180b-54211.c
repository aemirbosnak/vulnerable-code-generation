//Falcon-180B DATASET v1.0 Category: Poker Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 2
#define NUM_ROUNDS 5

enum CardSuit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum CardRank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

struct Card {
    enum CardSuit suit;
    enum CardRank rank;
};

void shuffleDeck(struct Card deck[NUM_CARDS]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i].suit = (enum CardSuit) rand() % NUM_CARDS;
        deck[i].rank = (enum CardRank) rand() % NUM_CARDS;
    }
}

void dealCard(struct Card deck[NUM_CARDS], int *cardIndex, struct Card hand[NUM_PLAYERS][NUM_ROUNDS]) {
    hand[*cardIndex][0] = deck[*cardIndex];
    (*cardIndex)++;
}

int compareHands(struct Card hand1[NUM_ROUNDS], struct Card hand2[NUM_ROUNDS]) {
    for (int i = 0; i < NUM_ROUNDS; i++) {
        if (hand1[i].rank > hand2[i].rank) {
            return 1;
        } else if (hand1[i].rank < hand2[i].rank) {
            return -1;
        }
    }
    return 0;
}

int main() {
    struct Card deck[NUM_CARDS];
    shuffleDeck(deck);

    struct Card hand1[NUM_PLAYERS][NUM_ROUNDS];
    struct Card hand2[NUM_PLAYERS][NUM_ROUNDS];

    int cardIndex = 0;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_ROUNDS; j++) {
            dealCard(deck, &cardIndex, hand1);
            dealCard(deck, &cardIndex, hand2);
        }
    }

    int result = compareHands(hand1[0], hand2[0]);

    if (result == 1) {
        printf("Player 1 wins!\n");
    } else if (result == -1) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}