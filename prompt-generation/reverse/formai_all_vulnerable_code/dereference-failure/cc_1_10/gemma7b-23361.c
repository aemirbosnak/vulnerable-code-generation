//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

// Define the board structure
typedef struct Board {
    int **board;
    int current_player;
    int game_status;
} Board;

// Function to initialize the board
Board *init_board() {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
    board->current_player = 1;
    board->game_status = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }

    return board;
}

// Function to place a mark on the board
void place_mark(Board *board, int row, int col) {
    if (board->board[row][col] != 0) {
        return;
    }

    board->board[row][col] = board->current_player;
}

// Function to check if the player has won
int check_win(Board *board, int player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[i][0] == player && board->board[i][1] == player && board->board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[0][j] == player && board->board[1][j] == player && board->board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player) {
        return 1;
    }

    // If all else fails, it's a draw
    return 2;
}

// Function to play the game
void play_game(Board *board) {
    // Loop until one player wins or it's a draw
    while (board->game_status == 0) {
        // Get the player's move
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;

        // Place the mark on the board
        place_mark(board, row, col);

        // Check if the player has won
        if (check_win(board, board->current_player) == 1) {
            board->game_status = 1;
            printf("Player %d won!", board->current_player);
        } else {
            // It's not a win, so switch to the next player
            board->current_player *= -1;
        }
    }

    // If it's a draw
    if (board->game_status == 2) {
        printf("It's a draw!");
    }
}

int main() {
    // Initialize the board
    Board *board = init_board();

    // Play the game
    play_game(board);

    // Free the memory
    free(board->board);
    free(board);

    return 0;
}