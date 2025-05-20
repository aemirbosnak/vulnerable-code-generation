//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int **grid;
    int size;
} Percolation;

Percolation* create_percolation(int n) {
    Percolation *p = (Percolation *)malloc(sizeof(Percolation));
    p->size = n;
    p->grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        p->grid[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            p->grid[i][j] = BLOCKED;
        }
    }
    return p;
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

int percolates(Percolation *p) {
    // DFS to check percolation from top to bottom
    for (int col = 0; col < p->size; col++) {
        if (is_open(p, 0, col)) {
            int *visited = (int *)calloc(p->size * p->size, sizeof(int));
            if (dfs(p, 0, col, visited)) {
                free(visited);
                return 1;
            }
            free(visited);
        }
    }
    return 0;
}

int dfs(Percolation *p, int row, int col, int *visited) {
    if (row == p->size - 1) {
        return 1; // Reached the last row
    }
    if (row < 0 || row >= p->size || col < 0 || col >= p->size || !is_open(p, row, col) || visited[row * p->size + col]) {
        return 0; // Out of bounds or blocked or already visited
    }
    
    visited[row * p->size + col] = 1; // Mark as visited

    // Explore all four directions
    if (dfs(p, row + 1, col, visited)) return 1; // Down
    if (dfs(p, row - 1, col, visited)) return 1; // Up
    if (dfs(p, row, col + 1, visited)) return 1; // Right
    if (dfs(p, row, col - 1, visited)) return 1; // Left
    
    return 0; // No path found
}

void print_grid(Percolation *p) {
    printf("Percolation grid:\n");
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

void free_percolation(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

int main() {
    srand(time(NULL));
    int n = 20; // Size of the grid
    Percolation *p = create_percolation(n);

    for (int i = 0; i < n * n / 2; i++) {
        int row = rand() % n;
        int col = rand() % n;
        open_site(p, row, col);
    }

    print_grid(p);
    
    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_percolation(p);
    return 0;
}