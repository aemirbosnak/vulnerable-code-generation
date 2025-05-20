//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct SudokuCell {
    int number;
    struct SudokuCell* up;
    struct SudokuCell* right;
    struct SudokuCell* down;
    struct SudokuCell* left;
} SudokuCell;

SudokuCell* sudoku_create(int n) {
    SudokuCell* cell = malloc(sizeof(SudokuCell));
    cell->number = n;
    cell->up = NULL;
    cell->right = NULL;
    cell->down = NULL;
    cell->left = NULL;
    return cell;
}

void sudoku_solve(SudokuCell* cell) {
    if (cell->number != 0) {
        return;
    }

    for (int i = 1; i <= SUDO_SIZE; i++) {
        if (sudoku_is_valid(cell, i)) {
            cell->number = i;
            sudoku_solve(cell->up);
            sudoku_solve(cell->right);
            sudoku_solve(cell->down);
            sudoku_solve(cell->left);
            cell->number = 0;
        }
    }
}

int sudoku_is_valid(SudokuCell* cell, int n) {
    if (cell->number != 0) {
        return 0;
    }

    // Check row
    for (SudokuCell* c = cell->up; c; c = c->up) {
        if (c->number == n) {
            return 0;
        }
    }

    // Check column
    for (SudokuCell* c = cell->left; c; c = c->left) {
        if (c->number == n) {
            return 0;
        }
    }

    // Check 3x3 box
    for (SudokuCell* r = cell->up; r; r = r->up) {
        for (SudokuCell* c = cell->left; c; c = c->left) {
            if (r->number == n && c->number == n) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    SudokuCell* cell = sudoku_create(0);

    sudoku_solve(cell);

    printf("Solution:\n");
    for (SudokuCell* c = cell; c; c = c->down) {
        printf("%d ", c->number);
    }

    return 0;
}