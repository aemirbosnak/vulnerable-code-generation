//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define NUM_COLUMNS 5
#define NUM_ROWS 5

typedef struct BingoCard {
    int **numbers;
    int winning_line;
    int winning_column;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->numbers = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->numbers[r] = (int *)malloc(NUM_COLUMNS * sizeof(int));
    }

    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLUMNS; c++) {
            card->numbers[r][c] = 0;
        }
    }

    card->winning_line = -1;
    card->winning_column = -1;
}

void markBingoCard(BingoCard *card, int number) {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLUMNS; c++) {
            if (card->numbers[r][c] == number) {
                card->numbers[r][c] = -1;
            }
        }
    }
}

int checkBingoCard(BingoCard *card) {
    // Check for winning line
    for (int r = 0; r < NUM_ROWS; r++) {
        int is_winning_line = 1;
        for (int c = 0; c < NUM_COLUMNS; c++) {
            if (card->numbers[r][c] != -1) {
                is_winning_line = 0;
            }
        }
        if (is_winning_line) {
            card->winning_line = r;
            return 1;
        }
    }

    // Check for winning column
    for (int c = 0; c < NUM_COLUMNS; c++) {
        int is_winning_column = 1;
        for (int r = 0; r < NUM_ROWS; r++) {
            if (card->numbers[r][c] != -1) {
                is_winning_column = 0;
            }
        }
        if (is_winning_column) {
            card->winning_column = c;
            return 1;
        }
    }

    // No winner
    return 0;
}

int main() {
    BingoCard card;
    initializeBingoCard(&card);

    // Mark the card
    markBingoCard(&card, 1);
    markBingoCard(&card, 2);
    markBingoCard(&card, 3);
    markBingoCard(&card, 4);
    markBingoCard(&card, 5);

    // Check for winner
    if (checkBingoCard(&card)) {
        printf("Congratulations! You won!");
    } else {
        printf("Sorry, no winner.");
    }

    return 0;
}