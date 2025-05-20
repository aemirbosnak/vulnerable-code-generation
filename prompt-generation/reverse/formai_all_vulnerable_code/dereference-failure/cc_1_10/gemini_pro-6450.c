//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bingo card dimensions
#define CARD_ROWS 5
#define CARD_COLS 5

// Create a bingo card
int** create_card() {
    // Allocate memory for the card
    int** card = (int**)malloc(sizeof(int*) * CARD_ROWS);
    for (int i = 0; i < CARD_ROWS; i++) {
        card[i] = (int*)malloc(sizeof(int) * CARD_COLS);
    }

    // Fill the card with random numbers
    srand(time(NULL));
    for (int i = 0; i < CARD_ROWS; i++) {
        for (int j = 0; j < CARD_COLS; j++) {
            card[i][j] = rand() % 75 + 1;
        }
    }

    return card;
}

// Print a bingo card
void print_card(int** card) {
    for (int i = 0; i < CARD_ROWS; i++) {
        for (int j = 0; j < CARD_COLS; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
}

// Check if a number is on a bingo card
int check_number(int** card, int number) {
    for (int i = 0; i < CARD_ROWS; i++) {
        for (int j = 0; j < CARD_COLS; j++) {
            if (card[i][j] == number) {
                return 1;
            }
        }
    }

    return 0;
}

// Mark a number on a bingo card
void mark_number(int** card, int number) {
    for (int i = 0; i < CARD_ROWS; i++) {
        for (int j = 0; j < CARD_COLS; j++) {
            if (card[i][j] == number) {
                card[i][j] = -1;
            }
        }
    }
}

// Check if a bingo card has won
int check_bingo(int** card) {
    // Check rows
    for (int i = 0; i < CARD_ROWS; i++) {
        int count = 0;
        for (int j = 0; j < CARD_COLS; j++) {
            if (card[i][j] == -1) {
                count++;
            }
        }
        if (count == CARD_COLS) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < CARD_COLS; i++) {
        int count = 0;
        for (int j = 0; j < CARD_ROWS; j++) {
            if (card[j][i] == -1) {
                count++;
            }
        }
        if (count == CARD_ROWS) {
            return 1;
        }
    }

    // Check diagonals
    int count_diag1 = 0;
    int count_diag2 = 0;
    for (int i = 0; i < CARD_ROWS; i++) {
        if (card[i][i] == -1) {
            count_diag1++;
        }
        if (card[i][CARD_COLS - i - 1] == -1) {
            count_diag2++;
        }
    }
    if (count_diag1 == CARD_ROWS || count_diag2 == CARD_ROWS) {
        return 1;
    }

    return 0;
}

// Play a game of bingo
void play_bingo() {
    // Create a bingo card
    int** card = create_card();

    // Print the bingo card
    printf("Your bingo card:\n");
    print_card(card);

    // Generate random numbers and check if they are on the card
    int number;
    while (1) {
        number = rand() % 75 + 1;
        printf("Number drawn: %d\n", number);

        if (check_number(card, number)) {
            // Mark the number on the card
            mark_number(card, number);

            // Print the updated card
            printf("Updated bingo card:\n");
            print_card(card);

            // Check if the card has won
            if (check_bingo(card)) {
                printf("BINGO! You win!\n");
                break;
            }
        }
    }

    // Free the memory allocated for the card
    for (int i = 0; i < CARD_ROWS; i++) {
        free(card[i]);
    }
    free(card);
}

// Main function
int main() {
    // Play a game of bingo
    play_bingo();

    return 0;
}