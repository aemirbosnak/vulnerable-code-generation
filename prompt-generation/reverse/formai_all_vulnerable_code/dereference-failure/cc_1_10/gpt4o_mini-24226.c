//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10 // Define the grid size
#define OPEN 1  // Site state representing open
#define CLOSED 0 // Site state representing closed

typedef struct {
    int **grid;
    int size;
} Percolation;

void initPercolation(Percolation *p, int size) {
    p->size = size;
    p->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        p->grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = CLOSED; // Initialize all sites to CLOSED
        }
    }
}

void freePercolation(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
}

void openSite(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        p->grid[row][col] = OPEN;
    }
}

bool isOpen(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        return p->grid[row][col] == OPEN;
    }
    return false;
}

bool percolateUtil(Percolation *p, int row, int col, bool visited[SIZE][SIZE]) {
    if (row == p->size - 1) return true; // Reached the bottom

    visited[row][col] = true; // Mark current site as visited

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        if (isOpen(p, newRow, newCol) && !visited[newRow][newCol]) {
            if (percolateUtil(p, newRow, newCol, visited)) {
                return true;
            }
        }
    }

    return false;
}

bool percolate(Percolation *p) {
    bool visited[SIZE][SIZE] = {false};

    for (int col = 0; col < p->size; col++) {
        if (isOpen(p, 0, col) && !visited[0][col]) {
            if (percolateUtil(p, 0, col, visited)) {
                return true;
            }
        }
    }
    return false;
}

void printGrid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%c ", p->grid[i][j] == OPEN ? '.' : '#');
        }
        printf("\n");
    }
}

void randomOpenSites(Percolation *p, double probability) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if ((double)rand() / RAND_MAX < probability) {
                openSite(p, i, j);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    Percolation p;
    initPercolation(&p, SIZE);

    // Open a random subset of sites
    randomOpenSites(&p, 0.55); // 55% chance to open a site

    // Print the grid
    printf("The Percolation Grid:\n");
    printGrid(&p);

    // Check for percolation
    if (percolate(&p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freePercolation(&p);
    return 0;
}