//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define CLOSED 0

typedef struct {
    int **grid;  // 2D grid to represent the percolation system
    int size;    // Size of the grid (size x size)
} Percolation;

Percolation* create_percolation(int size);
void free_percolation(Percolation *p);
void open_site(Percolation *p, int row, int col);
int is_open(Percolation *p, int row, int col);
int percolates(Percolation *p);
void print_grid(Percolation *p);
int validate_input(int row, int col, int size);
void run_simulation(int size);

int main() {
    int size;

    printf("Enter the size of the grid (n x n): ");
    scanf("%d", &size);
    
    run_simulation(size);

    return 0;
}

Percolation* create_percolation(int size) {
    Percolation *p = (Percolation*)malloc(sizeof(Percolation));
    p->size = size;

    p->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        p->grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = CLOSED;  // Initialize all sites as closed
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
    if (validate_input(row, col, p->size)) {
        p->grid[row][col] = OPEN;
    }
}

int is_open(Percolation *p, int row, int col) {
    return validate_input(row, col, p->size) ? (p->grid[row][col] == OPEN) : 0;
}

int validate_input(int row, int col, int size) {
    return (row >= 0 && row < size && col >= 0 && col < size);
}

int dfs(Percolation *p, int row, int col, int *visited) {
    if (!is_open(p, row, col) || visited[row * p->size + col]) {
        return 0;
    }
    
    visited[row * p->size + col] = 1;

    // If reaches the last row
    if (row == p->size - 1) {
        return 1;
    }

    // Check all four directions (up, down, left, right)
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        if (dfs(p, newRow, newCol, visited)) {
            return 1;
        }
    }

    return 0;
}

int percolates(Percolation *p) {
    int *visited = (int*)calloc(p->size * p->size, sizeof(int));
    for (int col = 0; col < p->size; col++) {
        if (is_open(p, 0, col) && dfs(p, 0, col, visited)) {
            free(visited);
            return 1;
        }
    }
    free(visited);
    return 0;
}

void print_grid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

void run_simulation(int size) {
    Percolation *p = create_percolation(size);
    srand(time(NULL));

    // Randomly open sites
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (rand() % 2) {  // 50% chance to open the site
                open_site(p, i, j);
            }
        }
    }

    printf("Final Grid:\n");
    print_grid(p);

    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does NOT percolate.\n");
    }

    free_percolation(p);
}