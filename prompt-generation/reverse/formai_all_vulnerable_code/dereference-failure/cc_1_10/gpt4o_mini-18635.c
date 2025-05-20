//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCKED 0
#define OPEN 1
#define FULL 2

typedef struct {
    int **grid;
    int size;
} Percolation;

Percolation* createPercolation(int size);
void freePercolation(Percolation *p);
void openSite(Percolation *p, int row, int col);
int isOpen(Percolation *p, int row, int col);
int isFull(Percolation *p, int row, int col);
void displayGrid(Percolation *p);
int percolates(Percolation *p);

int main() {
    int size, iterations;

    printf("Enter the grid size: ");
    scanf("%d", &size);

    printf("Enter the number of iterations for random open sites: ");
    scanf("%d", &iterations);

    Percolation *p = createPercolation(size);

    srand(time(NULL));

    for (int i = 0; i < iterations; i++) {
        int row = rand() % size;
        int col = rand() % size;
        openSite(p, row, col);
        printf("Opened site (%d, %d)\n", row, col);
        displayGrid(p);
        if (percolates(p)) {
            printf("The system percolates!\n");
            break;
        }
    }

    freePercolation(p);
    return 0;
}

Percolation* createPercolation(int size) {
    Percolation *p = (Percolation*) malloc(sizeof(Percolation));
    p->size = size;
    p->grid = (int**) malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++) {
        p->grid[i] = (int*) malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = BLOCKED;
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
    return (row >= 0 && row < p->size && col >= 0 && col < p->size) ? (p->grid[row][col] == OPEN) : 0;
}

int isFull(Percolation *p, int row, int col) {
    return (row >= 0 && row < p->size && col >= 0 && col < p->size) ? (p->grid[row][col] == FULL) : 0;
}

void displayGrid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if (p->grid[i][j] == BLOCKED) printf(" . ");
            else if (p->grid[i][j] == OPEN) printf(" O ");
            else printf(" X ");
        }
        printf("\n");
    }
    printf("\n");
}

int percolates(Percolation *p) {
    for (int j = 0; j < p->size; j++) {
        if (isOpen(p, 0, j)) {
            if (dfs(p, 0, j)) {
                return 1;
            }
        }
    }
    return 0;
}

int dfs(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size || isFull(p, row, col) || !isOpen(p, row, col)) {
        return 0;
    }
    if (row == p->size - 1) {
        return 1; // Reached bottom
    }
    
    p->grid[row][col] = FULL;

    // Check in 4 directions
    if (dfs(p, row + 1, col) || dfs(p, row - 1, col) || dfs(p, row, col + 1) || dfs(p, row, col - 1)) {
        return 1;
    }

    return 0;
}