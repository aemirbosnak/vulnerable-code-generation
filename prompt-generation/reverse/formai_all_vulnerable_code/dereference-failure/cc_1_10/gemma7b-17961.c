//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUDO_SIZE 9

typedef struct SudokuCell {
    int number;
    struct SudokuCell* north;
    struct SudokuCell* south;
    struct SudokuCell* east;
    struct SudokuCell* west;
    struct SudokuCell* up;
    struct SudokuCell* down;
} SudokuCell;

SudokuCell* sudoku_create(int number) {
    SudokuCell* cell = (SudokuCell*)malloc(sizeof(SudokuCell));
    cell->number = number;
    cell->north = NULL;
    cell->south = NULL;
    cell->east = NULL;
    cell->west = NULL;
    cell->up = NULL;
    cell->down = NULL;
    return cell;
}

void sudoku_solve(SudokuCell* cell) {
    if (cell->number != 0) {
        return;
    }

    for (int i = 1; i <= SUDO_SIZE; i++) {
        if (sudoku_is_valid(cell, i)) {
            cell->number = i;
            sudoku_solve(cell->north);
            sudoku_solve(cell->south);
            sudoku_solve(cell->east);
            sudoku_solve(cell->west);
            sudoku_solve(cell->up);
            sudoku_solve(cell->down);
        }
    }
}

int sudoku_is_valid(SudokuCell* cell, int number) {
    if (cell->number != 0) {
        return 0;
    }

    for (SudokuCell* c = cell->north; c; c = c->north) {
        if (c->number == number) {
            return 0;
        }
    }

    for (SudokuCell* c = cell->south; c; c = c->south) {
        if (c->number == number) {
            return 0;
        }
    }

    for (SudokuCell* c = cell->east; c; c = c->east) {
        if (c->number == number) {
            return 0;
        }
    }

    for (SudokuCell* c = cell->west; c; c = c->west) {
        if (c->number == number) {
            return 0;
        }
    }

    for (SudokuCell* c = cell->up; c; c = c->up) {
        if (c->number == number) {
            return 0;
        }
    }

    for (SudokuCell* c = cell->down; c; c = c->down) {
        if (c->number == number) {
            return 0;
        }
    }

    return 1;
}

int main() {
    SudokuCell* sudoku = sudoku_create(0);
    sudoku_solve(sudoku);

    return 0;
}