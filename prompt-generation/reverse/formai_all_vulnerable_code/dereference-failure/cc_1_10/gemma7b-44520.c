//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: medieval
#include <stdlib.h>
#include <time.h>

// Define the grid size
#define GRID_SIZE 10

// Define the number of iterations
#define ITERATIONS 1000

// Create the grid
int **grid = NULL;

// Initialize the grid
void initializeGrid() {
    grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}

// Percolation simulation
void simulatePercolation() {
    // Randomly choose a cell to activate
    int x = rand() % GRID_SIZE;
    int y = rand() % GRID_SIZE;
    grid[x][y] = 1;

    // Spread the activation to neighboring cells
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (x + dx >= 0 && x + dx < GRID_SIZE && y + dy >= 0 && y + dy < GRID_SIZE && grid[x + dx][y + dy] == 0) {
                grid[x + dx][y + dy] = 1;
            }
        }
    }
}

// Print the grid
void printGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initializeGrid();

    // Simulate percolation for the number of iterations
    for (int i = 0; i < ITERATIONS; i++) {
        simulatePercolation();
    }

    // Print the final grid
    printGrid();

    return 0;
}