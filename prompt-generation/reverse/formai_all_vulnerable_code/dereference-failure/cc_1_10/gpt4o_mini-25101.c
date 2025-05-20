//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0
#define GRID_SIZE 20

typedef struct {
    int *grid;
    int size;
} PercolationGrid;

// Function to create a percolation grid
PercolationGrid* createGrid(int size) {
    PercolationGrid *g = malloc(sizeof(PercolationGrid));
    g->grid = (int *)malloc(size * size * sizeof(int));
    g->size = size;

    // Initialize grid with all blocked cells
    for (int i = 0; i < size * size; i++) {
        g->grid[i] = BLOCKED;
    }
    return g;
}

// Function to open random cells in the grid
void openRandomCells(PercolationGrid *g, double probability) {
    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            if ((rand() / (double)RAND_MAX) < probability) {
                g->grid[i * g->size + j] = OPEN;
            }
        }
    }
}

// Function to print the grid
void printGrid(PercolationGrid *g) {
    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            printf("%d ", g->grid[i * g->size + j]);
        }
        printf("\n");
    }
}

// Helper functions for union-find (disjoint set)
typedef struct {
    int *parent;
    int *rank;
    int size;
} UnionFind;

// Create a union-find structure
UnionFind* createUnionFind(int size) {
    UnionFind *uf = malloc(sizeof(UnionFind));
    uf->parent = malloc(size * sizeof(int));
    uf->rank = malloc(size * sizeof(int));
    uf->size = size;
    for (int i = 0; i < size; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}

// Find the root of an element
int find(UnionFind *uf, int p) {
    if (uf->parent[p] != p) {
        uf->parent[p] = find(uf, uf->parent[p]);
    }
    return uf->parent[p];
}

// Union two sets
void unionSets(UnionFind *uf, int p, int q) {
    int rootP = find(uf, p);
    int rootQ = find(uf, q);
    if (rootP != rootQ) {
        if (uf->rank[rootP] < uf->rank[rootQ]) {
            uf->parent[rootP] = rootQ;
        } else if (uf->rank[rootP] > uf->rank[rootQ]) {
            uf->parent[rootQ] = rootP;
        } else {
            uf->parent[rootQ] = rootP;
            uf->rank[rootP]++;
        }
    }
}

// Check if the system percolates
int percolates(PercolationGrid *g) {
    UnionFind *uf = createUnionFind(g->size * g->size);
    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            if (g->grid[i * g->size + j] == OPEN) {
                // Connect to the cell below
                if (i < g->size - 1 && g->grid[(i + 1) * g->size + j] == OPEN) {
                    unionSets(uf, i * g->size + j, (i + 1) * g->size + j);
                }
                // Connect to the cell to the left
                if (j > 0 && g->grid[i * g->size + (j - 1)] == OPEN) {
                    unionSets(uf, i * g->size + j, i * g->size + (j - 1));
                }
                // Connect to the cell to the right
                if (j < g->size - 1 && g->grid[i * g->size + (j + 1)] == OPEN) {
                    unionSets(uf, i * g->size + j, i * g->size + (j + 1));
                }
            }
        }
    }

    // Check if there's a path from top to bottom
    for (int j = 0; j < g->size; j++) {
        if (g->grid[j] == OPEN && find(uf, 0) == find(uf, (g->size - 1) * g->size + j)) {
            free(uf->parent);
            free(uf->rank);
            free(uf);
            return 1; // Percolates
        }
    }

    free(uf->parent);
    free(uf->rank);
    free(uf);
    return 0; // Does not percolate
}

// Main function
int main() {
    srand(time(NULL));
    double probability = 0.5; // Probability of a site being open
    PercolationGrid *grid = createGrid(GRID_SIZE);
    
    openRandomCells(grid, probability);
    printGrid(grid);

    if (percolates(grid)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free(grid->grid);
    free(grid);
    return 0;
}