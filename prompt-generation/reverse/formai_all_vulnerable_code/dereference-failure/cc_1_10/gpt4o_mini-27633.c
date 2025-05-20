//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

typedef struct {
    int** grid;
    int size;
} Percolation;

Percolation* createPercolation(int size) {
    Percolation* perc = (Percolation*)malloc(sizeof(Percolation));
    perc->size = size;
    perc->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        perc->grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            perc->grid[i][j] = 0; // 0 indicates blocked site
        }
    }
    return perc;
}

void freePercolation(Percolation* perc) {
    for (int i = 0; i < perc->size; i++) {
        free(perc->grid[i]);
    }
    free(perc->grid);
    free(perc);
}

void openSite(Percolation* perc, int row, int col) {
    if (row >= 0 && row < perc->size && col >= 0 && col < perc->size) {
        perc->grid[row][col] = 1; // 1 indicates open site
    }
}

int isOpen(Percolation* perc, int row, int col) {
    return (row >= 0 && row < perc->size && col >= 0 && col < perc->size) ? perc->grid[row][col] : 0;
}

void printGrid(Percolation* perc) {
    for (int i = 0; i < perc->size; i++) {
        for (int j = 0; j < perc->size; j++) {
            printf("%d ", perc->grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isPercolated(Percolation* perc) {
    for (int col = 0; col < perc->size; col++) {
        if (isOpen(perc, perc->size - 1, col)) {
            return 1;
        }
    }
    return 0;
}

void randomOpenSites(Percolation* perc, int numSites) {
    int opened = 0;
    while (opened < numSites) {
        int row = rand() % perc->size;
        int col = rand() % perc->size;
        if (isOpen(perc, row, col) == 0) {
            openSite(perc, row, col);
            opened++;
        }
    }
}

int main() {
    srand(time(NULL));
    
    printf("Welcome to the Percolation Simulator!\n");
    printf("We will explore random openings in a grid, trying to see if they connect from top to bottom.\n\n");
    
    Percolation* perc = createPercolation(GRID_SIZE);
    
    int numOpenSites = GRID_SIZE * GRID_SIZE * 0.6; // Open about 60% of the grid
    randomOpenSites(perc, numOpenSites);
    
    printf("Current grid state (1 = open, 0 = blocked):\n");
    printGrid(perc);
    
    if (isPercolated(perc)) {
        printf("The system percolates! Water can flow from top to bottom.\n");
    } else {
        printf("The system does not percolate. No water flow from top to bottom.\n");
    }
    
    freePercolation(perc);
    
    return 0;
}