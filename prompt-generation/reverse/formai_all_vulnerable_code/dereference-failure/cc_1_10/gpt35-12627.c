//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function to check whether a site is open or not
int is_open(int row, int col, int *grid) {
    return *(grid + row*SIZE + col);
}

// Function to open a site
void open(int row, int col, int *grid) {
    *(grid + row*SIZE + col) = 1;
}

// Function to check whether the system percolates or not
int percolates(int *grid) {
    // Check if any site on the bottom row is connected to a site on the top row
    for(int i=0; i<SIZE; i++) {
        if (*(grid + (SIZE-1)*SIZE + i) == 1) {
            for(int j=0; j<SIZE; j++) {
                if(*(grid + j*SIZE + i) == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Function to randomly open a site
void random_open(int *grid) {
    int row = rand()%SIZE;
    int col = rand()%SIZE;
    open(row, col, grid);
}

int main() {
    int *grid = (int *)malloc(SIZE*SIZE*sizeof(int)); // Allocating memory for grid
    srand(time(NULL)); // Initializing the random number generator with current time

    // Initializing all sites as closed (0)
    for(int i=0; i<SIZE*SIZE; i++) {
        *(grid + i) = 0;
    }

    // Opening sites randomly until the system percolates
    while(!percolates(grid)) {
        random_open(grid);
    }

    // Printing the percolation cluster
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(*(grid + i*SIZE + j) == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    free(grid); // Freeing the allocated memory
    return 0;
}