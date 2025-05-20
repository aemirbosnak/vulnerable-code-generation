//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS 1000

// Define a grid of squares
typedef struct Square {
    int x;
    int y;
    int state;
} Square;

// Function to simulate percolation
void simulatePercolation(Square **grid, int size) {
    // Randomly assign a state to each square
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j].state = rand() % 2;
        }
    }

    // Iterate over the number of iterations
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        // For each square, check if it is connected to a wet square
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j].state == 1) {
                    // If the square is not wet, and it has a wet neighbor, make it wet
                    if (grid[i][j].state == 0 && (grid[i-1][j].state == 1 || grid[i+1][j].state == 1 || grid[i][j-1].state == 1 || grid[i][j+1].state == 1)) {
                        grid[i][j].state = 1;
                    }
                }
            }
        }
    }

    // Print the final state of the grid
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j].state);
        }
        printf("\n");
    }
}

int main() {
    // Define the size of the grid
    int size = 5;

    // Allocate memory for the grid
    Square **grid = (Square **)malloc(size * size * sizeof(Square));
    for (int i = 0; i < size; i++) {
        grid[i] = (Square *)malloc(size * sizeof(Square));
        for (int j = 0; j < size; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].state = 0;
        }
    }

    // Simulate percolation
    simulatePercolation(grid, size);

    // Free memory
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}