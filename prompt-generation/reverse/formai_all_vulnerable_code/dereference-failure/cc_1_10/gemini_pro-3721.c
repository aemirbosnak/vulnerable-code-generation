//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rows and columns in the bingo card
#define ROWS 5
#define COLS 5

// Define the range of numbers that can be drawn
#define MIN_NUM 1
#define MAX_NUM 75

// Define the number of balls to draw
#define NUM_BALLS 75

// Define the data structure for a bingo card
typedef struct {
    int numbers[ROWS][COLS];
    int marked[ROWS][COLS];
} BingoCard;

// Create a new bingo card
BingoCard* create_card() {
    BingoCard* card = malloc(sizeof(BingoCard));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            card->numbers[i][j] = 0;
            card->marked[i][j] = 0;
        }
    }
    return card;
}

// Free a bingo card
void free_card(BingoCard* card) {
    free(card);
}

// Generate a random number within a given range
int random_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Fill a bingo card with random numbers
void fill_card(BingoCard* card) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int number;
            do {
                number = random_num(MIN_NUM, MAX_NUM);
            } while (card->numbers[i][j] != 0);
            card->numbers[i][j] = number;
        }
    }
}

// Print a bingo card
void print_card(BingoCard* card) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", card->numbers[i][j]);
        }
        printf("\n");
    }
}

// Mark a number on a bingo card
void mark_number(BingoCard* card, int number) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card->numbers[i][j] == number) {
                card->marked[i][j] = 1;
            }
        }
    }
}

// Check if a bingo card has won
int check_win(BingoCard* card) {
    // Check for a horizontal win
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (card->marked[i][j] == 1) {
                count++;
            }
        }
        if (count == COLS) {
            return 1;
        }
    }

    // Check for a vertical win
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (card->marked[i][j] == 1) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1;
        }
    }

    // Check for a diagonal win
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (card->marked[i][i] == 1) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }

    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (card->marked[i][ROWS - i - 1] == 1) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }

    // No win
    return 0;
}

// Run a bingo simulation
void run_simulation() {
    // Create a bingo card
    BingoCard* card = create_card();

    // Fill the card with random numbers
    fill_card(card);

    // Print the card
    printf("Your bingo card:\n");
    print_card(card);

    // Draw balls until someone wins
    int balls_drawn = 0;
    while (balls_drawn < NUM_BALLS) {
        // Draw a random number
        int number = random_num(MIN_NUM, MAX_NUM);

        // Mark the number on the card
        mark_number(card, number);

        // Check if the card has won
        if (check_win(card)) {
            printf("You won after %d balls were drawn!\n", balls_drawn);
            break;
        }
        balls_drawn++;
    }

    // If the card did not win, print a message
    if (balls_drawn == NUM_BALLS) {
        printf("You did not win.\n");
    }

    // Free the card
    free_card(card);
}

int main() {
    srand(time(NULL));
    run_simulation();
    return 0;
}