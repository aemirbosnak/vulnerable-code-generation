//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int **grid;
    int size;
} PercolationSystem;

PercolationSystem* create_percolation_system(int size) {
    PercolationSystem *ps = malloc(sizeof(PercolationSystem));
    ps->size = size;
    ps->grid = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        ps->grid[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            ps->grid[i][j] = BLOCKED; // Initialize all sites to blocked
        }
    }
    return ps;
}

void destroy_percolation_system(PercolationSystem *ps) {
    for (int i = 0; i < ps->size; i++) {
        free(ps->grid[i]);
    }
    free(ps->grid);
    free(ps);
}

void random_fill(PercolationSystem *ps, float probability) {
    for (int i = 0; i < ps->size; i++) {
        for (int j = 0; j < ps->size; j++) {
            if ((float)rand() / RAND_MAX < probability) {
                ps->grid[i][j] = OPEN; // Randomly open some sites
            }
        }
    }
}

int is_valid(int x, int y, int size) {
    return (x >= 0 && x < size && y >= 0 && y < size);
}

int dfs(PercolationSystem *ps, int x, int y, int **visited) {
    if (!is_valid(x, y, ps->size) || visited[x][y] || ps->grid[x][y] == BLOCKED) {
        return 0;
    }
    
    visited[x][y] = 1; // Mark this site as visited

    // Check if we reached the bottom row
    if (x == ps->size - 1) {
        return 1; // Percolates
    }

    // Explore neighbors
    return dfs(ps, x + 1, y, visited) ||
           dfs(ps, x - 1, y, visited) ||
           dfs(ps, x, y + 1, visited) ||
           dfs(ps, x, y - 1, visited);
}

int percolates(PercolationSystem *ps) {
    int **visited = malloc(ps->size * sizeof(int*));
    for (int i = 0; i < ps->size; i++) {
        visited[i] = calloc(ps->size, sizeof(int));
    }

    for (int j = 0; j < ps->size; j++) {
        if (ps->grid[0][j] == OPEN && !visited[0][j]) {
            if (dfs(ps, 0, j, visited)) {
                for (int i = 0; i < ps->size; i++) {
                    free(visited[i]);
                }
                free(visited);
                return 1; // Found a path from top to bottom
            }
        }
    }

    for (int i = 0; i < ps->size; i++) {
        free(visited[i]);
    }
    free(visited);
    return 0; // No path found
}

void print_grid(PercolationSystem *ps) {
    printf("Percolation Grid:\n");
    for (int i = 0; i < ps->size; i++) {
        for (int j = 0; j < ps->size; j++) {
            printf("%d ", ps->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size = 10;
    float probability = 0.5;
    
    PercolationSystem *ps = create_percolation_system(size);
    random_fill(ps, probability);
    print_grid(ps);
    
    if (percolates(ps)) {
        printf("The system percolates! 🌊\n");
    } else {
        printf("Oh no! The system does not percolate! 😢\n");
    }
    
    destroy_percolation_system(ps);
    return 0;
}