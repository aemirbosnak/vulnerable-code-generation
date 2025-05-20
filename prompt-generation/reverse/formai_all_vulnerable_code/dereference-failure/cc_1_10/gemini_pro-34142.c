//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the game board
void initialize_board(int **board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to print the game board
void print_board(int **board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int is_valid_move(int **board, int rows, int cols, int row, int col) {
    return row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] == 0;
}

// Function to make a move
void make_move(int **board, int rows, int cols, int player, int row, int col) {
    if (is_valid_move(board, rows, cols, row, col)) {
        board[row][col] = player;
    }
}

// Function to check if a player has won
int has_won(int **board, int rows, int cols, int player) {
    // Check rows
    for (int i = 0; i < rows; i++) {
        int count = 0;
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == player) {
                count++;
            }
        }
        if (count == cols) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < cols; j++) {
        int count = 0;
        for (int i = 0; i < rows; i++) {
            if (board[i][j] == player) {
                count++;
            }
        }
        if (count == rows) {
            return 1;
        }
    }

    // Check diagonals
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                if (board[i][j] == player) {
                    count1++;
                }
            }
            if (i + j == rows - 1) {
                if (board[i][j] == player) {
                    count2++;
                }
            }
        }
    }
    if (count1 == rows || count2 == rows) {
        return 1;
    }

    return 0;
}

// Main game loop
int main() {
    // Initialize the game board
    int **board;
    int rows = 3;
    int cols = 3;
    board = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        board[i] = (int *)malloc(cols * sizeof(int));
    }
    initialize_board(board, rows, cols);

    // Print the game board
    print_board(board, rows, cols);

    // Get player input
    int player = 1;
    int row, col;
    while (1) {
        printf("Player %d, enter your move (row, col): ", player);
        scanf("%d %d", &row, &col);

        // Make the move
        make_move(board, rows, cols, player, row, col);

        // Print the game board
        print_board(board, rows, cols);

        // Check if a player has won
        if (has_won(board, rows, cols, player)) {
            printf("Player %d wins!\n", player);
            break;
        }

        // Switch players
        player = 3 - player;
    }

    // Free the game board
    for (int i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}