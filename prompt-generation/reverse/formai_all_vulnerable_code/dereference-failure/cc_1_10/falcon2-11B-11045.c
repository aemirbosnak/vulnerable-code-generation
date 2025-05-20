//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int row;
    int col;
} Coordinate;

typedef struct {
    int player;
    int count;
} Piece;

typedef struct {
    int size;
    Piece **board;
} Board;

Board *createBoard(int size) {
    Board *board = (Board *)malloc(sizeof(Board));
    board->size = size;
    board->board = (Piece **)malloc(sizeof(Piece *) * size);

    for (int i = 0; i < size; i++) {
        board->board[i] = (Piece *)malloc(sizeof(Piece) * size);
    }

    return board;
}

void displayBoard(Board *board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            printf("%d ", board->board[i][j].player);
        }
        printf("\n");
    }
}

int main() {
    int size = 8;
    Board *board = createBoard(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board->board[i][j].player = 0;
            board->board[i][j].count = 1;
        }
    }

    displayBoard(board);

    return 0;
}