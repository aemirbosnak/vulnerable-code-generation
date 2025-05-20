//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int row;
    int col;
    int color;
} Piece;

typedef struct {
    Piece* pieces;
    int size;
} Board;

void printBoard(Board* board) {
    int i, j;
    printf("+---+---+---+---+---+---+---+\n");
    for (i = 0; i < board->size; i++) {
        printf("|%d%d%d |", board->pieces[i].row, board->pieces[i].col, board->pieces[i].color);
        for (j = 0; j < board->size; j++) {
            if (j!= board->pieces[i].row || j!= board->pieces[i].col) {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("+---+---+---+---+---+---+---+\n");
}

void placePieces(Board* board) {
    int i, j;
    for (i = 0; i < board->size; i++) {
        for (j = 0; j < board->size; j++) {
            if (i == 0 && j == 0) {
                board->pieces[i].row = 0;
                board->pieces[i].col = 0;
                board->pieces[i].color = 1;
            } else if (i == 0 && j == board->size - 1) {
                board->pieces[i].row = board->size - 1;
                board->pieces[i].col = board->size - 1;
                board->pieces[i].color = -1;
            } else if (i == board->size - 1 && j == 0) {
                board->pieces[i].row = 0;
                board->pieces[i].col = 0;
                board->pieces[i].color = -1;
            } else if (i == board->size - 1 && j == board->size - 1) {
                board->pieces[i].row = board->size - 1;
                board->pieces[i].col = board->size - 1;
                board->pieces[i].color = 1;
            } else {
                board->pieces[i].row = i;
                board->pieces[i].col = j;
                board->pieces[i].color = 0;
            }
        }
    }
}

int main() {
    Board board;
    srand(time(NULL));
    board.size = 8;
    board.pieces = malloc(sizeof(Piece) * board.size);
    for (int i = 0; i < board.size; i++) {
        board.pieces[i].row = rand() % board.size;
        board.pieces[i].col = rand() % board.size;
        board.pieces[i].color = rand() % 2;
    }
    placePieces(&board);
    printBoard(&board);
    return 0;
}