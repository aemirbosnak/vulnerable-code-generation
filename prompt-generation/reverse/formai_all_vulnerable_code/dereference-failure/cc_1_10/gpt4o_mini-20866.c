//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY 0
#define OPEN 1
#define FULL 2

typedef struct {
    int **grid;
    int size;
} Percolation;

Percolation* createPercolation(int size) {
    Percolation *p = malloc(sizeof(Percolation));
    p->size = size;
    p->grid = malloc(size * sizeof(int *));
    
    for (int i = 0; i < size; i++) {
        p->grid[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = EMPTY;
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
    if (row < 0 || col < 0 || row >= p->size || col >= p->size) return;
    p->grid[row][col] = OPEN;
}

int isOpen(Percolation *p, int row, int col) {
    if (row < 0 || col < 0 || row >= p->size || col >= p->size) return 0;
    return p->grid[row][col] == OPEN;
}

int isFull(Percolation *p, int row, int col) {
    if (row < 0 || col < 0 || row >= p->size || col >= p->size) return 0;
    return p->grid[row][col] == FULL;
}

void checkForFull(Percolation *p) {
    for (int col = 0; col < p->size; col++) {
        if (isOpen(p, 0, col)) {
            p->grid[0][col] = FULL;
        }
    }

    for (int row = 1; row < p->size; row++) {
        for (int col = 0; col < p->size; col++) {
            if (isOpen(p, row, col)) {
                if (isFull(p, row - 1, col) || 
                    isFull(p, row, col - 1) || 
                    isFull(p, row, col + 1) ||
                    isFull(p, row + 1, col)) {
                    p->grid[row][col] = FULL;
                }
            }
        }
    }
}

int percolates(Percolation *p) {
    for (int col = 0; col < p->size; col++) {
        if (isFull(p, p->size - 1, col)) {
            return 1;
        }
    }
    return 0;
}

void printGrid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if (p->grid[i][j] == EMPTY) {
                printf(".");
            } else if (p->grid[i][j] == OPEN) {
                printf("O");
            } else {
                printf("F");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size = 10;
    Percolation *p = createPercolation(size);
    
    for (int i = 0; i < size * size / 2; i++) {
        int row = rand() % size;
        int col = rand() % size;
        openSite(p, row, col);
    }

    checkForFull(p);
    printGrid(p);
    
    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freePercolation(p);
    return 0;
}