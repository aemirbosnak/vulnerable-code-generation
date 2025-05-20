//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define GRID_WIDTH 10
#define GRID_HEIGHT 10

// Probability of a cell being open
#define OPEN_PROBABILITY 0.5

// Structure to represent a cell in the grid
typedef struct {
    int open;
    int visited;
} Cell;

// Function to create a new grid
Cell** createGrid() {
    Cell** grid = (Cell**)malloc(sizeof(Cell*) * GRID_HEIGHT);
    for (int i = 0; i < GRID_HEIGHT; i++) {
        grid[i] = (Cell*)malloc(sizeof(Cell) * GRID_WIDTH);
    }

    // Initialize the grid with closed cells
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            grid[i][j].open = 0;
            grid[i][j].visited = 0;
        }
    }

    return grid;
}

// Function to free the grid
void freeGrid(Cell** grid) {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        free(grid[i]);
    }
    free(grid);
}

// Function to open a cell
void openCell(Cell** grid, int i, int j) {
    grid[i][j].open = 1;
}

// Function to close a cell
void closeCell(Cell** grid, int i, int j) {
    grid[i][j].open = 0;
}

// Function to check if a cell is open
int isCellOpen(Cell** grid, int i, int j) {
    return grid[i][j].open;
}

// Function to check if a cell has been visited
int isCellVisited(Cell** grid, int i, int j) {
    return grid[i][j].visited;
}

// Function to visit a cell
void visitCell(Cell** grid, int i, int j) {
    grid[i][j].visited = 1;
}

// Function to generate a random number between 0 and 1
double randomNumber() {
    return (double)rand() / (double)RAND_MAX;
}

// Function to perform the percolation simulation
int doPercolationSimulation(Cell** grid) {
    // Open cells randomly with the given probability
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (randomNumber() < OPEN_PROBABILITY) {
                openCell(grid, i, j);
            }
        }
    }

    // Perform a depth-first search to find a path from the top to the bottom of the grid
    int percolates = 0;
    for (int i = 0; i < GRID_WIDTH; i++) {
        if (isCellOpen(grid, 0, i)) {
            percolates = doDepthFirstSearch(grid, 0, i);
            if (percolates) {
                break;
            }
        }
    }

    return percolates;
}

// Function to perform a depth-first search from a given cell
int doDepthFirstSearch(Cell** grid, int i, int j) {
    // Check if the cell is within the bounds of the grid
    if (i < 0 || i >= GRID_HEIGHT || j < 0 || j >= GRID_WIDTH) {
        return 0;
    }

    // Check if the cell is open and has not been visited
    if (!isCellOpen(grid, i, j) || isCellVisited(grid, i, j)) {
        return 0;
    }

    // Visit the cell
    visitCell(grid, i, j);

    // Check if the cell is at the bottom of the grid
    if (i == GRID_HEIGHT - 1) {
        return 1;
    }

    // Recursively search the adjacent cells
    int percolates = 0;
    percolates |= doDepthFirstSearch(grid, i + 1, j);
    percolates |= doDepthFirstSearch(grid, i, j + 1);
    percolates |= doDepthFirstSearch(grid, i, j - 1);

    return percolates;
}

// Function to print the grid
void printGrid(Cell** grid) {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            printf("%d ", isCellOpen(grid, i, j));
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new grid
    Cell** grid = createGrid();

    // Perform the percolation simulation
    int percolates = doPercolationSimulation(grid);

    // Print the grid
    printGrid(grid);

    // Free the grid
    freeGrid(grid);

    // Print the result
    printf("Percolates: %d\n", percolates);

    return 0;
}