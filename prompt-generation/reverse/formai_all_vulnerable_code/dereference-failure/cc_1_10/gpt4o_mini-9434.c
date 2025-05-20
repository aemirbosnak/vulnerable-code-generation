//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10 // Change this as needed for larger grids

typedef struct {
    int *parent;
    int *rank;
    int grid_size;
} UnionFind;

UnionFind* create_uf(int size) {
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->grid_size = size * size;
    uf->parent = (int*)malloc(uf->grid_size * sizeof(int));
    uf->rank = (int*)malloc(uf->grid_size * sizeof(int));

    for (int i = 0; i < uf->grid_size; i++) {
        uf->parent[i] = i; 
        uf->rank[i] = 0; 
    }
    return uf;
}

int find(UnionFind* uf, int p) {
    if (uf->parent[p] != p) {
        uf->parent[p] = find(uf, uf->parent[p]);
    }
    return uf->parent[p];
}

void union_uf(UnionFind* uf, int p, int q) {
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

bool connected(UnionFind* uf, int p, int q) {
    return find(uf, p) == find(uf, q);
}

int xy_to_index(int x, int y) {
    return y * SIZE + x;
}

typedef struct {
    bool* opened;
    UnionFind* uf;
} Percolation;

Percolation* create_percolation() {
    Percolation* p = (Percolation*)malloc(sizeof(Percolation));
    p->opened = (bool*)calloc(SIZE * SIZE, sizeof(bool));
    p->uf = create_uf(SIZE);

    for (int x = 0; x < SIZE; x++) {
        union_uf(p->uf, xy_to_index(x, 0), xy_to_index(x, 1));
    }
    return p;
}

void open_site(Percolation* p, int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) return;

    int index = xy_to_index(col, row);
    if (!p->opened[index]) {
        p->opened[index] = true;

        if (row > 0 && p->opened[xy_to_index(col, row - 1)]) {
            union_uf(p->uf, index, xy_to_index(col, row - 1));
        }
        if (row < SIZE - 1 && p->opened[xy_to_index(col, row + 1)]) {
            union_uf(p->uf, index, xy_to_index(col, row + 1));
        }
        if (col > 0 && p->opened[xy_to_index(col - 1, row)]) {
            union_uf(p->uf, index, xy_to_index(col - 1, row));
        }
        if (col < SIZE - 1 && p->opened[xy_to_index(col + 1, row)]) {
            union_uf(p->uf, index, xy_to_index(col + 1, row));
        }
    }
}

bool percolates(Percolation* p) {
    for (int x = 0; x < SIZE; x++) {
        if (connected(p->uf, xy_to_index(x, 0), xy_to_index(x, SIZE - 1))) {
            return true;
        }
    }
    return false;
}

int main() {
    Percolation* p = create_percolation();

    // Simulate opening sites
    for (int i = 0; i < SIZE; i++) {
        open_site(p, i, i);
    }

    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    // Clean up
    free(p->opened);
    free(p->uf->parent);
    free(p->uf->rank);
    free(p->uf);
    free(p);

    return 0;
}