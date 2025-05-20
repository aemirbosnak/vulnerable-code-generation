//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20 // Grid size configuration
#define PROBABILITY 60 // Probability of a cell being open (0-100)

// Structure to represent coordinates
typedef struct {
    int x;
    int y;
} Coordinate;

// Structure for the grid
typedef struct {
    int **cells;
    int n;
} Grid;

// Function to initialize the grid
Grid* createGrid(int size) {
    Grid *grid = malloc(sizeof(Grid));
    grid->n = size;
    grid->cells = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid->cells[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid->cells[i][j] = (rand() % 100 < PROBABILITY) ? 1 : 0; // Open (1) or blocked (0)
        }
    }
    return grid;
}

// Function to print the grid
void printGrid(Grid *grid) {
    printf("Grid (1 = Open, 0 = Blocked):\n");
    for (int i = 0; i < grid->n; i++) {
        for (int j = 0; j < grid->n; j++) {
            printf("%d ", grid->cells[i][j]);
        }
        printf("\n");
    }
}

// Function to check if coordinates are within the grid bounds
int inBounds(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

// Recursive function to explore percolation from a given cell
int percolate(Grid *grid, int x, int y, int **visited) {
    if (!inBounds(x, y, grid->n) || grid->cells[x][y] == 0 || visited[x][y]) {
        return 0; // Out of bounds, blocked or already visited
    }

    visited[x][y] = 1; // Mark as visited

    // Check for percolation reaching the bottom row
    if (x == grid->n - 1) {
        return 1; // Percolation found
    }

    // Check all four directions
    if (percolate(grid, x + 1, y, visited) ||
        percolate(grid, x - 1, y, visited) ||
        percolate(grid, x, y + 1, visited) ||
        percolate(grid, x, y - 1, visited)) {
        return 1; // If any direction leads to percolation return true
    }

    return 0; // No percolation found
}

// Function to simulate percolation
void simulatePercolation(Grid *grid) {
    int **visited = malloc(grid->n * sizeof(int *));
    for (int i = 0; i < grid->n; i++) {
        visited[i] = malloc(grid->n * sizeof(int));
        for (int j = 0; j < grid->n; j++) {
            visited[i][j] = 0; // Initialize visited cells
        }
    }

    int percolates = 0;
    // Start percolation from all cells in the first row
    for (int j = 0; j < grid->n; j++) {
        if (grid->cells[0][j] == 1 && !visited[0][j]) {
            if (percolate(grid, 0, j, visited)) {
                percolates = 1; // If any path leads to percolation, set the flag
                break;
            }
        }
    }

    printf("Does the fluid percolate? %s\n", percolates ? "YES" : "NO");

    // Free visited cells
    for (int i = 0; i < grid->n; i++) {
        free(visited[i]);
    }
    free(visited);
}

// Function to free the grid
void freeGrid(Grid *grid) {
    for (int i = 0; i < grid->n; i++) {
        free(grid->cells[i]);
    }
    free(grid->cells);
    free(grid);
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generator

    Grid *grid = createGrid(GRID_SIZE); // Create a new grid
    printGrid(grid); // Print the grid
    simulatePercolation(grid); // Run the percolation simulation
    freeGrid(grid); // Free the allocated memory

    return 0;
}