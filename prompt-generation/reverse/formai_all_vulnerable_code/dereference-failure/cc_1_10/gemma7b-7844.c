//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 20

typedef struct BingoCard {
    int numbers[MAX_NUM];
    int marked[MAX_NUM];
    int numWins;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    for (int i = 0; i < MAX_NUM; i++) {
        card->numbers[i] = -1;
        card->marked[i] = 0;
    }
    card->numWins = 0;
}

void markBingoCard(BingoCard *card, int number) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->numbers[i] == number && !card->marked[i]) {
            card->marked[i] = 1;
        }
    }
}

int checkBingoCard(BingoCard *card) {
    // Check rows
    for (int i = 0; i < MAX_NUM / 5; i++) {
        if (card->marked[i * 5] && card->marked[i * 5 + 1] && card->marked[i * 5 + 2] && card->marked[i * 5 + 3] && card->marked[i * 5 + 4]) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->marked[i] && card->marked[i + MAX_NUM] && card->marked[i + 2 * MAX_NUM] && card->marked[i + 3 * MAX_NUM] && card->marked[i + 4 * MAX_NUM]) {
            return 1;
        }
    }

    // Check diagonals
    if (card->marked[0] && card->marked[MAX_NUM - 1] && card->marked[MAX_NUM / 2] && card->marked[MAX_NUM / 2 - 1] && card->marked[MAX_NUM / 2 + 1]) {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard card;
    initializeBingoCard(&card);

    // Generate numbers
    srand(time(NULL));
    for (int i = 0; i < MAX_NUM; i++) {
        card.numbers[i] = rand() % MAX_NUM + 1;
    }

    // Mark numbers
    markBingoCard(&card, 12);
    markBingoCard(&card, 15);
    markBingoCard(&card, 19);
    markBingoCard(&card, 20);

    // Check for bingo
    if (checkBingoCard(&card)) {
        printf("Bingo! You won!");
    } else {
        printf("Sorry, you lose.");
    }

    return 0;
}