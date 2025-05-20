//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_grid(int *grid, int width, int height);
void update_grid(int *grid, int width, int height);

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int width = 10;
    int height = 10;

    int *grid = malloc(width * height * sizeof(int));

    for (int i = 0; i < width * height; i++) {
        grid[i] = 0;
    }

    print_grid(grid, width, height);

    while (1) {
        update_grid(grid, width, height);
        printf("-------------------------------\n");
        print_grid(grid, width, height);
        printf("-------------------------------\n");
    }

    free(grid);
    return 0;
}

void print_grid(int *grid, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", grid[i * width + j]);
        }
        printf("\n");
    }
}

void update_grid(int *grid, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int live_neighbors = 0;
            int live_grid[3][3] = {
                {grid[i * width + j - 1], grid[i * width + j], grid[i * width + j + 1]},
                {grid[i * width + j - width], grid[i * width + j], grid[i * width + j + width]},
                {grid[i * width + j - 1], grid[i * width + j], grid[i * width + j + 1]}
            };

            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (live_grid[k][l] == 1) {
                        live_neighbors++;
                    }
                }
            }

            if (grid[i * width + j] == 1 && (live_neighbors < 2 || live_neighbors > 3)) {
                grid[i * width + j] = 0;
            } else if (grid[i * width + j] == 0 && live_neighbors == 3) {
                grid[i * width + j] = 1;
            }
        }
    }
}