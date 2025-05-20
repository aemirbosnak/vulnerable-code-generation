//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20

// Struct to represent a site on the grid
typedef struct {
    int is_open;
    int is_connected;
} Site;

// Function to create a new grid of sites
Site** create_grid() {
    // Allocate memory for the grid
    Site** grid = malloc(GRID_SIZE * sizeof(Site*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = malloc(GRID_SIZE * sizeof(Site));
    }

    // Initialize the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j].is_open = 0;
            grid[i][j].is_connected = 0;
        }
    }

    return grid;
}

// Function to destroy a grid of sites
void destroy_grid(Site** grid) {
    // Free the memory for each row in the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        free(grid[i]);
    }

    // Free the memory for the grid itself
    free(grid);
}

// Function to open a site on the grid
void open_site(Site** grid, int row, int col) {
    grid[row][col].is_open = 1;
}

// Function to check if a site is open
int is_open(Site** grid, int row, int col) {
    return grid[row][col].is_open;
}

// Function to check if a site is connected to the top of the grid
int is_connected_to_top(Site** grid, int row, int col) {
    // Base case: if we're at the top of the grid, we're connected to the top
    if (row == 0) {
        return 1;
    }

    // Recursive case: if the site above us is open and connected to the top, then we're connected to the top
    else if (is_open(grid, row - 1, col) && is_connected_to_top(grid, row - 1, col)) {
        return 1;
    }

    // Otherwise, we're not connected to the top
    else {
        return 0;
    }
}

// Function to perform a depth-first search to find all connected sites to a given site
void dfs(Site** grid, int row, int col) {
    // Mark the site as connected
    grid[row][col].is_connected = 1;

    // Recursively visit all adjacent sites that are open and not yet connected
    if (row > 0 && is_open(grid, row - 1, col) && !grid[row - 1][col].is_connected) {
        dfs(grid, row - 1, col);
    }
    if (row < GRID_SIZE - 1 && is_open(grid, row + 1, col) && !grid[row + 1][col].is_connected) {
        dfs(grid, row + 1, col);
    }
    if (col > 0 && is_open(grid, row, col - 1) && !grid[row][col - 1].is_connected) {
        dfs(grid, row, col - 1);
    }
    if (col < GRID_SIZE - 1 && is_open(grid, row, col + 1) && !grid[row][col + 1].is_connected) {
        dfs(grid, row, col + 1);
    }
}

// Function to check if the grid percolates
int percolates(Site** grid) {
    // Perform a depth-first search from the bottom row of the grid to find all connected sites
    for (int i = 0; i < GRID_SIZE; i++) {
        if (is_open(grid, GRID_SIZE - 1, i) && is_connected_to_top(grid, GRID_SIZE - 1, i)) {
            return 1;
        }
    }

    // If no connected sites were found, the grid does not percolate
    return 0;
}

// Function to print the grid
void print_grid(Site** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j].is_open);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new grid
    Site** grid = create_grid();

    // Open a random number of sites on the grid
    for (int i = 0; i < GRID_SIZE * GRID_SIZE / 2; i++) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        open_site(grid, row, col);
    }

    // Print the grid
    print_grid(grid);

    // Check if the grid percolates
    int does_percolate = percolates(grid);

    // Print the result
    printf("The grid %s percolate.\n", does_percolate ? "does" : "does not");

    // Destroy the grid
    destroy_grid(grid);

    return 0;
}