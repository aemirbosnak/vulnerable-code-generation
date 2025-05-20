//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    char type;
    int color;
    Point pos;
} Piece;

typedef struct {
    Piece pieces[16];
    int turn;
} Board;

void print_board(Board *board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece piece = board->pieces[i * 8 + j];
            if (piece.type == ' ') {
                printf(" .");
            } else {
                printf(" %c", piece.type);
            }
        }
        printf("\n");
    }
}

int main() {
    Board board;

    // Initialize the board
    for (int i = 0; i < 16; i++) {
        board.pieces[i].type = ' ';
        board.pieces[i].color = 0;
        board.pieces[i].pos.x = -1;
        board.pieces[i].pos.y = -1;
    }

    // Set up the pawns
    for (int i = 0; i < 8; i++) {
        board.pieces[i].type = 'P';
        board.pieces[i].color = 1;
        board.pieces[i].pos.x = i;
        board.pieces[i].pos.y = 1;

        board.pieces[i + 8].type = 'P';
        board.pieces[i + 8].color = 2;
        board.pieces[i + 8].pos.x = i;
        board.pieces[i + 8].pos.y = 6;
    }

    // Set up the other pieces
    board.pieces[0].type = 'R';
    board.pieces[0].color = 1;
    board.pieces[0].pos.x = 0;
    board.pieces[0].pos.y = 0;

    board.pieces[1].type = 'N';
    board.pieces[1].color = 1;
    board.pieces[1].pos.x = 1;
    board.pieces[1].pos.y = 0;

    board.pieces[2].type = 'B';
    board.pieces[2].color = 1;
    board.pieces[2].pos.x = 2;
    board.pieces[2].pos.y = 0;

    board.pieces[3].type = 'Q';
    board.pieces[3].color = 1;
    board.pieces[3].pos.x = 3;
    board.pieces[3].pos.y = 0;

    board.pieces[4].type = 'K';
    board.pieces[4].color = 1;
    board.pieces[4].pos.x = 4;
    board.pieces[4].pos.y = 0;

    board.pieces[5].type = 'B';
    board.pieces[5].color = 1;
    board.pieces[5].pos.x = 5;
    board.pieces[5].pos.y = 0;

    board.pieces[6].type = 'N';
    board.pieces[6].color = 1;
    board.pieces[6].pos.x = 6;
    board.pieces[6].pos.y = 0;

    board.pieces[7].type = 'R';
    board.pieces[7].color = 1;
    board.pieces[7].pos.x = 7;
    board.pieces[7].pos.y = 0;

    board.pieces[8].type = 'R';
    board.pieces[8].color = 2;
    board.pieces[8].pos.x = 0;
    board.pieces[8].pos.y = 7;

    board.pieces[9].type = 'N';
    board.pieces[9].color = 2;
    board.pieces[9].pos.x = 1;
    board.pieces[9].pos.y = 7;

    board.pieces[10].type = 'B';
    board.pieces[10].color = 2;
    board.pieces[10].pos.x = 2;
    board.pieces[10].pos.y = 7;

    board.pieces[11].type = 'Q';
    board.pieces[11].color = 2;
    board.pieces[11].pos.x = 3;
    board.pieces[11].pos.y = 7;

    board.pieces[12].type = 'K';
    board.pieces[12].color = 2;
    board.pieces[12].pos.x = 4;
    board.pieces[12].pos.y = 7;

    board.pieces[13].type = 'B';
    board.pieces[13].color = 2;
    board.pieces[13].pos.x = 5;
    board.pieces[13].pos.y = 7;

    board.pieces[14].type = 'N';
    board.pieces[14].color = 2;
    board.pieces[14].pos.x = 6;
    board.pieces[14].pos.y = 7;

    board.pieces[15].type = 'R';
    board.pieces[15].color = 2;
    board.pieces[15].pos.x = 7;
    board.pieces[15].pos.y = 7;

    // Print the board
    print_board(&board);

    return 0;
}