//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of grid
#define OPEN 1
#define BLOCKED 0

// Union-Find data structure
typedef struct {
    int *parent;
    int *size;
    int count;
} UnionFind;

// Function prototypes
UnionFind* createUnionFind(int n);
void freeUnionFind(UnionFind* uf);
int find(UnionFind* uf, int p);
void unionSets(UnionFind* uf, int p, int q);
int connected(UnionFind* uf, int p, int q);
int xyTo1D(int x, int y);

// Grid and percolation related functions
void initializeGrid(int grid[N][N]);
void printGrid(int grid[N][N]);
void openSite(int grid[N][N], UnionFind* uf, int x, int y);
int isOpen(int grid[N][N], int x, int y);
int percolates(UnionFind* uf, int size);

int main() {
    srand(time(NULL));

    // Create the grid and union-find structure
    int grid[N][N];
    initializeGrid(grid);
    UnionFind* uf = createUnionFind(N * N + 2);
    
    // Open random sites until percolation occurs
    while (!percolates(uf, N)) {
        int x = rand() % N;
        int y = rand() % N;

        if (!isOpen(grid, x, y)) {
            openSite(grid, uf, x, y);
        }
        printGrid(grid);
        printf("\n");
    }

    printf("Percolation occurred!\n");
    freeUnionFind(uf);
    return 0;
}

UnionFind* createUnionFind(int n) {
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->parent = (int*)malloc(n * sizeof(int));
    uf->size = (int*)malloc(n * sizeof(int));
    uf->count = n;

    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->size[i] = 1;
    }
    return uf;
}

void freeUnionFind(UnionFind* uf) {
    free(uf->parent);
    free(uf->size);
    free(uf);
}

int find(UnionFind* uf, int p) {
    while (p != uf->parent[p]) {
        uf->parent[p] = uf->parent[uf->parent[p]]; // Path compression
        p = uf->parent[p];
    }
    return p;
}

void unionSets(UnionFind* uf, int p, int q) {
    int rootP = find(uf, p);
    int rootQ = find(uf, q);
    if (rootP != rootQ) {
        // Weighted union
        if (uf->size[rootP] < uf->size[rootQ]) {
            uf->parent[rootP] = rootQ;
            uf->size[rootQ] += uf->size[rootP];
        } else {
            uf->parent[rootQ] = rootP;
            uf->size[rootP] += uf->size[rootQ];
        }
    }
}

int connected(UnionFind* uf, int p, int q) {
    return find(uf, p) == find(uf, q);
}

int xyTo1D(int x, int y) {
    return x * N + y + 1; // +1 for virtual top site
}

void initializeGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = BLOCKED;
        }
    }
}

void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void openSite(int grid[N][N], UnionFind* uf, int x, int y) {
    grid[x][y] = OPEN;
    int index = xyTo1D(x, y);

    // Connect to virtual top row
    if (x == 0) {
        unionSets(uf, index, 0);
    }
    // Connect to the neighboring opened sites
    if (x > 0 && isOpen(grid, x - 1, y)) {
        unionSets(uf, index, xyTo1D(x - 1, y));
    }
    if (x < N - 1 && isOpen(grid, x + 1, y)) {
        unionSets(uf, index, xyTo1D(x + 1, y));
    }
    if (y > 0 && isOpen(grid, x, y - 1)) {
        unionSets(uf, index, xyTo1D(x, y - 1));
    }
    if (y < N - 1 && isOpen(grid, x, y + 1)) {
        unionSets(uf, index, xyTo1D(x, y + 1));
    }
}

int isOpen(int grid[N][N], int x, int y) {
    return grid[x][y] == OPEN;
}

int percolates(UnionFind* uf, int size) {
    return connected(uf, 0, N * N + 1); // Check if top is connected to bottom
}