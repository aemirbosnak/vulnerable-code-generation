//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BINGO_COLUMNS 5
#define NUM_BINGO_ROWS 5

typedef struct BingoCard {
    int **numbers;
    int **marks;
    int win_row_num;
    int win_column_num;
} BingoCard;

BingoCard* createBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->numbers = malloc(NUM_BINGO_ROWS * sizeof(int*));
    for (int i = 0; i < NUM_BINGO_ROWS; i++) {
        card->numbers[i] = malloc(NUM_BINGO_COLUMNS * sizeof(int));
    }
    card->marks = malloc(NUM_BINGO_ROWS * sizeof(int*));
    for (int i = 0; i < NUM_BINGO_ROWS; i++) {
        card->marks[i] = malloc(NUM_BINGO_COLUMNS * sizeof(int));
    }
    card->win_row_num = -1;
    card->win_column_num = -1;
    return card;
}

void generateBingoNumbers(BingoCard* card) {
    for (int i = 0; i < NUM_BINGO_ROWS; i++) {
        for (int j = 0; j < NUM_BINGO_COLUMNS; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }
}

void markBingoNumber(BingoCard* card, int number) {
    for (int i = 0; i < NUM_BINGO_ROWS; i++) {
        for (int j = 0; j < NUM_BINGO_COLUMNS; j++) {
            if (card->numbers[i][j] == number) {
                card->marks[i][j] = 1;
            }
        }
    }
}

int checkBingoWin(BingoCard* card) {
    // Check for win in rows
    for (int i = 0; i < NUM_BINGO_ROWS; i++) {
        int win = 1;
        for (int j = 0; j < NUM_BINGO_COLUMNS; j++) {
            if (card->marks[i][j] != 1) {
                win = 0;
            }
        }
        if (win) {
            card->win_row_num = i;
            return 1;
        }
    }

    // Check for win in columns
    for (int j = 0; j < NUM_BINGO_COLUMNS; j++) {
        int win = 1;
        for (int i = 0; i < NUM_BINGO_ROWS; i++) {
            if (card->marks[i][j] != 1) {
                win = 0;
            }
        }
        if (win) {
            card->win_column_num = j;
            return 1;
        }
    }

    // Check for win in diagonals
    int diag_win = 1;
    for (int i = 0; i < NUM_BINGO_ROWS; i++) {
        for (int j = 0; j < NUM_BINGO_COLUMNS; j++) {
            if (card->marks[i][j] != 1) {
                diag_win = 0;
            }
        }
    }
    if (diag_win) {
        card->win_row_num = -2;
        card->win_column_num = -2;
        return 1;
    }

    return 0;
}

int main() {
    BingoCard* card = createBingoCard();
    generateBingoNumbers(card);

    // Simulate drawing numbers
    for (int i = 0; i < 20; i++) {
        int number = rand() % 90 + 1;
        markBingoNumber(card, number);
    }

    if (checkBingoWin(card)) {
        printf("Congratulations! You won!\n");
        printf("Win row: %d, Win column: %d\n", card->win_row_num, card->win_column_num);
    } else {
        printf("Sorry, you lost.\n");
    }

    free(card);

    return 0;
}