//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    int type; // 0 - pawn, 1 - knight, 2 - bishop, 3 - rook, 4 - queen, 5 - king
} Piece;

typedef struct {
    Piece pieces[32];
    int turn; // 0 - white, 1 - black
} Board;

void initBoard(Board *board) {
    for (int i = 0; i < 8; i++) {
        board->pieces[i] = (Piece) { {i, 1}, 0 }; // white pawns
        board->pieces[i + 8] = (Piece) { {i, 6}, 0 }; // black pawns
    }
    board->pieces[8] = (Piece) { {0, 0}, 2 }; // white bishop
    board->pieces[9] = (Piece) { {1, 0}, 2 }; // white bishop
    board->pieces[10] = (Piece) { {2, 0}, 1 }; // white knight
    board->pieces[11] = (Piece) { {5, 0}, 1 }; // white knight
    board->pieces[12] = (Piece) { {3, 0}, 3 }; // white rook
    board->pieces[13] = (Piece) { {4, 0}, 3 }; // white rook
    board->pieces[14] = (Piece) { {0, 7}, 2 }; // black bishop
    board->pieces[15] = (Piece) { {1, 7}, 2 }; // black bishop
    board->pieces[16] = (Piece) { {2, 7}, 1 }; // black knight
    board->pieces[17] = (Piece) { {5, 7}, 1 }; // black knight
    board->pieces[18] = (Piece) { {3, 7}, 3 }; // black rook
    board->pieces[19] = (Piece) { {4, 7}, 3 }; // black rook
    board->pieces[20] = (Piece) { {3, 1}, 4 }; // white queen
    board->pieces[21] = (Piece) { {4, 1}, 5 }; // white king
    board->pieces[22] = (Piece) { {3, 6}, 4 }; // black queen
    board->pieces[23] = (Piece) { {4, 6}, 5 }; // black king
    board->turn = 0;
}

void printBoard(Board *board) {
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            Piece piece = board->pieces[i * 8 + j];
            if (piece.type == 0) {
                printf("P");
            } else if (piece.type == 1) {
                printf("N");
            } else if (piece.type == 2) {
                printf("B");
            } else if (piece.type == 3) {
                printf("R");
            } else if (piece.type == 4) {
                printf("Q");
            } else if (piece.type == 5) {
                printf("K");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    Board board;
    initBoard(&board);
    printBoard(&board);
    return 0;
}