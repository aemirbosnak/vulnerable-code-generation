//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: scientific
/**
* C Percolation Simulator Example Program
*
* This program simulates a percolation system with a given size.
* It uses Monte Carlo simulation to determine the probability of the system percolating.
* The system is represented with a 2D grid of sites, where each site can either be open or blocked.
* The simulation runs until a percolating cluster is found, and the probability is calculated.
*
* @author John Doe
* @date 01/01/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* Function to initialize the system with blocked sites.
*
* @param grid a 2D array representing the system
* @param size the size of the system
*/
void initBlocked(int** grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j] = 0; // 0 represents a blocked site
        }
    }
}

/**
* Function to randomly open sites in the system.
*
* @param grid a 2D array representing the system
* @param size the size of the system
* @param p the probability of each site being open
*/
void openSites(int** grid, int size, double p) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            double randNum = (double) rand() / RAND_MAX;
            if (randNum < p) {
                grid[i][j] = 1; // 1 represents an open site
            }
        }
    }
}

/**
* Function to check if the system percolates.
*
* @param grid a 2D array representing the system
* @param size the size of the system
* @return 1 if the system percolates, 0 otherwise
*/
int doesPercolate(int** grid, int size) {
    int* openSites[size];
    int visited[size][size];
    int i, j;
    int percolates = 0;

    // Initialize the openSites and visited arrays
    for (i = 0; i < size; i++) {
        openSites[i] = calloc(size, sizeof(int));
        for (j = 0; j < size; j++) {
            visited[i][j] = 0;
        }
    }

    // Check if any sites on the top row are open
    for (i = 0; i < size; i++) {
        if (grid[0][i] == 1) {
            openSites[0][i] = 1;
        }
    }

    // Use depth first search to find if any open sites are connected to the bottom row
    for (i = 0; i < size; i++) {
        if (openSites[size-1][i] == 1) {
            percolates = 1;
            break;
        }
        if (grid[size-1][i] == 1) {
            int stackX[size * size];
            int stackY[size * size];
            int stackSize = 0;

            stackX[stackSize] = size-1;
            stackY[stackSize] = i;
            visited[size-1][i] = 1;

            while (stackSize >= 0) {
                int currX = stackX[stackSize];
                int currY = stackY[stackSize];
                stackSize--;

                if (currX > 0 && grid[currX-1][currY] == 1 && visited[currX-1][currY] == 0) {
                    visited[currX-1][currY] = 1;
                    stackSize++;
                    stackX[stackSize] = currX-1;
                    stackY[stackSize] = currY;
                }
                if (currX < size-1 && grid[currX+1][currY] == 1 && visited[currX+1][currY] == 0) {
                    visited[currX+1][currY] = 1;
                    stackSize++;
                    stackX[stackSize] = currX+1;
                    stackY[stackSize] = currY;
                }
                if (currY > 0 && grid[currX][currY-1] == 1 && visited[currX][currY-1] == 0) {
                    visited[currX][currY-1] = 1;
                    stackSize++;
                    stackX[stackSize] = currX;
                    stackY[stackSize] = currY-1;
                }
                if (currY < size-1 && grid[currX][currY+1] == 1 && visited[currX][currY+1] == 0) {
                    visited[currX][currY+1] = 1;
                    stackSize++;
                    stackX[stackSize] = currX;
                    stackY[stackSize] = currY+1;
                }
            }
        }
    }

    // Free the memory used by the openSites and visited arrays
    for (i = 0; i < size; i++) {
        free(openSites[i]);
    }

    return percolates;
}

/**
* Main function to run the simulation.
*/
int main() {
    int size = 20;
    double p = 0.59;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the system and open sites
    int** grid = malloc(size * sizeof(int*));
    int i;
    for (i = 0; i < size; i++) {
        grid[i] = malloc(size * sizeof(int));
    }
    initBlocked(grid, size);
    openSites(grid, size, p);

    // Run the simulation until a percolating cluster is found
    int percolates = 0;
    int attempts = 0;
    while (percolates == 0) {
        percolates = doesPercolate(grid, size);
        attempts++;
        if (attempts % 1000 == 0) {
            printf("Attempts: %d\n", attempts);
        }
        if (attempts == 1000000) {
            printf("Could not find a percolating cluster in %d attempts.\n", attempts);
            break;
        }
    }

    // Calculate the probability of percolation
    double prob = (double) attempts / (size * size);
    printf("Probability of percolation: %f\n", prob);

    // Free the memory used by the grid
    for (i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}