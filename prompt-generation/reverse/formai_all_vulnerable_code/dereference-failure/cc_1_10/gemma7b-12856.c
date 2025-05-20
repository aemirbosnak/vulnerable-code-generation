//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 9

typedef struct SudokuCell {
    int number;
    struct SudokuCell* up;
    struct SudokuCell* right;
    struct SudokuCell* down;
    struct SudokuCell* left;
} SudokuCell;

SudokuCell* createCell(int number) {
    SudokuCell* cell = (SudokuCell*)malloc(sizeof(SudokuCell));
    cell->number = number;
    cell->up = NULL;
    cell->right = NULL;
    cell->down = NULL;
    cell->left = NULL;

    return cell;
}

void solveSudoku(SudokuCell* cell) {
    if (cell->number != 0) {
        return;
    }

    for (int i = 1; i <= MAX_SIZE; i++) {
        if (cell->up->number == i && cell->right->number == i && cell->down->number == i && cell->left->number == i) {
            cell->number = i;
            solveSudoku(cell->up);
            solveSudoku(cell->right);
            solveSudoku(cell->down);
            solveSudoku(cell->left);
            cell->number = 0;
        }
    }
}

int main() {
    SudokuCell* cell = createCell(0);

    cell->up = createCell(5);
    cell->right = createCell(3);
    cell->down = createCell(0);
    cell->left = createCell(4);

    cell->up->up = createCell(2);
    cell->up->right = createCell(0);
    cell->up->down = cell;

    cell->right->right = createCell(0);
    cell->right->down = cell;

    cell->down->down = createCell(0);

    cell->left->left = createCell(0);
    cell->left->up = cell;

    solveSudoku(cell);

    printf("%d", cell->number);

    return 0;
}