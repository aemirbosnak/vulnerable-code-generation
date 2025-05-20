//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINGO_CARDS 5

typedef struct BingoCard {
    int **numbers;
    int rows;
    int columns;
    int wins;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->rows = 5;
    card->columns = 5;
    card->numbers = (int **)malloc(sizeof(int *) * card->rows);
    for (int r = 0; r < card->rows; r++) {
        card->numbers[r] = (int *)malloc(sizeof(int) * card->columns);
    }
    card->wins = 0;
}

void populateBingoCard(BingoCard *card) {
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->columns; c++) {
            card->numbers[r][c] = rand() % 90 + 1;
        }
    }
}

int checkBingo(BingoCard *card) {
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->columns; c++) {
            if (card->numbers[r][c] == card->numbers[r][0] && card->numbers[r][c] == card->numbers[0][c]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    BingoCard cards[MAX_BINGO_CARDS];
    for (int i = 0; i < MAX_BINGO_CARDS; i++) {
        initializeBingoCard(&cards[i]);
        populateBingoCard(&cards[i]);
    }

    // Simulate drawing numbers
    for (int n = 0; n < 20; n++) {
        int number = rand() % 90 + 1;
        for (int i = 0; i < MAX_BINGO_CARDS; i++) {
            for (int r = 0; r < cards[i].rows; r++) {
                for (int c = 0; c < cards[i].columns; c++) {
                    if (cards[i].numbers[r][c] == number) {
                        cards[i].numbers[r][c] = -1;
                    }
                }
            }
        }

        // Check if anyone won
        for (int i = 0; i < MAX_BINGO_CARDS; i++) {
            if (checkBingo(&cards[i])) {
                cards[i].wins++;
                printf("Bingo! Card %d won!", i + 1);
                printf("\n");
            }
        }
    }

    return 0;
}