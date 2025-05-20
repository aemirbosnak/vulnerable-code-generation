//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct BingoCard {
    int **numbers;
    int cards_won;
} BingoCard;

void initialize_bingo_card(BingoCard *card) {
    card->numbers = (int **)malloc(NUM_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_ROWS; r++) {
        card->numbers[r] = (int *)malloc(NUM_COLS * sizeof(int));
        for (int c = 0; c < NUM_COLS; c++) {
            card->numbers[r][c] = 0;
        }
    }
    card->cards_won = 0;
}

void generate_bingo_card(BingoCard *card) {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            card->numbers[r][c] = rand() % 90 + 1;
        }
    }
}

void check_bingo(BingoCard *card) {
    for (int r = 0; r < NUM_ROWS; r++) {
        for (int c = 0; c < NUM_COLS; c++) {
            if (card->numbers[r][c] == card->numbers[r][0]) {
                card->numbers[r][c] = -1;
            }
        }
    }

    if (card->numbers[0][0] == -1) {
        card->cards_won++;
    }
}

int main() {
    BingoCard card;
    initialize_bingo_card(&card);
    generate_bingo_card(&card);

    for (int i = 0; i < 10; i++) {
        check_bingo(&card);
    }

    printf("Number of cards won: %d\n", card.cards_won);

    return 0;
}