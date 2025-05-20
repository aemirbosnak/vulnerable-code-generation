//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    int rows;
    int cols;
    bool **grid;
    bool **full;
} Percolation;

Percolation* createPercolation(int rows, int cols) {
    Percolation *perc = malloc(sizeof(Percolation));
    perc->rows = rows;
    perc->cols = cols;
    perc->grid = malloc(rows * sizeof(bool*));
    perc->full = malloc(rows * sizeof(bool*));
    
    for (int i = 0; i < rows; i++) {
        perc->grid[i] = calloc(cols, sizeof(bool));
        perc->full[i] = calloc(cols, sizeof(bool));
    }

    return perc;
}

void freePercolation(Percolation *perc) {
    for (int i = 0; i < perc->rows; i++) {
        free(perc->grid[i]);
        free(perc->full[i]);
    }
    free(perc->grid);
    free(perc->full);
    free(perc);
}

void openSite(Percolation *perc, int row, int col) {
    if (row < 0 || row >= perc->rows || col < 0 || col >= perc->cols) {
        return;
    }
    perc->grid[row][col] = true;
}

bool isOpen(Percolation *perc, int row, int col) {
    if (row < 0 || row >= perc->rows || col < 0 || col >= perc->cols) {
        return false;
    }
    return perc->grid[row][col];
}

void printGrid(Percolation *perc) {
    for (int i = 0; i < perc->rows; i++) {
        for (int j = 0; j < perc->cols; j++) {
            printf("%c ", perc->grid[i][j] ? 'O' : 'X');
        }
        printf("\n");
    }
}

void DFS(Percolation *perc, int row, int col) {
    if (row < 0 || row >= perc->rows || col < 0 || col >= perc->cols) {
        return;
    }
    if (!isOpen(perc, row, col) || perc->full[row][col]) {
        return;
    }

    perc->full[row][col] = true;

    // Visit neighbors
    DFS(perc, row - 1, col); // up
    DFS(perc, row + 1, col); // down
    DFS(perc, row, col - 1); // left
    DFS(perc, row, col + 1); // right
}

bool percolates(Percolation *perc) {
    for (int col = 0; col < perc->cols; col++) {
        if (isOpen(perc, 0, col) && !perc->full[0][col]) {
            DFS(perc, 0, col);
        }
    }

    for (int col = 0; col < perc->cols; col++) {
        if (perc->full[perc->rows - 1][col]) {
            return true;
        }
    }
    return false;
}

void randomOpenSites(Percolation *perc, double threshold) {
    srand(time(NULL));
    for (int i = 0; i < perc->rows; i++) {
        for (int j = 0; j < perc->cols; j++) {
            if ((double)rand() / RAND_MAX < threshold) {
                openSite(perc, i, j);
            }
        }
    }
}

int main() {
    int rows = 20;
    int cols = 20;
    double threshold = 0.55; // Probability of opening a site

    Percolation *perc = createPercolation(rows, cols);

    randomOpenSites(perc, threshold);
    printf("Percolation Grid:\n");
    printGrid(perc);

    if (percolates(perc)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freePercolation(perc);
    return 0;
}