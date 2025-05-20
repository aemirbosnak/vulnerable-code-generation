//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the cards
void shuffleCards(int* cards, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

// Function to deal cards to players
void dealCards(int* cards, int n, int players) {
    for (int i = 0; i < players; i++) {
        for (int j = 0; j < n; j++) {
            printf("Player %d: %d\n", i + 1, cards[j]);
            cards[j] = 0;
        }
    }
}

// Function to check for a winning hand
int checkHand(int* cards, int n) {
    if (cards[0] == cards[1] && cards[1] == cards[2] && cards[0]!= 0) {
        return 1;
    } else if (cards[0] == cards[3] && cards[1] == cards[4] && cards[0]!= 0) {
        return 1;
    } else if (cards[0] == cards[4] && cards[1] == cards[3] && cards[0]!= 0) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    int n = 52; // Number of cards
    srand(time(NULL));
    int cards[n];

    for (int i = 0; i < n; i++) {
        cards[i] = rand() % 13 + 1;
    }

    printf("Initial cards: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", cards[i]);
    }
    printf("\n");

    shuffleCards(cards, n);

    int players = 2; // Number of players
    int hands[players];

    dealCards(cards, n, players);

    int winner = 0;
    for (int i = 0; i < players; i++) {
        if (checkHand(hands[i], n)) {
            winner = i;
        }
    }

    if (winner == 0) {
        printf("No one won!\n");
    } else {
        printf("Player %d won!\n", winner + 1);
    }

    return 0;
}