//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define OPEN 1
#define BLOCKED 0

typedef struct {
    int *parent;
    int *rank;
    int size;
} UnionFind;

UnionFind* create_union_find(int size) {
    UnionFind *uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->size = size;
    uf->parent = (int*)malloc(size * sizeof(int));
    uf->rank = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}

int find(UnionFind *uf, int p) {
    if (uf->parent[p] != p) {
        uf->parent[p] = find(uf, uf->parent[p]); // Path compression
    }
    return uf->parent[p];
}

void union_set(UnionFind *uf, int p, int q) {
    int rootP = find(uf, p);
    int rootQ = find(uf, q);
    
    if (rootP != rootQ) {
        // Union by rank
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

void free_union_find(UnionFind *uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void percolation_simulator() {
    int grid[GRID_SIZE][GRID_SIZE];
    UnionFind *uf = create_union_find(GRID_SIZE * GRID_SIZE);

    // Randomly initialize the grid
    srand(time(NULL));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 2; // Randomly set to OPEN or BLOCKED
        }
    }

    // Print Initial Grid
    printf("Initial Grid:\n");
    print_grid(grid);
    
    // Create union connections for open sites
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == OPEN) {
                // Map 2D grid position to 1D array
                int index = i * GRID_SIZE + j;

                // Check neighboring cells (up, down, left, right)
                if (i > 0 && grid[i - 1][j] == OPEN) {
                    union_set(uf, index, (i - 1) * GRID_SIZE + j);
                }
                if (j > 0 && grid[i][j - 1] == OPEN) {
                    union_set(uf, index, i * GRID_SIZE + (j - 1));
                }
                if (i < GRID_SIZE - 1 && grid[i + 1][j] == OPEN) {
                    union_set(uf, index, (i + 1) * GRID_SIZE + j);
                }
                if (j < GRID_SIZE - 1 && grid[i][j + 1] == OPEN) {
                    union_set(uf, index, i * GRID_SIZE + (j + 1));
                }
            }
        }
    }

    // Check for percolation from the first row to the last row
    int top_root = find(uf, 0); // Top row
    int percolates = 0;
    
    for (int j = 0; j < GRID_SIZE; j++) {
        if (grid[GRID_SIZE - 1][j] == OPEN) {
            int bottom_index = (GRID_SIZE - 1) * GRID_SIZE + j;
            if (find(uf, bottom_index) == top_root) {
                percolates = 1;
                break;
            }
        }
    }

    // Result of percolation
    if (percolates) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_union_find(uf);
}

int main() {
    percolation_simulator();
    return 0;
}