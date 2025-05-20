//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid size
#define N 10

// Probability of a site being open
#define P 0.5

// Union-find data structure
typedef struct {
    int *id;
    int *sz;
} UF;

// Initialize the union-find data structure
void UF_init(UF *uf, int n) {
    uf->id = malloc(n * sizeof(int));
    uf->sz = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->id[i] = i;
        uf->sz[i] = 1;
    }
}

// Find the root of the tree containing p
int UF_find(UF *uf, int p) {
    while (p != uf->id[p]) {
        uf->id[p] = uf->id[uf->id[p]];
        p = uf->id[p];
    }
    return p;
}

// Merge the trees containing p and q
void UF_union(UF *uf, int p, int q) {
    int i = UF_find(uf, p);
    int j = UF_find(uf, q);
    if (i == j) return;
    if (uf->sz[i] < uf->sz[j]) {
        uf->id[i] = j;
        uf->sz[j] += uf->sz[i];
    } else {
        uf->id[j] = i;
        uf->sz[i] += uf->sz[j];
    }
}

// Print the grid
void print_grid(int *grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i * N + j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the grid
    int *grid = malloc(N * N * sizeof(int));

    // Initialize the union-find data structure
    UF uf;
    UF_init(&uf, N * N);

    // Open the sites
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rand() < P * RAND_MAX) {
                grid[i * N + j] = 1;
                UF_union(&uf, i * N + j, i * N + j + 1);
                UF_union(&uf, i * N + j, (i + 1) * N + j);
            }
        }
    }

    // Print the grid
    print_grid(grid);

    // Check for percolation
    int percolates = UF_find(&uf, 0) == UF_find(&uf, N * N - 1);

    // Print the result
    printf("Percolates: %d\n", percolates);

    // Free the memory
    free(grid);
    free(uf.id);
    free(uf.sz);

    return 0;
}