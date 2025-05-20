//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define SUDO_SIZE 9

typedef struct SudokuCell {
    int number;
    struct SudokuCell* up;
    struct SudokuCell* right;
    struct SudokuCell* down;
    struct SudokuCell* left;
} SudokuCell;

SudokuCell* createSudokuCell(int number) {
    SudokuCell* cell = (SudokuCell*)malloc(sizeof(SudokuCell));
    cell->number = number;
    cell->up = NULL;
    cell->right = NULL;
    cell->down = NULL;
    cell->left = NULL;

    return cell;
}

void solveSudoku(SudokuCell* cell) {
    if (cell->number) {
        return;
    }

    for (int i = 1; i <= SUDO_SIZE; i++) {
        if (cell->up->number != i && cell->right->number != i && cell->down->number != i && cell->left->number != i) {
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
    SudokuCell* cell = createSudokuCell(0);

    // Construct the sudoku grid
    cell->up = createSudokuCell(5);
    cell->up->up = createSudokuCell(3);
    cell->up->up->up = createSudokuCell(4);

    cell->right = createSudokuCell(6);
    cell->right->right = createSudokuCell(8);
    cell->right->right->right = createSudokuCell(9);

    cell->down = createSudokuCell(2);
    cell->down->down = createSudokuCell(7);
    cell->down->down->down = createSudokuCell(1);

    cell->left = createSudokuCell(9);
    cell->left->left = createSudokuCell(1);
    cell->left->left->left = createSudokuCell(3);

    solveSudoku(cell);

    // Print the sudoku solution
    for (SudokuCell* c = cell; c; c = c->down) {
        printf("%d ", c->number);
    }

    printf("\n");

    return 0;
}