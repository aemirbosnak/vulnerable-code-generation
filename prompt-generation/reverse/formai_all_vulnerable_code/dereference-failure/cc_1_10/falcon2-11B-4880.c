//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Cell;

typedef struct {
    int height;
    int width;
    Cell **matrix;
} Board;

void initialize_board(Board *board) {
    board->height = 20;
    board->width = 20;
    board->matrix = (Cell **)malloc(board->height * sizeof(Cell *));
    for (int i = 0; i < board->height; i++) {
        board->matrix[i] = (Cell *)malloc(board->width * sizeof(Cell));
        for (int j = 0; j < board->width; j++) {
            board->matrix[i][j].row = i;
            board->matrix[i][j].col = j;
            board->matrix[i][j].value = 0;
        }
    }
}

void print_board(Board *board) {
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            printf("(%d,%d): %d\n", board->matrix[i][j].row, board->matrix[i][j].col, board->matrix[i][j].value);
        }
    }
}

int is_neighbor(Board *board, int row, int col) {
    int neighbors = 0;
    if (row > 0 && col > 0) {
        neighbors += board->matrix[row - 1][col - 1].value;
    }
    if (row > 0 && col < board->width - 1) {
        neighbors += board->matrix[row - 1][col + 1].value;
    }
    if (row < board->height - 1 && col > 0) {
        neighbors += board->matrix[row + 1][col - 1].value;
    }
    if (row < board->height - 1 && col < board->width - 1) {
        neighbors += board->matrix[row + 1][col + 1].value;
    }
    return neighbors;
}

int is_filled(Board *board, int row, int col) {
    return board->matrix[row][col].value == 1;
}

void percolate(Board *board, int row, int col) {
    if (board->matrix[row][col].value == 0) {
        board->matrix[row][col].value = 1;
        int neighbors = is_neighbor(board, row, col);
        if (neighbors >= 4) {
            for (int i = 0; i < board->height; i++) {
                for (int j = 0; j < board->width; j++) {
                    if (board->matrix[i][j].value == 0) {
                        percolate(board, i, j);
                    }
                }
            }
        }
    }
}

int main() {
    Board board;
    initialize_board(&board);
    print_board(&board);

    for (int i = 0; i < board.height; i++) {
        for (int j = 0; j < board.width; j++) {
            percolate(&board, i, j);
        }
    }
    print_board(&board);

    return 0;
}