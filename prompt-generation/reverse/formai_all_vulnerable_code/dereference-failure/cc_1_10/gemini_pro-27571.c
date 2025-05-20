//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
// Percolation simulator using union-find
#include <stdio.h>
#include <stdlib.h>

// Union-find data structure
typedef struct {
    int *parent;
    int *size;
    int count;
} UF;

// Create a new union-find data structure
UF *uf_create(int n) {
    UF *uf = malloc(sizeof(UF));
    uf->parent = malloc(n * sizeof(int));
    uf->size = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->size[i] = 1;
    }
    uf->count = n;
    return uf;
}

// Destroy a union-find data structure
void uf_destroy(UF *uf) {
    free(uf->parent);
    free(uf->size);
    free(uf);
}

// Find the root of a node
int uf_find(UF *uf, int p) {
    if (uf->parent[p] != p)
        uf->parent[p] = uf_find(uf, uf->parent[p]);
    return uf->parent[p];
}

// Union two nodes
void uf_union(UF *uf, int p, int q) {
    int rootP = uf_find(uf, p);
    int rootQ = uf_find(uf, q);
    if (rootP == rootQ)
        return;
    if (uf->size[rootP] < uf->size[rootQ]) {
        uf->parent[rootP] = rootQ;
        uf->size[rootQ] += uf->size[rootP];
    } else {
        uf->parent[rootQ] = rootP;
        uf->size[rootP] += uf->size[rootQ];
    }
    uf->count--;
}

// Percolation simulator
typedef struct {
    int *grid;
    int n;
    UF *uf;
} Percolation;

// Create a new percolation simulator
Percolation *percolation_create(int n) {
    Percolation *perc = malloc(sizeof(Percolation));
    perc->grid = malloc(n * n * sizeof(int));
    perc->n = n;
    perc->uf = uf_create(n * n);
    for (int i = 0; i < n * n; i++) {
        perc->grid[i] = 0;
    }
    return perc;
}

// Destroy a percolation simulator
void percolation_destroy(Percolation *perc) {
    free(perc->grid);
    uf_destroy(perc->uf);
    free(perc);
}

// Open a cell
void percolation_open(Percolation *perc, int x, int y) {
    if (x < 0 || x >= perc->n || y < 0 || y >= perc->n)
        return;
    if (perc->grid[x * perc->n + y] == 1)
        return;
    perc->grid[x * perc->n + y] = 1;
    if (x > 0 && perc->grid[(x - 1) * perc->n + y] == 1)
        uf_union(perc->uf, x * perc->n + y, (x - 1) * perc->n + y);
    if (x < perc->n - 1 && perc->grid[(x + 1) * perc->n + y] == 1)
        uf_union(perc->uf, x * perc->n + y, (x + 1) * perc->n + y);
    if (y > 0 && perc->grid[x * perc->n + y - 1] == 1)
        uf_union(perc->uf, x * perc->n + y, x * perc->n + y - 1);
    if (y < perc->n - 1 && perc->grid[x * perc->n + y + 1] == 1)
        uf_union(perc->uf, x * perc->n + y, x * perc->n + y + 1);
}

// Check if a cell is open
int percolation_is_open(Percolation *perc, int x, int y) {
    if (x < 0 || x >= perc->n || y < 0 || y >= perc->n)
        return 0;
    return perc->grid[x * perc->n + y] == 1;
}

// Check if two cells are connected
int percolation_is_connected(Percolation *perc, int p, int q) {
    return uf_find(perc->uf, p) == uf_find(perc->uf, q);
}

// Check if the system percolates
int percolation_percolates(Percolation *perc) {
    for (int i = 0; i < perc->n; i++) {
        if (percolation_is_open(perc, i, 0) && percolation_is_open(perc, i, perc->n - 1))
            return 1;
    }
    return 0;
}

// Print the grid
void percolation_print(Percolation *perc) {
    for (int i = 0; i < perc->n; i++) {
        for (int j = 0; j < perc->n; j++) {
            printf("%d ", perc->grid[i * perc->n + j]);
        }
        printf("\n");
    }
}

// Test the percolation simulator
int main() {
    Percolation *perc = percolation_create(10);
    percolation_open(perc, 1, 1);
    percolation_open(perc, 1, 2);
    percolation_open(perc, 1, 3);
    percolation_open(perc, 1, 4);
    percolation_open(perc, 1, 5);
    percolation_open(perc, 2, 1);
    percolation_open(perc, 2, 2);
    percolation_open(perc, 2, 3);
    percolation_open(perc, 2, 4);
    percolation_open(perc, 2, 5);
    percolation_open(perc, 3, 1);
    percolation_open(perc, 3, 2);
    percolation_open(perc, 3, 3);
    percolation_open(perc, 3, 4);
    percolation_open(perc, 3, 5);
    percolation_open(perc, 4, 1);
    percolation_open(perc, 4, 2);
    percolation_open(perc, 4, 3);
    percolation_open(perc, 4, 4);
    percolation_open(perc, 4, 5);
    percolation_open(perc, 5, 1);
    percolation_open(perc, 5, 2);
    percolation_open(perc, 5, 3);
    percolation_open(perc, 5, 4);
    percolation_open(perc, 5, 5);
    percolation_print(perc);
    printf("Percolates: %d\n", percolation_percolates(perc));
    percolation_destroy(perc);
    return 0;
}