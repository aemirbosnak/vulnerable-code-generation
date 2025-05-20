//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // Size of the grid
#define THRESHOLD 0.6 // Probability threshold

// Function to print the grid
void print_grid(int** grid) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the bottom is accessible
int percolates(int** grid) {
    // Iterate through the bottom row
    for (int i = 0; i < SIZE; i++) {
        if (grid[SIZE-1][i] == 2) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Allocate memory for the grid
    int** grid = malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++) {
        grid[i] = malloc(SIZE * sizeof(int));
    }

    // Initialize the grid with blocked sites
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 1;
        }
    }

    // Open the top of the grid
    for (int i = 0; i < SIZE; i++) {
        grid[0][i] = 0;
    }
    
    // Keep digging until the grid percolates
    while (!percolates(grid)) {
        // Choose a random site
        int i = rand() % SIZE;
        int j = rand() % SIZE;

        // Dig the site if it is currently blocked
        if (grid[i][j] == 1 && (float)rand()/(float)RAND_MAX < THRESHOLD) {
            grid[i][j] = 0;

            // Check neighboring sites
            if (i > 0 && grid[i-1][j] == 0) {
                grid[i][j] = 2;
            }
            if (j > 0 && grid[i][j-1] == 0) {
                grid[i][j] = 2;
            }
            if (i < SIZE-1 && grid[i+1][j] == 0) {
                grid[i][j] = 2;
            }
            if (j < SIZE-1 && grid[i][j+1] == 0) {
                grid[i][j] = 2;
            }
        }

        // Print the grid
        print_grid(grid);
    }

    // Free memory
    for (int i = 0; i < SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}