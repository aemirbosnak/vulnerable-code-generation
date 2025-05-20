//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to initialize the game of life grid
void initializeGrid(int **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }
}

// Function to print the game of life grid
void printGrid(int **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to update the game of life grid
void updateGrid(int **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int liveNeighbors = countLiveNeighbors(grid, i, j, rows, cols);
            if (grid[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                grid[i][j] = 0;
            } else if (grid[i][j] == 0 && liveNeighbors == 3) {
                grid[i][j] = 1;
            }
        }
    }
}

// Function to count live neighbors of a cell
int countLiveNeighbors(int **grid, int i, int j, int rows, int cols) {
    int liveNeighbors = 0;
    if (i > 0) {
        if (grid[i - 1][j] == 1) {
            liveNeighbors++;
        }
    }
    if (j > 0) {
        if (grid[i][j - 1] == 1) {
            liveNeighbors++;
        }
    }
    if (i < rows - 1) {
        if (grid[i + 1][j] == 1) {
            liveNeighbors++;
        }
    }
    if (j < cols - 1) {
        if (grid[i][j + 1] == 1) {
            liveNeighbors++;
        }
    }
    return liveNeighbors;
}

int main() {
    int rows = 5;
    int cols = 7;

    int **grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }

    initializeGrid(grid, rows, cols);

    for (int i = 0; i < 1000; i++) {
        updateGrid(grid, rows, cols);
        printf("Generation %d:\n", i + 1);
        printGrid(grid, rows, cols);
        printf("\n");
    }

    return 0;
}