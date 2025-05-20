//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9

typedef struct SudokuCell {
    int number;
    struct SudokuCell* up;
    struct SudokuCell* down;
    struct SudokuCell* left;
    struct SudokuCell* right;
} SudokuCell;

SudokuCell* createCell(int number) {
    SudokuCell* cell = (SudokuCell*)malloc(sizeof(SudokuCell));
    cell->number = number;
    cell->up = NULL;
    cell->down = NULL;
    cell->left = NULL;
    cell->right = NULL;
    return cell;
}

void solveSudoku(SudokuCell* cell) {
    if (cell->number == 0) {
        for (int i = 1; i <= MAX_SIZE; i++) {
            if (cell->up->number != i && cell->down->number != i && cell->left->number != i && cell->right->number != i) {
                cell->number = i;
                solveSudoku(cell->up);
                solveSudoku(cell->down);
                solveSudoku(cell->left);
                solveSudoku(cell->right);
                if (cell->number != 0) {
                    return;
                }
            }
        }
        return;
    }
}

int main() {
    SudokuCell* cell = createCell(0);
    solveSudoku(cell);
    printf("Solution:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%d ", cell->number);
        }
        printf("\n");
    }
    return 0;
}