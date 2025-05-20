//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define OPEN 1
#define BLOCKED 0

typedef struct {
    int width;
    int height;
    int **grid;
} PercolationSystem;

typedef struct {
    int x;
    int y;
} Point;

// Function prototypes
PercolationSystem* createPercolationSystem(int width, int height);
void freePercolationSystem(PercolationSystem *system);
void initializeGrid(PercolationSystem *system);
void printGrid(PercolationSystem *system);
void openSite(PercolationSystem *system, int x, int y);
int isOpen(PercolationSystem *system, int x, int y);
int percolates(PercolationSystem *system);
void depthFirstSearch(PercolationSystem *system, int x, int y, int *visited);
int isOutOfBounds(PercolationSystem *system, int x, int y);

// Main function
int main() {
    int width, height, openSites, x, y;

    printf("Enter the width of the grid: ");
    scanf("%d", &width);
    
    printf("Enter the height of the grid: ");
    scanf("%d", &height);
    
    printf("Enter the number of open sites: ");
    scanf("%d", &openSites);
    
    PercolationSystem *system = createPercolationSystem(width, height);
    initializeGrid(system);

    srand(time(NULL));
    for (int i = 0; i < openSites; i++) {
        x = rand() % width;
        y = rand() % height;
        openSite(system, x, y);
    }

    printGrid(system);
    if (percolates(system)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freePercolationSystem(system);
    return 0;
}

PercolationSystem* createPercolationSystem(int width, int height) {
    PercolationSystem *system = (PercolationSystem*)malloc(sizeof(PercolationSystem));
    system->width = width;
    system->height = height;
    system->grid = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        system->grid[i] = (int*)malloc(width * sizeof(int));
    }
    return system;
}

void freePercolationSystem(PercolationSystem *system) {
    for (int i = 0; i < system->height; i++) {
        free(system->grid[i]);
    }
    free(system->grid);
    free(system);
}

void initializeGrid(PercolationSystem *system) {
    for (int i = 0; i < system->height; i++) {
        for (int j = 0; j < system->width; j++) {
            system->grid[i][j] = BLOCKED;
        }
    }
}

void printGrid(PercolationSystem *system) {
    for (int i = 0; i < system->height; i++) {
        for (int j = 0; j < system->width; j++) {
            printf("%d ", system->grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void openSite(PercolationSystem *system, int x, int y) {
    if (isOutOfBounds(system, x, y)) {
        printf("Error: Coordinates out of bounds (%d, %d).\n", x, y);
        return;
    }
    system->grid[y][x] = OPEN;
}

int isOpen(PercolationSystem *system, int x, int y) {
    return !isOutOfBounds(system, x, y) && (system->grid[y][x] == OPEN);
}

int percolates(PercolationSystem *system) {
    int *visited = (int*)malloc(system->width * system->height * sizeof(int));
    for (int i = 0; i < system->width * system->height; i++) {
        visited[i] = 0;
    }
    
    for (int i = 0; i < system->width; i++) {
        if (isOpen(system, i, 0) && !visited[i]) {
            depthFirstSearch(system, i, 0, visited);
        }
    }

    int doesPercolate = FALSE;
    for (int i = 0; i < system->width; i++) {
        if (visited[(system->height - 1) * system->width + i] == 1) {
            doesPercolate = TRUE;
            break;
        }
    }

    free(visited);
    return doesPercolate;
}

void depthFirstSearch(PercolationSystem *system, int x, int y, int *visited) {
    if (isOutOfBounds(system, x, y) || !isOpen(system, x, y) || visited[y * system->width + x]) {
        return;
    }
    
    visited[y * system->width + x] = 1;

    depthFirstSearch(system, x + 1, y, visited);
    depthFirstSearch(system, x - 1, y, visited);
    depthFirstSearch(system, x, y + 1, visited);
    depthFirstSearch(system, x, y - 1, visited);
}

int isOutOfBounds(PercolationSystem *system, int x, int y) {
    return (x < 0 || x >= system->width || y < 0 || y >= system->height);
}