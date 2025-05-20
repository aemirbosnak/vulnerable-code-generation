//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Allocate memory for the grid on the heap
int** allocateGrid(int n, int m) {
    int** grid = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        grid[i] = malloc(sizeof(int) * m);
    }
    return grid;
}

// Free the grid from the heap
void freeGrid(int** grid, int n) {
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
}

// Perform the Floyd-Warshall algorithm on the grid
void floydWarshall(int** grid, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > grid[i][k] + grid[k][j]) {
                    grid[i][j] = grid[i][k] + grid[k][j];
                }
            }
        }
    }
}

// Print the shortest paths between all pairs of vertices in the grid
void printShortestPaths(int** grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a grid of size n x n
    int n = 10;
    int** grid = allocateGrid(n, n);

    // Initialize the grid with random weights
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = rand() % 10;
        }
    }

    // Perform the Floyd-Warshall algorithm on the grid
    floydWarshall(grid, n);

    // Print the shortest paths between all pairs of vertices in the grid
    printShortestPaths(grid, n);

    // Free the grid from the heap
    freeGrid(grid, n);

    return 0;
}