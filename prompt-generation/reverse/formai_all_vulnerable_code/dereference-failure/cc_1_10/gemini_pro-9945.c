//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of bingo balls
#define BALL_COUNT 75

// Define the bingo card data structure
typedef struct bingo_card {
    int numbers[CARD_SIZE][CARD_SIZE];
    int marked[CARD_SIZE][CARD_SIZE];
} bingo_card;

// Create a new bingo card
bingo_card* create_card() {
    bingo_card* card = malloc(sizeof(bingo_card));
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            card->numbers[i][j] = 0;
            card->marked[i][j] = 0;
        }
    }
    return card;
}

// Generate a random bingo number
int generate_number() {
    return rand() % BALL_COUNT + 1;
}

// Mark a number on the bingo card
void mark_number(bingo_card* card, int number) {
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            if (card->numbers[i][j] == number) {
                card->marked[i][j] = 1;
            }
        }
    }
}

// Check if the bingo card has won
int check_win(bingo_card* card) {
    // Check rows
    for (int i = 0; i < CARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < CARD_SIZE; j++) {
            count += card->marked[i][j];
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < CARD_SIZE; j++) {
        int count = 0;
        for (int i = 0; i < CARD_SIZE; i++) {
            count += card->marked[i][j];
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check diagonals
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < CARD_SIZE; i++) {
        count1 += card->marked[i][i];
        count2 += card->marked[i][CARD_SIZE - 1 - i];
    }
    if (count1 == CARD_SIZE || count2 == CARD_SIZE) {
        return 1;
    }

    return 0;
}

// Print the bingo card
void print_card(bingo_card* card) {
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            printf("%2d ", card->numbers[i][j]);
        }
        printf("\n");
    }
}

// Play a game of bingo
void play_bingo() {
    // Create a new bingo card
    bingo_card* card = create_card();

    // Generate random numbers for the bingo card
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            int number = generate_number();
            while (card->numbers[i][j] == 0) {
                number = generate_number();
                for (int k = 0; k < CARD_SIZE; k++) {
                    if (card->numbers[k][j] == number) {
                        break;
                    }
                }
                for (int k = 0; k < CARD_SIZE; k++) {
                    if (card->numbers[i][k] == number) {
                        break;
                    }
                }
                card->numbers[i][j] = number;
            }
        }
    }

    // Print the bingo card
    printf("Your bingo card:\n");
    print_card(card);

    // Draw bingo numbers until someone wins
    int number;
    while (1) {
        // Generate a random bingo number
        number = generate_number();

        // Mark the number on the bingo card
        mark_number(card, number);

        // Check if the bingo card has won
        if (check_win(card)) {
            break;
        }
    }

    // Print the winning bingo card
    printf("Winning bingo card:\n");
    print_card(card);

    // Free the bingo card
    free(card);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play a game of bingo
    play_bingo();

    return 0;
}