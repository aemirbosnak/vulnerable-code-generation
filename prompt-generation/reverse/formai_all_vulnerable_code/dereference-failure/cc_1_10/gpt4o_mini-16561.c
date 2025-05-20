//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
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
            p->grid[i][j] = BLOCKED; // Initialize all cells as blocked
        }
    }
    return p;
}

void free_percolation(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void open_site(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        p->grid[row][col] = OPEN;
    }
}

int is_open(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        return p->grid[row][col] == OPEN;
    }
    return 0;
}

int check_percolation(Percolation *p) {
    for (int col = 0; col < p->size; col++) {
        if (is_open(p, 0, col)) {
            if (depth_first_search(p, 0, col, 0)) {
                return 1; // System percolates
            }
        }
    }
    return 0; // System does not percolate
}

int depth_first_search(Percolation *p, int row, int col, int visited[][p->size]) {
    if (row == p->size - 1) return 1; // Reached the last row
    if (row < 0 || col < 0 || row >= p->size || col >= p->size || visited[row][col] || !is_open(p, row, col)) {
        return 0;
    }
    visited[row][col] = 1; // Mark site as visited
    // Explore neighbors
    return depth_first_search(p, row + 1, col, visited) || // Down
           depth_first_search(p, row - 1, col, visited) || // Up
           depth_first_search(p, row, col + 1, visited) || // Right
           depth_first_search(p, row, col - 1, visited);   // Left
}

void random_open_sites(Percolation *p, int attempts) {
    srand(time(NULL));
    for (int i = 0; i < attempts; i++) {
        int row = rand() % p->size;
        int col = rand() % p->size;
        open_site(p, row, col);
    }
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
    int size = 10;
    int attempts = 30;
    
    Percolation* p = create_percolation(size);
    random_open_sites(p, attempts);
    
    print_grid(p);
    
    if (check_percolation(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_percolation(p);
    return 0;
}