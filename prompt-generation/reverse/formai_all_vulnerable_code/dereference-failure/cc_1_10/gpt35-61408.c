//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// function prototypes
int isOpen(int** percolationGrid, int row, int col);
int isFull(int** percolationGrid, int row, int col);
void openSite(int** percolationGrid, int row, int col);
void printGrid(int** percolationGrid);

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // allocate memory for the percolation grid
    int** percolationGrid = (int**) malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++) {
        percolationGrid[i] = (int*) malloc(SIZE * sizeof(int));
    }
    
    // set all sites to closed (0)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            percolationGrid[i][j] = 0;
        }
    }
    
    // randomly open some sites
    for (int i = 0; i < SIZE/2; i++) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (isOpen(percolationGrid, row, col)) {
            i--;
        } else {
            openSite(percolationGrid, row, col);
        }
    }
    
    // print the initial percolation grid
    printf("Initial percolation grid:\n");
    printGrid(percolationGrid);
    
    // simulate percolation
    for (int i = 0; i < SIZE; i++) {
        if (isFull(percolationGrid, 0, i)) {
            printf("The system percolates!\n");
            break;
        }
    }
    
    // free memory allocated for the percolation grid
    for (int i = 0; i < SIZE; i++) {
        free(percolationGrid[i]);
    }
    free(percolationGrid);
    
    return 0;
}

// function to check if a site is open
int isOpen(int** percolationGrid, int row, int col) {
    return percolationGrid[row][col];
}

// function to check if a site is full
int isFull(int** percolationGrid, int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0; // site is not in the grid
    }
    if (percolationGrid[row][col] == 0) {
        return 0; // site is closed
    }
    if (row == SIZE-1) {
        return 1; // site is connected to top row
    }
    // check if any neighboring sites are full
    return isFull(percolationGrid, row-1, col) || isFull(percolationGrid, row+1, col) || isFull(percolationGrid, row, col-1) || isFull(percolationGrid, row, col+1);
}

// function to open a site
void openSite(int** percolationGrid, int row, int col) {
    percolationGrid[row][col] = 1;
    if (row > 0 && isOpen(percolationGrid, row-1, col)) {
        // open site to the north
        openSite(percolationGrid, row-1, col);
    }
    if (row < SIZE-1 && isOpen(percolationGrid, row+1, col)) {
        // open site to the south
        openSite(percolationGrid, row+1, col);
    }
    if (col > 0 && isOpen(percolationGrid, row, col-1)) {
        // open site to the west
        openSite(percolationGrid, row, col-1);
    }
    if (col < SIZE-1 && isOpen(percolationGrid, row, col+1)) {
        // open site to the east
        openSite(percolationGrid, row, col+1);
    }
}

// function to print the percolation grid
void printGrid(int** percolationGrid) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (percolationGrid[i][j]) {
                printf("O ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}