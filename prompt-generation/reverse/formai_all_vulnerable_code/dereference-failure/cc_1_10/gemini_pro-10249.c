//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char type;
    Position position;
} Piece;

typedef struct {
    Piece pieces[32];
    int turn;
} Board;

void initBoard(Board *board) {
    for (int i = 0; i < 8; i++) {
        board->pieces[i] = (Piece) {'p', {i, 1}};
        board->pieces[i + 8] = (Piece) {'P', {i, 6}};
    }
    board->pieces[8] = (Piece) {'r', {0, 0}};
    board->pieces[9] = (Piece) {'n', {1, 0}};
    board->pieces[10] = (Piece) {'b', {2, 0}};
    board->pieces[11] = (Piece) {'q', {3, 0}};
    board->pieces[12] = (Piece) {'k', {4, 0}};
    board->pieces[13] = (Piece) {'b', {5, 0}};
    board->pieces[14] = (Piece) {'n', {6, 0}};
    board->pieces[15] = (Piece) {'r', {7, 0}};
    board->pieces[24] = (Piece) {'R', {0, 7}};
    board->pieces[25] = (Piece) {'N', {1, 7}};
    board->pieces[26] = (Piece) {'B', {2, 7}};
    board->pieces[27] = (Piece) {'Q', {3, 7}};
    board->pieces[28] = (Piece) {'K', {4, 7}};
    board->pieces[29] = (Piece) {'B', {5, 7}};
    board->pieces[30] = (Piece) {'N', {6, 7}};
    board->pieces[31] = (Piece) {'R', {7, 7}};
    board->turn = 0;
}

void printBoard(Board *board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece piece = board->pieces[i * 8 + j];
            if (piece.type == 0) {
                printf(" ");
            } else {
                printf("%c", piece.type);
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