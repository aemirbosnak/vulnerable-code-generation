//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 6

typedef struct Piece {
    int x, y;
    char color;
} Piece;

void initializeBoard(Piece **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].x = -1;
            board[i][j].y = -1;
            board[i][j].color = '\0';
        }
    }
}

void placePiece(Piece **board, int x, int y, char color) {
    board[x][y].x = x;
    board[x][y].y = y;
    board[x][y].color = color;
}

int movePiece(Piece **board, int x, int y) {
    if (board[x][y].x == -1) {
        return 0;
    }
    int dx = abs(board[x][y].x - board[x][y].x);
    int dy = abs(board[x][y].y - board[x][y].y);

    if (dx + dy == 2) {
        board[x][y].x = -1;
        board[x][y].y = -1;
        return 1;
    }
    return 0;
}

int main() {
    Piece **board = (Piece **)malloc(BOARD_SIZE * sizeof(Piece *) + BOARD_SIZE);
    initializeBoard(board);

    placePiece(board, 2, 2, 'a');
    placePiece(board, 3, 2, 'b');

    if (movePiece(board, 2, 2) == 1) {
        printf("Piece moved successfully!\n");
    } else {
        printf("Invalid move.\n");
    }

    free(board);

    return 0;
}