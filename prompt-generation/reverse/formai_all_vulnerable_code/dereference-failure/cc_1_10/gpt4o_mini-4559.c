//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int n;            // size of the grid
    int **grid;      // the grid itself
    bool *topRow;    // keeps track of full sites in the top row
    bool *bottomRow; // keeps track of full sites in the bottom row
} Percolation;

Percolation *createPercolation(int n) {
    Percolation *p = (Percolation *)malloc(sizeof(Percolation));
    p->n = n;
    p->grid = (int **)malloc(n * sizeof(int *));
    p->topRow = (bool *)calloc(n, sizeof(bool));
    p->bottomRow = (bool *)calloc(n, sizeof(bool));
    
    for (int i = 0; i < n; i++) {
        p->grid[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            p->grid[i][j] = BLOCKED;
        }
    }
    
    return p;
}

void freePercolation(Percolation *p) {
    for (int i = 0; i < p->n; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p->topRow);
    free(p->bottomRow);
    free(p);
}

void openSite(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->n && col >= 0 && col < p->n) {
        p->grid[row][col] = OPEN;
    }
}

// Recursively checks connectivity (DFS)
bool isFull(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->n || col < 0 || col >= p->n || p->grid[row][col] == BLOCKED) {
        return false;
    }
    
    if (p->topRow[col]) return true;

    p->grid[row][col] = BLOCKED; // Mark as visited
    // Check adjacent cells
    bool full = 
        isFull(p, row - 1, col) ||
        isFull(p, row + 1, col) ||
        isFull(p, row, col - 1) ||
        isFull(p, row, col + 1);
    
    if (row == p->n - 1) {
        p->bottomRow[col] = true; // Mark col in bottom row
    }
    
    return full;
}

bool percolates(Percolation *p) {
    for (int col = 0; col < p->n; col++) {
        if (p->grid[0][col] == OPEN) {
            isFull(p, 0, col);
        }
    }

    for (int col = 0; col < p->n; col++) {
        if (p->bottomRow[col]) {
            return true;
        }
    }
    return false;
}

void printGrid(Percolation *p) {
    printf("Percolation grid:\n");
    for (int i = 0; i < p->n; i++) {
        for (int j = 0; j < p->n; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int size = 5; // example size
    Percolation *p = createPercolation(size);

    // Open some random sites in the grid
    openSite(p, 0, 0);
    openSite(p, 1, 0);
    openSite(p, 1, 1);
    openSite(p, 2, 1);
    openSite(p, 3, 1);
    openSite(p, 3, 2);
    openSite(p, 4, 2);
    openSite(p, 4, 3);
    openSite(p, 4, 4); // This creates a path to bottom

    printGrid(p);

    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does NOT percolate.\n");
    }

    freePercolation(p);
    return 0;
}