//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_BINGO_CARDS 10

typedef struct BingoCard {
    int **numbers;
    int num_rows;
    int num_cols;
} BingoCard;

void initializeBingoCard(BingoCard *card, int rows, int cols) {
    card->num_rows = rows;
    card->num_cols = cols;
    card->numbers = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        card->numbers[i] = (int *)malloc(sizeof(int) * cols);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            card->numbers[i][j] = 0;
        }
    }
}

void markBingoCard(BingoCard *card, int num) {
    for (int i = 0; i < card->num_rows; i++) {
        for (int j = 0; j < card->num_cols; j++) {
            if (card->numbers[i][j] == num) {
                card->numbers[i][j] = -1;
            }
        }
    }
}

int checkBingo(BingoCard *card) {
    // Check rows
    for (int i = 0; i < card->num_rows; i++) {
        int is_bingo = 1;
        for (int j = 0; j < card->num_cols; j++) {
            if (card->numbers[i][j] != -1) {
                is_bingo = 0;
            }
        }
        if (is_bingo) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < card->num_cols; j++) {
        int is_bingo = 1;
        for (int i = 0; i < card->num_rows; i++) {
            if (card->numbers[i][j] != -1) {
                is_bingo = 0;
            }
        }
        if (is_bingo) {
            return 1;
        }
    }

    // Check diagonals
    if (card->num_rows == card->num_cols) {
        int is_bingo = 1;
        for (int i = 0; i < card->num_rows; i++) {
            for (int j = 0; j < card->num_cols; j++) {
                if (card->numbers[i][j] != -1) {
                    is_bingo = 0;
                }
            }
        }
        if (is_bingo) {
            return 1;
        }
    }

    return 0;
}

int main() {
    BingoCard *cards[MAX_NUM_BINGO_CARDS];
    for (int i = 0; i < MAX_NUM_BINGO_CARDS; i++) {
        initializeBingoCard(&cards[i], 5, 5);
    }

    // Generate some random numbers
    int num_drawn = 0;
    int numbers[MAX_NUM_BINGO_CARDS] = {0};
    for (int i = 0; i < MAX_NUM_BINGO_CARDS; i++) {
        numbers[i] = rand() % 25 + 1;
    }

    // Mark the cards
    for (int i = 0; i < MAX_NUM_BINGO_CARDS; i++) {
        markBingoCard(&cards[i], numbers[i]);
    }

    // Check if anyone has won
    for (int i = 0; i < MAX_NUM_BINGO_CARDS; i++) {
        if (checkBingo(&cards[i])) {
            printf("Player %d has won!", i);
            break;
        }
    }

    return 0;
}