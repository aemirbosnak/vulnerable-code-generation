//Falcon-180B DATASET v1.0 Category: Poker Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define NUM_PLAYERS 2
#define NUM_CARDS_DEALT_PER_ROUND 5
#define NUM_ROUNDS 5

typedef struct {
    char suit;
    char rank;
} Card;

void shuffleDeck(Card deck[DECK_SIZE]) {
    int i, j;
    for (i = 0; i < DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCard(Card deck[DECK_SIZE], int numCardsDealt, Card hand[NUM_PLAYERS][DECK_SIZE]) {
    int i, j;
    for (i = 0; i < numCardsDealt; i++) {
        j = rand() % DECK_SIZE;
        hand[0][i] = deck[j];
        deck[j] = deck[DECK_SIZE - 1];
        deck[DECK_SIZE - 1] = hand[0][i];
        deck[DECK_SIZE - 1].rank = 'X'; // Mark the card as used
    }
}

int compareHands(Card hand1[NUM_PLAYERS][DECK_SIZE], Card hand2[NUM_PLAYERS][DECK_SIZE]) {
    int i, j;
    for (i = 0; i < NUM_PLAYERS; i++) {
        for (j = 0; j < NUM_CARDS_DEALT_PER_ROUND; j++) {
            if (hand1[i][j].rank > hand2[i][j].rank) {
                return 1;
            } else if (hand1[i][j].rank < hand2[i][j].rank) {
                return -1;
            }
        }
    }
    return 0;
}

void printHand(Card hand[NUM_PLAYERS][DECK_SIZE]) {
    int i, j;
    for (i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand:\n", i + 1);
        for (j = 0; j < NUM_CARDS_DEALT_PER_ROUND; j++) {
            printf("%c%c\n", hand[i][j].rank, hand[i][j].suit);
        }
    }
}

int main() {
    Card deck[DECK_SIZE];
    Card hand[NUM_PLAYERS][DECK_SIZE];
    int i, j, k;
    srand(time(NULL));

    // Initialize deck
    for (i = 0; i < DECK_SIZE; i++) {
        deck[i].rank = 'A' + (i % 13);
        deck[i].suit = (i / 13) % 4 + 'A';
    }

    // Shuffle deck
    shuffleDeck(deck);

    // Deal cards
    for (k = 0; k < NUM_ROUNDS; k++) {
        printf("Round %d:\n", k + 1);
        dealCard(deck, NUM_CARDS_DEALT_PER_ROUND, hand);
        printHand(hand);
        printf("Press enter to continue...\n");
        getchar();
    }

    // Determine winner
    int winner = 0;
    for (i = 1; i < NUM_PLAYERS; i++) {
        if (compareHands(hand, hand + i * DECK_SIZE) == 1) {
            winner = i;
            break;
        }
    }

    printf("The winner is Player %d!\n", winner + 1);

    return 0;
}