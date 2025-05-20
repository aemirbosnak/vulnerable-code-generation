//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Define the grid size
    int gridSize = 10;

    // Allocate memory for the grid
    int** grid = (int**)malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        grid[i] = (int*)malloc(gridSize * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    int numTrials = 1000;
    for (int t = 0; t < numTrials; t++) {
        // Randomly choose two points
        int x1 = rand() % gridSize;
        int y1 = rand() % gridSize;
        int x2 = rand() % gridSize;
        int y2 = rand() % gridSize;

        // If the two points are connected, set the grid cell at (x, y) to 1
        if (x1 - x2 == 0 || y1 - y2 == 0) {
            grid[x1][y1] = 1;
        }
    }

    // Print the grid
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < gridSize; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}