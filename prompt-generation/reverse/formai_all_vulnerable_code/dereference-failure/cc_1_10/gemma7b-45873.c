//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 6

typedef struct Board {
    int **board;
    int size;
    int turn;
} Board;

void initBoard(Board *board) {
    board->board = (int **)malloc(board->size * sizeof(int *));
    for (int i = 0; i < board->size; i++) {
        board->board[i] = (int *)malloc(board->size * sizeof(int));
    }
    board->size = board->size;
    board->turn = 0;
}

void placePiece(Board *board, int x, int y, int piece) {
    if (board->board[x][y] != 0) {
        return;
    }
    board->board[x][y] = piece;
}

int getPiece(Board *board, int x, int y) {
    return board->board[x][y];
}

int isMoveValid(Board *board, int x, int y, int direction) {
    switch (direction) {
        case 0:
            return (getPiece(board, x - 1, y) == board->board[x][y] && getPiece(board, x - 1, y) != 0);
        case 1:
            return (getPiece(board, x + 1, y) == board->board[x][y] && getPiece(board, x + 1, y) != 0);
        case 2:
            return (getPiece(board, x, y - 1) == board->board[x][y] && getPiece(board, x, y - 1) != 0);
        case 3:
            return (getPiece(board, x, y + 1) == board->board[x][y] && getPiece(board, x, y + 1) != 0);
    }
    return 0;
}

int main() {
    Board board;
    initBoard(&board);
    placePiece(&board, 2, 2, 1);
    placePiece(&board, 3, 2, 2);
    placePiece(&board, 4, 2, 1);
    placePiece(&board, 5, 2, 2);
    placePiece(&board, 2, 3, 1);
    placePiece(&board, 3, 3, 2);

    if (isMoveValid(&board, 2, 3, 0)) {
        printf("Move is valid\n");
    } else {
        printf("Move is not valid\n");
    }

    return 0;
}