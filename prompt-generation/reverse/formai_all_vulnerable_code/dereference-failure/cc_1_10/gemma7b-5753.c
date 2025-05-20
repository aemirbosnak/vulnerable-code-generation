//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINGO_CARD_SIZE 5
#define MAX_NUM_BALLS 10

typedef struct BingoCard {
    int **numbers;
    int size;
    int is_winner;
} BingoCard;

BingoCard *createBingoCard(int size) {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numbers = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        card->numbers[i] = malloc(sizeof(int) * MAX_BINGO_CARD_SIZE);
    }
    card->size = size;
    card->is_winner = 0;
    return card;
}

void fillBingoCard(BingoCard *card) {
    for (int i = 0; i < card->size; i++) {
        for (int j = 0; j < MAX_BINGO_CARD_SIZE; j++) {
            card->numbers[i][j] = rand() % MAX_NUM_BALLS + 1;
        }
    }
}

int checkBingo(BingoCard *card) {
    // Check rows
    for (int i = 0; i < card->size; i++) {
        int is_winner = 1;
        for (int j = 0; j < MAX_BINGO_CARD_SIZE; j++) {
            if (card->numbers[i][j] != card->numbers[i][0]) {
                is_winner = 0;
            }
        }
        if (is_winner) {
            card->is_winner = 1;
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < MAX_BINGO_CARD_SIZE; j++) {
        int is_winner = 1;
        for (int i = 0; i < card->size; i++) {
            if (card->numbers[i][j] != card->numbers[0][j]) {
                is_winner = 0;
            }
        }
        if (is_winner) {
            card->is_winner = 1;
            return 1;
        }
    }

    // Check diagonals
    int is_winner = 1;
    for (int i = 0; i < card->size; i++) {
        for (int j = 0; j < MAX_BINGO_CARD_SIZE; j++) {
            if (card->numbers[i][j] != card->numbers[0][0]) {
                is_winner = 0;
            }
        }
    }
    if (is_winner) {
        card->is_winner = 1;
        return 1;
    }

    return 0;
}

int main() {
    BingoCard *card = createBingoCard(5);
    fillBingoCard(card);

    if (checkBingo(card)) {
        printf("You won!");
    } else {
        printf("You lost.");
    }

    return 0;
}