//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 6

typedef struct Board {
    int **board;
    int turn;
    int winner;
} Board;

void initBoard(Board *board);
void displayBoard(Board *board);
void makeMove(Board *board, int x, int y);
int checkWin(Board *board, int player);

int main() {
    Board *board = malloc(sizeof(Board));
    initBoard(board);

    displayBoard(board);

    makeMove(board, 0, 0);
    makeMove(board, 2, 2);

    displayBoard(board);

    if (checkWin(board, 1) == 1) {
        printf("Player 1 won!\n");
    } else if (checkWin(board, 2) == 2) {
        printf("Player 2 won!\n");
    } else {
        printf("It's a draw.\n");
    }

    free(board);

    return 0;
}

void initBoard(Board *board) {
    board->board = malloc(MAX_BOARD_SIZE * MAX_BOARD_SIZE * sizeof(int));
    board->turn = 1;
    board->winner = 0;

    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
}

void displayBoard(Board *board) {
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }
}

void makeMove(Board *board, int x, int y) {
    if (board->board[x][y] != 0) {
        return;
    }

    board->board[x][y] = board->turn;
    board->turn *= -1;
}

int checkWin(Board *board, int player) {
    // Check rows
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            if (board->board[i][j] == player &&
                board->board[i][j - 1] == player &&
                board->board[i][j - 2] == player) {
                return player;
            }
        }
    }

    // Check columns
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            if (board->board[i][j] == player &&
                board->board[i - 1][j] == player &&
                board->board[i - 2][j] == player) {
                return player;
            }
        }
    }

    // Check diagonals
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            if (board->board[i][j] == player &&
                board->board[i - 1][j + 1] == player &&
                board->board[i - 2][j + 2] == player) {
                return player;
            }
        }
    }

    return 0;
}