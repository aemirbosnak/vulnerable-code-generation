//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the percolation grid
void initializeGrid(int** grid, int size) {
    for (int i = 0; i < size; i++) {
        grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
}

// Function to simulate percolation
void simulatePercolation(int** grid, int size) {
    int** visited = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        visited[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            visited[i][j] = 0;
        }
    }

    int** active = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        active[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            active[i][j] = 0;
        }
    }

    // Simulate percolation for 1000 iterations
    for (int i = 0; i < 1000; i++) {
        // Choose a random cell to start percolation
        int x = rand() % size;
        int y = rand() % size;
        if (grid[x][y] == 0) {
            active[x][y] = 1;
        }

        // Check if the active cell is connected to a neighboring cell
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) {
                    continue;
                }
                int newX = x + dx;
                int newY = y + dy;
                if (newX >= 0 && newX < size && newY >= 0 && newY < size) {
                    if (active[newX][newY] == 1) {
                        visited[x][y] = 1;
                        break;
                    }
                }
            }
        }

        // If the active cell is connected to a neighboring cell, increase the percolation probability
        int probability = rand() % 100;
        if (probability < 10) {
            grid[x][y] = 1;
        } else {
            grid[x][y] = 0;
        }
    }

    // Print the final percolation grid
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < size; i++) {
        free(visited[i]);
    }
    free(visited);
    for (int i = 0; i < size; i++) {
        free(active[i]);
    }
    free(active);
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);
}

int main() {
    int size = 20;
    int** grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    initializeGrid(grid, size);

    simulatePercolation(grid, size);

    return 0;
}