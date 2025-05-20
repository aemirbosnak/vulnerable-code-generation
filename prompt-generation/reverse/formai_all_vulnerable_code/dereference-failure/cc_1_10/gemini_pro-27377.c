//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define grid size and site properties
#define GRID_SIZE 100
#define SITE '*'
#define FULL '*'
#define EMPTY ' '

// Function to create and initialize a grid
char** create_grid() {
    char** grid = malloc(GRID_SIZE * sizeof(char*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = malloc(GRID_SIZE * sizeof(char));
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
    return grid;
}

// Function to open a random site
void open_site(char** grid, int row, int col) {
    grid[row][col] = SITE;
}

// Function to check if a site is open
bool is_open(char** grid, int row, int col) {
    return grid[row][col] == SITE;
}

// Function to check if a site is full
bool is_full(char** grid, int row, int col) {
    return grid[row][col] == FULL;
}

// Function to check if a site is empty
bool is_empty(char** grid, int row, int col) {
    return grid[row][col] == EMPTY;
}

// Function to fill a site
void fill_site(char** grid, int row, int col) {
    if (is_open(grid, row, col)) {
        grid[row][col] = FULL;
    }
}

// Function to check if a site is percolating
bool is_percolating(char** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (is_full(grid, 0, i)) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (is_full(grid, GRID_SIZE - 1, j)) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Function to print the grid
void print_grid(char** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create and initialize the grid
    char** grid = create_grid();

    // Open random sites until the grid percolates
    srand(time(NULL));
    while (!is_percolating(grid)) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        open_site(grid, row, col);
    }

    // Print the final grid
    print_grid(grid);

    // Free the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}