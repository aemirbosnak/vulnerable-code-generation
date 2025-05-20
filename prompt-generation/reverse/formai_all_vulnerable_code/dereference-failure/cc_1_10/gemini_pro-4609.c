//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5

// Structure to represent a bingo card
typedef struct {
    int numbers[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

// Function to create a new bingo card
BingoCard* create_bingo_card() {
    BingoCard* card = malloc(sizeof(BingoCard));

    // Initialize the card with random numbers
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            card->numbers[i][j] = (rand() % 99) + 1;
        }
    }

    // Initialize the marked array to all 0s
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            card->marked[i][j] = 0;
        }
    }

    return card;
}

// Function to print a bingo card
void print_bingo_card(BingoCard* card) {
    printf("---------------------\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            printf("%2d ", card->numbers[i][j]);
        }
        printf("\n");
    }
    printf("---------------------\n");
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
int check_for_win(BingoCard* card) {
    // Check for horizontal wins
    for (int i = 0; i < BINGO_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BINGO_SIZE; j++) {
            count += card->marked[i][j];
        }
        if (count == BINGO_SIZE) {
            return 1;
        }
    }

    // Check for vertical wins
    for (int i = 0; i < BINGO_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BINGO_SIZE; j++) {
            count += card->marked[j][i];
        }
        if (count == BINGO_SIZE) {
            return 1;
        }
    }

    // Check for diagonal wins
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < BINGO_SIZE; i++) {
        count1 += card->marked[i][i];
        count2 += card->marked[i][BINGO_SIZE - i - 1];
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
    print_bingo_card(card);

    // Get the input from the user
    int number;
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &number);

        // Mark the number on the bingo card
        mark_number(card, number);

        // Print the bingo card
        print_bingo_card(card);

        // Check if the player has won
        if (check_for_win(card)) {
            printf("You win!\n");
            break;
        }
    }

    // Free the memory allocated for the bingo card
    free(card);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Play the game of bingo
    play_bingo();

    return 0;
}