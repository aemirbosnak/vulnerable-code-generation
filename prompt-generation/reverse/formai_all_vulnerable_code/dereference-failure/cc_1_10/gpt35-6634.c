//FormAI DATASET v1.0 Category: Chess engine ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum {
    WHITE,
    BLACK
} COLOR;

typedef enum {
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN
} PIECE_TYPE;

typedef struct {
    PIECE_TYPE type;
    COLOR color;
} PIECE;

typedef struct {
    PIECE* pieces[BOARD_SIZE][BOARD_SIZE];
} BOARD;

PIECE* create_piece(PIECE_TYPE type, COLOR color) {
    PIECE* piece = malloc(sizeof(PIECE));
    piece->type = type;
    piece->color = color;
    return piece;
}

BOARD create_board() {
    BOARD board;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            PIECE_TYPE type;
            COLOR color;
            if (row == 0 || row == 7) {
                color = row == 0 ? BLACK : WHITE;
                type = col == 0 || col == 7 ? ROOK :
                       col == 1 || col == 6 ? KNIGHT :
                       col == 2 || col == 5 ? BISHOP :
                       col == 3 ? QUEEN :
                       KING;
            } else if (row == 1 || row == 6) {
                color = row == 1 ? BLACK : WHITE;
                type = PAWN;
            } else {
                board.pieces[row][col] = NULL;
                continue;
            }
            board.pieces[row][col] = create_piece(type, color);
        }
    }
    return board;
}

int main() {
    BOARD board = create_board();
    return 0;
}