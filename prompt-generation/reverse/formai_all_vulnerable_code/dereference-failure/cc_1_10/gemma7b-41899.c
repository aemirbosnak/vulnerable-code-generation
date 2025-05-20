//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_CHAR '-'
#define PLAYER_CHAR 'X'
#define COMPUTER_CHAR 'O'

// Board structure
typedef struct Board {
    char board[BOARD_SIZE][BOARD_SIZE];
    char current_player;
    int game_status;
} Board;

// Function to initialize the board
void initialize_board(Board *board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            board->board[r][c] = EMPTY_CHAR;
        }
    }
    board->current_player = PLAYER_CHAR;
    board->game_status = 0;
}

// Function to place a mark on the board
void place_mark(Board *board, int row, int column) {
    if (board->board[row][column] == EMPTY_CHAR && board->game_status == 0) {
        board->board[row][column] = board->current_player;
        board->current_player = (board->current_player == PLAYER_CHAR) ? COMPUTER_CHAR : PLAYER_CHAR;
    }
}

// Function to check if the player has won
int has_player_won(Board *board, char player_char) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board->board[r][0] == player_char && board->board[r][1] == player_char && board->board[r][2] == player_char) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board->board[0][c] == player_char && board->board[1][c] == player_char && board->board[2][c] == player_char) {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == player_char && board->board[1][1] == player_char && board->board[2][2] == player_char) {
        return 1;
    }

    // If all else fails, it's a draw
    return 0;
}

// Function to play the game
void play_game(Board *board) {
    int game_round = 0;
    while (board->game_status == 0) {
        int row, column;
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &column);

        place_mark(board, row, column);

        game_round++;
    }

    // Game over
    if (board->game_status == 1) {
        printf("Congratulations! You won!");
    } else if (board->game_status == 2) {
        printf("Draw!");
    }
}

int main() {
    Board board;
    initialize_board(&board);
    play_game(&board);

    return 0;
}