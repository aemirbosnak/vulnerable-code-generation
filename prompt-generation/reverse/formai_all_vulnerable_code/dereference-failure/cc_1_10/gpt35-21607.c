//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Struct that represents a site in the percolation grid
typedef struct Site {
    int row;
    int col;
    int isOpen;
    int isFull;
} Site;


// Function declarations
Site **createGrid(int size);
void openSite(Site **grid, int row, int col);
void percolate(Site **grid, int size);
int isPercolating(Site **grid, int size);
void printGrid(Site **grid, int size);


int main() {
    int size = 10;
    Site **grid = createGrid(size);

    percolate(grid, size);
    printGrid(grid, size);

    // Free memory
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}


// Creates a size x size grid of closed sites
Site **createGrid(int size) {
    Site **grid = malloc(size * sizeof(Site *));
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(size * sizeof(Site));
        for (int j = 0; j < size; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].isOpen = 0;
            grid[i][j].isFull = 0;
        }
    }
    return grid;
}


// Opens the site at the given row and column
void openSite(Site **grid, int row, int col) {
    grid[row][col].isOpen = 1;
}


// Simulates percolation on the grid
void percolate(Site **grid, int size) {
    srand(time(NULL));  // Use current time as seed for random generator

    // Open sites randomly until the grid percolates
    while (!isPercolating(grid, size)) {
        int row = rand() % size;
        int col = rand() % size;
        openSite(grid, row, col);
    }
}


// Checks whether the grid is percolating
int isPercolating(Site **grid, int size) {
    // Mark all open sites in the top row as full
    for (int j = 0; j < size; j++) {
        if (grid[0][j].isOpen) {
            grid[0][j].isFull = 1;
        }
    }

    // Mark all connected open sites as full
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j].isOpen &&
                (grid[i-1][j].isFull || 
                 (j > 0 && grid[i][j-1].isFull) || 
                 (j < size-1 && grid[i][j+1].isFull))) {
                grid[i][j].isFull = 1;
            }
        }
    }

    // Check if there is a full site in the bottom row
    for (int j = 0; j < size; j++) {
        if (grid[size-1][j].isFull) {
            return 1;
        }
    }

    return 0;
}


// Prints the grid to the console
void printGrid(Site **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j].isOpen) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}