//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 5

typedef struct BingoCard {
    int numbers[MAX_NUM];
    int marked[MAX_NUM];
    int wins;
} BingoCard;

BingoCard *createBingoCard() {
    BingoCard *card = (BingoCard *)malloc(sizeof(BingoCard));
    card->numbers[0] = rand() % MAX_NUM + 1;
    card->numbers[1] = rand() % MAX_NUM + 1;
    card->numbers[2] = rand() % MAX_NUM + 1;
    card->numbers[3] = rand() % MAX_NUM + 1;
    card->numbers[4] = rand() % MAX_NUM + 1;
    card->marked[0] = card->marked[1] = card->marked[2] = card->marked[3] = card->marked[4] = 0;
    card->wins = 0;
    return card;
}

void markCard(BingoCard *card, int num) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->numbers[i] == num && card->marked[i] == 0) {
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
    for (int j = 0; j < MAX_NUM; j++) {
        int wins = 0;
        for (int i = 0; i < MAX_NUM; i++) {
            if (card->marked[i] == 1 && card->numbers[i] == card->numbers[j]) {
                wins++;
            }
        }
        if (wins == 5) {
            return 1;
        }
    }

    // Check diagonals
    if (card->marked[0] == 1 && card->marked[2] == 1 && card->marked[4] == 1) {
        return 1;
    }
    if (card->marked[1] == 1 && card->marked[3] == 1 && card->marked[5] == 1) {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard *card = createBingoCard();

    // Draw numbers
    for (int i = 0; i < 20; i++) {
        int num = rand() % MAX_NUM + 1;
        markCard(card, num);
    }

    // Check for win
    if (checkWin(card)) {
        printf("Congratulations! You won!\n");
        card->wins++;
    } else {
        printf("Sorry, you lost.\n");
    }

    // Print wins
    printf("Your total wins: %d\n", card->wins);

    return 0;
}