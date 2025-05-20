//Falcon-180B DATASET v1.0 Category: Poker Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define NUM_PLAYERS 2
#define NUM_CARDS_DEALT 5

typedef struct {
    char suit;
    char rank;
} Card;

void shuffleDeck(Card deck[DECK_SIZE]) {
    srand(time(0));
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i].suit = rand() % 4 + 1;
        deck[i].rank = rand() % 13 + 1;
    }
}

void dealCard(Card deck[DECK_SIZE], int *cardIndex, Card hand[NUM_CARDS_DEALT]) {
    hand[*cardIndex] = deck[*cardIndex];
    (*cardIndex)++;
}

int compareCards(Card hand1[NUM_CARDS_DEALT], Card hand2[NUM_CARDS_DEALT]) {
    for (int i = 0; i < NUM_CARDS_DEALT; i++) {
        if (hand1[i].rank > hand2[i].rank) {
            return 1;
        } else if (hand1[i].rank < hand2[i].rank) {
            return -1;
        }
    }
    return 0;
}

void printHand(Card hand[NUM_CARDS_DEALT]) {
    for (int i = 0; i < NUM_CARDS_DEALT; i++) {
        printf("%c%c ", hand[i].rank, hand[i].suit);
    }
    printf("\n");
}

int main() {
    Card deck[DECK_SIZE];
    shuffleDeck(deck);

    Card player1Hand[NUM_CARDS_DEALT];
    Card player2Hand[NUM_CARDS_DEALT];

    int player1Score = 0;
    int player2Score = 0;

    int cardIndex = 0;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < NUM_CARDS_DEALT; j++) {
            dealCard(deck, &cardIndex, player1Hand);
            dealCard(deck, &cardIndex, player2Hand);
        }
    }

    printHand(player1Hand);
    printf("Player 1 score: %d\n", player1Score);

    printHand(player2Hand);
    printf("Player 2 score: %d\n", player2Score);

    return 0;
}