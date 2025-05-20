//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void percolate(int **grid, int rows, int cols) {
    int i, j;
    int temp;

    // Loop through all the cells in the grid
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            // If the current cell is empty
            if (grid[i][j] == 0) {
                // Check the neighboring cells
                if (j > 0 && grid[i][j - 1] == 1) {
                    grid[i][j] = 1;
                    percolate(grid, rows, cols);
                    return;
                }
                if (j < cols - 1 && grid[i][j + 1] == 1) {
                    grid[i][j] = 1;
                    percolate(grid, rows, cols);
                    return;
                }
                if (i > 0 && grid[i - 1][j] == 1) {
                    grid[i][j] = 1;
                    percolate(grid, rows, cols);
                    return;
                }
                if (i < rows - 1 && grid[i + 1][j] == 1) {
                    grid[i][j] = 1;
                    percolate(grid, rows, cols);
                    return;
                }
            }
        }
    }
}

int main() {
    int rows = 10, cols = 10;
    int **grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Initialize the grid
    percolate(grid, rows, cols);

    // Print the grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}