//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BINGO_NUMBERS 75
#define NUM_BINGO_ROWS 5
#define NUM_BINGO_COLUMNS 5

// Bingo card data structure
typedef struct bingo_card {
    int numbers[NUM_BINGO_NUMBERS];
    int marked[NUM_BINGO_NUMBERS];
} bingo_card;

// Function to generate a random bingo number
int generate_bingo_number() {
    return rand() % NUM_BINGO_NUMBERS + 1;
}

// Function to create a new bingo card
bingo_card* create_bingo_card() {
    bingo_card* card = malloc(sizeof(bingo_card));
    for (int i = 0; i < NUM_BINGO_NUMBERS; i++) {
        card->numbers[i] = 0;
        card->marked[i] = 0;
    }
    return card;
}

// Function to mark a number on a bingo card
void mark_number(bingo_card* card, int number) {
    for (int i = 0; i < NUM_BINGO_NUMBERS; i++) {
        if (card->numbers[i] == number) {
            card->marked[i] = 1;
        }
    }
}

// Function to check if a bingo card has won
int check_for_win(bingo_card* card) {
    // Check rows
    for (int i = 0; i < NUM_BINGO_ROWS; i++) {
        int count = 0;
        for (int j = 0; j < NUM_BINGO_COLUMNS; j++) {
            if (card->marked[i * NUM_BINGO_COLUMNS + j]) {
                count++;
            }
        }
        if (count == NUM_BINGO_COLUMNS) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < NUM_BINGO_COLUMNS; i++) {
        int count = 0;
        for (int j = 0; j < NUM_BINGO_ROWS; j++) {
            if (card->marked[j * NUM_BINGO_COLUMNS + i]) {
                count++;
            }
        }
        if (count == NUM_BINGO_ROWS) {
            return 1;
        }
    }

    // Check diagonals
    int count = 0;
    for (int i = 0; i < NUM_BINGO_ROWS; i++) {
        if (card->marked[i * NUM_BINGO_COLUMNS + i]) {
            count++;
        }
    }
    if (count == NUM_BINGO_ROWS) {
        return 1;
    }

    count = 0;
    for (int i = 0; i < NUM_BINGO_ROWS; i++) {
        if (card->marked[(NUM_BINGO_ROWS - 1 - i) * NUM_BINGO_COLUMNS + i]) {
            count++;
        }
    }
    if (count == NUM_BINGO_ROWS) {
        return 1;
    }

    return 0;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a new bingo card
    bingo_card* card = create_bingo_card();

    // Generate random numbers and mark them on the card
    for (int i = 0; i < NUM_BINGO_NUMBERS; i++) {
        int number = generate_bingo_number();
        mark_number(card, number);
    }

    // Check if the card has won
    int win = check_for_win(card);

    // Print the results
    if (win) {
        printf("You win!\n");
    } else {
        printf("You lose.\n");
    }

    // Free the bingo card
    free(card);

    return 0;
}