//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define WIDTH 20
#define HEIGHT 20

// Probability of a cell being open
#define P 0.5

// Union-find data structure
typedef struct {
    int *id;
    int count;
} UF;

// Create a new union-find data structure
UF *UF_create(int n) {
    UF *uf = malloc(sizeof(UF));
    uf->id = malloc(n * sizeof(int));
    uf->count = n;
    for (int i = 0; i < n; i++) {
        uf->id[i] = i;
    }
    return uf;
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
    int rootP = UF_find(uf, p);
    int rootQ = UF_find(uf, q);
    if (rootP == rootQ) {
        return;
    }
    uf->id[rootP] = rootQ;
    uf->count--;
}

// Generate a random grid of open and closed cells
int **generate_grid() {
    int **grid = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = malloc(WIDTH * sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = (rand() < RAND_MAX * P) ? 1 : 0;
        }
    }
    return grid;
}

// Print the grid to the console
void print_grid(int **grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Check if the system percolates
int percolates(int **grid) {
    UF *uf = UF_create(WIDTH * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 0) {
                continue;
            }
            if (i > 0 && grid[i-1][j] == 1) {
                UF_union(uf, i*WIDTH + j, (i-1)*WIDTH + j);
            }
            if (j > 0 && grid[i][j-1] == 1) {
                UF_union(uf, i*WIDTH + j, i*WIDTH + j - 1);
            }
        }
    }
    for (int i = 0; i < WIDTH; i++) {
        if (UF_find(uf, i) == UF_find(uf, WIDTH * HEIGHT - 1)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));

    int **grid = generate_grid();
    print_grid(grid);

    if (percolates(grid)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    return 0;
}