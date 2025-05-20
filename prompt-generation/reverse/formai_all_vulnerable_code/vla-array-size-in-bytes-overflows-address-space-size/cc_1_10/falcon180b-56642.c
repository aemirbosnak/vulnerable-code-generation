//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

typedef struct {
    int num;
    char called;
} BingoCard;

void initCard(BingoCard *card) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->num = rand() % 75 + 1;
            card->called = 0;
            printf("%d ", card->num);
        }
        printf("\n");
    }
}

void printCard(BingoCard *card) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card->called) {
                printf("X ");
            } else {
                printf("%d ", card->num);
            }
        }
        printf("\n");
    }
}

int checkWin(BingoCard *card, int num) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card->num == num &&!card->called) {
                card->called = 1;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int numPlayers;
    printf("How many players? ");
    scanf("%d", &numPlayers);
    BingoCard cards[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        initCard(&cards[i]);
    }
    int numCalled = 0;
    int winner = -1;
    while (numCalled < 75) {
        int num = rand() % 75 + 1;
        printf("Called number: %d\n", num);
        for (int i = 0; i < numPlayers; i++) {
            if (checkWin(&cards[i], num)) {
                numCalled++;
                winner = i;
            }
        }
    }
    printf("We have a winner! Player %d wins!\n", winner + 1);
    return 0;
}