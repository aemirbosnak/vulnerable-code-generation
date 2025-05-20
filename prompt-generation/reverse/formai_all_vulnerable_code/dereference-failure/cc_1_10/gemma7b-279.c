//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _BingoCard {
    int numbers[5][5];
    int calledNumbers[5][5];
    int cardsWon;
} BingoCard;

BingoCard *createBingoCard() {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numbers[0][0] = -1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
            card->calledNumbers[i][j] = 0;
        }
    }
    card->cardsWon = 0;
    return card;
}

void callNumber(BingoCard *card, int number) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card->numbers[i][j] == number && card->calledNumbers[i][j] == 0) {
                card->calledNumbers[i][j] = 1;
                if (checkBingo(card)) {
                    card->cardsWon++;
                }
            }
        }
    }
}

int checkBingo(BingoCard *card) {
    for (int i = 0; i < 5; i++) {
        if (card->calledNumbers[i][0] == 1 && card->calledNumbers[i][1] == 1 && card->calledNumbers[i][2] == 1 && card->calledNumbers[i][3] == 1 && card->calledNumbers[i][4] == 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    BingoCard *card = createBingoCard();
    callNumber(card, 12);
    callNumber(card, 34);
    callNumber(card, 67);
    callNumber(card, 18);
    callNumber(card, 23);
    callNumber(card, 56);

    printf("Number of cards won: %d\n", card->cardsWon);

    return 0;
}