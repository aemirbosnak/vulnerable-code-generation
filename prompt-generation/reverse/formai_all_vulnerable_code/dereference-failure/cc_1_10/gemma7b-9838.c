//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int **grid = NULL;
    int size = 0;

    // Allocate memory for the grid
    grid = malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++) {
        grid[i] = malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    size = rand() % MAX_SIZE;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = 1;
        }
    }

    // Simulate percolation
    int num_percolations = 0;
    while (num_percolations < 10) {
        int x = rand() % size;
        int y = rand() % size;
        if (grid[x][y] == 0) {
            grid[x][y] = 1;
            num_percolations++;
        }
    }

    // Print the grid
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < MAX_SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}