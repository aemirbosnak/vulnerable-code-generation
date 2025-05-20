//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4
#define NUM_CARDS (ROWS * COLS)
#define NUM_ATTEMPTS 10

void shuffleDeck(int deck[NUM_CARDS]);
void printDeck(int deck[NUM_CARDS]);
int matchCards(int deck[NUM_CARDS], int card1, int card2);

int main() {
    int deck[NUM_CARDS];
    int attempts = 0;
    int matches = 0;

    srand(time(NULL));

    // initialize deck
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i + 1;
    }

    // shuffle deck
    shuffleDeck(deck);

    // print deck
    printf("Shuffled deck:\n");
    printDeck(deck);

    // start game
    while (attempts < NUM_ATTEMPTS) {
        int card1, card2;
        printf("Attempt %d:\n", attempts + 1);
        printf("Enter first card number: ");
        scanf("%d", &card1);
        printf("Enter second card number: ");
        scanf("%d", &card2);

        if (matchCards(deck, card1, card2)) {
            printf("Match! Try again.\n");
        } else {
            printf("No match. Try again.\n");
        }

        attempts++;
    }

    printf("Game over. You made %d matches in %d attempts.\n", matches, attempts);

    return 0;
}

void shuffleDeck(int deck[NUM_CARDS]) {
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printDeck(int deck[NUM_CARDS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", deck[(i * COLS) + j]);
        }
        printf("\n");
    }
}

int matchCards(int deck[NUM_CARDS], int card1, int card2) {
    if (deck[card1 - 1] == deck[card2 - 1]) {
        return 1;
    }

    return 0;
}