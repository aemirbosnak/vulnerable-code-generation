//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A site on the grid
typedef struct site {
    int x, y;   // Coordinates
    int open;   // Is the site open?
} site;

// The grid
site *grid;
int width, height;  // Dimensions of the grid

// Initialize the grid
void init_grid(int w, int h) {
    width = w;
    height = h;
    grid = malloc(sizeof(site) * w * h);
    for (int i = 0; i < w * h; i++) {
        grid[i].x = i % w;
        grid[i].y = i / w;
        grid[i].open = 0;
    }
}

// Open a site
void open_site(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return;  // Out of bounds
    }
    grid[y * width + x].open = 1;
}

// Is a site open?
int is_open(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return 0;  // Out of bounds
    }
    return grid[y * width + x].open;
}

// Count the number of open sites in a row
int count_open_in_row(int y) {
    int count = 0;
    for (int x = 0; x < width; x++) {
        if (is_open(x, y)) {
            count++;
        }
    }
    return count;
}

// Count the number of open sites in a column
int count_open_in_column(int x) {
    int count = 0;
    for (int y = 0; y < height; y++) {
        if (is_open(x, y)) {
            count++;
        }
    }
    return count;
}

// Percolate the grid
void percolate() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (is_open(x, y)) {
                // Check if the site is connected to the top
                if (y == 0 || is_open(x, y - 1)) {
                    // Open the site below
                    open_site(x, y + 1);
                }
                // Check if the site is connected to the left
                if (x == 0 || is_open(x - 1, y)) {
                    // Open the site to the right
                    open_site(x + 1, y);
                }
            }
        }
    }
}

// Print the grid
void print_grid() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", is_open(x, y) ? 'O' : 'X');
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the grid
    init_grid(20, 20);

    // Open a random number of sites
    for (int i = 0; i < 100; i++) {
        open_site(rand() % width, rand() % height);
    }

    // Percolate the grid
    percolate();

    // Print the grid
    print_grid();

    return 0;
}