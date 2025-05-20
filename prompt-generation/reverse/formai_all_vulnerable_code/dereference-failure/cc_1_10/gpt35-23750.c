//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create a struct to represent a cell in the grid
typedef struct cell {
    int status; // 0 for blocked, 1 for open
    int visited; // 0 for unvisited, 1 for visited
} Cell;

// Function to initialize all cells as blocked and unvisited
void initializeGrid(Cell** grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j].status = 0;
            grid[i][j].visited = 0;
        }
    }
}

// Function to randomly open cells in the top row of the grid
void openRandomCells(Cell** grid, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int randNum = rand() % 2; // 50% chance of opening cell
        if (randNum == 1) {
            grid[0][i].status = 1;
        }
    }
}

// Function to check if a cell is valid (inside the grid and unvisited)
int isValid(Cell** grid, int i, int j, int n) {
    if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j].visited == 1) {
        return 0;
    }
    return 1;
}

// Recursive function to explore open cells and mark them as visited
void exploreOpenCells(Cell** grid, int i, int j, int n) {
    grid[i][j].visited = 1;
    if (isValid(grid, i-1, j, n) && grid[i-1][j].status == 1) {
        exploreOpenCells(grid, i-1, j, n); // up
    }
    if (isValid(grid, i+1, j, n) && grid[i+1][j].status == 1) {
        exploreOpenCells(grid, i+1, j, n); // down
    }
    if (isValid(grid, i, j-1, n) && grid[i][j-1].status == 1) {
        exploreOpenCells(grid, i, j-1, n); // left
    }
    if (isValid(grid, i, j+1, n) && grid[i][j+1].status == 1) {
        exploreOpenCells(grid, i, j+1, n); // right
    }
}

// Function to check if there is a percolation path from top row to bottom row
int percolates(Cell** grid, int n) {
    for (int j = 0; j < n; j++) {
        if (grid[n-1][j].status == 1 && grid[n-1][j].visited == 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n = 20; // size of grid
    Cell** grid = malloc(n * sizeof(Cell*));
    for (int i = 0; i < n; i++) {
        grid[i] = malloc(n * sizeof(Cell));
    }

    initializeGrid(grid, n);
    openRandomCells(grid, n);
    for (int i = 0; i < n; i++) {
        if (grid[0][i].status == 1 && grid[0][i].visited == 0) {
            exploreOpenCells(grid, 0, i, n);
        }
    }
    int percolation = percolates(grid, n);
    if (percolation == 1) {
        printf("Percolation detected!\n");
    } else {
        printf("No percolation detected.\n");
    }

    // Free memory used for grid
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}