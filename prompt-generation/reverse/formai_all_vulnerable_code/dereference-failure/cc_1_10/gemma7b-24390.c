//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_BINGO_CARDS 20

typedef struct BingoCard {
    int **numbers;
    int rows;
    int columns;
    int current_balls;
} BingoCard;

BingoCard *createBingoCard(int rows, int columns) {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->rows = rows;
    card->columns = columns;
    card->numbers = malloc(rows * columns * sizeof(int));
    card->current_balls = 0;
    return card;
}

void addBallToCard(BingoCard *card, int number) {
    card->numbers[card->current_balls++] = number;
}

int checkIfWon(BingoCard *card) {
    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->columns; j++) {
            if (card->numbers[i * card->columns + j] == -1) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    BingoCard *cards[MAX_NUM_BINGO_CARDS];
    for (int i = 0; i < MAX_NUM_BINGO_CARDS; i++) {
        cards[i] = createBingoCard(5, 5);
    }

    // Simulate drawing balls
    for (int i = 0; i < 100; i++) {
        int number = rand() % 100 + 1;
        for (int j = 0; j < MAX_NUM_BINGO_CARDS; j++) {
            addBallToCard(cards[j], number);
        }
    }

    // Check if anyone won
    for (int i = 0; i < MAX_NUM_BINGO_CARDS; i++) {
        if (checkIfWon(cards[i]) == 1) {
            printf("Congratulations! You won!\n");
            break;
        }
    }

    return 0;
}