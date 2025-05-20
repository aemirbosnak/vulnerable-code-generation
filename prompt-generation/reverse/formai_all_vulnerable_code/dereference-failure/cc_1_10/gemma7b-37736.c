//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BINGO_ROWS 5
#define NUM_BINGO_COLS 5

typedef struct BingoCard {
    char **numbers;
    int wins;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->numbers = malloc(NUM_BINGO_ROWS * sizeof(char *));
    for (int r = 0; r < NUM_BINGO_ROWS; r++) {
        card->numbers[r] = malloc(NUM_BINGO_COLS * sizeof(char));
        for (int c = 0; c < NUM_BINGO_COLS; c++) {
            card->numbers[r][c] = ' ';
        }
    }
    card->wins = 0;
}

void markBingoCard(BingoCard *card, char number) {
    for (int r = 0; r < NUM_BINGO_ROWS; r++) {
        for (int c = 0; c < NUM_BINGO_COLS; c++) {
            if (card->numbers[r][c] == number) {
                card->numbers[r][c] = 'X';
            }
        }
    }
}

int checkBingoCard(BingoCard *card) {
    // Check rows
    for (int r = 0; r < NUM_BINGO_ROWS; r++) {
        if (card->numbers[r][0] == 'X' && card->numbers[r][1] == 'X' && card->numbers[r][2] == 'X' && card->numbers[r][3] == 'X' && card->numbers[r][4] == 'X') {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < NUM_BINGO_COLS; c++) {
        if (card->numbers[0][c] == 'X' && card->numbers[1][c] == 'X' && card->numbers[2][c] == 'X' && card->numbers[3][c] == 'X' && card->numbers[4][c] == 'X') {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0][0] == 'X' && card->numbers[1][1] == 'X' && card->numbers[2][2] == 'X' && card->numbers[3][3] == 'X' && card->numbers[4][4] == 'X') {
        return 1;
    }

    // No bingo
    return 0;
}

int main() {
    BingoCard *card = malloc(sizeof(BingoCard));
    initializeBingoCard(card);

    // Play the game
    markBingoCard(card, 'A');
    markBingoCard(card, 'B');
    markBingoCard(card, 'C');
    markBingoCard(card, 'D');
    markBingoCard(card, 'E');

    if (checkBingoCard(card)) {
        printf("You win!");
        card->wins++;
    } else {
        printf("Sorry, no win.");
    }

    printf("Wins: %d", card->wins);

    return 0;
}