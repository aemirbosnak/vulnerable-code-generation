//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GRID_SIZE 9

typedef struct SudokuGrid {
    int **data;
    int size;
} SudokuGrid;

SudokuGrid* sudoku_grid_create(int size) {
    SudokuGrid* grid = malloc(sizeof(SudokuGrid));
    grid->size = size;
    grid->data = malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++) {
        grid->data[i] = 0;
    }
    return grid;
}

void sudoku_grid_set(SudokuGrid* grid, int x, int y, int value) {
    if (x < 0 || x >= grid->size || y < 0 || y >= grid->size || value < 0 || value > 9) {
        return;
    }
    grid->data[x * grid->size + y] = value;
}

int sudoku_grid_get(SudokuGrid* grid, int x, int y) {
    if (x < 0 || x >= grid->size || y < 0 || y >= grid->size) {
        return -1;
    }
    return grid->data[x * grid->size + y];
}

int sudoku_solve(SudokuGrid* grid) {
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            if (sudoku_grid_get(grid, i, j) == 0) {
                for (int k = 0; k < grid->size; k++) {
                    if (sudoku_grid_get(grid, k, j) != 0 && k != i) {
                        if (sudoku_grid_get(grid, i, k) != 0) {
                            continue;
                        }
                    }
                    sudoku_grid_set(grid, i, j, sudoku_grid_get(grid, k, j));
                    if (sudoku_solve(grid) == 1) {
                        return 1;
                    }
                    sudoku_grid_set(grid, i, j, 0);
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    SudokuGrid* grid = sudoku_grid_create(MAX_GRID_SIZE);
    sudoku_grid_set(grid, 0, 0, 5);
    sudoku_grid_set(grid, 2, 2, 3);
    sudoku_grid_set(grid, 4, 4, 9);
    sudoku_grid_set(grid, 6, 6, 1);
    sudoku_solve(grid);

    for (int i = 0; i < MAX_GRID_SIZE; i++) {
        for (int j = 0; j < MAX_GRID_SIZE; j++) {
            printf("%d ", sudoku_grid_get(grid, i, j));
        }
        printf("\n");
    }

    return 0;
}