//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of rows and columns in the bingo card
#define ROWS 5
#define COLS 5

// Define the maximum number of balls to draw
#define MAX_BALLS 75

// Define the bingo card data structure
typedef struct bingo_card {
    int numbers[CARD_SIZE][CARD_SIZE];
    int marked[CARD_SIZE][CARD_SIZE];
} bingo_card;

// Create a new bingo card
bingo_card *create_card() {
    bingo_card *card = malloc(sizeof(bingo_card));
    if (card == NULL) {
        return NULL;
    }

    // Initialize the card with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            card->numbers[i][j] = (i * COLS) + j + 1;
        }
    }

    // Shuffle the card
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int x = rand() % ROWS;
            int y = rand() % COLS;
            int temp = card->numbers[i][j];
            card->numbers[i][j] = card->numbers[x][y];
            card->numbers[x][y] = temp;
        }
    }

    // Initialize the marked array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            card->marked[i][j] = 0;
        }
    }

    return card;
}

// Free the memory allocated for the bingo card
void free_card(bingo_card *card) {
    free(card);
}

// Print the bingo card
void print_card(bingo_card *card) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", card->numbers[i][j]);
        }
        printf("\n");
    }
}

// Mark a number on the bingo card
void mark_number(bingo_card *card, int number) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card->numbers[i][j] == number) {
                card->marked[i][j] = 1;
            }
        }
    }
}

// Check if the bingo card has won
int check_win(bingo_card *card) {
    // Check rows
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

    // Check columns
    for (int i = 0; i < COLS; i++) {
        int count = 0;
        for (int j = 0; j < ROWS; j++) {
            if (card->marked[j][i] == 1) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1;
        }
    }

    // Check diagonals
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

    return 0;
}

// Play the bingo game
void play_bingo() {
    // Create a new bingo card
    bingo_card *card = create_card();

    // Print the bingo card
    printf("Your bingo card:\n");
    print_card(card);

    // Draw balls until someone wins
    int balls_drawn = 0;
    while (balls_drawn < MAX_BALLS) {
        // Draw a random ball
        int ball = rand() % MAX_BALLS + 1;

        // Mark the ball on the bingo card
        mark_number(card, ball);

        // Check if the bingo card has won
        if (check_win(card)) {
            printf("Congratulations! You won!\n");
            break;
        }

        // Print the ball that was drawn
        printf("Ball drawn: %d\n", ball);

        // Increment the number of balls drawn
        balls_drawn++;
    }

    // Free the memory allocated for the bingo card
    free_card(card);
}

// The main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the bingo game
    play_bingo();

    return 0;
}