//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

#define DEFAULT_BOARD_SIZE 4
#define MAX_BOARD_SIZE 10

// Create a 2D array of characters.
char** create_board(int size) {
    char** board = malloc(sizeof(char*) * size);
    for (int i = 0; i < size; i++) {
        board[i] = malloc(sizeof(char) * size);
    }
    return board;
}

// Free the 2D array of characters.
void free_board(char** board, int size) {
    for (int i = 0; i < size; i++) {
        free(board[i]);
    }
    free(board);
}

// Initialize the board with random characters.
void initialize_board(char** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 'A' + rand() % 26;
        }
    }
}

// Print the board to the console.
void print_board(char** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Get the player's input.
void get_input(int* row, int* col) {
    printf("Enter the row and column of the card you want to flip (e.g., 1 2): ");
    scanf("%d %d", row, col);
}

// Check if the two cards match.
bool cards_match(char** board, int row1, int col1, int row2, int col2) {
    return board[row1][col1] == board[row2][col2];
}

// Flip the two cards over.
void flip_cards(char** board, int row1, int col1, int row2, int col2) {
    board[row1][col1] = ' ';
    board[row2][col2] = ' ';
}

// Check if the player has won the game.
bool player_has_won(char** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] != ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Initialize the random number generator.
    srand(time(NULL));

    // Get the board size from the user.
    int size;
    printf("Enter the size of the board (e.g., 4): ");
    scanf("%d", &size);
    if (size < 2 || size > MAX_BOARD_SIZE) {
        printf("Invalid board size. Please enter a value between 2 and 10.\n");
        return 1;
    }

    // Create the game board.
    char** board = create_board(size);

    // Initialize the game board.
    initialize_board(board, size);

    // Print the game board to the console.
    print_board(board, size);

    // Get the player's input.
    int row1, col1, row2, col2;
    get_input(&row1, &col1);
    get_input(&row2, &col2);

    // Check if the cards match.
    if (cards_match(board, row1, col1, row2, col2)) {
        // Flip the cards over.
        flip_cards(board, row1, col1, row2, col2);

        // Print the game board to the console.
        print_board(board, size);
    } else {
        printf("The cards do not match. Try again.\n");
    }

    // Check if the player has won the game.
    if (player_has_won(board, size)) {
        printf("Congratulations! You won the game.\n");
    } else {
        printf("Keep playing!\n");
    }

    // Free the game board.
    free_board(board, size);

    return 0;
}