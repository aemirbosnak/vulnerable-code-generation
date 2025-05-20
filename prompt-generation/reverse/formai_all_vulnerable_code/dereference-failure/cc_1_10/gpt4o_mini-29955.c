//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5 // grid size
#define OPEN 1
#define BLOCKED 0

typedef struct {
    int **grid;
    int rows;
    int cols;
} Percolation;

Percolation *initializeGrid(int rows, int cols);
void freeGrid(Percolation *p);
void openSite(Percolation *p, int x, int y);
int isOpen(Percolation *p, int x, int y);
int percolates(Percolation *p);
int checkPercolation(Percolation *p, int x, int y, int visited[SIZE][SIZE]);
void printGrid(Percolation *p);

int main() {
    srand(time(NULL)); // Seed for random generator

    Percolation *p = initializeGrid(SIZE, SIZE);

    // Randomly open sites in the grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (rand() % 2 == 0) {
                openSite(p, i, j);
            }
        }
    }

    printGrid(p);

    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freeGrid(p);
    return 0;
}

Percolation *initializeGrid(int rows, int cols) {
    Percolation *p = malloc(sizeof(Percolation));
    p->rows = rows;
    p->cols = cols;

    p->grid = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        p->grid[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            p->grid[i][j] = BLOCKED; // Initialize all sites as blocked
        }
    }
    return p;
}

void freeGrid(Percolation *p) {
    for (int i = 0; i < p->rows; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void openSite(Percolation *p, int x, int y) {
    if (x >= 0 && x < p->rows && y >= 0 && y < p->cols) {
        p->grid[x][y] = OPEN; // Open the site
    }
}

int isOpen(Percolation *p, int x, int y) {
    return (x >= 0 && x < p->rows && y >= 0 && y < p->cols && p->grid[x][y] == OPEN);
}

int percolates(Percolation *p) {
    // Check from all sites in the top row
    int visited[SIZE][SIZE] = {0}; // Initialize visited array
    for (int j = 0; j < p->cols; j++) {
        if (isOpen(p, 0, j) && !visited[0][j]) {
            if (checkPercolation(p, 0, j, visited)) {
                return 1; // If any of the dfs returns true
            }
        }
    }
    return 0;
}

int checkPercolation(Percolation *p, int x, int y, int visited[SIZE][SIZE]) {
    if (x == p->rows - 1) return 1; // Reached bottom row
    visited[x][y] = 1; // Mark the site as visited
    // Move in 4 possible directions
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        if (isOpen(p, newX, newY) && !visited[newX][newY]) {
            if (checkPercolation(p, newX, newY, visited)) {
                return 1; // If any of the dfs returns true
            }
        }
    }
    return 0;
}

void printGrid(Percolation *p) {
    printf("Grid Layout:\n");
    for (int i = 0; i < p->rows; i++) {
        for (int j = 0; j < p->cols; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}