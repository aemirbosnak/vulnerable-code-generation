//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array to store the grid of cells
    int **grid = NULL;
    grid = malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++) {
        grid[i] = malloc(10 * sizeof(int));
    }

    // Initialize the grid with random values
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Percolation simulation
    int num_steps = 0;
    while (!percolation(grid)) {
        num_steps++;
    }

    // Print the final grid
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    for (int i = 0; i < 10; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

int percolation(int **grid) {
    // Check if the grid is saturated
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 1) {
                return 0;
            }
        }
    }

    // Otherwise, return 1
    return 1;
}