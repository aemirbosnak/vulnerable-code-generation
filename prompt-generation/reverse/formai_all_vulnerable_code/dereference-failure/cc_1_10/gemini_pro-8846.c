//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bingo card dimensions
#define CARD_WIDTH 5
#define CARD_HEIGHT 5

// Number of bingo balls
#define NUM_BALLS 75

// Bingo card data structure
typedef struct {
    int numbers[CARD_WIDTH][CARD_HEIGHT];
    int marked[CARD_WIDTH][CARD_HEIGHT];
} BingoCard;

// Function to create a new bingo card
BingoCard* create_card() {
    BingoCard* card = malloc(sizeof(BingoCard));
    for (int i = 0; i < CARD_WIDTH; i++) {
        for (int j = 0; j < CARD_HEIGHT; j++) {
            card->numbers[i][j] = 0;
            card->marked[i][j] = 0;
        }
    }
    return card;
}

// Function to generate a random number between 1 and NUM_BALLS
int generate_random_number() {
    return rand() % NUM_BALLS + 1;
}

// Function to mark a number on a bingo card
void mark_number(BingoCard* card, int number) {
    for (int i = 0; i < CARD_WIDTH; i++) {
        for (int j = 0; j < CARD_HEIGHT; j++) {
            if (card->numbers[i][j] == number) {
                card->marked[i][j] = 1;
            }
        }
    }
}

// Function to check if a bingo card has won
int check_for_win(BingoCard* card) {
    // Check for horizontal wins
    for (int i = 0; i < CARD_WIDTH; i++) {
        int count = 0;
        for (int j = 0; j < CARD_HEIGHT; j++) {
            count += card->marked[i][j];
        }
        if (count == CARD_WIDTH) {
            return 1;
        }
    }

    // Check for vertical wins
    for (int j = 0; j < CARD_HEIGHT; j++) {
        int count = 0;
        for (int i = 0; i < CARD_WIDTH; i++) {
            count += card->marked[i][j];
        }
        if (count == CARD_HEIGHT) {
            return 1;
        }
    }

    // Check for diagonal wins
    int count_left_diagonal = 0;
    int count_right_diagonal = 0;
    for (int i = 0; i < CARD_WIDTH; i++) {
        count_left_diagonal += card->marked[i][i];
        count_right_diagonal += card->marked[i][CARD_WIDTH - i - 1];
    }
    if (count_left_diagonal == CARD_WIDTH || count_right_diagonal == CARD_WIDTH) {
        return 1;
    }

    // No win yet
    return 0;
}

// Function to print a bingo card
void print_card(BingoCard* card) {
    for (int i = 0; i < CARD_WIDTH; i++) {
        for (int j = 0; j < CARD_HEIGHT; j++) {
            if (card->marked[i][j]) {
                printf("XX ");
            } else {
                printf("%d ", card->numbers[i][j]);
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a new bingo card
    BingoCard* card = create_card();

    // Generate random numbers and mark them on the card
    for (int i = 0; i < NUM_BALLS; i++) {
        int number = generate_random_number();
        mark_number(card, number);

        // Print the card
        print_card(card);

        // Check for a win
        if (check_for_win(card)) {
            printf("BINGO!!!\n");
            break;
        }
    }

    // Free the bingo card
    free(card);

    return 0;
}