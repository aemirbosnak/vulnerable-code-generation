//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int size;
    int **grid;
} Percolation;

Percolation* createPercolation(int size) {
    Percolation *p = malloc(sizeof(Percolation));
    p->size = size;
    p->grid = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        p->grid[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = BLOCKED;
        }
    }
    return p;
}

void destroyPercolation(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void openSite(Percolation *p, int row, int col) {
    p->grid[row][col] = OPEN;
}

int isOpen(Percolation *p, int row, int col) {
    return p->grid[row][col] == OPEN;
}

void printGrid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int percolates(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) {
        return 0;
    }
    if (!isOpen(p, row, col)) {
        return 0;
    }
    if (row == p->size - 1) {
        return 1;
    }
    
    // Temporarily mark the cell to avoid cycles
    p->grid[row][col] = -1;
    
    // Check downward, left, right, top
    int result = percolates(p, row + 1, col) ||
                 percolates(p, row - 1, col) ||
                 percolates(p, row, col + 1) ||
                 percolates(p, row, col - 1);
    
    // Unmark the cell
    p->grid[row][col] = OPEN;
    return result;
}

int main() {
    srand(time(NULL));
    int size = 10; // Size of the grid
    Percolation *p = createPercolation(size);
    
    // Randomly open sites
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (rand() % 2 == 0) {
                openSite(p, i, j);
            }
        }
    }
    
    printf("Percolation grid:\n");
    printGrid(p);
    
    // Check if the system percolates
    int doesPercolate = 0;
    for (int j = 0; j < size; j++) { // Start from the top row
        if (isOpen(p, 0, j)) {
            if (percolates(p, 0, j)) {
                doesPercolate = 1;
                break;
            }
        }
    }
    
    if (doesPercolate) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    
    destroyPercolation(p);
    return 0;
}