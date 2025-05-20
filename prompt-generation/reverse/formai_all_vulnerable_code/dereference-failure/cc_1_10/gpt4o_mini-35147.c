//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define DEFAULT_SIZE 10

// Structure to represent a Union-Find
typedef struct {
    int *parent;
    int *rank;
    int size;
} UnionFind;

// Create a union-find structure
UnionFind* createUnionFind(int size) {
    UnionFind *uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->parent = (int*)malloc(size * sizeof(int));
    uf->rank = (int*)malloc(size * sizeof(int));
    uf->size = size;

    for (int i = 0; i < size; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}

// Find with path compression
int find(UnionFind *uf, int p) {
    if (uf->parent[p] != p) {
        uf->parent[p] = find(uf, uf->parent[p]);
    }
    return uf->parent[p];
}

// Union by rank
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

// Check if two elements are in the same component
bool connected(UnionFind *uf, int p, int q) {
    return find(uf, p) == find(uf, q);
}

void freeUnionFind(UnionFind *uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

// Percolation system
typedef struct {
    int size;
    bool **grid;
    UnionFind *uf;
    int topVirtual;
    int bottomVirtual;
} Percolation;

Percolation* createPercolation(int n) {
    Percolation *perc = (Percolation*)malloc(sizeof(Percolation));
    perc->size = n;
    perc->grid = (bool**)malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++) {
        perc->grid[i] = (bool*)calloc(n, sizeof(bool));
    }
    perc->uf = createUnionFind(n * n + 2); // grid + 2 virtual sites
    perc->topVirtual = n * n;          // index of top virtual site
    perc->bottomVirtual = n * n + 1;   // index of bottom virtual site

    // Connect top row to top virtual site and bottom row to bottom virtual site
    for (int j = 0; j < n; j++) {
        unionSets(perc->uf, 0, j + 1);
        unionSets(perc->uf, n - 1, (n - 1) * n + j + 1);
    }
    return perc;
}

void openSite(Percolation *perc, int row, int col) {
    if (perc->grid[row][col]) return; // already opened
    perc->grid[row][col] = true;

    int index = row * perc->size + col + 1; // 1-based index
    if (row == 0) {
        unionSets(perc->uf, perc->topVirtual, index);
    }
    if (row == perc->size - 1) {
        unionSets(perc->uf, perc->bottomVirtual, index);
    }

    // Check neighbors and union them
    if (row > 0 && perc->grid[row - 1][col]) {
        unionSets(perc->uf, index, (row - 1) * perc->size + col + 1);
    }
    if (row < perc->size - 1 && perc->grid[row + 1][col]) {
        unionSets(perc->uf, index, (row + 1) * perc->size + col + 1);
    }
    if (col > 0 && perc->grid[row][col - 1]) {
        unionSets(perc->uf, index, row * perc->size + (col - 1) + 1);
    }
    if (col < perc->size - 1 && perc->grid[row][col + 1]) {
        unionSets(perc->uf, index, row * perc->size + (col + 1) + 1);
    }
}

bool percolates(Percolation *perc) {
    return connected(perc->uf, perc->topVirtual, perc->bottomVirtual);
}

void freePercolation(Percolation *perc) {
    for (int i = 0; i < perc->size; i++) {
        free(perc->grid[i]);
    }
    free(perc->grid);
    freeUnionFind(perc->uf);
    free(perc);
}
 
void printGrid(Percolation *perc) {
    printf("Percolation Grid:\n");
    for (int i = 0; i < perc->size; i++) {
        for (int j = 0; j < perc->size; j++) {
            printf(perc->grid[i][j] ? "O " : ". ");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed for randomization
    int size = DEFAULT_SIZE;

    Percolation *perc = createPercolation(size);

    int sitesToOpen = (size * size) / 2; // Open half the grid
    for (int i = 0; i < sitesToOpen; i++) {
        int row = rand() % size;
        int col = rand() % size;
        openSite(perc, row, col);
    }

    printGrid(perc);

    if (percolates(perc)) {
        printf("Coffee percolates through the filter!\n");
    } else {
        printf("Coffee does NOT percolate through the filter!\n");
    }

    freePercolation(perc);
    return 0;
}