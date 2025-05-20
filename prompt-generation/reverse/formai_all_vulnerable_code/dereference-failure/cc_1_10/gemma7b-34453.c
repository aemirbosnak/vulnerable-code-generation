//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
    int **numbers;
    int wins;
    char **marked;
} BingoCard;

void initializeBingoCard(BingoCard *card) {
    card->numbers = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->numbers[r] = (int *)malloc(NUM_COLS * sizeof(int));
        for (int c = 0; c < NUM_COLS; c++) {
            card->numbers[r][c] = 0;
        }
    }

    card->marked = (char **)malloc(NUM_ROWS * sizeof(char *));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->marked[r] = (char *)malloc(NUM_COLS * sizeof(char));
        for (int c = 0; c < NUM_COLS; c++) {
            card->marked[r][c] = ' ';
        }
    }

    card->wins = 0;
}

void markBingoCard(BingoCard *card, int number) {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            if (card->numbers[r][c] == number) {
                card->marked[r][c] = 'X';
            }
        }
    }
}

int checkBingo(BingoCard *card) {
    // Check rows
    for (int r = 0; r < NUM_ROWS; r++) {
        if (card->marked[r][0] == 'X' && card->marked[r][1] == 'X' && card->marked[r][2] == 'X' && card->marked[r][3] == 'X' && card->marked[r][4] == 'X') {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < NUM_COLS; c++) {
        if (card->marked[0][c] == 'X' && card->marked[1][c] == 'X' && card->marked[2][c] == 'X' && card->marked[3][c] == 'X' && card->marked[4][c] == 'X') {
            return 1;
        }
    }

    // Check diagonals
    if (card->marked[0][0] == 'X' && card->marked[1][1] == 'X' && card->marked[2][2] == 'X' && card->marked[3][3] == 'X' && card->marked[4][4] == 'X') {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard *card = malloc(sizeof(BingoCard));
    initializeBingoCard(card);

    // Play the game
    for (int i = 0; i < 10; i++) {
        markBingoCard(card, rand() % 50);
        if (checkBingo(card)) {
            card->wins++;
            printf("Congratulations! You won!\n");
            break;
        }
    }

    // Free the memory
    free(card->numbers);
    free(card->marked);
    free(card);

    return 0;
}