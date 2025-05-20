//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100
#define NEIGHBORS 8

void initialize(int** grid, int* grid_width, int* grid_height) {
    *grid_width = WIDTH;
    *grid_height = HEIGHT;

    int i, j;
    for (i = 0; i < *grid_height; i++) {
        for (j = 0; j < *grid_width; j++) {
            grid[i][j] = 1;
        }
    }
}

void print_grid(int** grid, int* grid_width, int* grid_height) {
    int i, j;
    for (i = 0; i < *grid_height; i++) {
        for (j = 0; j < *grid_width; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void percolation(int** grid, int* grid_width, int* grid_height, int** connected_components) {
    srand(time(NULL));

    int i, j;
    for (i = 0; i < *grid_height; i++) {
        for (j = 0; j < *grid_width; j++) {
            if (grid[i][j] == 1) {
                int count = 0;
                int neighbors[NEIGHBORS];

                int neighbor_count = 0;
                for (int k = 0; k < NEIGHBORS; k++) {
                    int neighbor_index = (i - 1 + rand() % (2 * WIDTH)) % WIDTH + j - 1 + rand() % (2 * HEIGHT);
                    neighbors[k] = grid[neighbor_index][j];
                }

                for (int k = 0; k < NEIGHBORS; k++) {
                    if (neighbors[k] == 1) {
                        count++;
                    }
                }

                if (count >= NEIGHBORS * 2 + 1) {
                    connected_components[0][0] = 1;
                    printf("Connected component formed at (%d, %d)\n", j, i);
                }
            }
        }
    }
}

int main() {
    int** grid;
    int grid_width, grid_height;
    int** connected_components;

    initialize(&grid, &grid_width, &grid_height);
    print_grid(grid, &grid_width, &grid_height);

    connected_components = (int**)malloc(sizeof(int*) * 1);
    connected_components[0] = (int*)malloc(sizeof(int) * 1);

    percolation(grid, &grid_width, &grid_height, connected_components);

    print_grid(grid, &grid_width, &grid_height);

    free(connected_components);
    free(grid);

    return 0;
}