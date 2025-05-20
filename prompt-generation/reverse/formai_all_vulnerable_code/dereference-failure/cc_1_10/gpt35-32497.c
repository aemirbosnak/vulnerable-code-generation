//FormAI DATASET v1.0 Category: Chess engine ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 8
#define COLS 8

struct piece {
    char symbol;
    int row, col;
};

struct board {
    struct piece** pieces;
};

struct move {
    int row_from, col_from, row_to, col_to;
};

void print_board(struct board* board) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("[%c]", board->pieces[row][col].symbol);
        }
        printf("\n");
    }
}

struct board* create_board() {
    struct board* board = (struct board*)malloc(sizeof(struct board));
    board->pieces = (struct piece**)malloc(sizeof(struct piece*) * ROWS);
    for (int row = 0; row < ROWS; row++) {
        board->pieces[row] = (struct piece*)malloc(sizeof(struct piece) * COLS);
        for (int col = 0; col < COLS; col++) {
            board->pieces[row][col].symbol = '-';
            board->pieces[row][col].row = row;
            board->pieces[row][col].col = col;
        }
    }
    return board;
}

void init_board(struct board* board) {
    // pawns
    for (int i = 0; i < COLS; i++) {
        board->pieces[1][i].symbol = 'P';
        board->pieces[6][i].symbol = 'P';
    }

    // rooks
    board->pieces[0][0].symbol = 'R';
    board->pieces[0][7].symbol = 'R';
    board->pieces[7][0].symbol = 'R';
    board->pieces[7][7].symbol = 'R';

    // knights
    board->pieces[0][1].symbol = 'N';
    board->pieces[0][6].symbol = 'N';
    board->pieces[7][1].symbol = 'N';
    board->pieces[7][6].symbol = 'N';

    // bishops
    board->pieces[0][2].symbol = 'B';
    board->pieces[0][5].symbol = 'B';
    board->pieces[7][2].symbol = 'B';
    board->pieces[7][5].symbol = 'B';

    // king & queen
    board->pieces[0][3].symbol = 'Q';
    board->pieces[0][4].symbol = 'K';
    board->pieces[7][3].symbol = 'Q';
    board->pieces[7][4].symbol = 'K';
}

void move_piece(struct board* board, struct move* move) {
    // get piece from move coordinates
    struct piece piece = board->pieces[move->row_from][move->col_from];

    // remove piece from old position
    board->pieces[move->row_from][move->col_from].symbol = '-';

    // add piece to new position
    board->pieces[move->row_to][move->col_to] = piece;
}

int main() {
    struct board* board = create_board();
    init_board(board);
    print_board(board);

    struct move pawn_move;
    pawn_move.row_from = 1;
    pawn_move.col_from = 1;
    pawn_move.row_to = 2;
    pawn_move.col_to = 1;
    move_piece(board, &pawn_move);

    printf("-----------------------\n");

    print_board(board);
    return 0;
}