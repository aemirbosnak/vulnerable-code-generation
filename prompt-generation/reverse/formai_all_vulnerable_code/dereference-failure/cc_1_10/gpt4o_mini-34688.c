//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int size;
    int **grid;
} PercolationGrid;

PercolationGrid *createGrid(int size) {
    PercolationGrid *pg = malloc(sizeof(PercolationGrid));
    pg->size = size;
    pg->grid = malloc(size * sizeof(int *));
    
    for(int i = 0; i < size; i++) {
        pg->grid[i] = malloc(size * sizeof(int));
        for(int j = 0; j < size; j++) {
            pg->grid[i][j] = BLOCKED; // All initially blocked
        }
    }
    return pg;
}

void freeGrid(PercolationGrid *pg) {
    for(int i = 0; i < pg->size; i++) {
        free(pg->grid[i]);
    }
    free(pg->grid);
    free(pg);
}

void openSite(PercolationGrid *pg, int row, int col) {
    if (row >= 0 && row < pg->size && col >= 0 && col < pg->size) {
        pg->grid[row][col] = OPEN;
    }
}

int isOpen(PercolationGrid *pg, int row, int col) {
    return pg->grid[row][col] == OPEN;
}

void printGrid(PercolationGrid *pg) {
    for(int i = 0; i < pg->size; i++) {
        for(int j = 0; j < pg->size; j++) {
            printf("%d ", pg->grid[i][j]);
        }
        printf("\n");
    }
}

int percolates(PercolationGrid *pg) {
    // Check if any of the sites in the bottom row are open
    for(int col = 0; col < pg->size; col++) {
        if (isOpen(pg, pg->size - 1, col)) {
            return 1; // Percolates if any bottom cell is open
        }
    }
    return 0; // Does not percolate
}

void randomOpen(PercolationGrid *pg, int numSites) {
    srand(time(0));
    for (int i = 0; i < numSites; i++) {
        int row = rand() % pg->size;
        int col = rand() % pg->size;
        openSite(pg, row, col);
    }
}

int main() {
    int size = 10; // Size of the grid
    PercolationGrid *pg = createGrid(size);
    
    // Randomly open sites
    randomOpen(pg, 30);
    
    printf("Initial Grid:\n");
    printGrid(pg);

    if (percolates(pg)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freeGrid(pg);
    return 0;
}