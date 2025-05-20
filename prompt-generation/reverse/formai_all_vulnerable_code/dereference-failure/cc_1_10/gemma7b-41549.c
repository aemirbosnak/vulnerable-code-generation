//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GRID_SIZE 9

typedef struct SudokuGrid {
    int grid[MAX_GRID_SIZE][MAX_GRID_SIZE];
    int solve_status;
} SudokuGrid;

SudokuGrid *sudoku_grid_init() {
    SudokuGrid *grid = malloc(sizeof(SudokuGrid));
    grid->solve_status = 0;
    for (int r = 0; r < MAX_GRID_SIZE; r++) {
        for (int c = 0; c < MAX_GRID_SIZE; c++) {
            grid->grid[r][c] = 0;
        }
    }
    return grid;
}

void sudoku_grid_set_value(SudokuGrid *grid, int r, int c, int value) {
    if (value != 0 && grid->grid[r][c] != 0) {
        return;
    }
    grid->grid[r][c] = value;
}

int sudoku_grid_is_valid(SudokuGrid *grid) {
    for (int r = 0; r < MAX_GRID_SIZE; r++) {
        for (int c = 0; c < MAX_GRID_SIZE; c++) {
            if (grid->grid[r][c] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int sudoku_grid_solve(SudokuGrid *grid) {
    if (sudoku_grid_is_valid(grid)) {
        grid->solve_status = 1;
        return 1;
    }

    for (int r = 0; r < MAX_GRID_SIZE; r++) {
        for (int c = 0; c < MAX_GRID_SIZE; c++) {
            if (grid->grid[r][c] == 0) {
                for (int v = 1; v <= MAX_GRID_SIZE; v++) {
                    sudoku_grid_set_value(grid, r, c, v);
                    if (sudoku_grid_solve(grid)) {
                        return 1;
                    }
                    sudoku_grid_set_value(grid, r, c, 0);
                }
            }
        }
    }

    return 0;
}

int main() {
    SudokuGrid *grid = sudoku_grid_init();
    sudoku_grid_set_value(grid, 0, 0, 5);
    sudoku_grid_set_value(grid, 2, 2, 3);
    sudoku_grid_set_value(grid, 4, 4, 9);

    sudoku_grid_solve(grid);

    if (grid->solve_status) {
        printf("Sudoku solution:\n");
        for (int r = 0; r < MAX_GRID_SIZE; r++) {
            for (int c = 0; c < MAX_GRID_SIZE; c++) {
                printf("%d ", grid->grid[r][c]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }

    return 0;
}