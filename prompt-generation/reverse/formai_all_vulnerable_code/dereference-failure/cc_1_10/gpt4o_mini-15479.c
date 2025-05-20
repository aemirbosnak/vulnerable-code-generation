//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCKED 0
#define OPEN 1
#define FULL 2

typedef struct {
    int width;
    int height;
    int **grid;
} Percolation;

Percolation* create_percolation(int width, int height) {
    Percolation *p = (Percolation*)malloc(sizeof(Percolation));
    p->width = width;
    p->height = height;

    p->grid = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; ++i) {
        p->grid[i] = (int*)malloc(width * sizeof(int));
        for (int j = 0; j < width; ++j) {
            p->grid[i][j] = BLOCKED; // Initialize all sites as BLOCKED
        }
    }
    return p;
}

void free_percolation(Percolation *p) {
    for (int i = 0; i < p->height; ++i) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void open_site(Percolation *p, int row, int col) {
    if (row < 0 || row >= p->height || col < 0 || col >= p->width) {
        return; // Out of bounds
    }
    p->grid[row][col] = OPEN; // Open the site
}

void print_grid(Percolation *p) {
    for (int i = 0; i < p->height; ++i) {
        for (int j = 0; j < p->width; ++j) {
            if (p->grid[i][j] == BLOCKED) {
                printf(" . ");
            } else if (p->grid[i][j] == OPEN) {
                printf(" O ");
            } else if (p->grid[i][j] == FULL) {
                printf(" F ");
            }
        }
        printf("\n");
    }
}

int is_valid(int row, int col, Percolation *p) {
    return row >= 0 && row < p->height && col >= 0 && col < p->width && p->grid[row][col] == OPEN;
}

void flood_fill(Percolation *p, int row, int col) {
    if (!is_valid(row, col, p)) return;
    p->grid[row][col] = FULL; // Mark the site as FULL

    // Recursive calls to fill adjacent sites
    flood_fill(p, row + 1, col);
    flood_fill(p, row - 1, col);
    flood_fill(p, row, col + 1);
    flood_fill(p, row, col - 1);
}

int does_percolate(Percolation *p) {
    for (int col = 0; col < p->width; ++col) {
        if (p->grid[0][col] == OPEN) { // Start from the top row
            flood_fill(p, 0, col);
        }
    }
    for (int col = 0; col < p->width; ++col) {
        if (p->grid[p->height - 1][col] == FULL) {
            return 1; // Percolates!
        }
    }
    return 0; // Does not percolate
}

void initialize_random_percolation(Percolation *p, float probability) {
    srand(time(NULL)); // Seed random number generator
    for (int i = 0; i < p->height; ++i) {
        for (int j = 0; j < p->width; ++j) {
            if ((float)rand() / RAND_MAX < probability) {
                open_site(p, i, j); // Open site with given probability
            }
        }
    }
}

int main() {
    int width = 10, height = 10;
    float probability = 0.5;

    printf("Percolation Simulator\n");
    printf("Grid Size: %dx%d\n", width, height);
    printf("Opening Probability: %.2f\n\n", probability);

    Percolation *p = create_percolation(width, height);
    initialize_random_percolation(p, probability);

    printf("Initial Grid:\n");
    print_grid(p);

    if (does_percolate(p)) {
        printf("\nThe system percolates!\n");
    } else {
        printf("\nThe system does not percolate.\n");
    }

    free_percolation(p);
    return 0;
}