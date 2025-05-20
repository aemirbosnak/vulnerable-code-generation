//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 20

typedef struct {
    int** grid;
    bool* visited;
} Percolation;

Percolation* create_percolation() {
    Percolation* p = (Percolation*)malloc(sizeof(Percolation));
    p->grid = (int**)malloc(GRID_SIZE * sizeof(int*));
    for (int i = 0; i < GRID_SIZE; i++) {
        p->grid[i] = (int*)malloc(GRID_SIZE * sizeof(int));
    }

    p->visited = (bool*)malloc(GRID_SIZE * GRID_SIZE * sizeof(bool));
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        p->visited[i] = false;
    }
    
    return p;
}

void free_percolation(Percolation* p) {
    for (int i = 0; i < GRID_SIZE; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p->visited);
    free(p);
}

void initialize_grid(Percolation* p, double p_open) {
    srand(time(NULL));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if ((double)rand() / RAND_MAX < p_open) {
                p->grid[i][j] = 1; // Open site
            } else {
                p->grid[i][j] = 0; // Blocked site
            }
        }
    }
}

void print_grid(Percolation* p) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

bool is_valid(int x, int y) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE);
}

void dfs(Percolation* p, int x, int y) {
    if (!is_valid(x, y) || p->visited[x * GRID_SIZE + y] || p->grid[x][y] == 0) {
        return;
    }

    p->visited[x * GRID_SIZE + y] = true;

    // Check neighbors
    dfs(p, x - 1, y); // up
    dfs(p, x + 1, y); // down
    dfs(p, x, y - 1); // left
    dfs(p, x, y + 1); // right
}

bool does_percolate(Percolation* p) {
    for (int j = 0; j < GRID_SIZE; j++) {
        if (p->grid[0][j] == 1 && !p->visited[0 * GRID_SIZE + j]) {
            dfs(p, 0, j);
        }
    }

    for (int j = 0; j < GRID_SIZE; j++) {
        if (p->visited[(GRID_SIZE - 1) * GRID_SIZE + j]) {
            return true; // Percolates
        }
    }

    return false; // Does not percolate
}

int main() {
    double p_open = 0.5; // Probability of a site being open
    int trials = 1000; // Number of trials
    int percolation_count = 0;

    for (int trial = 0; trial < trials; trial++) {
        Percolation* p = create_percolation();
        initialize_grid(p, p_open);
        
        if (does_percolate(p)) {
            percolation_count++;
        }

        free_percolation(p); // Clean up
    }

    double percolation_probability = (double)percolation_count / trials;
    printf("After %d trials, the percolation probability is: %.4f\n", trials, percolation_probability);
    
    return 0;
}