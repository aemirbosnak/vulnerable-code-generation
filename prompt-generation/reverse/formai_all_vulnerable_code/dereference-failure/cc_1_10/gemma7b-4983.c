//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BINGO_COLUMNS 5
#define NUM_BINGO_ROWS 5

typedef struct BingoCard {
    int **cards;
    int wins;
    time_t last_win_time;
} BingoCard;

void initializeBingoCard(BingoCard *card);
void generateBingoNumbers(BingoCard *card);
void checkBingo(BingoCard *card);

int main() {
    BingoCard *card = malloc(sizeof(BingoCard));
    initializeBingoCard(card);
    generateBingoNumbers(card);
    checkBingo(card);

    free(card);
    return 0;
}

void initializeBingoCard(BingoCard *card) {
    card->cards = malloc(NUM_BINGO_ROWS * sizeof(int *));
    for (int i = 0; i < NUM_BINGO_ROWS; i++) {
        card->cards[i] = malloc(NUM_BINGO_COLUMNS * sizeof(int));
    }

    card->wins = 0;
    card->last_win_time = time(NULL);
}

void generateBingoNumbers(BingoCard *card) {
    // Generate random numbers for each cell in the card
    for (int i = 0; i < NUM_BINGO_ROWS; i++) {
        for (int j = 0; j < NUM_BINGO_COLUMNS; j++) {
            card->cards[i][j] = rand() % 90 + 1;
        }
    }
}

void checkBingo(BingoCard *card) {
    // Check if the card has won
    if (card->wins == 0) {
        for (int i = 0; i < NUM_BINGO_ROWS; i++) {
            for (int j = 0; j < NUM_BINGO_COLUMNS; j++) {
                // Check if the number is marked and if the row or column has won
                if (card->cards[i][j] == card->cards[i][0] && card->cards[i][j] == card->cards[0][j]) {
                    card->wins++;
                    card->last_win_time = time(NULL);
                }
            }
        }
    }
}