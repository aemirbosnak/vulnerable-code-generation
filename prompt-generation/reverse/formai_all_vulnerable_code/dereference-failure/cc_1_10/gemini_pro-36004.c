//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Size of the grid */
#define SIZE 10

/* Probability of a site being open */
#define P 0.5

/* Data structure for a site */
typedef struct site {
    int open;
    int visited;
} site;

/* Function to create a new site */
site *new_site() {
    site *s = malloc(sizeof(site));
    s->open = rand() < P * RAND_MAX;
    s->visited = 0;
    return s;
}

/* Function to print a site */
void print_site(site *s) {
    printf("%d", s->open);
}

/* Function to create a new grid */
site **new_grid() {
    site **grid = malloc(SIZE * sizeof(site *));
    for (int i = 0; i < SIZE; i++) {
        grid[i] = malloc(SIZE * sizeof(site));
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = *new_site();
        }
    }
    return grid;
}

/* Function to print a grid */
void print_grid(site **grid) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            print_site(&grid[i][j]);
        }
        printf("\n");
    }
}

/* Function to check if a site is open */
int is_open(site *s) {
    return s->open;
}

/* Function to check if a site has been visited */
int is_visited(site *s) {
    return s->visited;
}

/* Function to mark a site as visited */
void visit_site(site *s) {
    s->visited = 1;
}

/* Function to check if a site is part of the percolating cluster */
int is_percolating(site *s) {
    return s->open && s->visited;
}

/* Function to check if a grid percolates */
int does_grid_percolate(site **grid) {
    // Check if the top row of the grid percolates
    for (int i = 0; i < SIZE; i++) {
        if (is_percolating(&grid[0][i])) {
            return 1;
        }
    }

    // Check if the bottom row of the grid percolates
    for (int i = 0; i < SIZE; i++) {
        if (is_percolating(&grid[SIZE - 1][i])) {
            return 1;
        }
    }

    // Check if any of the sites in the grid percolates
    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            if (is_percolating(&grid[i][j])) {
                return 1;
            }
        }
    }

    // The grid does not percolate
    return 0;
}

/* Main function */
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new grid
    site **grid = new_grid();

    // Print the grid
    print_grid(grid);

    // Check if the grid percolates
    int percolates = does_grid_percolate(grid);

    // Print the result
    printf("The grid %s percolate.\n", percolates ? "does" : "does not");

    // Free the grid
    for (int i = 0; i < SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}