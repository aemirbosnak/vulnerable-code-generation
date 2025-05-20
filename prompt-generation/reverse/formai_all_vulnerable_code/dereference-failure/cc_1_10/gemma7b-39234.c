//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5

typedef struct BingoCard {
    int **numbers;
    int rows;
    int cols;
    int winning_number;
} BingoCard;

void initialize_bingo_card(BingoCard *card) {
    card->numbers = malloc(card->rows * sizeof(int *));
    for (int r = 0; r < card->rows; r++) {
        card->numbers[r] = malloc(card->cols * sizeof(int));
    }

    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            card->numbers[r][c] = rand() % 90 + 1;
        }
    }
}

void check_bingo(BingoCard *card) {
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            if (card->numbers[r][c] == card->winning_number) {
                card->numbers[r][c] = -1;
            }
        }
    }

    if (card->winning_number != -1) {
        printf("Congratulations, you won!\n");
    } else {
        printf("Sorry, you lost.\n");
    }
}

int main() {
    BingoCard card;
    card.rows = MAX_ROWS;
    card.cols = MAX_COLS;

    initialize_bingo_card(&card);

    card.winning_number = rand() % 90 + 1;

    check_bingo(&card);

    return 0;
}