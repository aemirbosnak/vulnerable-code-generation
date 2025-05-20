//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the grid
void initGrid(int** grid, int size) {
    for (int i = 0; i < size; i++) {
        grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
}

// Function to print the grid
void printGrid(int** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to get the next state of the grid
void nextState(int** grid, int size) {
    // Iterate over all cells in the grid
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Check for each cell if it is alive in the next state
            int aliveNeighbors = 0;

            // Check neighbors in 8 directions
            int x = i - 1, y = j - 1;
            while (x >= 0 && y >= 0 && x < size && y < size) {
                if (grid[x][y]) {
                    aliveNeighbors++;
                }
                x -= 2;
                y -= 2;
            }

            x = i - 1, y = j + 1;
            while (x >= 0 && y < size && x < size && y < size) {
                if (grid[x][y]) {
                    aliveNeighbors++;
                }
                x -= 2;
                y += 2;
            }

            x = i + 1, y = j - 1;
            while (x < size && y >= 0 && x < size && y < size) {
                if (grid[x][y]) {
                    aliveNeighbors++;
                }
                x += 2;
                y -= 2;
            }

            x = i + 1, y = j + 1;
            while (x < size && y < size && x < size && y < size) {
                if (grid[x][y]) {
                    aliveNeighbors++;
                }
                x += 2;
                y += 2;
            }

            if (grid[i][j] && (aliveNeighbors < 2 || aliveNeighbors > 3)) {
                grid[i][j] = 0;
            } else if (!grid[i][j] && aliveNeighbors == 3) {
                grid[i][j] = 1;
            }
        }
    }
}

// Main function
int main() {
    // Set up the grid
    int size = 30;
    int** grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    initGrid(grid, size);

    // Print the initial grid
    printf("Initial grid:\n");
    printGrid(grid, size);

    // Update the grid for each iteration
    srand(time(NULL));
    int iterations = 10;
    for (int i = 0; i < iterations; i++) {
        nextState(grid, size);
        printf("Iteration %d:\n", i + 1);
        printGrid(grid, size);
    }

    // Free the allocated memory
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}