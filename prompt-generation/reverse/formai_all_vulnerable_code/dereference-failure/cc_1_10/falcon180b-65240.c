//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define NUM_CARDS 8

void initDeck(int deck[][COLS], char suits[][COLS], char ranks[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            deck[i][j] = 0;
        }
    }
    for (i = 0; i < COLS; i++) {
        strcpy(suits[i], "Hearts");
        strcpy(ranks[i], "Ace");
    }
}

void shuffleDeck(int deck[][COLS], int numCards) {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < numCards; i++) {
        for (j = 0; j < ROWS; j++) {
            temp = deck[j][i];
            deck[j][i] = deck[i][j];
            deck[i][j] = temp;
        }
    }
}

void printDeck(int deck[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", deck[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int deck[ROWS][COLS];
    char suits[COLS][COLS];
    char ranks[COLS][COLS];

    initDeck(deck, suits, ranks);
    shuffleDeck(deck, NUM_CARDS);

    printf("Shuffled deck:\n");
    printDeck(deck);

    return 0;
}