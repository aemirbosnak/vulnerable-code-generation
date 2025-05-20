//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BOX_SIZE 10
#define MAX_ITERATIONS 100000

int main() {
    int** grid = malloc(BOX_SIZE * sizeof(int*));
    for (int i = 0; i < BOX_SIZE; i++) {
        grid[i] = malloc(BOX_SIZE * sizeof(int));
        for (int j = 0; j < BOX_SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    srand(time(NULL));

    int num_occupied = 0;
    int num_neighbors = 0;
    for (int i = 0; i < BOX_SIZE; i++) {
        for (int j = 0; j < BOX_SIZE; j++) {
            int num_neighbors = 0;
            for (int k = 0; k < BOX_SIZE; k++) {
                if (i == k || j == k) continue;
                if (grid[i][k] || grid[k][j]) num_neighbors++;
            }
            if (rand() % 100 < num_neighbors / (BOX_SIZE * BOX_SIZE)) {
                grid[i][j] = 1;
                num_occupied++;
            }
        }
    }

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        int num_occupied_new = 0;
        for (int i = 0; i < BOX_SIZE; i++) {
            for (int j = 0; j < BOX_SIZE; j++) {
                if (grid[i][j] == 1) {
                    int num_neighbors = 0;
                    for (int k = 0; k < BOX_SIZE; k++) {
                        if (i == k || j == k) continue;
                        if (grid[i][k] || grid[k][j]) num_neighbors++;
                    }
                    if (num_neighbors >= 4) {
                        grid[i][j] = 2;
                        num_occupied_new++;
                    } else {
                        grid[i][j] = 0;
                    }
                }
            }
        }
        if (num_occupied_new == num_occupied) break;
        num_occupied = num_occupied_new;
    }

    for (int i = 0; i < BOX_SIZE; i++) {
        for (int j = 0; j < BOX_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    free(grid[0]);
    free(grid);

    return 0;
}