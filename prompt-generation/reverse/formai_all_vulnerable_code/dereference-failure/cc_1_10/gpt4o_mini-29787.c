//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int **grid;
    int size;
} Percolation;

Percolation* createPercolation(int size) {
    Percolation *p = malloc(sizeof(Percolation));
    p->size = size;
    p->grid = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        p->grid[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = BLOCKED; // Start with a fully blocked grid
        }
    }
    return p;
}

void freePercolation(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void openSite(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        p->grid[row][col] = OPEN;
    }
}

int isOpen(Percolation *p, int row, int col) {
    return (row >= 0 && row < p->size && col >= 0 && col < p->size) ? p->grid[row][col] : BLOCKED;
}

int isFull(Percolation *p, int row, int col) {
    return isOpen(p, row, col) ? 1 : 0;
}

void displayGrid(Percolation *p) {
    printf("Percolation Grid:\n");
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

int percolates(Percolation *p) {
    for (int col = 0; col < p->size; col++) {
        if (isFull(p, 0, col)) {
            for (int row = 1; row < p->size; row++) {
                if (isOpen(p, row, col) && isFull(p, row - 1, col)) {
                    openSite(p, row, col);
                }
            }
        }
    }
    for (int col = 0; col < p->size; col++) {
        if (isFull(p, p->size - 1, col)) {
            return 1; // Found a full site in bottom row
        }
    }
    return 0; // No full sites in the bottom row
}

void randomSiteOpening(Percolation *p, float probability) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if ((float)rand()/RAND_MAX < probability) {
                openSite(p, i, j);
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int gridSize = 10;
    float openProbability = 0.4;
    Percolation *p = createPercolation(gridSize);

    randomSiteOpening(p, openProbability);
    displayGrid(p);
    
    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freePercolation(p);
    return 0;
}