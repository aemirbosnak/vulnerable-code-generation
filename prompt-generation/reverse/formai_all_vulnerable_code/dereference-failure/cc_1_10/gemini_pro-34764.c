//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define BINGO_SIZE 5

// Bingo card structure
typedef struct {
    int numbers[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

// Function to create a new bingo card
BingoCard* create_bingo_card() {
    BingoCard* card = malloc(sizeof(BingoCard));

    // Generate random numbers for the bingo card
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            card->numbers[i][j] = rand() % 100;
        }
    }

    // Initialize the marked array to all zeros
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            card->marked[i][j] = 0;
        }
    }

    return card;
}

// Function to print a bingo card
void print_bingo_card(BingoCard* card) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }
}

// Function to mark a number on a bingo card
void mark_number(BingoCard* card, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->numbers[i][j] == number) {
                card->marked[i][j] = 1;
            }
        }
    }
}

// Function to check if a bingo card has won
int check_for_bingo(BingoCard* card) {
    // Check for horizontal wins
    for (int i = 0; i < BINGO_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->marked[i][j]) {
                count++;
            }
        }
        if (count == BINGO_SIZE) {
            return 1;
        }
    }

    // Check for vertical wins
    for (int i = 0; i < BINGO_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->marked[j][i]) {
                count++;
            }
        }
        if (count == BINGO_SIZE) {
            return 1;
        }
    }

    // Check for diagonal wins
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (card->marked[i][i]) {
            count1++;
        }
        if (card->marked[i][BINGO_SIZE - i - 1]) {
            count2++;
        }
    }
    if (count1 == BINGO_SIZE || count2 == BINGO_SIZE) {
        return 1;
    }

    return 0;
}

// Function to play a game of bingo
void play_bingo() {
    // Create a new bingo card
    BingoCard* card = create_bingo_card();

    // Print the bingo card
    printf("Your bingo card:\n");
    print_bingo_card(card);

    // Generate random numbers until someone wins
    int number;
    while (!check_for_bingo(card)) {
        // Generate a random number
        number = rand() % 100;

        // Mark the number on the bingo card
        mark_number(card, number);

        // Print the number that was drawn
        printf("Number drawn: %d\n", number);

        // Print the updated bingo card
        print_bingo_card(card);
    }

    // Someone has won!
    printf("Congratulations! You won!\n");
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play a game of bingo
    play_bingo();

    return 0;
}