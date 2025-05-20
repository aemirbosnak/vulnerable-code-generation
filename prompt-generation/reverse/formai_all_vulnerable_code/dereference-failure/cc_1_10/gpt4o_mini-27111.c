//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int **grid;
    int size;
} Grid;

// Function to create a grid of given size
Grid* createGrid(int size) {
    Grid *g = malloc(sizeof(Grid));
    g->size = size;
    g->grid = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        g->grid[i] = malloc(size * sizeof(int));
    }
    return g;
}

// Function to free the memory allocated for the grid
void freeGrid(Grid *g) {
    for (int i = 0; i < g->size; i++) {
        free(g->grid[i]);
    }
    free(g->grid);
    free(g);
}

// Function to initialize the grid with blocked cells and open cells
void initializeGrid(Grid *g, double openProbability) {
    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            g->grid[i][j] = ((rand() / (double)RAND_MAX) < openProbability) ? OPEN : BLOCKED;
        }
    }
}

// Function to print the grid
void printGrid(Grid *g) {
    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            printf("%d ", g->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is valid and open
int isOpen(Grid *g, int x, int y) {
    return (x >= 0 && x < g->size && y >= 0 && y < g->size && g->grid[x][y] == OPEN);
}

// Depth-First Search for connected open sites
void dfs(Grid *g, int x, int y, int *visited) {
    if (!isOpen(g, x, y)) return;
    
    visited[x * g->size + y] = 1;

    // Explore all 4 neighboring cells
    dfs(g, x + 1, y, visited);
    dfs(g, x - 1, y, visited);
    dfs(g, x, y + 1, visited);
    dfs(g, x, y - 1, visited);
}

// Function to count connected components
int countConnectedComponents(Grid *g) {
    int *visited = calloc(g->size * g->size, sizeof(int));
    int components = 0;

    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            if (isOpen(g, i, j) && !visited[i * g->size + j]) {
                // Found an unvisited open site
                components++;
                dfs(g, i, j, visited);
            }
        }
    }

    free(visited);
    return components;
}

// Main function to simulate percolation
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <grid_size> <open_probability>\n", argv[0]);
        return EXIT_FAILURE;
    }

    srand(time(NULL));
    int gridSize = atoi(argv[1]);
    double openProbability = atof(argv[2]);

    Grid *g = createGrid(gridSize);
    initializeGrid(g, openProbability);
    printf("Initialized Grid (%d x %d) with open probability %.2f:\n", gridSize, gridSize, openProbability);

    printGrid(g);
    
    int connectedComponents = countConnectedComponents(g);
    printf("\nNumber of connected components of open sites: %d\n", connectedComponents);

    freeGrid(g);
    return EXIT_SUCCESS;
}