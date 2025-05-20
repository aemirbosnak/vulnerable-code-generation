//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int current_player;
    int winner;
} Board;

void init_board(Board *board) {
    board->board = (int **)malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
    board->current_player = 1;
    board->winner = 0;
}

void place_mark(Board *board, int row, int col) {
    if (board->board[row][col] != 0) {
        return;
    }
    board->board[row][col] = board->current_player;
    board->current_player *= -1;
}

int check_winner(Board *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return board->board[j][0];
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0];
    }

    // If all cells are occupied and no winner, it's a draw
    return 0;
}

int main() {
    Board board;
    init_board(&board);

    // Play the game
    place_mark(&board, 1, 1);
    place_mark(&board, 2, 2);
    place_mark(&board, 0, 0);
    place_mark(&board, 1, 0);
    place_mark(&board, 2, 0);
    place_mark(&board, 0, 1);

    // Check for winner or draw
    int winner = check_winner(&board);
    if (winner) {
        printf("Winner: Player %d\n", winner);
    } else {
        printf("Draw!\n");
    }

    return 0;
}