//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALIVE 1
#define DEAD 0

typedef struct {
    int *parent;
    int *rank;
    int size;
} UnionFind;

UnionFind* create_uf(int size) {
    UnionFind *uf = malloc(sizeof(UnionFind));
    uf->size = size;
    uf->parent = malloc(size * sizeof(int));
    uf->rank = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
        uf->parent[i] = i;
    return uf;
}

int find(UnionFind *uf, int p) {
    if (uf->parent[p] != p)
        uf->parent[p] = find(uf, uf->parent[p]);
    return uf->parent[p];
}

void union_sets(UnionFind *uf, int p, int q) {
    int rootP = find(uf, p);
    int rootQ = find(uf, q);
    if (rootP != rootQ) {
        if (uf->rank[rootP] > uf->rank[rootQ])
            uf->parent[rootQ] = rootP;
        else if (uf->rank[rootP] < uf->rank[rootQ])
            uf->parent[rootP] = rootQ;
        else {
            uf->parent[rootQ] = rootP;
            uf->rank[rootP]++;
        }
    }
}

int connected(UnionFind *uf, int p, int q) {
    return find(uf, p) == find(uf, q);
}

typedef struct {
    int **grid;
    int n;
    UnionFind *uf;
} Percolation;

Percolation* create_percolation(int n) {
    Percolation *p = malloc(sizeof(Percolation));
    p->n = n;
    p->grid = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        p->grid[i] = calloc(n, sizeof(int));
    }
    p->uf = create_uf(n * n + 2);
    return p;
}

void open_site(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->n || col < 0 || col >= p->n) return;
    if (p->grid[row][col] == ALIVE) return;
    
    p->grid[row][col] = ALIVE;
    int index = row * p->n + col;
    
    if (row == 0) {
        union_sets(p->uf, index, p->n * p->n);
    }
    if (row == p->n - 1) {
        union_sets(p->uf, index, p->n * p->n + 1);
    }
    
    if (row > 0 && p->grid[row - 1][col] == ALIVE)
        union_sets(p->uf, index, (row - 1) * p->n + col);
    if (row < p->n - 1 && p->grid[row + 1][col] == ALIVE)
        union_sets(p->uf, index, (row + 1) * p->n + col);
    if (col > 0 && p->grid[row][col - 1] == ALIVE)
        union_sets(p->uf, index, row * p->n + (col - 1));
    if (col < p->n - 1 && p->grid[row][col + 1] == ALIVE)
        union_sets(p->uf, index, row * p->n + (col + 1));
}

int percolates(Percolation *p) {
    return connected(p->uf, p->n * p->n, p->n * p->n + 1);
}

void free_percolation(Percolation *p) {
    for (int i = 0; i < p->n; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p->uf->parent);
    free(p->uf->rank);
    free(p->uf);
    free(p);
}

int main() {
    srand(time(NULL));
    int n = 10; // Size of the grid
    Percolation *p = create_percolation(n);
    
    for (int trials = 0; trials < 100; trials++) {
        int row = rand() % n;
        int col = rand() % n;
        open_site(p, row, col);
        
        if (percolates(p)) {
            printf("Percolation occurs after %d trials!\n", trials + 1);
            break;
        }
    }
    
    free_percolation(p);
    return 0;
}