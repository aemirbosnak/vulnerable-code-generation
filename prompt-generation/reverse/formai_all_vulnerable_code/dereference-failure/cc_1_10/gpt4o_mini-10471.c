//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20 // Define the size of the percolation grid
#define OPEN 1       // Represents an open site
#define BLOCKED 0    // Represents a blocked site

typedef struct {
    int grid[GRID_SIZE][GRID_SIZE];
    int *parent;
    int n;
} Percolation;

void initPercolation(Percolation *p) {
    p->n = GRID_SIZE;
    p->parent = (int*)malloc(GRID_SIZE * GRID_SIZE * sizeof(int));
    
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            p->grid[i][j] = BLOCKED; // Start with all sites blocked
        }
    }
    
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        p->parent[i] = i; // Each site is its own parent initially
    }
}

int find(Percolation *p, int idx) {
    if (p->parent[idx] != idx) {
        p->parent[idx] = find(p, p->parent[idx]); // Path compression
    }
    return p->parent[idx];
}

void unionSite(Percolation *p, int site1, int site2) {
    int root1 = find(p, site1);
    int root2 = find(p, site2);
    if (root1 != root2) {
        p->parent[root1] = root2; // Connect the two components
    }
}

void openSite(Percolation *p, int row, int col) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) return;
    if (p->grid[row][col] == OPEN) return; // Site already open
    
    p->grid[row][col] = OPEN; // Open the site
    
    int siteIndex = row * GRID_SIZE + col; // Convert 2D to 1D index
    
    // Connect to surrounding open sites
    if (row > 0 && p->grid[row - 1][col] == OPEN) {
        unionSite(p, siteIndex, (row - 1) * GRID_SIZE + col);
    }
    if (row < GRID_SIZE - 1 && p->grid[row + 1][col] == OPEN) {
        unionSite(p, siteIndex, (row + 1) * GRID_SIZE + col);
    }
    if (col > 0 && p->grid[row][col - 1] == OPEN) {
        unionSite(p, siteIndex, row * GRID_SIZE + col - 1);
    }
    if (col < GRID_SIZE - 1 && p->grid[row][col + 1] == OPEN) {
        unionSite(p, siteIndex, row * GRID_SIZE + col + 1);
    }
}

int percolates(Percolation *p) {
    for (int col = 0; col < GRID_SIZE; col++) {
        if (p->grid[0][col] == OPEN) {
            int root = find(p, col);
            for (int bottomCol = 0; bottomCol < GRID_SIZE; bottomCol++) {
                if (p->grid[GRID_SIZE - 1][bottomCol] == OPEN) {
                    if (root == find(p, (GRID_SIZE - 1) * GRID_SIZE + bottomCol)) {
                        return 1; // System percolates
                    }
                }
            }
        }
    }
    return 0; // System does not percolate
}

void displayGrid(Percolation *p) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", p->grid[i][j] == OPEN ? '.' : '#');
        }
        printf("\n");
    }
}

void freePercolation(Percolation *p) {
    free(p->parent);
}

int main() {
    srand(time(0)); // Seed for randomness
    Percolation p;
    initPercolation(&p);

    // Randomly open sites until system percolates
    while (!percolates(&p)) {
        int randRow = rand() % GRID_SIZE;
        int randCol = rand() % GRID_SIZE;
        openSite(&p, randRow, randCol);
    }

    // Display resulting grid and the percolation status
    printf("Percolation grid:\n");
    displayGrid(&p);
    printf("Percolation occurs: %s\n", percolates(&p) ? "Yes" : "No");

    freePercolation(&p);
    return 0;
}