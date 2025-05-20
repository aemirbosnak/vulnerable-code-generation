//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// Structure to represent a card
typedef struct card {
    int value;
    int revealed;
} card;

// Function to create a new game board
card** create_board() {
    // Allocate memory for the board
    card** board = (card**)malloc(BOARD_SIZE * sizeof(card*));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (card*)malloc(BOARD_SIZE * sizeof(card));
    }

    // Initialize the board with random values
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = rand() % 10;
            board[i][j].revealed = 0;
        }
    }

    // Return the board
    return board;
}

// Function to print the game board
void print_board(card** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed) {
                printf("%d ", board[i][j].value);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// Function to get the user's input
void get_input(int* row, int* col) {
    printf("Enter the row and column of the card you want to reveal (0-based): ");
    scanf("%d %d", row, col);
}

// Function to check if the game is over
int is_game_over(card** board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].revealed) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to play the game
void play_game() {
    // Create the game board
    card** board = create_board();

    // Print the game board
    print_board(board);

    // Get the user's input
    int row, col;
    get_input(&row, &col);

    // Reveal the card
    board[row][col].revealed = 1;

    // Print the game board
    print_board(board);

    // Check if the game is over
    if (is_game_over(board)) {
        printf("Congratulations! You won the game.\n");
    } else {
        // Continue playing the game
        play_game();
    }

    // Free the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);
}

int main() {
    // Play the game
    play_game();

    return 0;
}