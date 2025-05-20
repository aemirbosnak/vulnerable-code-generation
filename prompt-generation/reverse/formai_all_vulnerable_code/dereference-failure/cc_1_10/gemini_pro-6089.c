//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20  // Size of the grid

// Function to create a random grid
int** create_grid() {
    int** grid = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        grid[i] = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    return grid;
}

// Function to print the grid
void print_grid(int** grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a site is open
int is_open(int** grid, int i, int j) {
    return grid[i][j] == 1;
}

// Function to check if a site is connected to the top of the grid
int is_connected_to_top(int** grid, int i, int j) {
    if (i == 0) {
        return 1;
    }
    return is_open(grid, i - 1, j) && is_connected_to_top(grid, i - 1, j);
}

// Function to check if a site is connected to the bottom of the grid
int is_connected_to_bottom(int** grid, int i, int j) {
    if (i == N - 1) {
        return 1;
    }
    return is_open(grid, i + 1, j) && is_connected_to_bottom(grid, i + 1, j);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a random grid
    int** grid = create_grid();

    // Print the grid
    print_grid(grid);

    // Check if the grid percolates
    int percolates = 0;
    for (int j = 0; j < N; j++) {
        if (is_connected_to_top(grid, 0, j) && is_connected_to_bottom(grid, N - 1, j)) {
            percolates = 1;
            break;
        }
    }

    // Print the result
    if (percolates) {
        printf("The grid percolates.\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    // Free the grid
    for (int i = 0; i < N; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}