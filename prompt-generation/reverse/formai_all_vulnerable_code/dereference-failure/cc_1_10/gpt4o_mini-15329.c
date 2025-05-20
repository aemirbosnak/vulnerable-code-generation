//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 50
#define NUM_TRIALS 1000

typedef struct {
    int *grid;
    int size;
} Percolation;

void initPercolation(Percolation *p, int size) {
    p->size = size;
    p->grid = (int *)malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++) {
        p->grid[i] = 0;  // All sites are initially blocked
    }
}

void freePercolation(Percolation *p) {
    free(p->grid);
}

int index(int row, int col, int size) {
    return row * size + col;
}

void openSite(Percolation *p, int row, int col) {
    p->grid[index(row, col, p->size)] = 1;
}

int isOpen(Percolation *p, int row, int col) {
    return p->grid[index(row, col, p->size)];
}

int isFull(Percolation *p, int row, int col) {
    return (row < 0 || row >= p->size || col < 0 || col >= p->size || !isOpen(p, row, col)) ? 0 : 1;
}

int percolates(Percolation *p) {
    // Check for percolation using DFS
    int *visited = (int *)calloc(p->size * p->size, sizeof(int));
    int stack[GRID_SIZE * GRID_SIZE];
    int top = -1;

    // Push all open sites in the first row onto the stack
    for (int col = 0; col < p->size; col++) {
        if (isOpen(p, 0, col)) {
            stack[++top] = index(0, col, p->size);
        }
    }

    while (top >= 0) {
        int current = stack[top--];
        int row = current / p->size;
        int col = current % p->size;

        // Check if we reached the last row
        if (row == p->size - 1) {
            free(visited);
            return 1;
        }

        // Mark the current site as visited
        visited[current] = 1;

        // Check all four possible directions
        if (isFull(p, row + 1, col) && !visited[index(row + 1, col, p->size)]) {
            stack[++top] = index(row + 1, col, p->size);
        }
        if (isFull(p, row - 1, col) && !visited[index(row - 1, col, p->size)]) {
            stack[++top] = index(row - 1, col, p->size);
        }
        if (isFull(p, row, col + 1) && !visited[index(row, col + 1, p->size)]) {
            stack[++top] = index(row, col + 1, p->size);
        }
        if (isFull(p, row, col - 1) && !visited[index(row, col - 1, p->size)]) {
            stack[++top] = index(row, col - 1, p->size);
        }
    }

    free(visited);
    return 0;
}

void performTrials(int gridSize, int trials) {
    int percolationCount = 0;

    for (int t = 0; t < trials; t++) {
        Percolation p;
        initPercolation(&p, gridSize);

        // Randomly open sites
        for (int i = 0; i < gridSize * gridSize * 0.6; i++) { // Open ~60% of the sites
            int row = rand() % gridSize;
            int col = rand() % gridSize;
            openSite(&p, row, col);
        }

        if (percolates(&p)) {
            percolationCount++;
        }
        freePercolation(&p);
    }

    printf("Out of %d trials, %d percolated.\n", trials, percolationCount);
    printf("Percolation probability: %f\n", (double)percolationCount / trials);
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    performTrials(GRID_SIZE, NUM_TRIALS);
    return 0;
}