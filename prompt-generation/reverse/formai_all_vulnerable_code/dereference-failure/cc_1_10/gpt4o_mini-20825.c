//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int **grid;
    int size;
} Percolation;

Percolation* createPercolation(int n) {
    Percolation* p = (Percolation*)malloc(sizeof(Percolation));
    p->size = n;
    p->grid = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        p->grid[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            p->grid[i][j] = BLOCKED; // Initialize all sites as blocked
        }
    }
    return p;
}

void freePercolation(Percolation* p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void displayGrid(Percolation* p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

void randomOpenSites(Percolation* p, float probability) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if ((float)rand() / RAND_MAX < probability) {
                p->grid[i][j] = OPEN; // Open the site
            }
        }
    }
}

int isValid(int x, int y, Percolation* p) {
    return (x >= 0 && x < p->size && y >= 0 && y < p->size);
}

int percolates(Percolation* p) {
    for (int j = 0; j < p->size; j++) {
        if (p->grid[0][j] == OPEN) { // Check first row
            int visited[p->size][p->size];
            for (int i = 0; i < p->size; i++) {
                for (int j = 0; j < p->size; j++) {
                    visited[i][j] = 0; // Initialize visited
                }
            }
            // Start recursive search
            if (dfs(0, j, p, visited)) {
                return 1; // Found a path to the bottom
            }
        }
    }
    return 0; // No path found
}

int dfs(int x, int y, Percolation* p, int visited[][p->size]) {
    if (x == p->size - 1) return 1; // Reached the last row
    visited[x][y] = 1; // Mark this cell as visited
    // Explore neighbors
    int directions[][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}}; // Down, Right, Left, Up
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        if (isValid(newX, newY, p) && !visited[newX][newY] && p->grid[newX][newY] == OPEN) {
            if (dfs(newX, newY, p, visited)) {
                return 1; // Path found
            }
        }
    }
    return 0; // No path found
}

int main() {
    srand(time(NULL));
    int size = 10;
    float probability = 0.5;
    Percolation* p = createPercolation(size);
    
    randomOpenSites(p, probability);
    
    printf("Percolation Grid:\n");
    displayGrid(p);
    
    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    
    freePercolation(p);
    return 0;
}