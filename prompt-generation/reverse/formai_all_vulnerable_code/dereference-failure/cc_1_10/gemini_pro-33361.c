//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 9

typedef struct {
    int value;
    int possibilities;
} Cell;

typedef struct {
    Cell grid[GRID_SIZE][GRID_SIZE];
} SudokuGrid;

void printGrid(SudokuGrid* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid->grid[i][j].value == 0) {
                printf("   ");
            } else {
                printf("%2d ", grid->grid[i][j].value);
            }
        }
        printf("\n");
    }
}

SudokuGrid* createGrid() {
    SudokuGrid* grid = (SudokuGrid*)malloc(sizeof(SudokuGrid));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid->grid[i][j].value = 0;
            grid->grid[i][j].possibilities = 1 << GRID_SIZE;
        }
    }
    return grid;
}

void freeGrid(SudokuGrid* grid) {
    free(grid);
}

int isSafe(SudokuGrid* grid, int row, int col, int value) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid->grid[row][i].value == value) {
            return 0;
        }
        if (grid->grid[i][col].value == value) {
            return 0;
        }
    }

    int boxRow = row / 3;
    int boxCol = col / 3;
    for (int i = boxRow * 3; i < boxRow * 3 + 3; i++) {
        for (int j = boxCol * 3; j < boxCol * 3 + 3; j++) {
            if (grid->grid[i][j].value == value) {
                return 0;
            }
        }
    }

    return 1;
}

int solveSudoku(SudokuGrid* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid->grid[i][j].value == 0) {
                for (int value = 1; value <= GRID_SIZE; value++) {
                    if (isSafe(grid, i, j, value)) {
                        grid->grid[i][j].value = value;
                        if (solveSudoku(grid)) {
                            return 1;
                        } else {
                            grid->grid[i][j].value = 0;
                        }
                    }
                }

                return 0;
            }
        }
    }

    return 1;
}

int main() {
    SudokuGrid* grid = createGrid();

    printGrid(grid);
    printf("\n");

    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        printf("No solution exists.\n");
    }

    freeGrid(grid);

    return 0;
}