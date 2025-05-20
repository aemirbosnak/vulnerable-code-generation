//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 4

// Define the number of cards
#define NUM_CARDS 8

// Structure to represent a card
typedef struct {
    int value;
    int is_flipped;
} Card;

// Function to create a new game board
Card** create_board() {
    // Allocate memory for the game board
    Card** board = (Card**)malloc(sizeof(Card*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (Card*)malloc(sizeof(Card) * BOARD_SIZE);
    }

    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = 0;
            board[i][j].is_flipped = 0;
        }
    }

    // Return the game board
    return board;
}

// Function to free the game board
void free_board(Card** board) {
    // Free the memory allocated for the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);
}

// Function to print the game board
void print_board(Card** board) {
    // Print the game board
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

// Function to generate a random number
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate the values for the cards
void generate_values(Card** board) {
    // Generate the values for the cards
    int values[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++) {
        values[i] = random_number(1, NUM_CARDS / 2);
    }

    // Assign the values to the cards
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = values[index];
            index++;
        }
    }
}

// Function to check if the player has won
int check_win(Card** board) {
    // Check if all the cards are flipped
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].is_flipped) {
                return 0;
            }
        }
    }

    // Return 1 if the player has won
    return 1;
}

// Function to play the game
void play_game() {
    // Create a new game board
    Card** board = create_board();

    // Generate the values for the cards
    generate_values(board);

    // Print the game board
    print_board(board);

    // Get the user's input
    int row1, col1, row2, col2;
    printf("Enter the coordinates of the first card (row, column): ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the coordinates of the second card (row, column): ");
    scanf("%d %d", &row2, &col2);

    // Flip the cards
    board[row1][col1].is_flipped = 1;
    board[row2][col2].is_flipped = 1;

    // Print the game board
    print_board(board);

    // Check if the player has won
    if (check_win(board)) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }

    // Free the game board
    free_board(board);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    play_game();

    return 0;
}