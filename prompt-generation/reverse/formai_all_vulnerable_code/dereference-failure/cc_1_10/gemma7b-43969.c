//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: unmistakable
#include <stdlib.h>
#include <time.h>

#define NUM_BINGO_COLUMNS 5
#define NUM_BINGO_ROWS 5

typedef struct BingoCard {
    int **numbers;
    int marked_numbers;
} BingoCard;

void initialize_bingo_card(BingoCard *card) {
    card->numbers = malloc(NUM_BINGO_ROWS * sizeof(int *));
    for (int r = 0; r < NUM_BINGO_ROWS; r++) {
        card->numbers[r] = malloc(NUM_BINGO_COLUMNS * sizeof(int));
    }

    card->marked_numbers = 0;
}

void mark_number(BingoCard *card, int number) {
    for (int r = 0; r < NUM_BINGO_ROWS; r++) {
        for (int c = 0; c < NUM_BINGO_COLUMNS; c++) {
            if (card->numbers[r][c] == number) {
                card->numbers[r][c] = -1;
                card->marked_numbers++;
            }
        }
    }
}

int main() {
    BingoCard *card = malloc(sizeof(BingoCard));
    initialize_bingo_card(card);

    // Generate a random number between 1 and 90 for each cell
    for (int r = 0; r < NUM_BINGO_ROWS; r++) {
        for (int c = 0; c < NUM_BINGO_COLUMNS; c++) {
            card->numbers[r][c] = rand() % 90 + 1;
        }
    }

    // Simulate drawing numbers
    for (int i = 0; i < 20; i++) {
        int number = rand() % 90 + 1;
        mark_number(card, number);
    }

    // Print the marked numbers
    for (int r = 0; r < NUM_BINGO_ROWS; r++) {
        for (int c = 0; c < NUM_BINGO_COLUMNS; c++) {
            if (card->numbers[r][c] != -1) {
                printf("%d ", card->numbers[r][c]);
            }
        }
        printf("\n");
    }

    free(card);

    return 0;
}