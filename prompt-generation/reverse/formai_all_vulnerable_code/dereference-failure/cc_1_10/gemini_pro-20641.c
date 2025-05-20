//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define GRID_WIDTH 20
#define GRID_HEIGHT 20

// Probability of a site being open
#define P 0.5

// Union-find data structure
typedef struct UnionFind {
    int *parent;
    int *rank;
    int count;
} UnionFind;

// Initialize the union-find data structure
UnionFind *init_union_find(int n) {
    UnionFind *uf = malloc(sizeof(UnionFind));
    uf->parent = malloc(n * sizeof(int));
    uf->rank = malloc(n * sizeof(int));
    uf->count = n;
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}

// Find the root of the tree containing the given element
int find(UnionFind *uf, int p) {
    if (uf->parent[p] == p) {
        return p;
    }
    return uf->parent[p] = find(uf, uf->parent[p]);
}

// Merge the trees containing the given elements
void unite(UnionFind *uf, int p, int q) {
    int root_p = find(uf, p);
    int root_q = find(uf, q);
    if (root_p == root_q) {
        return;
    }
    if (uf->rank[root_p] < uf->rank[root_q]) {
        uf->parent[root_p] = root_q;
    } else if (uf->rank[root_p] > uf->rank[root_q]) {
        uf->parent[root_q] = root_p;
    } else {
        uf->parent[root_p] = root_q;
        uf->rank[root_q]++;
    }
    uf->count--;
}

// Simulate the percolation process
int percolation(float p) {
    // Create the grid
    int grid[GRID_WIDTH][GRID_HEIGHT];
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            grid[i][j] = (rand() < (RAND_MAX * p));
        }
    }

    // Initialize the union-find data structure
    UnionFind *uf = init_union_find(GRID_WIDTH * GRID_HEIGHT);

    // Perform union-find operations to identify connected components
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            if (grid[i][j]) {
                // Check if the current site is connected to any of its neighbors
                if (i > 0 && grid[i - 1][j]) {
                    unite(uf, i * GRID_WIDTH + j, (i - 1) * GRID_WIDTH + j);
                }
                if (i < GRID_WIDTH - 1 && grid[i + 1][j]) {
                    unite(uf, i * GRID_WIDTH + j, (i + 1) * GRID_WIDTH + j);
                }
                if (j > 0 && grid[i][j - 1]) {
                    unite(uf, i * GRID_WIDTH + j, i * GRID_WIDTH + j - 1);
                }
                if (j < GRID_HEIGHT - 1 && grid[i][j + 1]) {
                    unite(uf, i * GRID_WIDTH + j, i * GRID_WIDTH + j + 1);
                }
            }
        }
    }

    // Check if there is a path from the top to the bottom of the grid
    int top_root = find(uf, 0);
    int bottom_root = find(uf, GRID_WIDTH * GRID_HEIGHT - 1);
    if (top_root == bottom_root) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Perform multiple simulations to estimate the percolation threshold
    int num_simulations = 1000;
    int num_percolations = 0;
    for (int i = 0; i < num_simulations; i++) {
        if (percolation(P)) {
            num_percolations++;
        }
    }

    // Print the estimated percolation threshold
    float percolation_threshold = (float)num_percolations / num_simulations;
    printf("Estimated percolation threshold: %f\n", percolation_threshold);

    return 0;
}