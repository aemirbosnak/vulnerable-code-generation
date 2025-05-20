//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int z;
} Point;

int main() {
    // Seed the random number generator with current time
    srand(time(NULL));
    
    // Create a grid of cells
    int gridSize = 100;
    Point** grid = (Point**)malloc(gridSize * sizeof(Point*));
    for (int i = 0; i < gridSize; i++) {
        grid[i] = (Point*)malloc(gridSize * sizeof(Point));
    }
    
    // Initialize the grid with random values
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            int x = rand() % 2;
            int y = rand() % 2;
            int z = rand() % 2;
            grid[i][j].x = x;
            grid[i][j].y = y;
            grid[i][j].z = z;
        }
    }
    
    // Check for percolation
    int percolationCount = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j].x && grid[i][j].y && grid[i][j].z) {
                percolationCount++;
            }
        }
    }
    
    printf("Percolation count: %d\n", percolationCount);
    
    // Free memory
    for (int i = 0; i < gridSize; i++) {
        free(grid[i]);
    }
    free(grid);
    
    return 0;
}