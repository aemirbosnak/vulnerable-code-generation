//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int **grid;
    int size;
} Percolation;

Percolation* create_percolation(int n) {
    Percolation* perc = (Percolation*)malloc(sizeof(Percolation));
    perc->size = n;
    perc->grid = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        perc->grid[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            perc->grid[i][j] = BLOCKED; // Initialize everything as blocked
        }
    }
    return perc;
}

void free_percolation(Percolation* perc) {
    for (int i = 0; i < perc->size; i++) {
        free(perc->grid[i]);
    }
    free(perc->grid);
    free(perc);
}

void open_site(Percolation* perc, int row, int col) {
    if (row >= 0 && row < perc->size && col >= 0 && col < perc->size) {
        perc->grid[row][col] = OPEN;
    }
}

int is_open(Percolation* perc, int row, int col) {
    return perc->grid[row][col] == OPEN;
}

int is_valid(int row, int col, int n) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

int percolates_helper(Percolation* perc, int row, int col, int* visited) {
    if (row == perc->size - 1) {
        return 1; // Reached the bottom
    }

    visited[row * perc->size + col] = 1; // Mark as visited

    // Directions: down, up, right, left
    int dRow[] = {1, -1, 0, 0};
    int dCol[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        int newRow = row + dRow[i];
        int newCol = col + dCol[i];

        if (is_valid(newRow, newCol, perc->size) && 
            is_open(perc, newRow, newCol) && 
            !visited[newRow * perc->size + newCol]) {
            if (percolates_helper(perc, newRow, newCol, visited)) {
                return 1;
            }
        }
    }

    return 0; // No path found
}

int percolates(Percolation* perc) {
    int n = perc->size;
    int* visited = (int*)calloc(n * n, sizeof(int));

    for (int col = 0; col < n; col++) {
        if (is_open(perc, 0, col) && !visited[0 * n + col]) { 
            if (percolates_helper(perc, 0, col, visited)) {
                free(visited);
                return 1; // Found a percolating path
            }
        }
    }

    free(visited);
    return 0; // No percolating path
}

void print_grid(Percolation* perc) {
    for (int i = 0; i < perc->size; i++) {
        for (int j = 0; j < perc->size; j++) {
            printf("%d ", perc->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int n = 10; // Size of the grid
    Percolation* perc = create_percolation(n);

    // Randomly open sites
    for (int i = 0; i < n * n / 2; i++) {
        int row = rand() % n;
        int col = rand() % n;
        open_site(perc, row, col);
    }

    print_grid(perc);

    if (percolates(perc)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_percolation(perc);
    return 0;
}