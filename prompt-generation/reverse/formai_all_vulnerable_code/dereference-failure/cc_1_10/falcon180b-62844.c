//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CARDS 100

struct Card {
    int number;
    int marked;
};

void initCards(struct Card* cards) {
    for (int i = 0; i < MAX_CARDS; i++) {
        cards[i].number = i + 1;
        cards[i].marked = 0;
    }
}

void shuffleCards(struct Card* cards) {
    srand(time(NULL));
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        struct Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void printCard(struct Card* card) {
    printf("%d ", card->number);
}

void markCard(struct Card* card) {
    card->marked = 1;
}

int checkBingo(struct Card* cards, int numCards) {
    int rowCount = 0;
    int colCount = 0;
    int diagCount = 0;

    for (int i = 0; i < numCards; i++) {
        if (cards[i].marked) {
            rowCount++;
        }
    }

    for (int i = 0; i < numCards; i++) {
        if (cards[i].marked) {
            colCount++;
        }
    }

    for (int i = 0; i < numCards; i++) {
        if (cards[i].marked) {
            diagCount++;
        }
    }

    if (rowCount == numCards || colCount == numCards || diagCount == numCards) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct Card* cards = (struct Card*)malloc(MAX_CARDS * sizeof(struct Card));
    initCards(cards);
    shuffleCards(cards);

    int numCards = 0;
    while (numCards < 5) {
        printf("Card %d: ", numCards + 1);
        printCard(cards + numCards);
        printf("Mark card? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y') {
            markCard(cards + numCards);
            numCards++;
        }
    }

    int bingo = checkBingo(cards, numCards);

    if (bingo) {
        printf("Bingo!\n");
    } else {
        printf("No bingo.\n");
    }

    free(cards);
    return 0;
}