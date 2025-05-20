//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20
#define PERCOLATION_THRESHOLD 0.592746

// Grid cell states
#define CELL_EMPTY 0
#define CELL_OCCUPIED 1
#define CELL_PERCOLATED 2

// Function to generate a random grid
int** generate_grid() {
    int i, j;
    int** grid = malloc(GRID_SIZE * sizeof(int*));
    for (i = 0; i < GRID_SIZE; i++) {
        grid[i] = malloc(GRID_SIZE * sizeof(int));
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    return grid;
}

// Function to print the grid
void print_grid(int** grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is occupied
int is_occupied(int** grid, int i, int j) {
    return grid[i][j] == CELL_OCCUPIED;
}

// Function to check if a cell is percolated
int is_percolated(int** grid, int i, int j) {
    return grid[i][j] == CELL_PERCOLATED;
}

// Function to check if the grid percolates
int does_grid_percolate(int** grid) {
    int i, j;
    // Check if the top row contains any percolated cells
    for (i = 0; i < GRID_SIZE; i++) {
        if (is_percolated(grid, i, 0)) {
            return 1;
        }
    }
    // Check if any cell in the bottom row is occupied
    for (i = 0; i < GRID_SIZE; i++) {
        if (is_occupied(grid, i, GRID_SIZE - 1)) {
            return 0;
        }
    }
    // Recursively check if any cell in the grid is percolated
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (is_percolated(grid, i, j)) {
                if (does_grid_percolate(grid)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Function to run the percolation simulation
int main() {
    int** grid;
    int num_iterations = 10000;
    int num_percolated = 0;
    srand(time(NULL));
    for (int i = 0; i < num_iterations; i++) {
        grid = generate_grid();
        if (does_grid_percolate(grid)) {
            num_percolated++;
        }
        for (int j = 0; j < GRID_SIZE; j++) {
            free(grid[j]);
        }
        free(grid);
    }
    double percolation_probability = (double)num_percolated / (double)num_iterations;
    printf("Percolation probability: %f\n", percolation_probability);
    return 0;
}