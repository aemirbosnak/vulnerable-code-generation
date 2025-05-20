//Gemma-7B DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYER_COUNT 2

typedef struct GameBoard {
    int **board;
    int rows;
    int cols;
} GameBoard;

void initGameBoard(GameBoard *board, int rows, int cols) {
    board->board = malloc(rows * cols * sizeof(int));
    board->rows = rows;
    board->cols = cols;

    for (int r = 0; r < board->rows; r++) {
        for (int c = 0; c < board->cols; c++) {
            board->board[r][c] = 0;
        }
    }
}

void placePiece(GameBoard *board, int player, int row, int col) {
    if (board->board[row][col] != 0) {
        return;
    }

    board->board[row][col] = player;
}

int checkWin(GameBoard *board, int player) {
    // Check rows
    for (int r = 0; r < board->rows; r++) {
        for (int c = 0; c < board->cols - 2; c++) {
            if (board->board[r][c] == board->board[r][c + 1] && board->board[r][c] == board->board[r][c + 2] && board->board[r][c] == player) {
                return 1;
            }
        }
    }

    // Check columns
    for (int c = 0; c < board->cols; c++) {
        for (int r = 0; r < board->rows - 2; r++) {
            if (board->board[r][c] == board->board[r + 1][c] && board->board[r][c] == board->board[r + 2][c] && board->board[r][c] == player) {
                return 1;
            }
        }
    }

    // Check diagonals
    for (int d = 0; d < board->rows - 2; d++) {
        for (int r = 0; r < board->rows - 2; r++) {
            for (int c = 0; c < board->cols - 2; c++) {
                if (board->board[r][c] == board->board[r + 1][c + 1] && board->board[r][c] == board->board[r + 2][c + 2] && board->board[r][c] == player) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main() {
    GameBoard *board = NULL;
    initGameBoard(board, 3, 5);

    int player = 1;
    placePiece(board, player, 1, 1);
    placePiece(board, player, 2, 2);
    placePiece(board, player, 0, 0);
    placePiece(board, player, 2, 3);

    if (checkWin(board, player) == 1) {
        printf("Player %d won!", player);
    } else {
        printf("No winner!");
    }

    free(board->board);
    free(board);

    return 0;
}