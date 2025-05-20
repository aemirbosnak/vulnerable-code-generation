//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 20
#define MAX_HEIGHT 20

// Define the grid structure
typedef struct Grid {
    int **data;
    int width;
    int height;
} Grid;

// Function to create a new grid
Grid* createGrid(int w, int h) {
    Grid* g = malloc(sizeof(Grid));
    g->data = malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++) {
        g->data[i] = malloc(w * sizeof(int));
    }
    g->width = w;
    g->height = h;
    return g;
}

// Function to simulate percolation
void simulatePercolation(Grid* g) {
    int x, y, r;
    srand(time(NULL));

    // Iterate over the grid
    for (x = 0; x < g->width; x++) {
        for (y = 0; y < g->height; y++) {
            // Randomly choose a neighbor
            r = rand() % 4;

            // If the neighbor is open and the current cell is not, open the current cell
            if (g->data[y][x] == 0 && g->data[y-1][x] == 1) {
                g->data[y][x] = 1;
            }
        }
    }
}

int main() {
    Grid* g = createGrid(MAX_WIDTH, MAX_HEIGHT);

    // Simulate percolation
    simulatePercolation(g);

    // Print the grid
    for (int y = 0; y < g->height; y++) {
        for (int x = 0; x < g->width; x++) {
            printf("%d ", g->data[y][x]);
        }
        printf("\n");
    }

    return 0;
}