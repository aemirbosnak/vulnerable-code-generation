//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the game board
#define BOARD_SIZE 4

// Define the number of pairs of cards
#define NUM_PAIRS 8

// Create a struct to represent a card
typedef struct {
    int value;
    int is_flipped;
} card;

// Create a function to initialize the game board
void initialize_board(card board[BOARD_SIZE][BOARD_SIZE]) {
    // Initialize the random number generator
    srand(time(NULL));

    // Create an array of all the possible card values
    int values[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        values[i] = i / 2;
    }

    // Shuffle the array of card values
    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        int j = rand() % (NUM_PAIRS * 2);
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Assign the card values to the game board
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = values[index];
            board[i][j].is_flipped = 0;
            index++;
        }
    }
}

// Create a function to print the game board
void print_board(card board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].is_flipped) {
                printf("%d ", board[i][j].value);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// Create a function to get the user's input
void get_input(int *row, int *col) {
    printf("Enter the row and column of the card you want to flip (e.g. 1 2): ");
    scanf("%d %d", row, col);
}

// Create a function to check if the two cards match
int check_match(card card1, card card2) {
    return card1.value == card2.value;
}

// Create a function to play the game
void play_game(card board[BOARD_SIZE][BOARD_SIZE]) {
    int num_flipped = 0;
    int first_row, first_col, second_row, second_col;

    while (num_flipped < NUM_PAIRS * 2) {
        // Get the user's input
        get_input(&first_row, &first_col);

        // Flip the first card
        board[first_row][first_col].is_flipped = 1;

        // Print the game board
        print_board(board);

        // Get the user's input
        get_input(&second_row, &second_col);

        // Flip the second card
        board[second_row][second_col].is_flipped = 1;

        // Print the game board
        print_board(board);

        // Check if the two cards match
        if (check_match(board[first_row][first_col], board[second_row][second_col])) {
            printf("Match!\n");
            num_flipped += 2;
        } else {
            printf("No match.\n");

            // Flip the cards back over
            board[first_row][first_col].is_flipped = 0;
            board[second_row][second_col].is_flipped = 0;
        }
    }

    printf("You win!\n");
}

int main() {
    // Create the game board
    card board[BOARD_SIZE][BOARD_SIZE];

    // Initialize the game board
    initialize_board(board);

    // Play the game
    play_game(board);

    return 0;
}