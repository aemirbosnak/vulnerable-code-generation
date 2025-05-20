//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int *parent;
    int *rank;
    int size;
} UnionFind;

UnionFind* createUnionFind(int n) {
    UnionFind *uf = malloc(sizeof(UnionFind));
    uf->parent = malloc(n * sizeof(int));
    uf->rank = malloc(n * sizeof(int));
    uf->size = n;

    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}

int find(UnionFind *uf, int x) {
    if (uf->parent[x] != x) {
        uf->parent[x] = find(uf, uf->parent[x]);
    }
    return uf->parent[x];
}

void unionSet(UnionFind *uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);

    if (rootX != rootY) {
        if (uf->rank[rootX] > uf->rank[rootY]) {
            uf->parent[rootY] = rootX;
        } else if (uf->rank[rootX] < uf->rank[rootY]) {
            uf->parent[rootX] = rootY;
        } else {
            uf->parent[rootY] = rootX;
            uf->rank[rootX]++;
        }
    }
}

#define INDEX(row, col, size) ((row) * (size) + (col))

typedef struct {
    int size;
    int *grid;
    UnionFind *uf;
} Percolation;

Percolation* createPercolation(int n) {
    Percolation *p = malloc(sizeof(Percolation));
    p->size = n;
    p->grid = calloc(n * n, sizeof(int));
    p->uf = createUnionFind(n * n + 2); // Two extra for virtual top/bottom

    for (int col = 0; col < n; col++) {
        unionSet(p->uf, INDEX(0, col, n), n * n); // Connect top row to virtual top
        unionSet(p->uf, INDEX(n - 1, col, n), n * n + 1); // Connect bottom row to virtual bottom
    }

    return p;
}

void openSite(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) return;

    int index = INDEX(row, col, p->size);
    if (p->grid[index] == OPEN) return; // Already open

    p->grid[index] = OPEN;

    if (row > 0 && p->grid[INDEX(row - 1, col, p->size)] == OPEN) {
        unionSet(p->uf, index, INDEX(row - 1, col, p->size));
    }
    if (row < p->size - 1 && p->grid[INDEX(row + 1, col, p->size)] == OPEN) {
        unionSet(p->uf, index, INDEX(row + 1, col, p->size));
    }
    if (col > 0 && p->grid[INDEX(row, col - 1, p->size)] == OPEN) {
        unionSet(p->uf, index, INDEX(row, col - 1, p->size));
    }
    if (col < p->size - 1 && p->grid[INDEX(row, col + 1, p->size)] == OPEN) {
        unionSet(p->uf, index, INDEX(row, col + 1, p->size));
    }
}

bool percolates(Percolation *p) {
    return find(p->uf, p->size * p->size) == find(p->uf, p->size * p->size + 1);
}

void freePercolation(Percolation *p) {
    free(p->grid);
    free(p->uf->parent);
    free(p->uf->rank);
    free(p->uf);
    free(p);
}

void printGrid(Percolation *p) {
    for (int row = 0; row < p->size; row++) {
        for (int col = 0; col < p->size; col++) {
            int index = INDEX(row, col, p->size);
            printf("%s ", p->grid[index] == OPEN ? "O" : "X");
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    int n = 10; // Size of the grid
    Percolation *p = createPercolation(n);

    // Randomly open sites
    for (int i = 0; i < n * n; i++) {
        int row = rand() % n;
        int col = rand() % n;
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