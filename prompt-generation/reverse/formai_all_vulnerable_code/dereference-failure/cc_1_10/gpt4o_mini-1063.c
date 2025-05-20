//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int **grid;
    int size;
    int *parent;
} Percolation;

int find(Percolation *p, int i) {
    if (p->parent[i] != i) {
        p->parent[i] = find(p, p->parent[i]);
    }
    return p->parent[i];
}

void union_set(Percolation *p, int p1, int p2) {
    int root1 = find(p, p1);
    int root2 = find(p, p2);
    if (root1 != root2) {
        p->parent[root1] = root2;
    }
}

Percolation* create_percolation(int size) {
    Percolation *p = (Percolation*)malloc(sizeof(Percolation));
    p->size = size;
    p->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        p->grid[i] = (int*)calloc(size, sizeof(int));
    }
    p->parent = (int*)malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++) {
        p->parent[i] = i;
    }
    return p;
}

void free_percolation(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p->parent);
    free(p);
}

void open_site(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) {
        return;
    }
    p->grid[row][col] = TRUE;
    int index = row * p->size + col;
    if (row == 0) {
        union_set(p, index, p->size * p->size); // Connect to virtual top site
    }
    
    if (row > 0 && p->grid[row - 1][col]) {
        union_set(p, index, (row - 1) * p->size + col);
    }
    if (row < p->size - 1 && p->grid[row + 1][col]) {
        union_set(p, index, (row + 1) * p->size + col);
    }
    if (col > 0 && p->grid[row][col - 1]) {
        union_set(p, index, row * p->size + (col - 1));
    }
    if (col < p->size - 1 && p->grid[row][col + 1]) {
        union_set(p, index, row * p->size + (col + 1));
    }
}

int percolates(Percolation *p) {
    for (int col = 0; col < p->size; col++) {
        if (find(p, p->size * (p->size - 1) + col) == find(p, p->size * p->size)) {
            return TRUE;
        }
    }
    return FALSE;
}

void print_grid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

void simulate_percolation(int size, float probability) {
    Percolation *p = create_percolation(size);
    srand(time(0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((float)rand() / RAND_MAX <= probability) {
                open_site(p, i, j);
            }
        }
    }

    print_grid(p);
    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_percolation(p);
}

int main() {
    int size = 5;
    float probability = 0.5; // 50% chance to open a site
    simulate_percolation(size, probability);
    return 0;
}