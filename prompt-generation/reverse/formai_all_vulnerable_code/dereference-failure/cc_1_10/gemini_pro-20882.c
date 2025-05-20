//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bingo card dimensions
#define CARD_ROWS 5
#define CARD_COLS 5

// Number range for bingo balls
#define MIN_NUM 1
#define MAX_NUM 75

// Bingo card data structure
typedef struct {
    int numbers[CARD_ROWS][CARD_COLS];
    int marked[CARD_ROWS][CARD_COLS];
} BingoCard;

// Function to create a new bingo card
BingoCard* create_card() {
    BingoCard* card = malloc(sizeof(BingoCard));

    // Generate random numbers for the card
    for (int i = 0; i < CARD_ROWS; i++) {
        for (int j = 0; j < CARD_COLS; j++) {
            card->numbers[i][j] = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        }
    }

    // Initialize the marked array to all zeros
    for (int i = 0; i < CARD_ROWS; i++) {
        for (int j = 0; j < CARD_COLS; j++) {
            card->marked[i][j] = 0;
        }
    }

    return card;
}

// Function to print a bingo card
void print_card(BingoCard* card) {
    for (int i = 0; i < CARD_ROWS; i++) {
        for (int j = 0; j < CARD_COLS; j++) {
            printf("%2d ", card->numbers[i][j]);
        }
        printf("\n");
    }
}

// Function to mark a number on a bingo card
void mark_number(BingoCard* card, int number) {
    for (int i = 0; i < CARD_ROWS; i++) {
        for (int j = 0; j < CARD_COLS; j++) {
            if (card->numbers[i][j] == number) {
                card->marked[i][j] = 1;
            }
        }
    }
}

// Function to check if a bingo card has won
int check_win(BingoCard* card) {
    // Check for horizontal wins
    for (int i = 0; i < CARD_ROWS; i++) {
        int win = 1;
        for (int j = 0; j < CARD_COLS; j++) {
            if (!card->marked[i][j]) {
                win = 0;
            }
        }
        if (win) {
            return 1;
        }
    }

    // Check for vertical wins
    for (int j = 0; j < CARD_COLS; j++) {
        int win = 1;
        for (int i = 0; i < CARD_ROWS; i++) {
            if (!card->marked[i][j]) {
                win = 0;
            }
        }
        if (win) {
            return 1;
        }
    }

    // Check for diagonal wins
    int win1 = 1;
    int win2 = 1;
    for (int i = 0; i < CARD_ROWS; i++) {
        if (!card->marked[i][i]) {
            win1 = 0;
        }
        if (!card->marked[i][CARD_COLS - i - 1]) {
            win2 = 0;
        }
    }
    if (win1 || win2) {
        return 1;
    }

    return 0;
}

// Main game loop
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a new bingo card
    BingoCard* card = create_card();

    // Print the bingo card
    printf("Your bingo card:\n");
    print_card(card);

    // Draw bingo balls until someone wins
    int drawn_numbers[MAX_NUM];
    int num_drawn = 0;
    int winner = 0;
    while (!winner) {
        // Draw a new bingo ball
        int number = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;

        // Check if the number has already been drawn
        int already_drawn = 0;
        for (int i = 0; i < num_drawn; i++) {
            if (drawn_numbers[i] == number) {
                already_drawn = 1;
            }
        }

        // If the number has not been drawn, add it to the list of drawn numbers and mark it on the cards
        if (!already_drawn) {
            drawn_numbers[num_drawn++] = number;
            printf("Drawn number: %d\n", number);
            mark_number(card, number);

            // Check if the card has won
            if (check_win(card)) {
                winner = 1;
            }
        }
    }

    // Print the winning card
    printf("Winning card:\n");
    print_card(card);

    return 0;
}