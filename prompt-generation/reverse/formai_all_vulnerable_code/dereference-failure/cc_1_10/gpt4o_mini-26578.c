//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int *parent;
    int *rank;
    int size;
} UnionFind;

// Function prototypes
UnionFind *createUnionFind(int n);
void unionSets(UnionFind *uf, int p, int q);
int findSet(UnionFind *uf, int p);
int connected(UnionFind *uf, int p, int q);
void freeUnionFind(UnionFind *uf);
void percolate(int gridSize, UnionFind *uf, int **grid);
int isPercolating(UnionFind *uf, int gridSize);
void openSite(int **grid, UnionFind *uf, int gridSize, int row, int col);
void printGrid(int **grid, int gridSize);

int main() {
    srand(time(NULL));
    int gridSize = 5; // Size of the grid (5x5)
    int **grid = malloc(gridSize * sizeof(int *));
    for (int i = 0; i < gridSize; i++) {
        grid[i] = malloc(gridSize * sizeof(int));
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = BLOCKED; // Initialize the grid as blocked
        }
    }

    UnionFind *uf = createUnionFind(gridSize * gridSize);
    int openSites = 0;

    // Randomly open sites until the system percolates
    while (!isPercolating(uf, gridSize)) {
        int row = rand() % gridSize;
        int col = rand() % gridSize;

        if (grid[row][col] == BLOCKED) {
            openSite(grid, uf, gridSize, row, col);
            openSites++;
        }
    }

    printf("Percolation occurred after opening %d sites:\n", openSites);
    printGrid(grid, gridSize);

    // Cleanup
    for (int i = 0; i < gridSize; i++) {
        free(grid[i]);
    }
    free(grid);
    freeUnionFind(uf);
    
    return 0;
}

UnionFind *createUnionFind(int n) {
    UnionFind *uf = malloc(sizeof(UnionFind));
    uf->parent = malloc(n * sizeof(int));
    uf->rank = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
    uf->size = n;
    return uf;
}

void unionSets(UnionFind *uf, int p, int q) {
    int rootP = findSet(uf, p);
    int rootQ = findSet(uf, q);
    if (rootP != rootQ) {
        if (uf->rank[rootP] > uf->rank[rootQ]) {
            uf->parent[rootQ] = rootP;
        } else if (uf->rank[rootP] < uf->rank[rootQ]) {
            uf->parent[rootP] = rootQ;
        } else {
            uf->parent[rootQ] = rootP;
            uf->rank[rootP]++;
        }
    }
}

int findSet(UnionFind *uf, int p) {
    if (uf->parent[p] != p) {
        uf->parent[p] = findSet(uf, uf->parent[p]);
    }
    return uf->parent[p];
}

int connected(UnionFind *uf, int p, int q) {
    return findSet(uf, p) == findSet(uf, q);
}

void freeUnionFind(UnionFind *uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

void openSite(int **grid, UnionFind *uf, int gridSize, int row, int col) {
    grid[row][col] = OPEN;
    int index = row * gridSize + col;

    // Connect to open neighbors
    if (row > 0 && grid[row - 1][col] == OPEN) {
        unionSets(uf, index, (row - 1) * gridSize + col);
    }
    if (row < gridSize - 1 && grid[row + 1][col] == OPEN) {
        unionSets(uf, index, (row + 1) * gridSize + col);
    }
    if (col > 0 && grid[row][col - 1] == OPEN) {
        unionSets(uf, index, row * gridSize + (col - 1));
    }
    if (col < gridSize - 1 && grid[row][col + 1] == OPEN) {
        unionSets(uf, index, row * gridSize + (col + 1));
    }

    // Connect to virtual top and bottom
    if (row == 0) {
        unionSets(uf, index, gridSize * gridSize); // virtual top node
    }
    if (row == gridSize - 1) {
        unionSets(uf, index, gridSize * gridSize + 1); // virtual bottom node
    }
}

int isPercolating(UnionFind *uf, int gridSize) {
    return connected(uf, gridSize * gridSize, gridSize * gridSize + 1);
}

void printGrid(int **grid, int gridSize) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}