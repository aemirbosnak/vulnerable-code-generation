//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int turn;
    int winner;
} Board;

void init_board(Board *board) {
    board->board = malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
    board->turn = 0;
    board->winner = 0;
}

void play_turn(Board *board, int row, int col) {
    if (board->board[row][col] != 0) {
        return;
    }
    board->board[row][col] = board->turn;
    board->turn++;
}

int check_win(Board *board) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board->board[r][0] == board->board[r][1] && board->board[r][0] == board->board[r][2] && board->board[r][0] != 0) {
            return board->board[r][0];
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board->board[0][c] == board->board[1][c] && board->board[0][c] == board->board[2][c] && board->board[0][c] != 0) {
            return board->board[0][c];
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0];
    }

    // No winner
    return 0;
}

int main() {
    Board board;
    init_board(&board);

    // Play until there is a winner or the board is full
    while (!check_win(&board) && board.turn < BOARD_SIZE * BOARD_SIZE) {
        // Get the player's move
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);

        // Play the turn
        play_turn(&board, row, col);
    }

    // Print the winner or draw
    if (check_win(&board) != 0) {
        printf("The winner is player %d!\n", check_win(&board));
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}