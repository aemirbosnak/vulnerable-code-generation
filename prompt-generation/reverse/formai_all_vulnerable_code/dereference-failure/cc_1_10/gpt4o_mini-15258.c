//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int rows;
    int cols;
    int **grid;
} Percolation;

Percolation* create_percolation(int rows, int cols) {
    Percolation *p = (Percolation *)malloc(sizeof(Percolation));
    p->rows = rows;
    p->cols = cols;
    
    p->grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        p->grid[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            p->grid[i][j] = BLOCKED;
        }
    }

    return p;
}

void free_percolation(Percolation *p) {
    for (int i = 0; i < p->rows; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void print_grid(Percolation *p) {
    for (int i = 0; i < p->rows; i++) {
        for (int j = 0; j < p->cols; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void open_site(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->rows && col >= 0 && col < p->cols) {
        p->grid[row][col] = OPEN;
    }
}

int is_open(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->rows && col >= 0 && col < p->cols) {
        return p->grid[row][col] == OPEN;
    }
    return 0;
}

int validate_percolation(Percolation *p, int row, int col) {
    if (row == p->rows - 1) return 1; // Reached the bottom
    
    // Check possible connections (down, left, right)
    if (is_open(p, row + 1, col) && validate_percolation(p, row + 1, col)) return 1;
    if (is_open(p, row, col - 1) && validate_percolation(p, row, col - 1)) return 1;
    if (is_open(p, row, col + 1) && validate_percolation(p, row, col + 1)) return 1;
    
    return 0;
}

int percolates(Percolation *p) {
    for (int col = 0; col < p->cols; col++) {
        if (is_open(p, 0, col) && validate_percolation(p, 0, col)) {
            return 1; // Percolates if we can connect top to bottom
        }
    }
    return 0;
}

void random_open_sites(Percolation *p, float prob) {
    for (int i = 0; i < p->rows; i++) {
        for (int j = 0; j < p->cols; j++) {
            if (((float)rand() / RAND_MAX) < prob) {
                open_site(p, i, j);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int rows = 10;
    int cols = 10;
    float probability = 0.55; // Probability of opening a site

    Percolation *p = create_percolation(rows, cols);
    random_open_sites(p, probability);
    
    printf("Percolation grid:\n");
    print_grid(p);

    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_percolation(p);
    return 0;
}