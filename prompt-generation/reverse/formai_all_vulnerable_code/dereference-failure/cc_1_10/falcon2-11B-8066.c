//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to create a 2D array of size (width x height) with all cells initialized to 0
int** createGrid(int width, int height) {
    int** grid = (int**)malloc(width * sizeof(int*));
    for (int i = 0; i < width; i++) {
        grid[i] = (int*)malloc(height * sizeof(int));
        for (int j = 0; j < height; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

// Function to print the grid
void printGrid(int** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to simulate percolation in the grid
void percolation(int** grid, int width, int height, int density) {
    int** visited = createGrid(width, height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            visited[i][j] = 0;
        }
    }
    int numOpen = 0;
    int numOpenNeighbors = 0;
    int numIterations = 0;
    while (numOpen < (width * height * density) && numIterations < 1000) {
        numIterations++;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    visited[i][j] = 1;
                    numOpenNeighbors = 0;
                    for (int k = -1; k <= 1; k++) {
                        for (int l = -1; l <= 1; l++) {
                            if ((k == 0 && l == 0) || i + k < 0 || j + l < 0 || i + k >= width || j + l >= height) {
                                continue;
                            }
                            if (grid[i + k][j + l] == 1) {
                                numOpenNeighbors++;
                            }
                        }
                    }
                    if (numOpenNeighbors >= 2) {
                        for (int k = -1; k <= 1; k++) {
                            for (int l = -1; l <= 1; l++) {
                                if ((k == 0 && l == 0) || i + k < 0 || j + l < 0 || i + k >= width || j + l >= height) {
                                    continue;
                                }
                                if (grid[i + k][j + l] == 0) {
                                    grid[i + k][j + l] = 1;
                                    numOpen++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printGrid(grid, width, height);
}

int main() {
    int width = 10;
    int height = 10;
    int density = 0.5;
    int** grid = createGrid(width, height);
    percolation(grid, width, height, density);
    free(grid);
    return 0;
}