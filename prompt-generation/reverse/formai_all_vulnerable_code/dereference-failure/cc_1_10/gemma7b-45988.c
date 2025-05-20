//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 20

typedef struct BingoCard {
    int numbers[MAX_NUM];
    int marked[MAX_NUM];
    int wins;
} BingoCard;

BingoCard *createBingoCard() {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numbers[0] = 0;
    for (int i = 1; i < MAX_NUM; i++) {
        card->numbers[i] = i;
    }
    for (int i = 0; i < MAX_NUM; i++) {
        card->marked[i] = 0;
    }
    card->wins = 0;
    return card;
}

void markCard(BingoCard *card, int number) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->numbers[i] == number && card->marked[i] == 0) {
            card->marked[i] = 1;
        }
    }
}

int checkWin(BingoCard *card) {
    // Check rows
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->marked[i] == 5) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < MAX_NUM; i++) {
        int columnWins = 0;
        for (int j = 0; j < MAX_NUM; j++) {
            if (card->marked[j] == 1 && card->marked[j] == card->marked[i]) {
                columnWins++;
            }
        }
        if (columnWins == 5) {
            return 1;
        }
    }

    // Check diagonals
    if (card->marked[0] == 1 && card->marked[6] == 1 && card->marked[12] == 1) {
        return 1;
    }
    if (card->marked[4] == 1 && card->marked[8] == 1 && card->marked[16] == 1) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));

    BingoCard *card = createBingoCard();
    markCard(card, rand() % MAX_NUM);
    markCard(card, rand() % MAX_NUM);
    markCard(card, rand() % MAX_NUM);
    markCard(card, rand() % MAX_NUM);
    markCard(card, rand() % MAX_NUM);

    if (checkWin(card)) {
        printf("Congratulations! You won!\n");
        card->wins++;
    } else {
        printf("Sorry, you lost.\n");
    }

    free(card);

    return 0;
}