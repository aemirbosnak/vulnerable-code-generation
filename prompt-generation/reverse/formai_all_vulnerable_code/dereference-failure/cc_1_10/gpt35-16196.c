//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Helper function to generate random values */
int get_random_value(double p) {
    double r = (double)rand() / RAND_MAX;
    return r < p;
}

/* Helper function to print the grid */
void print_grid(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

/* Helper function to free memory allocated for the grid */
void free_grid(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);
}

/* Main function to simulate percolation */
int main() {
    /* Set grid size and percolation probability */
    int size = 10;
    double p = 0.6;

    /* Allocate memory for the grid */
    int **grid = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(size * sizeof(int));
    }

    /* Initialize grid with blocked sites */
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }

    /* Open top and bottom virtual sites */
    for (int j = 0; j < size; j++) {
        grid[0][j] = 1;
        grid[size - 1][j] = 1;
    }

    /* Randomly open sites until percolation occurs */
    int percolates = 0;
    while (!percolates) {
        /* Generate random site coordinates */
        int i = rand() % size;
        int j = rand() % size;

        /* Open site if it is not already open */
        if (!grid[i][j]) {
            grid[i][j] = 1;

            /* Check if percolation occurs */
            for (int k = 0; k < size; k++) {
                if (grid[0][k] && grid[size - 1][k]) {
                    percolates = 1;
                    break;
                }
            }
        }
    }

    /* Print the final grid */
    print_grid(grid, size);

    /* Free memory allocated for the grid */
    free_grid(grid, size);

    return 0;
}