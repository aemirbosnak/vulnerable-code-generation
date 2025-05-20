//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN   1
#define BLOCKED 0

typedef struct {
    int size;
    int **grid;
} Percolation;

Percolation* create_percolation(int size) {
    Percolation *p = malloc(sizeof(Percolation));
    p->size = size;
    p->grid = malloc(size * sizeof(int *));
    
    for (int i = 0; i < size; i++) {
        p->grid[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = BLOCKED;
        }
    }
    return p;
}

void free_percolation(Percolation *p) {
    if (!p) return;

    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void open_site(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }
    p->grid[row][col] = OPEN;
}

int is_open(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) {
        return 0;
    }
    return p->grid[row][col] == OPEN;
}

int percolates(Percolation *p) {
    for (int col = 0; col < p->size; col++) {
        if (is_open(p, p->size - 1, col)) {
            if (dfs(p, p->size - 1, col)) {
                return 1;
            }
        }
    }
    return 0;
}

int dfs(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size) {
        return 0;
    }
    if (!is_open(p, row, col)) {
        return 0;
    }
    if (row == 0) {
        return 1;  // Reached the top
    }

    p->grid[row][col] = BLOCKED;  // Mark as visited

    int result = dfs(p, row - 1, col) || 
                 dfs(p, row + 1, col) || 
                 dfs(p, row, col - 1) || 
                 dfs(p, row, col + 1);

    p->grid[row][col] = OPEN; // Unmark after visit
    return result;
}

void print_grid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size = 10; // Grid size
    Percolation *p = create_percolation(size);

    // Randomly open sites
    for (int i = 0; i < size * size / 2; i++) {
        int row = rand() % size;
        int col = rand() % size;
        open_site(p, row, col);
    }

    printf("Grid state:\n");
    print_grid(p);

    if (percolates(p)) {
        printf("Percolates!\n");
    } else {
        printf("Does not percolate.\n");
    }

    free_percolation(p);
    return 0;
}