//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define EMPTY 0
#define BLOCKED 1
#define OPEN 2

typedef struct {
    int size;
    int **grid;
} Percolation;

Percolation *createPercolation(int size) {
    Percolation *p = malloc(sizeof(Percolation));
    p->size = size;
    p->grid = malloc(size * sizeof(int *));
    
    for (int i = 0; i < size; i++) {
        p->grid[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = BLOCKED; // Initially all sites are blocked
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
        p->grid[row][col] = OPEN; // Open the site
    }
}

bool isOpen(Percolation *p, int row, int col) {
    return (row >= 0 && row < p->size && col >= 0 && col < p->size && p->grid[row][col] == OPEN);
}

bool percolates(Percolation *p) {
    // Simple DFS to check percolation
    bool *visited = malloc(p->size * p->size * sizeof(bool));
    for (int i = 0; i < p->size * p->size; i++) {
        visited[i] = false;
    }

    for (int col = 0; col < p->size; col++) {
        if (isOpen(p, 0, col)) {
            int stack[p->size * p->size], stackIndex = 0;
            stack[stackIndex++] = 0 * p->size + col; // Push initial cell
            visited[0 * p->size + col] = true;

            while (stackIndex > 0) {
                int current = stack[--stackIndex];
                int r = current / p->size;
                int c = current % p->size;

                // Check if we reached the bottom
                if (r == p->size - 1) {
                    free(visited);
                    return true;
                }

                // Check four possible directions
                if (isOpen(p, r + 1, c) && !visited[(r + 1) * p->size + c]) {
                    visited[(r + 1) * p->size + c] = true;
                    stack[stackIndex++] = (r + 1) * p->size + c;
                }
                if (isOpen(p, r - 1, c) && !visited[(r - 1) * p->size + c]) {
                    visited[(r - 1) * p->size + c] = true;
                    stack[stackIndex++] = (r - 1) * p->size + c;
                }
                if (isOpen(p, r, c + 1) && !visited[r * p->size + (c + 1)]) {
                    visited[r * p->size + (c + 1)] = true;
                    stack[stackIndex++] = r * p->size + (c + 1);
                }
                if (isOpen(p, r, c - 1) && !visited[r * p->size + (c - 1)]) {
                    visited[r * p->size + (c - 1)] = true;
                    stack[stackIndex++] = r * p->size + (c - 1);
                }
            }
        }
    }

    free(visited);
    return false;
}

void printGrid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if (p->grid[i][j] == BLOCKED) {
                printf("■ ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    
    int size = 10; // Size of the grid
    Percolation *p = createPercolation(size);

    // Randomly open some sites
    for (int i = 0; i < size * size * 0.6; i++) {
        int row = rand() % size;
        int col = rand() % size;
        openSite(p, row, col);
    }

    printGrid(p);
    
    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freePercolation(p);
    return 0;
}