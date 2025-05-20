//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    int grid_size = atoi(argv[1]);
    int max_steps = atoi(argv[2]);

    int grid[grid_size][grid_size];
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            grid[i][j] = 0;
        }
    }

    int num_open = 0;
    int num_adjacent = 0;
    int step = 0;

    srand(time(NULL));

    while (step < max_steps && num_open < grid_size * grid_size) {
        int x = rand() % grid_size;
        int y = rand() % grid_size;

        if (grid[x][y] == 0) {
            grid[x][y] = 1;
            num_open++;
            num_adjacent++;

            int neighbors[8];
            neighbors[0] = x - 1;
            neighbors[1] = x + 1;
            neighbors[2] = y - 1;
            neighbors[3] = y + 1;

            if (neighbors[0] >= 0 && neighbors[0] < grid_size && grid[neighbors[0]][y] == 0) {
                grid[neighbors[0]][y] = 1;
                num_open++;
                num_adjacent++;
            }

            if (neighbors[1] >= 0 && neighbors[1] < grid_size && grid[neighbors[1]][y] == 0) {
                grid[neighbors[1]][y] = 1;
                num_open++;
                num_adjacent++;
            }

            if (neighbors[2] >= 0 && neighbors[2] < grid_size && grid[x][neighbors[2]] == 0) {
                grid[x][neighbors[2]] = 1;
                num_open++;
                num_adjacent++;
            }

            if (neighbors[3] >= 0 && neighbors[3] < grid_size && grid[x][neighbors[3]] == 0) {
                grid[x][neighbors[3]] = 1;
                num_open++;
                num_adjacent++;
            }

            if (num_adjacent == 8) {
                printf("Percolation occurred at (%d, %d) after %d steps.\n", x, y, step);
                break;
            }
        }
    }

    if (step >= max_steps) {
        printf("No percolation occurred after %d steps.\n", max_steps);
    }

    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}