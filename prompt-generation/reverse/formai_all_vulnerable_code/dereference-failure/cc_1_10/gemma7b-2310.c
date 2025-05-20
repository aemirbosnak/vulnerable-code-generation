//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUM_BALLS 25

typedef struct BingoCard {
    int **numbers;
    int rows;
    int columns;
    int balls_won;
} BingoCard;

void create_bingo_card(BingoCard *card) {
    card->rows = rand() % MAX_BINGO_CARD_SIZE + 1;
    card->columns = rand() % MAX_BINGO_CARD_SIZE + 1;
    card->numbers = (int **)malloc(card->rows * sizeof(int *));
    for (int r = 0; r < card->rows; r++) {
        card->numbers[r] = (int *)malloc(card->columns * sizeof(int));
    }

    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->columns; c++) {
            card->numbers[r][c] = rand() % MAX_NUM_BALLS + 1;
        }
    }
}

void play_bingo(BingoCard *card) {
    int ball_drawn = 0;
    while (!card->balls_won) {
        int number_drawn = rand() % MAX_NUM_BALLS + 1;
        for (int r = 0; r < card->rows; r++) {
            for (int c = 0; c < card->columns; c++) {
                if (card->numbers[r][c] == number_drawn) {
                    card->numbers[r][c] = -1;
                    ball_drawn++;
                }
            }
        }

        if (ball_drawn % 5 == 0) {
            printf("Ball drawn: %d\n", number_drawn);
        }

        if (card->balls_won) {
            printf("Winner! You won with %d balls!\n", ball_drawn);
        }
    }
}

int main() {
    BingoCard card;
    create_bingo_card(&card);
    play_bingo(&card);

    return 0;
}