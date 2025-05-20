//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    char color;
} Piece;

typedef struct {
    Piece* board[8][8];
    int winner;
} CheckersBoard;

CheckersBoard* initializeBoard() {
    CheckersBoard* board = malloc(sizeof(CheckersBoard));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board->board[i][j] = malloc(sizeof(Piece));
            board->board[i][j]->x = i;
            board->board[i][j]->y = j;
            board->board[i][j]->color = 'W';
        }
    }
    board->winner = 0;
    return board;
}

void printBoard(CheckersBoard* board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board->board[i][j]->color);
        }
        printf("\n");
    }
}

int isValidMove(CheckersBoard* board, int i, int j, char color) {
    Piece* piece = board->board[i][j];
    if (piece->color!= color) {
        return 0;
    }
    if (i < 0 || j < 0 || i >= 8 || j >= 8) {
        return 0;
    }
    if (board->board[i][j]->color == 'W') {
        return 1;
    }
    if (board->board[i][j]->color == 'B') {
        Piece* piece = board->board[i + 1][j];
        if (piece && piece->color == color) {
            return 1;
        }
        piece = board->board[i - 1][j];
        if (piece && piece->color == color) {
            return 1;
        }
        piece = board->board[i][j + 1];
        if (piece && piece->color == color) {
            return 1;
        }
        piece = board->board[i][j - 1];
        if (piece && piece->color == color) {
            return 1;
        }
        return 0;
    } else {
        Piece* piece = board->board[i + 1][j];
        if (piece && piece->color == color) {
            return 1;
        }
        piece = board->board[i - 1][j];
        if (piece && piece->color == color) {
            return 1;
        }
        piece = board->board[i][j + 1];
        if (piece && piece->color == color) {
            return 1;
        }
        piece = board->board[i][j - 1];
        if (piece && piece->color == color) {
            return 1;
        }
        return 0;
    }
}

void makeMove(CheckersBoard* board, int i, int j, char color) {
    Piece* piece = board->board[i][j];
    if (piece->color!= color) {
        return;
    }
    if (isValidMove(board, i, j, color)) {
        Piece* newPiece = malloc(sizeof(Piece));
        newPiece->x = i;
        newPiece->y = j;
        newPiece->color = color;
        board->board[i][j] = newPiece;
        free(board->board[i][j]);
        if (color == 'B') {
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    Piece* piece = board->board[k][l];
                    if (piece && piece->color == color) {
                        if (isValidMove(board, k, l, 'W')) {
                            makeMove(board, k, l, 'W');
                        }
                    }
                }
            }
        } else {
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    Piece* piece = board->board[k][l];
                    if (piece && piece->color == color) {
                        if (isValidMove(board, k, l, 'B')) {
                            makeMove(board, k, l, 'B');
                        }
                    }
                }
            }
        }
        board->winner = 1;
    }
}

int main() {
    CheckersBoard* board = initializeBoard();
    printBoard(board);
    makeMove(board, 0, 0, 'B');
    printBoard(board);
    makeMove(board, 1, 2, 'W');
    printBoard(board);
    makeMove(board, 2, 1, 'B');
    printBoard(board);
    return 0;
}