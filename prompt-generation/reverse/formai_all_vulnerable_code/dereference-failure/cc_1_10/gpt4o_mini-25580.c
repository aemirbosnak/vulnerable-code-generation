//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int n;
    int grid[MAX_SIZE][MAX_SIZE];
    bool open[MAX_SIZE][MAX_SIZE];
} Percolation;

Percolation* createPercolation(int n) {
    Percolation* p = (Percolation*)malloc(sizeof(Percolation));
    p->n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p->grid[i][j] = 0;
            p->open[i][j] = false;
        }
    }
    return p;
}

void openSite(Percolation* p, int row, int col) {
    if (row < 0 || col < 0 || row >= p->n || col >= p->n) {
        printf("Index out of bounds!\n");
        return;
    }
    p->open[row][col] = true;
}

bool isOpen(Percolation* p, int row, int col) {
    if (row < 0 || col < 0 || row >= p->n || col >= p->n) {
        return false;
    }
    return p->open[row][col];
}

bool percolatesHelper(Percolation* p, int row, int col, bool* visited) {
    if (row == p->n - 1) {
        return true;
    }
    if (row < 0 || col < 0 || row >= p->n || col >= p->n || !isOpen(p, row, col) || visited[row * p->n + col]) {
        return false;
    }
    
    visited[row * p->n + col] = true;

    if (percolatesHelper(p, row + 1, col, visited) ||
        percolatesHelper(p, row - 1, col, visited) ||
        percolatesHelper(p, row, col + 1, visited) ||
        percolatesHelper(p, row, col - 1, visited)) {
        return true;
    }
    return false;
}

bool percolates(Percolation* p) {
    bool* visited = (bool*)calloc(p->n * p->n, sizeof(bool));
    for (int col = 0; col < p->n; col++) {
        if (isOpen(p, 0, col)) {
            if (percolatesHelper(p, 0, col, visited)) {
                free(visited);
                return true;
            }
        }
    }
    free(visited);
    return false;
}

void randomizeGrid(Percolation* p, float prob) {
    srand(time(NULL));
    for (int i = 0; i < p->n; i++) {
        for (int j = 0; j < p->n; j++) {
            if ((float)rand() / RAND_MAX < prob) {
                openSite(p, i, j);
            }
        }
    }
}

void printGrid(Percolation* p) {
    for (int i = 0; i < p->n; i++) {
        for (int j = 0; j < p->n; j++) {
            if (isOpen(p, i, j)) {
                printf(" O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

void freePercolation(Percolation* p) {
    free(p);
}

int main() {
    int size;
    float prob;

    printf("Enter the size of the grid (n x n): ");
    scanf("%d", &size);
    printf("Enter the probability of opening a site (0.0 to 1.0): ");
    scanf("%f", &prob);

    Percolation* p = createPercolation(size);
    randomizeGrid(p, prob);

    printf("\nGenerated Grid:\n");
    printGrid(p);

    if (percolates(p)) {
        printf("\nThe system percolates!\n");
    } else {
        printf("\nThe system does not percolate.\n");
    }
    
    freePercolation(p);
    return 0;
}