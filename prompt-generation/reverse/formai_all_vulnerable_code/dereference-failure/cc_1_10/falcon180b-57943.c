//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_CARDS 24

typedef struct {
    int value;
    char letter;
} Card;

void generateCards(Card cards[MAX_CARDS]) {
    int i = 0;
    for (int row = 1; row <= ROWS; row++) {
        for (int col = 1; col <= COLS; col++) {
            cards[i].value = row * COLS + col;
            cards[i].letter = 'B' + row - 1;
            i++;
        }
    }
}

void shuffleCards(Card cards[MAX_CARDS]) {
    srand(time(0));
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void printCard(Card card) {
    printf("%c%d ", card.letter, card.value);
}

void printCards(Card cards[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        printCard(cards[i]);
        printf("\n");
    }
}

int main() {
    Card cards[MAX_CARDS];
    generateCards(cards);
    shuffleCards(cards);
    printCards(cards);
    return 0;
}