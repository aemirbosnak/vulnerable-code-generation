//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 25
#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
    int **cards;
    int current_number;
    int wins;
} BingoCard;

void initialize_bingo_card(BingoCard *card) {
    card->cards = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->cards[r] = (int *)malloc(NUM_COLS * sizeof(int));
        for (int c = 0; c < NUM_COLS; c++) {
            card->cards[r][c] = 0;
        }
    }
    card->current_number = -1;
    card->wins = 0;
}

void generate_bingo_number(BingoCard *card) {
    card->current_number = rand() % MAX_NUM + 1;
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            if (card->cards[r][c] == card->current_number) {
                card->cards[r][c] = -1;
            }
        }
    }
}

int check_bingo(BingoCard *card) {
    for (int r = 0; r < NUM_ROWS; r++) {
        if (card->cards[r][0] == -1 && card->cards[r][1] == -1 && card->cards[r][2] == -1 && card->cards[r][3] == -1 && card->cards[r][4] == -1) {
            return 1;
        }
    }

    for (int c = 0; c < NUM_COLS; c++) {
        if (card->cards[0][c] == -1 && card->cards[1][c] == -1 && card->cards[2][c] == -1 && card->cards[3][c] == -1 && card->cards[4][c] == -1) {
            return 1;
        }
    }

    if (card->cards[0][0] == -1 && card->cards[1][1] == -1 && card->cards[2][2] == -1 && card->cards[3][3] == -1 && card->cards[4][4] == -1) {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard card;
    initialize_bingo_card(&card);

    for (int i = 0; i < 10; i++) {
        generate_bingo_number(&card);
        if (check_bingo(&card)) {
            card.wins++;
            printf("Bingo! You won %d times!\n", card.wins);
        }
    }

    return 0;
}