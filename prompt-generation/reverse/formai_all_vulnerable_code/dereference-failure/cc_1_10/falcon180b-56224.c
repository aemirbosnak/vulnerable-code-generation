//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // number of nodes
#define P 0.5 // probability of a node being open

void init(int *grid) {
    for (int i = 0; i < N; i++) {
        grid[i] = 0; // closed
    }
}

void percolate(int *grid) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (grid[i] == 1) {
            count++;
        }
    }
    if (count == 0) {
        printf("No percolation\n");
    } else {
        printf("Percolation with %d clusters\n", count);
    }
}

void print_grid(int *grid) {
    for (int i = 0; i < N; i++) {
        if (grid[i] == 1) {
            printf("X ");
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // seed the random number generator

    int *grid = (int *)malloc(N * sizeof(int)); // allocate memory for the grid

    init(grid); // initialize the grid to all closed

    for (int i = 0; i < N; i++) {
        if (rand() % 100 < P * 100) { // open the node with probability P
            grid[i] = 1;
        }
    }

    percolate(grid); // check for percolation

    print_grid(grid); // print the final grid

    free(grid); // free the memory used by the grid

    return 0;
}