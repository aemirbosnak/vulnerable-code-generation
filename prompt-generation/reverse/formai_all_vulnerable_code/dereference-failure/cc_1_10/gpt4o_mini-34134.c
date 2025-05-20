//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10  // Grid size
#define OPEN '.'
#define BLOCKED '#'
#define FILLED '*'

typedef struct {
    int **grid;
    int size;
} Percolation;

Percolation* create_percolation(int size) {
    Percolation* p = (Percolation*)malloc(sizeof(Percolation));
    p->size = size;
    p->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        p->grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = 1;  // Start blocked
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

void print_grid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if (p->grid[i][j] == 0)
                printf("%c ", OPEN);
            else if (p->grid[i][j] == 1)
                printf("%c ", BLOCKED);
            else
                printf("%c ", FILLED);
        }
        printf("\n");
    }
    printf("\n\n");
}

void generate_random_grid(Percolation *p) {
    srand(time(NULL));
    int num_open_sites = (rand() % (p->size * p->size)) + 1;
    for (int i = 0; i < num_open_sites; i++) {
        int x = rand() % p->size;
        int y = rand() % p->size;
        p->grid[x][y] = 0;  // Open site
    }
}

int is_open(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->size || col < 0 || col >= p->size)
        return 1; // Out of bounds is considered blocked
    return p->grid[row][col] == 0;
}

int percolates_util(Percolation *p, int row, int col, int **visited) {
    if (row == p->size - 1) return 1; // Reached bottom
    if (row < 0 || row >= p->size || col < 0 || col >= p->size || 
        visited[row][col] || p->grid[row][col] != 0)
        return 0; // Out of bounds or already visited or blocked

    visited[row][col] = 1; // Mark as visited

    // Explore all directions
    if (percolates_util(p, row + 1, col, visited)) return 1; // Down
    if (percolates_util(p, row - 1, col, visited)) return 1; // Up
    if (percolates_util(p, row, col + 1, visited)) return 1; // Right
    if (percolates_util(p, row, col - 1, visited)) return 1; // Left
    return 0;
}

int percolates(Percolation *p) {
    int **visited = (int**)malloc(p->size * sizeof(int*));
    for (int i = 0; i < p->size; i++) {
        visited[i] = (int*)calloc(p->size, sizeof(int));
    }

    // Trying from every top row site
    for (int col = 0; col < p->size; col++) {
        if (is_open(p, 0, col) && percolates_util(p, 0, col, visited)) {
            for (int i = 0; i < p->size; i++) free(visited[i]);
            free(visited);
            return 1;
        }
    }
    
    for (int i = 0; i < p->size; i++) free(visited[i]);
    free(visited);
    return 0;
}

int main() {
    Percolation *p = create_percolation(N);
    generate_random_grid(p);
    
    printf("Grid Representation:\n");
    print_grid(p);
    
    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_percolation(p);
    return 0;
}