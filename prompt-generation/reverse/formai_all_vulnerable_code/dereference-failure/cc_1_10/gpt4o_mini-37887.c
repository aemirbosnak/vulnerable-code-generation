//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GRID_SIZE 10
#define PROBABILITY 0.6

typedef struct {
    int **grid;
    bool **visited;
    int size;
} Percolation;

Percolation* create_grid(int size);
void free_grid(Percolation* p);
void random_fill(Percolation* p);
void print_grid(Percolation* p);
bool percolates(Percolation* p);
void dfs(Percolation* p, int x, int y);
bool is_within_grid(int x, int y, int size);

int main() {
    srand(time(NULL));
    
    Percolation* simulation = create_grid(GRID_SIZE);
    random_fill(simulation);
    
    printf("Grid configuration:\n");
    print_grid(simulation);
    
    if (percolates(simulation)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    
    free_grid(simulation);
    return 0;
}

Percolation* create_grid(int size) {
    Percolation* p = (Percolation*)malloc(sizeof(Percolation));
    p->size = size;

    p->grid = (int**)malloc(size * sizeof(int*));
    p->visited = (bool**)malloc(size * sizeof(bool*));
    
    for (int i = 0; i < size; i++) {
        p->grid[i] = (int*)malloc(size * sizeof(int));
        p->visited[i] = (bool*)malloc(size * sizeof(bool));
        for (int j = 0; j < size; j++) {
            p->visited[i][j] = false;
        }
    }
    
    return p;
}

void free_grid(Percolation* p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
        free(p->visited[i]);
    }
    free(p->grid);
    free(p->visited);
    free(p);
}

void random_fill(Percolation* p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            p->grid[i][j] = (rand() / (float)RAND_MAX < PROBABILITY) ? 1 : 0;
        }
    }
}

void print_grid(Percolation* p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

bool percolates(Percolation* p) {
    for (int i = 0; i < p->size; i++) {
        if (p->grid[0][i] == 1 && !p->visited[0][i]) {
            dfs(p, 0, i);
        }
    }
    
    for (int i = 0; i < p->size; i++) {
        if (p->visited[p->size - 1][i]) {
            return true;
        }
    }
    
    return false;
}

void dfs(Percolation* p, int x, int y) {
    if (!is_within_grid(x, y, p->size) || p->grid[x][y] == 0 || p->visited[x][y]) {
        return;
    }
    
    p->visited[x][y] = true;

    dfs(p, x + 1, y); // down
    dfs(p, x - 1, y); // up
    dfs(p, x, y + 1); // right
    dfs(p, x, y - 1); // left
}

bool is_within_grid(int x, int y, int size) {
    return x >= 0 && x < size && y >= 0 && y < size;
}