//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int size;
    int **grid;
} Percolation;

Percolation *createPercolation(int n) {
    Percolation *perc = (Percolation *)malloc(sizeof(Percolation));
    perc->size = n;
    perc->grid = (int **)malloc(n * sizeof(int *));
    
    for (int i = 0; i < n; i++) {
        perc->grid[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            perc->grid[i][j] = BLOCKED; // Initially, all sites are blocked
        }
    }
    
    return perc;
}

void destroyPercolation(Percolation *perc) {
    for (int i = 0; i < perc->size; i++) {
        free(perc->grid[i]);
    }
    free(perc->grid);
    free(perc);
}

void openSite(Percolation *perc, int row, int col) {
    if (row >= 0 && row < perc->size && col >= 0 && col < perc->size) {
        perc->grid[row][col] = OPEN;
    }
}

int isOpen(Percolation *perc, int row, int col) {
    if (row >= 0 && row < perc->size && col >= 0 && col < perc->size) {
        return perc->grid[row][col] == OPEN;
    }
    return 0;
}

int percolates(Percolation *perc) {
    for (int col = 0; col < perc->size; col++) {
        if (isOpen(perc, 0, col) && dfs(perc, 0, col)) {
            return 1;
        }
    }
    return 0;
}

int dfs(Percolation *perc, int row, int col) {
    if (row == perc->size - 1) {
        return 1; // Reached the bottom row
    }
    
    if (!isOpen(perc, row, col)) {
        return 0;
    }

    // Mark site as visited
    perc->grid[row][col] = -OPEN; // Temporarily mark as visited

    // Check adjacent cells
    int result = dfs(perc, row + 1, col) || 
                 dfs(perc, row - 1, col) ||
                 dfs(perc, row, col + 1) ||
                 dfs(perc, row, col - 1);

    // Unmark site (backtrack)
    perc->grid[row][col] = OPEN;
    
    return result;
}

void displayGrid(Percolation *perc) {
    for (int i = 0; i < perc->size; i++) {
        for (int j = 0; j < perc->size; j++) {
            printf("%d ", perc->grid[i][j]);
        }
        printf("\n");
    }
}

void randomOpenSites(Percolation *perc, int numSites) {
    srand(time(0)); 
    for (int i = 0; i < numSites; i++) {
        int r = rand() % perc->size;
        int c = rand() % perc->size;
        openSite(perc, r, c);
    }
}

int main() {
    int n = 10; // Size of grid
    Percolation *perc = createPercolation(n);
    
    randomOpenSites(perc, 30); // Open random 30 sites

    printf("Percolation Grid:\n");
    displayGrid(perc);
    
    if (percolates(perc)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    
    destroyPercolation(perc);
    return 0;
}