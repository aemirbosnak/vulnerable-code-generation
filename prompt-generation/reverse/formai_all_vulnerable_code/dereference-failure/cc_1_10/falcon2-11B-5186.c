//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 81

typedef struct cell {
    int num;
    int marked;
} cell;

typedef struct board {
    cell *cells;
    int size;
} board;

board *create_board(int size) {
    board *b = (board*)malloc(sizeof(board));
    b->size = size;
    b->cells = (cell*)malloc(b->size * sizeof(cell));
    for (int i = 0; i < b->size; i++) {
        b->cells[i].marked = 0;
        b->cells[i].num = 0;
    }
    return b;
}

int solve_sudoku(board *b) {
    int i, j, k;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (b->cells[i * 9 + j].marked == 0) {
                for (k = 1; k <= 9; k++) {
                    if (is_valid(b, i, j, k)) {
                        b->cells[i * 9 + j].num = k;
                        if (solve_sudoku(b)) {
                            return 1;
                        }
                        b->cells[i * 9 + j].num = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int is_valid(board *b, int i, int j, int num) {
    int k;
    for (k = 0; k < 9; k++) {
        if (b->cells[k].num == num && b->cells[i * 9 + k].marked == 0) {
            return 0;
        }
        if (b->cells[k].num == num && b->cells[j * 9 + k].marked == 0) {
            return 0;
        }
        if (b->cells[i * 9 + k].num == num && b->cells[j * 9 + k].num == num) {
            return 0;
        }
    }
    return 1;
}

int main() {
    board *b = create_board(9);
    solve_sudoku(b);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", b->cells[i * 9 + j].num);
        }
        printf("\n");
    }
    return 0;
}