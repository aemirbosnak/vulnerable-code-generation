//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRID_SIZE 10 // the size of the grid
#define PERC_THRESHOLD 0.55 // the threshold for percolation

/* Function declarations */
void initialise_grid(bool** grid);
void print_grid(bool** grid);
bool percolates(bool** grid);
void percolation_simulation(bool** grid);

/* Main function */
int main() {
    bool** grid = malloc(sizeof(bool*) * GRID_SIZE); // allocate memory for 2D grid
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = malloc(sizeof(bool) * GRID_SIZE);
    }
    
    initialise_grid(grid); // set initial values for grid
    
    printf("Initial grid:\n");
    print_grid(grid);
    
    percolation_simulation(grid); // run simulation until percolation is achieved
    
    printf("Final grid:\n");
    print_grid(grid);
    
    if (percolates(grid)) {
        printf("Percolation achieved!\n");
    } else {
        printf("Percolation not achieved :(\n");
    }
    
    // free allocated memory
    for (int i = 0; i < GRID_SIZE; i++) {
        free(grid[i]);
    }
    free(grid);
    
    return 0;
}

/* Function to set all grid values to false */
void initialise_grid(bool** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = false;
        }
    }
}

/* Function to print current grid */
void print_grid(bool** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j]) {
                printf("# "); // occupied site
            } else {
                printf(". "); // unoccupied site
            }
        }
        printf("\n");
    }
    printf("\n");
}

/* Function to check for percolation */
bool percolates(bool** grid) {
    for (int j = 0; j < GRID_SIZE; j++) {
        if (grid[0][j]) { // check top row
            for (int i = 1; i < GRID_SIZE; i++) {
                if (grid[i][j]) { // check if site is occupied
                    return true;
                }
            }
        }
    }
    return false;
}

/* Function to implement percolation simulation */
void percolation_simulation(bool** grid) {
    bool percolation_achieved = false;
    while (!percolation_achieved) {
        int occupied_sites = 0;
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if ((float)rand() / (float)RAND_MAX < PERC_THRESHOLD) { // random site ocupation
                    grid[i][j] = true;
                    occupied_sites++;
                }
            }
        }
        float perc = (float)occupied_sites / (float)(GRID_SIZE * GRID_SIZE);
        if (perc >= PERC_THRESHOLD) {
            percolation_achieved = true;
        } else {
            initialise_grid(grid); // reset grid if percolation not achieved
        }
    }
}