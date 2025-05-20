//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Tic Tac Toe board
#define BOARD_SIZE 3

// Define the winning conditions
#define WIN_ROWS 3
#define WIN_COLS 3
#define WIN_DIAG 2

// Define the player's mark
#define PLAYER_MARK 'X'

// Define the computer's mark
#define COMPUTER_MARK 'O'

// Define the game state
typedef enum game_state {
    PLAYER_TURN,
    COMPUTER_TURN,
    GAME_OVER,
    GAME_DRAW
} game_state_t;

// Function to initialize the board
void initialize_board(int **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to place a mark on the board
void place_mark(int **board, int row, int col, char mark) {
    board[row][col] = mark;
}

// Function to check if the player has won
int has_player_won(int **board, char mark) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == mark && board[1][j] == mark && board[2][j] == mark) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
        return 1;
    }

    // If all else fails, it's a draw
    return 0;
}

// Function to generate the computer's move
int generate_computer_move(int **board) {
    // Choose a random move
    int row = rand() % BOARD_SIZE;
    int col = rand() % BOARD_SIZE;

    // If the move is valid, return it
    if (board[row][col] == 0) {
        return row * BOARD_SIZE + col;
    } else {
        // Otherwise, generate a new move
        return generate_computer_move(board);
    }
}

// Function to play the game
int main() {
    // Initialize the board
    int **board = (int **)malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (int *)malloc(sizeof(int) * BOARD_SIZE);
    }

    initialize_board(board);

    // Place the player's mark
    place_mark(board, 0, 0, PLAYER_MARK);

    // Play the game
    game_state_t state = PLAYER_TURN;
    while (state != GAME_OVER && state != GAME_DRAW) {
        // Get the computer's move
        int move = generate_computer_move(board);

        // Place the computer's mark
        place_mark(board, move / BOARD_SIZE, move % BOARD_SIZE, COMPUTER_MARK);

        // Check if the player has won
        if (has_player_won(board, PLAYER_MARK)) {
            state = GAME_OVER;
        } else {
            state = COMPUTER_TURN;
        }
    }

    // Print the winner or draw
    if (state == GAME_OVER) {
        printf("You win!");
    } else if (state == GAME_DRAW) {
        printf("It's a draw!");
    }

    // Free the memory
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}