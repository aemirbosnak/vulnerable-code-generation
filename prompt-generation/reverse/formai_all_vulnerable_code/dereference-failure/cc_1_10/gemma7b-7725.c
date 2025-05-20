//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define the grid size
#define GRID_SIZE 5

// Define the number of iterations
#define ITERATIONS 1000

// Define the percolation probability
#define PERCOLATION_PROB 0.5

// Create the grid
int **grid = NULL;

// Initialize the grid
void initialize_grid() {
    grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}

// Percolation simulation
void simulate_percolation() {
    for (int i = 0; i < ITERATIONS; i++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            for (int y = 0; y < GRID_SIZE; y++) {
                if (grid[x][y] == 0 && rand() % 1000 < PERCOLATION_PROB * 1000) {
                    grid[x][y] = 1;
                }
            }
        }
    }
}

// Print the grid
void print_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initialize_grid();
    simulate_percolation();
    print_grid();

    return 0;
}