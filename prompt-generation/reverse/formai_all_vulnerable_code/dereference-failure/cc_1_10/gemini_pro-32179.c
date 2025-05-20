//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define GRID_SIZE 20

// Probability of a cell being open
#define OPEN_PROBABILITY 0.5

// Number of simulations to run
#define NUM_SIMULATIONS 1000

// Function to generate a random grid
int** generate_grid() {
    int** grid = malloc(GRID_SIZE * sizeof(int*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = malloc(GRID_SIZE * sizeof(int));
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = (rand() < (RAND_MAX * OPEN_PROBABILITY)) ? 1 : 0;
        }
    }
    return grid;
}

// Function to check if a cell is open
int is_open(int** grid, int i, int j) {
    return (i >= 0 && i < GRID_SIZE && j >= 0 && j < GRID_SIZE && grid[i][j]);
}

// Function to check if a path exists from the top to the bottom of the grid
int percolates(int** grid) {
    // Create a queue to store the cells that need to be checked
    int queue[GRID_SIZE * GRID_SIZE];
    int front = 0, rear = 0;

    // Add the top row of cells to the queue
    for (int j = 0; j < GRID_SIZE; j++) {
        if (is_open(grid, 0, j)) {
            queue[rear++] = j;
        }
    }

    // While there are cells in the queue
    while (front != rear) {
        // Get the next cell from the queue
        int j = queue[front++];

        // Check if the cell is at the bottom of the grid
        if (j == GRID_SIZE - 1) {
            return 1;
        }

        // Add the adjacent cells to the queue
        if (is_open(grid, j + 1, j)) {
            queue[rear++] = j + 1;
        }
        if (is_open(grid, j - 1, j)) {
            queue[rear++] = j - 1;
        }
    }

    // If no path was found, return 0
    return 0;
}

// Function to run multiple simulations and calculate the percolation probability
double percolation_probability() {
    int num_percolating = 0;

    // Run the simulation multiple times
    for (int i = 0; i < NUM_SIMULATIONS; i++) {
        // Generate a random grid
        int** grid = generate_grid();

        // Check if the grid percolates
        if (percolates(grid)) {
            num_percolating++;
        }

        // Free the memory allocated for the grid
        for (int j = 0; j < GRID_SIZE; j++) {
            free(grid[j]);
        }
        free(grid);
    }

    // Return the percolation probability
    return (double)num_percolating / NUM_SIMULATIONS;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Calculate the percolation probability
    double probability = percolation_probability();

    // Print the percolation probability
    printf("Percolation probability: %.2f%%\n", probability * 100);

    return 0;
}