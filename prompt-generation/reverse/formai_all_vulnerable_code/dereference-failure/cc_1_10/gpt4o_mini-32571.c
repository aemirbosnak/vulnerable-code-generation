//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int size;
    int *grid;
} Percolation;

Percolation* create_percolation(int size) {
    Percolation *p = malloc(sizeof(Percolation));
    p->size = size;
    p->grid = malloc(size * size * sizeof(int));

    for (int i = 0; i < size * size; i++) {
        p->grid[i] = BLOCKED;
    }
    return p;
}

void free_percolation(Percolation *p) {
    free(p->grid);
    free(p);
}

void open_site(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        p->grid[row * p->size + col] = OPEN;
    }
}

int is_open(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        return p->grid[row * p->size + col] == OPEN;
    }
    return 0;
}

int find(int *parent, int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void union_sets(int *parent, int *rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int percolates(Percolation *p) {
    int *parent = malloc(sizeof(int) * p->size * p->size);
    int *rank = calloc(p->size * p->size, sizeof(int));

    for (int i = 0; i < p->size * p->size; i++) {
        parent[i] = i;
    }

    for (int row = 0; row < p->size; row++) {
        for (int col = 0; col < p->size; col++) {
            if (p->grid[row * p->size + col] == OPEN) {
                if (row > 0 && is_open(p, row - 1, col)) {
                    union_sets(parent, rank, row * p->size + col, (row - 1) * p->size + col);
                }
                if (col > 0 && is_open(p, row, col - 1)) {
                    union_sets(parent, rank, row * p->size + col, row * p->size + (col - 1));
                }
                if (row < p->size - 1 && is_open(p, row + 1, col)) {
                    union_sets(parent, rank, row * p->size + col, (row + 1) * p->size + col);
                }
                if (col < p->size - 1 && is_open(p, row, col + 1)) {
                    union_sets(parent, rank, row * p->size + col, row * p->size + (col + 1));
                }
            }
        }
    }

    int topRoot = find(parent, 0);
    for (int col = 0; col < p->size; col++) {
        if (is_open(p, p->size - 1, col)) {
            if (find(parent, (p->size - 1) * p->size + col) == topRoot) {
                free(parent);
                free(rank);
                return 1; // Percolates
            }
        }
    }

    free(parent);
    free(rank);
    return 0; // Does not percolate
}

void display_grid(Percolation *p) {
    for (int row = 0; row < p->size; row++) {
        for (int col = 0; col < p->size; col++) {
            printf("%c ", p->grid[row * p->size + col] == OPEN ? '.' : '#');
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size = 10; // Grid size
    Percolation *p = create_percolation(size);

    // Randomly open some sites in the grid
    for (int i = 0; i < size * size / 2; i++) {
        int row = rand() % size;
        int col = rand() % size;
        open_site(p, row, col);
    }

    printf("Current Grid:\n");
    display_grid(p);

    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_percolation(p);
    return 0;
}