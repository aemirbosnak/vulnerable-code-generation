//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: accurate
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int turn;
} Board;

Board *initBoard() {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = malloc(sizeof(int) * BOARD_SIZE);
    }
    board->turn = 1;
    return board;
}

void placeMark(Board *board, int row, int col) {
    if (board->board[row][col] != 0) {
        return;
    }
    board->board[row][col] = board->turn;
    board->turn *= -1;
}

int checkWin(Board *board) {
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

    // If all cells are occupied and there is no winner, it's a draw
    return 0;
}

int main() {
    Board *board = initBoard();
    placeMark(board, 1, 1);
    placeMark(board, 2, 0);
    placeMark(board, 0, 2);
    placeMark(board, 1, 0);
    placeMark(board, 2, 2);
    placeMark(board, 0, 0);

    int winner = checkWin(board);

    if (winner) {
        printf("Winner: Player %d\n", winner);
    } else {
        printf("Draw\n");
    }

    return 0;
}