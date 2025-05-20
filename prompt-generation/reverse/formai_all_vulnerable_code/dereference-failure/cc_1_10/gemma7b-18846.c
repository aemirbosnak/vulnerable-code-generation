//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 64

typedef struct Piece {
    int x, y;
    char color;
} Piece;

void initializeBoard(Piece **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = NULL;
    }
}

void placePiece(Piece **board, int x, int y, char color) {
    board[x] = malloc(sizeof(Piece));
    board[x]->x = x;
    board[x]->y = y;
    board[x]->color = color;
}

void movePiece(Piece **board, int fromX, int fromY, int toX, int toY) {
    Piece *piece = board[fromX];
    board[fromX] = NULL;
    piece->x = toX;
    piece->y = toY;
    board[toX] = piece;
}

int main() {
    Piece **board = (Piece **)malloc(BOARD_SIZE * sizeof(Piece));
    initializeBoard(board);

    placePiece(board, 0, 0, 'B');
    placePiece(board, 1, 0, 'B');
    placePiece(board, 2, 0, 'B');
    placePiece(board, 3, 0, 'B');
    placePiece(board, 4, 0, 'B');

    placePiece(board, 0, 7, 'W');
    placePiece(board, 1, 7, 'W');
    placePiece(board, 2, 7, 'W');
    placePiece(board, 3, 7, 'W');
    placePiece(board, 4, 7, 'W');

    movePiece(board, 0, 0, 0, 2);
    movePiece(board, 1, 0, 1, 2);
    movePiece(board, 2, 0, 2, 2);
    movePiece(board, 3, 0, 3, 2);

    movePiece(board, 0, 2, 0, 4);
    movePiece(board, 1, 2, 1, 4);
    movePiece(board, 2, 2, 2, 4);

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] != NULL) {
            printf("x: %d, y: %d, color: %c\n", board[i]->x, board[i]->y, board[i]->color);
        }
    }

    return 0;
}