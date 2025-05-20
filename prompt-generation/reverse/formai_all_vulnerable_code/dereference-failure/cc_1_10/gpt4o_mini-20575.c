//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 10
#define TRIALS 1000

typedef struct {
    bool **grid;
    int size;
} Percolation;

Percolation* createPercolation(int size);
void freePercolation(Percolation *p);
void fillGrid(Percolation *p);
bool percolates(Percolation *p);
void printGrid(Percolation *p);
void simulatePercolation(int trials);
void help();

int main(int argc, char **argv) {
    srand(time(NULL));
    
    if (argc != 3) {
        help();
        return EXIT_FAILURE;
    }

    int gridSize = atoi(argv[1]);
    int trials = atoi(argv[2]);

    if (gridSize <= 0 || trials <= 0) {
        help();
        return EXIT_FAILURE;
    }

    printf("Starting simulation with grid size %d for %d trials.\n", gridSize, trials);
    simulatePercolation(trials);

    return EXIT_SUCCESS;
}

Percolation* createPercolation(int size) {
    Percolation *p = (Percolation *)malloc(sizeof(Percolation));
    p->size = size;
    p->grid = (bool **)malloc(size * sizeof(bool *));
    for (int i = 0; i < size; i++) {
        p->grid[i] = (bool *)calloc(size, sizeof(bool));
    }
    return p;
}

void freePercolation(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void fillGrid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            p->grid[i][j] = rand() % 2; // Randomly fill with true(1) or false(0)
        }
    }
}

bool dfs(Percolation *p, int x, int y, bool **visited) {
    if (x < 0 || y < 0 || x >= p->size || y >= p->size || visited[x][y] || !p->grid[x][y]) {
        return false;
    }
    visited[x][y] = true;
    if (x == p->size - 1) {
        return true;
    }
    return dfs(p, x + 1, y, visited) ||
           dfs(p, x, y + 1, visited) ||
           dfs(p, x - 1, y, visited) ||
           dfs(p, x, y - 1, visited);
}

bool percolates(Percolation *p) {
    bool **visited = (bool **)malloc(p->size * sizeof(bool *));
    for (int i = 0; i < p->size; i++) {
        visited[i] = (bool *)calloc(p->size, sizeof(bool));
    }
    bool result = false;
    for (int j = 0; j < p->size; j++) {
        if (dfs(p, 0, j, visited)) {
            result = true;
            break;
        }
    }
    for (int i = 0; i < p->size; i++) {
        free(visited[i]);
    }
    free(visited);
    return result;
}

void simulatePercolation(int trials) {
    int successCount = 0;
    for (int t = 0; t < trials; t++) {
        Percolation *p = createPercolation(GRID_SIZE);
        fillGrid(p);
        if (percolates(p)) {
            successCount++;
        }
        freePercolation(p);
    }
    printf("Out of %d trials, the system percolated %d times (%.2f%% success rate).\n", trials, successCount, (successCount / (float)trials) * 100);
}

void help() {
    printf("Usage: ./percolation_simulator <grid_size> <number_of_trials>\n");
    printf("Example: ./percolation_simulator 10 1000\n");
    printf("The program simulates a percolation system on a grid of specified size.\n");
    printf("It fills the grid randomly and checks for percolation from top to bottom.\n");
}