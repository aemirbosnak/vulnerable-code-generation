//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define OPEN 1
#define BLOCKED 0

typedef struct {
    int **grid;
    int size;
} Percolation;

Percolation* create_percolation(int size) {
    Percolation *p = malloc(sizeof(Percolation));
    p->size = size;
    p->grid = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        p->grid[i] = malloc(size * sizeof(int));
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

void initialize_grid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            p->grid[i][j] = rand() % 2; // Randomly assign OPEN or BLOCKED
        }
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

int valid_position(int x, int y, Percolation *p) {
    return x >= 0 && x < p->size && y >= 0 && y < p->size && p->grid[x][y] == OPEN;
}

int percolates_helper(Percolation *p, int x, int y, int *visited) {
    if (x == p->size - 1) return 1; // Reach bottom row
    
    // Mark the current position as visited
    visited[x * p->size + y] = 1;

    // Check all four directions (up, down, left, right)
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        int new_x = x + directions[i][0];
        int new_y = y + directions[i][1];
        if (valid_position(new_x, new_y, p) && !visited[new_x * p->size + new_y]) {
            if (percolates_helper(p, new_x, new_y, visited)) {
                return 1;
            }
        }
    }
    return 0; // No path found
}

int percolates(Percolation *p) {
    int *visited = calloc(p->size * p->size, sizeof(int));
    for (int j = 0; j < p->size; j++) {
        if (p->grid[0][j] == OPEN && !visited[j]) { // Start from top row
            if (percolates_helper(p, 0, j, visited)) {
                free(visited);
                return 1; // Percolates!
            }
        }
    }
    free(visited);
    return 0; // Does not percolate
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    Percolation *p = create_percolation(GRID_SIZE);
    initialize_grid(p);
    
    printf("Grid:\n");
    print_grid(p);
    
    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    
    free_percolation(p);
    return 0;
}