//GEMINI-pro DATASET v1.0 Category: Chess engine ; Style: futuristic
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
    Piece pieces[32];
    int num_pieces;
} Board;

void init_board(Board *board) {
    board->num_pieces = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece piece;
            piece.position.x = i;
            piece.position.y = j;

            if (i == 1 || i == 6) {
                piece.type = 'P';
            } else if (i == 0 || i == 7) {
                switch (j) {
                    case 0:
                    case 7:
                        piece.type = 'R';
                        break;
                    case 1:
                    case 6:
                        piece.type = 'N';
                        break;
                    case 2:
                    case 5:
                        piece.type = 'B';
                        break;
                    case 3:
                        piece.type = 'Q';
                        break;
                    case 4:
                        piece.type = 'K';
                        break;
                }
            } else {
                piece.type = ' ';
            }

            board->pieces[board->num_pieces++] = piece;
        }
    }
}

void print_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board->pieces[i * BOARD_SIZE + j].type);
        }
        printf("\n");
    }
}

int main() {
    Board board;
    init_board(&board);
    print_board(&board);

    return 0;
}