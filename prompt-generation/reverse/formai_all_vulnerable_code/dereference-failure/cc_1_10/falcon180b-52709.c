//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30
#define POROSITY 0.5

int** createGrid();
void randomFill(int** grid);
void displayGrid(int** grid);
void percolate(int** grid);
int countAdjacent(int** grid, int row, int col);

int main() {
    int** grid = createGrid();
    randomFill(grid);
    displayGrid(grid);
    percolate(grid);
    return 0;
}

int** createGrid() {
    int** grid = (int**)malloc(ROWS * sizeof(int*));
    for (int i = 0; i < ROWS; i++) {
        grid[i] = (int*)malloc(COLS * sizeof(int));
    }
    return grid;
}

void randomFill(int** grid) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (rand() % 100 < POROSITY * 100) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

void displayGrid(int** grid) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

void percolate(int** grid) {
    int** newGrid = createGrid();
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int count = countAdjacent(grid, i, j);
            if (grid[i][j] == 1 && count == 0) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] == 0 && count > 0) {
                newGrid[i][j] = 1;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
    free(newGrid);
}

int countAdjacent(int** grid, int row, int col) {
    int count = 0;
    if (grid[row - 1][col] == 1) {
        count++;
    }
    if (grid[row + 1][col] == 1) {
        count++;
    }
    if (grid[row][col - 1] == 1) {
        count++;
    }
    if (grid[row][col + 1] == 1) {
        count++;
    }
    return count;
}