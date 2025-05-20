//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

int main(int argc, char *argv[]) {
    // Set up grid size
    int grid_size = atoi(argv[1]);
    int grid[grid_size][grid_size];

    // Initialize grid to all 0's
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            grid[i][j] = 0;
        }
    }

    // Seed grid with some initial open cells
    int num_seeds = atoi(argv[2]);
    srand(time(NULL));
    for (int i = 0; i < num_seeds; i++) {
        int x = rand() % grid_size;
        int y = rand() % grid_size;
        grid[x][y] = 1;
    }

    // Iterate through grid and count open cells
    int open_cells = 0;
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            if (grid[i][j] == 1) {
                open_cells++;
            }
        }
    }

    // Check if percolation has occurred
    int percolation_threshold = atoi(argv[3]);
    if (open_cells > percolation_threshold) {
        printf("Percolation occurred!\n");
    } else {
        printf("Percolation did not occur.\n");
    }

    return 0;
}