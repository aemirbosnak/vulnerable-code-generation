//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUM_BALLS 30

typedef struct BingoCard {
    int **numbers;
    int num_rows;
    int num_cols;
    int winning_row;
    int winning_col;
    int winning_diagonal;
} BingoCard;

BingoCard *createBingoCard(int num_rows, int num_cols) {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numbers = malloc(num_rows * num_cols * sizeof(int));
    card->num_rows = num_rows;
    card->num_cols = num_cols;
    card->winning_row = -1;
    card->winning_col = -1;
    card->winning_diagonal = -1;
    return card;
}

void generateBingoBall(BingoCard *card) {
    int num_balls_drawn = 0;
    while (num_balls_drawn < MAX_NUM_BALLS) {
        int number = rand() % MAX_BINGO_CARD_SIZE + 1;
        if (card->numbers[number] == 0) {
            card->numbers[number] = 1;
            num_balls_drawn++;
        }
    }
}

int checkBingo(BingoCard *card) {
    // Check rows
    for (int r = 0; r < card->num_rows; r++) {
        int is_winner = 1;
        for (int c = 0; c < card->num_cols; c++) {
            if (card->numbers[r][c] == 0) {
                is_winner = 0;
            }
        }
        if (is_winner) {
            card->winning_row = r;
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < card->num_cols; c++) {
        int is_winner = 1;
        for (int r = 0; r < card->num_rows; r++) {
            if (card->numbers[r][c] == 0) {
                is_winner = 0;
            }
        }
        if (is_winner) {
            card->winning_col = c;
            return 1;
        }
    }

    // Check diagonal
    if (card->num_rows == card->num_cols) {
        int is_winner = 1;
        for (int d = 0; d < card->num_rows; d++) {
            if (card->numbers[d][d] == 0) {
                is_winner = 0;
            }
        }
        if (is_winner) {
            card->winning_diagonal = 1;
            return 1;
        }
    }

    return 0;
}

int main() {
    BingoCard *card = createBingoCard(5, 5);
    generateBingoBall(card);
    checkBingo(card);

    if (card->winning_row != -1) {
        printf("Winner: Row %d\n", card->winning_row);
    } else if (card->winning_col != -1) {
        printf("Winner: Column %d\n", card->winning_col);
    } else if (card->winning_diagonal != -1) {
        printf("Winner: Diagonal\n");
    } else {
        printf("No winner\n");
    }

    return 0;
}