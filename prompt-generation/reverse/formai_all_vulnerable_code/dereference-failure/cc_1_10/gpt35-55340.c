//FormAI DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 20

// Returns a randomly generated starting grid
int** initGrid() {
    int** grid = (int**) malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        grid[i] = (int*) malloc(sizeof(int) * COLS);
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2; // Either 0 or 1
        }
    }
    return grid;
}

// Prints grid to console
void printGrid(int** grid) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] ? '#' : '-');
        }
        printf("\n");
    }
}

// Returns the number of living neighbors for given cell
int getLivingNeighbors(int** grid, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighborX = x + i;
            int neighborY = y + j;
            if (i == 0 && j == 0) continue; // Skip self
            if (neighborX < 0 || neighborX >= ROWS) continue; // Skip if out of bounds
            if (neighborY < 0 || neighborY >= COLS) continue; // Skip if out of bounds
            if (grid[neighborX][neighborY]) count++;
        }
    }
    return count;
}

// Returns updated cell status
int updatedCellStatus(int** grid, int x, int y) {
    int neighbors = getLivingNeighbors(grid, x, y);
    if (grid[x][y]) {
        if (neighbors < 2 || neighbors > 3) return 0; // Underpopulation or overpopulation
        else return 1; // Survives
    } else {
        if (neighbors == 3) return 1; // Reproduction
        else return 0; // Stays dead
    }
}

// Updates all cells in the grid
void updateGrid(int** grid) {
    int** newGrid = (int**) malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        newGrid[i] = (int*) malloc(sizeof(int) * COLS);
        for (int j = 0; j < COLS; j++) {
            newGrid[i][j] = updatedCellStatus(grid, i, j);
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
        free(newGrid[i]);
    }
    free(newGrid);
}

int main() {
    int** grid = initGrid();
    for (int i = 0; i < 20; i++) { // Run for 20 generations
        printGrid(grid);
        printf("\n");
        updateGrid(grid);
    }
    for (int i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}