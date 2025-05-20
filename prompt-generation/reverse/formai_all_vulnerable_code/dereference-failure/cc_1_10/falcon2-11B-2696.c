//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the probability of percolation
double percolationProbability(int gridSize, int numTrials) {
    int *grid = (int*)malloc(gridSize * gridSize * sizeof(int));
    srand(time(0));

    // Initialize the grid with 50% open cells
    for (int i = 0; i < gridSize * gridSize; i++) {
        grid[i] = rand() % 2 == 0? 1 : 0;
    }

    int numOpenCells = 0;
    int numTrees = 0;

    for (int trial = 0; trial < numTrials; trial++) {
        // Choose a random cell to start the tree
        int startCell = rand() % gridSize * gridSize;

        // Initialize the tree with the chosen cell
        int treeSize = 1;
        grid[startCell] = 1;

        // Grow the tree by adding adjacent open cells
        int x = startCell % gridSize;
        int y = startCell / gridSize;
        while (treeSize < gridSize * gridSize) {
            int dx = (x + 1) % gridSize;
            int dy = (y + 1) % gridSize;
            if (dx >= 0 && dy >= 0 && dx < gridSize && dy < gridSize && grid[dx + gridSize * dy] == 1) {
                grid[dx + gridSize * dy] = 1;
                treeSize++;
            }
        }

        // Increment the number of open cells and trees
        numOpenCells += treeSize;
        numTrees++;
    }

    free(grid);

    return numOpenCells / numTrials;
}

int main() {
    int gridSize = 50;
    int numTrials = 10000;

    double probability = percolationProbability(gridSize, numTrials);

    printf("The probability of percolation is %.6f.\n", probability);

    return 0;
}