//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SITE_CLOSED 0
#define SITE_OPEN 1

typedef struct {
    int size;
    int **grid;
} Percolation;

Percolation* createPercolation(int n) {
    Percolation *p = (Percolation *)malloc(sizeof(Percolation));
    p->size = n;
    p->grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        p->grid[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            p->grid[i][j] = SITE_CLOSED;
        }
    }
    return p;
}

void openSite(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        p->grid[row][col] = SITE_OPEN;
    }
}

int isOpen(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        return p->grid[row][col] == SITE_OPEN;
    }
    return 0;
}

int percolates(Percolation *p) {
    for (int col = 0; col < p->size; col++) {
        if (isOpen(p, 0, col)) {
            if (searchPath(p, 0, col)) {
                return 1;
            }
        }
    }
    return 0;
}

int searchPath(Percolation *p, int row, int col) {
    if (row == p->size - 1) {
        return 1; // Reached the bottom row
    }
    
    if (!isOpen(p, row, col)) {
        return 0; // Current site is closed
    }
    
    // Mark the site as visited
    p->grid[row][col] = -1; // Use -1 to mark as visited
    
    // Check adjacent sites
    int result = searchPath(p, row + 1, col) || // Down
                 searchPath(p, row - 1, col) || // Up
                 searchPath(p, row, col + 1) || // Right
                 searchPath(p, row, col - 1);   // Left
    
    // Restore the site status
    p->grid[row][col] = SITE_OPEN; 
    return result;
}

void displayGrid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

void freePercolation(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

int main() {
    srand(time(0));
    const int N = 10;
    Percolation *p = createPercolation(N);
    
    // Randomly open sites
    for (int i = 0; i < N * N / 2; i++) {
        int row = rand() % N;
        int col = rand() % N;
        openSite(p, row, col);
    }
    
    printf("Percolation Grid:\n");
    displayGrid(p);

    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate!\n");
    }

    freePercolation(p);
    return 0;
}