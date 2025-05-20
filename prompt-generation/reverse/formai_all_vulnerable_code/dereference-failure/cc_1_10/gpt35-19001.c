//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the percolation system

int find_root(int *ids, int p) {
    while (p != ids[p]) {
        ids[p] = ids[ids[p]]; // Path compression optimization
        p = ids[p];
    }
    return p;
}

void union_sites(int *ids, int *sizes, int p, int q) {
    int root_p = find_root(ids, p);
    int root_q = find_root(ids, q);
    if (root_p == root_q) {
        return;
    }
    if (sizes[root_p] < sizes[root_q]) {
        ids[root_p] = root_q;
        sizes[root_q] += sizes[root_p];
    } else {
        ids[root_q] = root_p;
        sizes[root_p] += sizes[root_q];
    }
}

int percolates(int *ids) {
    for (int i = 1; i < SIZE + 1; i++) {
        if (find_root(ids, 0) == find_root(ids, i + (SIZE * (SIZE - 1)))) {
            return 1;
        }
    }
    return 0;
}

void print_grid(int *grid) {
    for (int i = 0; i < SIZE; i++) {
        printf("|");
        for (int j = 0; j < SIZE; j++) {
            if (*(grid + i * SIZE + j) == 1) {
                printf("O");
            } else {
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
    }
}

int main() {
    int *ids = malloc(sizeof(int) * (SIZE * SIZE + 1));
    int *sizes = malloc(sizeof(int) * (SIZE * SIZE + 1));
    int *grid = malloc(sizeof(int) * (SIZE * SIZE));
    srand(time(NULL));
    
    // Initialize sites as closed (0)
    for (int i = 0; i < SIZE * SIZE; i++) {
        *(grid + i) = 0;
    }
    
    // Initialize sites' ids and sizes for union-find
    for (int i = 0; i < SIZE * SIZE + 1; i++) {
        *(ids + i) = i;
        *(sizes + i) = 1;
    }
    
    // Open top and bottom virtual sites
    *(ids + 0) = SIZE * SIZE;
    *(sizes + SIZE * SIZE) = 1;
    *(ids + SIZE * SIZE + 1) = SIZE * SIZE;
    *(sizes + SIZE * SIZE) += 1;
    
    // Open random sites until percolation occurs
    while (!percolates(ids)) {
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        *(grid + i * SIZE + j) = 1;
        if (i > 0 && *(grid + (i - 1) * SIZE + j) == 1) { // check left neighbor
            union_sites(ids, sizes, i * SIZE + j + 1, (i - 1) * SIZE + j + 1);
        }
        if (i < SIZE - 1 && *(grid + (i + 1) * SIZE + j) == 1) { // check right neighbor
            union_sites(ids, sizes, i * SIZE + j + 1, (i + 1) * SIZE + j + 1);
        }
        if (j > 0 && *(grid + i * SIZE + j - 1) == 1) { // check top neighbor
            union_sites(ids, sizes, i * SIZE + j + 1, i * SIZE + j);
        }
        if (j < SIZE - 1 && *(grid + i * SIZE + j + 1) == 1) { // check bottom neighbor
            union_sites(ids, sizes, i * SIZE + j + 1, i * SIZE + j + 2);
        }
    }
    
    print_grid(grid);
    
    free(ids);
    free(sizes);
    free(grid);
    
    return 0;
}