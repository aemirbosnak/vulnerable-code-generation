//Gemma-7B DATASET v1.0 Category: Checkers Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 6

typedef struct Piece {
    int row, col, is_king, color;
} Piece;

void initialize_board(Piece **board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            board[r][c].row = r;
            board[r][c].col = c;
            board[r][c].is_king = 0;
            board[r][c].color = 0;
        }
    }
}

void place_piece(Piece **board, int row, int col, int color) {
    board[row][col].row = row;
    board[row][col].col = col;
    board[row][col].color = color;
}

int move_piece(Piece **board, int from_row, int from_col, int to_row, int to_col) {
    if (board[from_row][from_col].color != board[to_row][to_col].color) {
        return 0;
    }

    if (board[from_row][from_col].is_king) {
        return 0;
    }

    if (from_row == to_row) {
        return 0;
    }

    if (from_col == to_col) {
        return 0;
    }

    board[to_row][to_col].row = to_row;
    board[to_row][to_col].col = to_col;

    board[from_row][from_col].row = -1;
    board[from_row][from_col].col = -1;

    return 1;
}

void display_board(Piece **board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            printf("%c ", board[r][c].color);
        }
        printf("\n");
    }
}

int main() {
    Piece **board = (Piece **)malloc(BOARD_SIZE * sizeof(Piece *)
                                  + BOARD_SIZE * sizeof(Piece));

    initialize_board(board);

    place_piece(board, 1, 1, 1);
    place_piece(board, 2, 2, 2);
    place_piece(board, 3, 3, 1);
    place_piece(board, 4, 4, 2);

    move_piece(board, 1, 1, 3, 3);

    display_board(board);

    return 0;
}