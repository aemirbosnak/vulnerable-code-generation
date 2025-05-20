//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int width;
    int height;
    int** grid;
} Percolation;

void initialize_grid(Percolation* percolation) {
    percolation->width = 100;
    percolation->height = 100;
    percolation->grid = (int**)malloc(percolation->width * sizeof(int*));

    for (int i = 0; i < percolation->width; i++) {
        percolation->grid[i] = (int*)malloc(percolation->height * sizeof(int));

        for (int j = 0; j < percolation->height; j++) {
            percolation->grid[i][j] = 0;
        }
    }
}

int is_connected(Percolation* percolation, int x, int y) {
    if (x < 0 || x >= percolation->width || y < 0 || y >= percolation->height) {
        return 0;
    }

    return percolation->grid[x][y] > 0;
}

int main() {
    srand(time(0));

    Percolation percolation;
    initialize_grid(&percolation);

    for (int i = 0; i < percolation.width; i++) {
        for (int j = 0; j < percolation.height; j++) {
            int r = rand() % 100;
            if (r < 50) {
                percolation.grid[i][j] = 1;
            }
        }
    }

    int num_connected = 0;
    for (int i = 0; i < percolation.width; i++) {
        for (int j = 0; j < percolation.height; j++) {
            if (is_connected(&percolation, i, j)) {
                num_connected++;
            }
        }
    }

    printf("Number of connected components: %d\n", num_connected);

    return 0;
}