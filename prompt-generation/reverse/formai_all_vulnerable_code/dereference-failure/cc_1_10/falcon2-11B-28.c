//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WHITE 1
#define BLACK -1

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char *name;
    int color;
} Piece;

typedef struct {
    Piece *pieces[8];
    int capturedPieces[8];
} Board;

void printBoard(Board* board) {
    printf("+--------+--------+--------+\n");
    printf("| %s   | %s   | %s   |\n", board->pieces[0]->name, board->pieces[1]->name, board->pieces[2]->name);
    printf("+--------+--------+--------+\n");
    printf("| %s   | %s   | %s   |\n", board->pieces[3]->name, board->pieces[4]->name, board->pieces[5]->name);
    printf("+--------+--------+--------+\n");
    printf("| %s   | %s   | %s   |\n", board->pieces[6]->name, board->pieces[7]->name, board->pieces[8]->name);
    printf("+--------+--------+--------+\n");
}

int main() {
    Board board;
    Piece *whitePieces[] = {
        {"Pawn", WHITE},
        {"Rook", WHITE},
        {"Knight", WHITE},
        {"Bishop", WHITE},
        {"Queen", WHITE},
        {"King", WHITE},
        {"Bishop", WHITE},
        {"Knight", WHITE},
    };
    Piece *blackPieces[] = {
        {"Pawn", BLACK},
        {"Rook", BLACK},
        {"Knight", BLACK},
        {"Bishop", BLACK},
        {"Queen", BLACK},
        {"King", BLACK},
        {"Bishop", BLACK},
        {"Knight", BLACK},
    };
    int i, j;

    board.pieces[0] = whitePieces[0];
    board.pieces[1] = whitePieces[1];
    board.pieces[2] = whitePieces[2];
    board.pieces[3] = whitePieces[3];
    board.pieces[4] = whitePieces[4];
    board.pieces[5] = whitePieces[5];
    board.pieces[6] = whitePieces[6];
    board.pieces[7] = whitePieces[7];

    board.capturedPieces[0] = 0;
    board.capturedPieces[1] = 0;
    board.capturedPieces[2] = 0;
    board.capturedPieces[3] = 0;
    board.capturedPieces[4] = 0;
    board.capturedPieces[5] = 0;
    board.capturedPieces[6] = 0;
    board.capturedPieces[7] = 0;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board.pieces[i]->color == WHITE) {
                if (i == j) {
                    board.capturedPieces[i]++;
                } else {
                    board.capturedPieces[i]++;
                }
            }
        }
    }

    printBoard(&board);

    return 0;
}