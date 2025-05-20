//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform the percolation simulation
int percolation(int numCells, int numNeighbors, int density) {
    int* percolatedCells = (int*)malloc(numCells * sizeof(int));
    int* visitedCells = (int*)malloc(numCells * sizeof(int));
    
    // Initialize all cells as unvisited
    for (int i = 0; i < numCells; i++) {
        visitedCells[i] = 0;
    }
    
    // Initialize percolated cells as unvisited
    for (int i = 0; i < numCells; i++) {
        percolatedCells[i] = 0;
    }
    
    // Mark cells as visited as we explore them
    int numPercolatedCells = 0;
    srand(time(0));
    
    // Run the simulation for the given density
    for (int i = 0; i < numCells; i++) {
        int r = rand() % numNeighbors;
        if (r < density) {
            percolatedCells[i] = 1;
            visitedCells[i] = 1;
            numPercolatedCells++;
        }
    }
    
    // Free memory
    free(percolatedCells);
    free(visitedCells);
    
    return numPercolatedCells;
}

int main() {
    int numCells = 1000;
    int numNeighbors = 8;
    int density = 0.05;
    
    int numPercolatedCells = percolation(numCells, numNeighbors, density);
    printf("Number of percolated cells: %d\n", numPercolatedCells);
    
    return 0;
}