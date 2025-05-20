//FormAI DATASET v1.0 Category: Chess AI ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Define constants for board */
#define ROWS 8
#define COLS 8
#define EMPTY 0

/* Define constants for pieces */
#define KING 1
#define QUEEN 2
#define BISHOP 3
#define KNIGHT 4
#define ROOK 5
#define PAWN 6

/* Define structure for a piece */
typedef struct {
    int type;
    int color;
    bool hasMoved;
} Piece;

/* Define structure for a chess board */
typedef struct {
    Piece *board[ROWS][COLS];
} Board;

/* Generate a new piece */
Piece *createPiece(int type, int color) {
    Piece *p = (Piece*)malloc(sizeof(Piece));
    p->type = type;
    p->color = color;
    p->hasMoved = false;
    return p;
}

/* Initialize a new chess board */
void initializeBoard(Board *board) {
    int i, j;

    /* Set up white pieces */
    board->board[0][0] = createPiece(ROOK, 1);
    board->board[0][1] = createPiece(KNIGHT, 1);
    board->board[0][2] = createPiece(BISHOP, 1);
    board->board[0][3] = createPiece(QUEEN, 1);
    board->board[0][4] = createPiece(KING, 1);
    board->board[0][5] = createPiece(BISHOP, 1);
    board->board[0][6] = createPiece(KNIGHT, 1);
    board->board[0][7] = createPiece(ROOK, 1);
    for (i = 0; i < COLS; i++) {
        board->board[1][i] = createPiece(PAWN, 1);
    }

    /* Set up black pieces */
    board->board[7][0] = createPiece(ROOK, 0);
    board->board[7][1] = createPiece(KNIGHT, 0);
    board->board[7][2] = createPiece(BISHOP, 0);
    board->board[7][3] = createPiece(QUEEN, 0);
    board->board[7][4] = createPiece(KING, 0);
    board->board[7][5] = createPiece(BISHOP, 0);
    board->board[7][6] = createPiece(KNIGHT, 0);
    board->board[7][7] = createPiece(ROOK, 0);
    for (i = 0; i < COLS; i++) {
        board->board[6][i] = createPiece(PAWN, 0);
    }

    /* Set the rest of the board to empty */
    for (i = 2; i < 6; i++) {
        for (j = 0; j < COLS; j++) {
            board->board[i][j] = NULL;
        }
    }
}

/* Print the chess board */
void printBoard(Board *board) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board->board[i][j] == NULL) {
                printf(" - ");
            }
            else {
                switch(board->board[i][j]->type) {
                    case KING:
                        printf(" K ");
                        break;
                    case QUEEN:
                        printf(" Q ");
                        break;
                    case BISHOP:
                        printf(" B ");
                        break;
                    case KNIGHT:
                        printf(" N ");
                        break;
                    case ROOK:
                        printf(" R ");
                        break;
                    case PAWN:
                        printf(" P ");
                        break;
                    default:
                        printf(" ? ");
                        break;
                }
            }
        }
        printf("\n");
    }
}

/* Main function */
int main() {
    Board board;
    initializeBoard(&board);
    printBoard(&board);
    return 0;
}