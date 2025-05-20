//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: life N M S\n");
        printf("    N: number of rows\n");
        printf("    M: number of columns\n");
        printf("    S: number of generations to simulate\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int s = atoi(argv[3]);

    bool **grid = malloc(n * sizeof(bool *));
    for (int i = 0; i < n; i++) {
        grid[i] = malloc(m * sizeof(bool));
    }

    // Initialize the grid randomly
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Simulate the Game of Life for s generations
    for (int t = 0; t < s; t++) {
        // Count the number of living neighbors for each cell
        int **neighbors = malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            neighbors[i] = malloc(m * sizeof(int));
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                neighbors[i][j] = 0;
                if (i > 0) {
                    neighbors[i][j] += grid[i - 1][j];
                    if (j > 0) {
                        neighbors[i][j] += grid[i - 1][j - 1];
                    }
                    if (j < m - 1) {
                        neighbors[i][j] += grid[i - 1][j + 1];
                    }
                }
                if (j > 0) {
                    neighbors[i][j] += grid[i][j - 1];
                }
                if (j < m - 1) {
                    neighbors[i][j] += grid[i][j + 1];
                }
                if (i < n - 1) {
                    neighbors[i][j] += grid[i + 1][j];
                    if (j > 0) {
                        neighbors[i][j] += grid[i + 1][j - 1];
                    }
                    if (j < m - 1) {
                        neighbors[i][j] += grid[i + 1][j + 1];
                    }
                }
            }
        }

        // Update the grid based on the number of living neighbors
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    if (neighbors[i][j] < 2 || neighbors[i][j] > 3) {
                        grid[i][j] = false;
                    }
                } else {
                    if (neighbors[i][j] == 3) {
                        grid[i][j] = true;
                    }
                }
            }
        }

        // Free the memory allocated for the neighbors array
        for (int i = 0; i < n; i++) {
            free(neighbors[i]);
        }
        free(neighbors);
    }

    // Print the final state of the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}