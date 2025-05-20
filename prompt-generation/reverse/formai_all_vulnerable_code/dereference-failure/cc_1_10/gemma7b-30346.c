//Gemma-7B DATASET v1.0 Category: Poker Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HAND_SIZE 5

typedef struct Card {
    int number;
    char suit;
} Card;

void dealCards(Card **hand, int numCards) {
    // Shuffle the deck
    srand(time(NULL));
    for (int i = 0; i < numCards; i++) {
        hand[i] = malloc(sizeof(Card));
        hand[i]->number = rand() % 13 + 1;
        hand[i]->suit = 'H' + rand() % 4;
    }
}

int compareHands(Card **hand1, Card **hand2) {
    // Compare cards
    for (int i = 0; i < MAX_HAND_SIZE; i++) {
        if (hand1[i]->number != hand2[i]->number) {
            return hand1[i]->number - hand2[i]->number;
        }
    }

    // If all cards are the same, return a tie
    return 0;
}

int main() {
    Card **hand1 = NULL;
    Card **hand2 = NULL;

    dealCards(&hand1, 5);
    dealCards(&hand2, 5);

    int winner = compareHands(hand1, hand2);

    if (winner == 0) {
        printf("It's a tie!\n");
    } else if (winner > 0) {
        printf("Hand 1 wins!\n");
    } else {
        printf("Hand 2 wins!\n");
    }

    return 0;
}