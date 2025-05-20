//GEMINI-pro DATASET v1.0 Category: Chess AI ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char type;
    Position position;
} Piece;

typedef struct {
    Piece pieces[16];
    int turn;
} Board;

void print_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece piece = board->pieces[i * BOARD_SIZE + j];
            if (piece.type == ' ') {
                printf("    ");
            } else {
                printf("%c   ", piece.type);
            }
        }
        printf("\n");
    }
}

int main() {
    Board board;
    memset(&board, 0, sizeof(Board));

    board.pieces[0] = (Piece) {'R', {0, 0}};
    board.pieces[1] = (Piece) {'N', {1, 0}};
    board.pieces[2] = (Piece) {'B', {2, 0}};
    board.pieces[3] = (Piece) {'Q', {3, 0}};
    board.pieces[4] = (Piece) {'K', {4, 0}};
    board.pieces[5] = (Piece) {'B', {5, 0}};
    board.pieces[6] = (Piece) {'N', {6, 0}};
    board.pieces[7] = (Piece) {'R', {7, 0}};

    board.pieces[8] = (Piece) {'p', {0, 1}};
    board.pieces[9] = (Piece) {'p', {1, 1}};
    board.pieces[10] = (Piece) {'p', {2, 1}};
    board.pieces[11] = (Piece) {'p', {3, 1}};
    board.pieces[12] = (Piece) {'p', {4, 1}};
    board.pieces[13] = (Piece) {'p', {5, 1}};
    board.pieces[14] = (Piece) {'p', {6, 1}};
    board.pieces[15] = (Piece) {'p', {7, 1}};

    board.turn = 0;

    print_board(&board);

    return 0;
}