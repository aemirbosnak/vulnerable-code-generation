//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define ROWS 10
#define COLS 10

// Probability of a site being open
#define P_OPEN 0.5

// Union-find data structure
struct UF {
    int *parent;
    int *rank;
    int count;
};

// Create a new union-find data structure
struct UF *UF_new(int n) {
    struct UF *uf = malloc(sizeof(struct UF));
    uf->parent = malloc(n * sizeof(int));
    uf->rank = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
    uf->count = n;
    return uf;
}

// Destroy a union-find data structure
void UF_destroy(struct UF *uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

// Find the root of a node
int UF_find(struct UF *uf, int p) {
    if (uf->parent[p] == p) {
        return p;
    }
    return uf->parent[p] = UF_find(uf, uf->parent[p]);
}

// Union two nodes
void UF_union(struct UF *uf, int p, int q) {
    int rootP = UF_find(uf, p);
    int rootQ = UF_find(uf, q);
    if (rootP == rootQ) {
        return;
    }
    if (uf->rank[rootP] < uf->rank[rootQ]) {
        uf->parent[rootP] = rootQ;
    } else if (uf->rank[rootP] > uf->rank[rootQ]) {
        uf->parent[rootQ] = rootP;
    } else {
        uf->parent[rootP] = rootQ;
        uf->rank[rootQ]++;
    }
    uf->count--;
}

// Generate a random grid
int **generate_grid() {
    int **grid = malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        grid[i] = malloc(COLS * sizeof(int));
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = (rand() < RAND_MAX * P_OPEN) ? 1 : 0;
        }
    }
    return grid;
}

// Print a grid
void print_grid(int **grid) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Check if a grid percolates
int percolates(int **grid) {
    // Create a union-find data structure
    struct UF *uf = UF_new(ROWS * COLS);

    // Iterate over the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // If the site is open
            if (grid[i][j] == 1) {
                // Union the site with its neighbors
                if (i > 0 && grid[i - 1][j] == 1) {
                    UF_union(uf, i * COLS + j, (i - 1) * COLS + j);
                }
                if (i < ROWS - 1 && grid[i + 1][j] == 1) {
                    UF_union(uf, i * COLS + j, (i + 1) * COLS + j);
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    UF_union(uf, i * COLS + j, i * COLS + j - 1);
                }
                if (j < COLS - 1 && grid[i][j + 1] == 1) {
                    UF_union(uf, i * COLS + j, i * COLS + j + 1);
                }
            }
        }
    }

    // Check if the top and bottom rows are connected
    int top_root = UF_find(uf, 0);
    int bottom_root = UF_find(uf, (ROWS - 1) * COLS);

    // Destroy the union-find data structure
    UF_destroy(uf);

    // Return whether the grid percolates
    return top_root == bottom_root;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a grid
    int **grid = generate_grid();

    // Print the grid
    printf("Grid:\n");
    print_grid(grid);

    // Check if the grid percolates
    int percolates_result = percolates(grid);

    // Print the result
    printf("Percolates: %d\n", percolates_result);

    // Free the grid
    for (int i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}