//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BALLS 10
#define MAX_NUM_ROWS 5
#define MAX_NUM_COLS 5

typedef struct BingoCard {
    int **numbers;
    int rows;
    int cols;
    int balls_left;
} BingoCard;

void initialize_bingo_card(BingoCard *card) {
    card->numbers = (int **)malloc(card->rows * sizeof(int *));
    for (int i = 0; i < card->rows; i++) {
        card->numbers[i] = (int *)malloc(card->cols * sizeof(int));
    }

    card->balls_left = MAX_NUM_BALLS;
}

void generate_bingo_card(BingoCard *card) {
    srand(time(NULL));

    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            card->numbers[r][c] = rand() % MAX_NUM_BALLS + 1;
        }
    }
}

void mark_bingo_card(BingoCard *card, int number) {
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            if (card->numbers[r][c] == number) {
                card->numbers[r][c] = -1;
            }
        }
    }
}

int check_bingo(BingoCard *card) {
    for (int r = 0; r < card->rows; r++) {
        if (card->numbers[r][0] == -1 && card->numbers[r][1] == -1 && card->numbers[r][2] == -1) {
            return 1;
        }
    }

    for (int c = 0; c < card->cols; c++) {
        if (card->numbers[0][c] == -1 && card->numbers[1][c] == -1 && card->numbers[2][c] == -1) {
            return 1;
        }
    }

    if (card->numbers[0][0] == -1 && card->numbers[1][1] == -1 && card->numbers[2][2] == -1) {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard card;
    initialize_bingo_card(&card);
    generate_bingo_card(&card);

    // Simulate drawing balls
    for (int i = 0; i < MAX_NUM_BALLS; i++) {
        int number = rand() % MAX_NUM_BALLS + 1;
        mark_bingo_card(&card, number);

        if (check_bingo(&card)) {
            printf("Bingo!\n");
            break;
        }
    }

    return 0;
}