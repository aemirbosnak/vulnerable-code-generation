//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 20 // Dimension of the square grid
#define THRESHOLD 0.55 // Probability threshold for site percolation

typedef struct {
    int **grid;
    int size;
} PercolationGrid;

PercolationGrid* createGrid(int size) {
    PercolationGrid* pGrid = malloc(sizeof(PercolationGrid));
    pGrid->size = size;
    pGrid->grid = malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++) {
        pGrid->grid[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            // Randomly assign sites as open (1) or blocked (0)
            pGrid->grid[i][j] = (rand() / (double)RAND_MAX) < THRESHOLD ? 1 : 0;
        }
    }
    return pGrid;
}

void freeGrid(PercolationGrid* pGrid) {
    for (int i = 0; i < pGrid->size; i++) {
        free(pGrid->grid[i]);
    }
    free(pGrid->grid);
    free(pGrid);
}

bool isSafe(int x, int y, PercolationGrid* pGrid, bool **visited) {
    return (x >= 0 && y >= 0 && x < pGrid->size && y < pGrid->size && 
            pGrid->grid[x][y] == 1 && !visited[x][y]);
}

bool dfs(int x, int y, PercolationGrid* pGrid, bool **visited) {
    if (x == pGrid->size - 1) {
        return true; // Reached the last row, percolation occurs
    }

    visited[x][y] = true; // Mark this cell as visited

    // Define movements in 4 directions
    int rowNum[] = {-1, 1, 0, 0};
    int colNum[] = {0, 0, -1, 1};

    // Explore all adjacent cells
    for (int k = 0; k < 4; k++) {
        int newX = x + rowNum[k];
        int newY = y + colNum[k];
        if (isSafe(newX, newY, pGrid, visited)) {
            if (dfs(newX, newY, pGrid, visited))
                return true;
        }
    }
    return false; // No path found
}

bool percolates(PercolationGrid* pGrid) {
    bool **visited = malloc(pGrid->size * sizeof(bool*));
    for (int i = 0; i < pGrid->size; i++) {
        visited[i] = calloc(pGrid->size, sizeof(bool));
    }

    for (int j = 0; j < pGrid->size; j++) {
        if (pGrid->grid[0][j] == 1 && !visited[0][j]) {
            if (dfs(0, j, pGrid, visited)) {
                for (int i = 0; i < pGrid->size; i++) free(visited[i]);
                free(visited);
                return true; // Percolation found
            }
        }
    }

    for (int i = 0; i < pGrid->size; i++) free(visited[i]);
    free(visited);
    return false; // No percolation
}

void printGrid(PercolationGrid* pGrid) {
    for (int i = 0; i < pGrid->size; i++) {
        for (int j = 0; j < pGrid->size; j++) {
            printf("%d ", pGrid->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    PercolationGrid* pGrid = createGrid(GRID_SIZE);
    printf("Percolation Grid (%d x %d):\n", GRID_SIZE, GRID_SIZE);
    printGrid(pGrid);

    if (percolates(pGrid)) {
        printf("\nThe system percolates!\n");
    } else {
        printf("\nThe system does not percolate.\n");
    }

    freeGrid(pGrid);
    return 0;
}