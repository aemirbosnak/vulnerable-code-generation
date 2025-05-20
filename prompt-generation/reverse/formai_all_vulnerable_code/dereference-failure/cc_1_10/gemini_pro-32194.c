//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define N 100

// Probability of a cell being open
#define P 0.5

// Number of Monte Carlo simulations
#define M 10000

// Function to generate a random grid
int** generate_grid() {
    int** grid = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        grid[i] = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            grid[i][j] = (rand() < P * RAND_MAX);
        }
    }
    return grid;
}

// Function to check if a cell is open
int is_open(int** grid, int i, int j) {
    return grid[i][j] == 1;
}

// Function to check if a cell is on the top row
int is_top_row(int i) {
    return i == 0;
}

// Function to check if a cell is on the bottom row
int is_bottom_row(int i) {
    return i == N - 1;
}

// Function to check if a cell is on the leftmost column
int is_leftmost_column(int j) {
    return j == 0;
}

// Function to check if a cell is on the rightmost column
int is_rightmost_column(int j) {
    return j == N - 1;
}

// Function to check if a cell is percolating
int is_percolating(int** grid) {
    // Check if the top row is open
    for (int j = 0; j < N; j++) {
        if (is_open(grid, 0, j)) {
            // Recursively check if the cell below is open
            if (is_percolating_helper(grid, 1, j)) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if a cell is percolating (helper function)
int is_percolating_helper(int** grid, int i, int j) {
    // Check if the cell is open
    if (!is_open(grid, i, j)) {
        return 0;
    }

    // Check if the cell is on the bottom row
    if (is_bottom_row(i)) {
        return 1;
    }

    // Recursively check if the cell below, to the right, or to the left is open
    return is_percolating_helper(grid, i + 1, j) ||
           is_percolating_helper(grid, i, j + 1) ||
           is_percolating_helper(grid, i, j - 1);
}

// Function to run a Monte Carlo simulation
int run_simulation() {
    // Generate a random grid
    int** grid = generate_grid();

    // Check if the grid is percolating
    int percolating = is_percolating(grid);

    // Free the grid
    for (int i = 0; i < N; i++) {
        free(grid[i]);
    }
    free(grid);

    return percolating;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Run the Monte Carlo simulation M times
    int num_percolating = 0;
    for (int i = 0; i < M; i++) {
        num_percolating += run_simulation();
    }

    // Print the results
    printf("Percolation probability: %f\n", (double)num_percolating / M);

    return 0;
}