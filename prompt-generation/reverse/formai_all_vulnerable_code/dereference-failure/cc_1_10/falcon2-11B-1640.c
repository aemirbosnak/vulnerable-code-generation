//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CARDS 100

typedef struct {
    int num;
    int match;
} Card;

void initializeCards(Card* cards, int numCards) {
    for (int i = 0; i < numCards; i++) {
        cards[i].num = i + 1;
        cards[i].match = -1;
    }
}

void showCards(Card* cards, int numCards) {
    for (int i = 0; i < numCards; i++) {
        printf("%d ", cards[i].num);
    }
    printf("\n");
}

void matchCard(Card* cards, int numCards, int i, int j) {
    if (i!= j) {
        cards[i].match = j;
        cards[j].match = i;
    }
}

int main() {
    int numCards = 10;
    Card* cards = (Card*) malloc(sizeof(Card) * numCards);

    initializeCards(cards, numCards);
    showCards(cards, numCards);

    int correctMatch = 0;
    int incorrectMatch = 0;

    while (correctMatch < numCards) {
        int i = rand() % numCards;
        int j = rand() % numCards;

        if (cards[i].match == -1 && cards[j].match == -1) {
            matchCard(cards, numCards, i, j);
            correctMatch++;
        } else if (cards[i].match!= -1 && cards[j].match!= -1) {
            if (cards[i].match == cards[j].match) {
                matchCard(cards, numCards, i, j);
                correctMatch++;
            } else {
                incorrectMatch++;
            }
        }
    }

    printf("Correct matches: %d\n", correctMatch);
    printf("Incorrect matches: %d\n", incorrectMatch);

    showCards(cards, numCards);

    free(cards);

    return 0;
}