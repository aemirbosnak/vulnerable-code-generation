//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print the percolation grid
void printGrid(int *grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (*(grid + i * n + j) == 0) {
                printf(". ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

// function to check if the grid percolates
int percolates(int *grid, int n) {
    for (int j = 0; j < n; j++) {
        if (*(grid + (n-1) * n + j) == 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL)); // seed the random number generator

    int n = 10; // grid size
    int *grid = malloc(n * n * sizeof(int)); // allocate memory for the grid
    
    // initialize grid to all 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(grid + i * n + j) = 0;
        }
    }

    // randomly choose cells to become open
    for (int i = 0; i < n * n / 2; i++) {
        int r = rand() % n;
        int c = rand() % n;
        *(grid + r * n + c) = 1;
    }

    printGrid(grid, n); // print the initial grid

    // loop until the grid percolates or all cells are filled
    int count = 0;
    while (!percolates(grid, n) && count < n * n) {
        int r = rand() % n;
        int c = rand() % n;
        if (*(grid + r * n + c) == 0) {
            *(grid + r * n + c) = 1;
            count++;
        }
    }

    printf("\n");
    printGrid(grid, n); // print the final grid
    
    // free the allocated memory
    free(grid);

    return 0;
}