//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 1024

int main() {
    // Allocate memory for the grid
    int **grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++) {
        grid[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Percolation
    int iterations = 0;
    while (!percolation(grid, MAX_SIZE, MAX_SIZE, iterations)) {
        iterations++;
    }

    // Print the grid
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

int percolation(int **grid, int x, int y, int iterations) {
    // Check if the grid is saturated
    if (grid[0][0] == x * y) {
        return 1;
    }

    // Randomly choose a cell
    int i = rand() % x;
    int j = rand() % y;

    // If the cell is not saturated and it has not been visited
    if (grid[i][j] == 0) {
        // Mark the cell as visited
        grid[i][j] = 1;

        // Recursively percolate the cell
        percolation(grid, x, y, iterations);

        // If the grid is saturated, return 1
        if (grid[0][0] == x * y) {
            return 1;
        }
    }

    return 0;
}